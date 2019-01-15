cmake_minimum_required(VERSION 3.0)
project(proio VERSION 0.10.5)

set(CMAKE_CXX_STANDARD 11)

# Options
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "..." FORCE)
endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

option(REPORT_COVERAGE "Enable coverage report" OFF)

# Find Protobuf
find_package(Protobuf 3.1 REQUIRED)
if(NOT Protobuf_INCLUDE_DIRS)
    set(Protobuf_INCLUDE_DIRS ${PROTOBUF_INCLUDE_DIRS})
endif()
if(NOT Protobuf_LIBRARY)
    set(Protobuf_LIBRARY ${PROTOBUF_LIBRARY})
endif()
if(NOT Protobuf_LIBRARY_DIR)
    set(Protobuf_LIBRARY_DIR ${PROTOBUF_LIBRARY_DIR})
endif()
if(NOT Protobuf_PROTOC_EXECUTABLE)
    set(Protobuf_PROTOC_EXECUTABLE ${PROTOBUF_PROTOC_EXECUTABLE})
endif()
include_directories(${Protobuf_INCLUDE_DIRS})
get_filename_component(Protobuf_LIBRARY_DIR ${Protobuf_LIBRARY} DIRECTORY)
link_directories(${Protobuf_LIBRARY_DIR})

# Find lz4
find_path(LZ4_INCLUDE_DIR NAMES lz4frame.h)
if(NOT LZ4_INCLUDE_DIR)
    message(FATAL_ERROR "lz4frame.h not found!")
endif()
include_directories(${LZ4_INCLUDE_DIR})
find_library(LZ4_LIBRARY NAMES lz4)
if(NOT LZ4_LIBRARY)
    message(FATAL_ERROR "lz4 was not found!")
endif()
get_filename_component(LZ4_LIBRARY_DIR ${LZ4_LIBRARY} DIRECTORY)
link_directories(${LZ4_LIBRARY_DIR})

# Generate Protobuf code
function(protobuf_generate_cpp sources headers abs_proto_path rel_output_path)
    set(${sources})
    set(${headers})
    foreach(proto ${ARGN})
        get_filename_component(proto_dir ${proto} DIRECTORY)
        get_filename_component(proto_base ${proto} NAME_WE)
        file(RELATIVE_PATH proto_rel_dir ${abs_proto_path} ${proto_dir})
        set(proto_new_dir ${CMAKE_CURRENT_BINARY_DIR}/${rel_output_path}/${proto_rel_dir})
        set(source "${proto_new_dir}/${proto_base}.pb.cc")
        list(APPEND ${sources} ${source})
        set(header "${proto_new_dir}/${proto_base}.pb.h")
        list(APPEND ${headers} ${header})
        add_custom_command(
            OUTPUT ${source} ${header}
            COMMAND ${Protobuf_PROTOC_EXECUTABLE}
            ARGS --cpp_out ${CMAKE_CURRENT_BINARY_DIR} --proto_path=${rel_output_path}=${abs_proto_path} ${proto}
            DEPENDS ${proto}
            COMMENT "Running C++ protobuf compiler on ${proto}"
            )
    endforeach()
    set_source_files_properties(${${sources}} ${${headers}} PROPERTIES GENERATED TRUE)
    set(${sources} ${${sources}} PARENT_SCOPE)
    set(${headers} ${${headers}} PARENT_SCOPE)
endfunction()

set(proioprotos
    ${PROJECT_SOURCE_DIR}/proto/proio.proto
    )
protobuf_generate_cpp(protosources protoheaders ${PROJECT_SOURCE_DIR}/proto proio/proto ${proioprotos})
file(GLOB_RECURSE modelprotos ${PROJECT_SOURCE_DIR}/proto/model/*.proto)
protobuf_generate_cpp(modelsources modelheaders ${PROJECT_SOURCE_DIR}/proto/model proio/model ${modelprotos})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Specify library code
set(librarysources
    ${PROJECT_SOURCE_DIR}/src/event.cc
    ${PROJECT_SOURCE_DIR}/src/reader.cc
    ${PROJECT_SOURCE_DIR}/src/writer.cc
    )
set(libraryheaders
    ${PROJECT_SOURCE_DIR}/src/event.h
    ${PROJECT_SOURCE_DIR}/src/reader.h
    ${PROJECT_SOURCE_DIR}/src/writer.h
    )
include_directories(${PROJECT_SOURCE_DIR}/src)

# Add library targets
add_library(proio.pb SHARED
    ${protosources} ${protoheaders}
    ${modelsources} ${modelheaders}
    )
target_link_libraries(proio.pb PUBLIC protobuf)

add_library(proio SHARED
    ${librarysources} ${libraryheaders}
    )
target_link_libraries(proio PRIVATE proio.pb protobuf lz4 pthread)

# Install library and headers
set(proio_INCLUDE_DIR include)
install(TARGETS proio proio.pb
    EXPORT proioTargets
    DESTINATION lib
    )
foreach(header ${protoheaders} ${modelheaders})
    get_filename_component(dir ${header} DIRECTORY)
    file(RELATIVE_PATH rel_dir ${CMAKE_CURRENT_BINARY_DIR} ${dir})
    install(FILES ${header}
        DESTINATION ${proio_INCLUDE_DIR}/${rel_dir}
        )
endforeach()
foreach(header ${libraryheaders})
    install(FILES ${header}
        DESTINATION ${proio_INCLUDE_DIR}/proio/
        )
endforeach()

# Configure and install rootmap files
foreach(header ${protoheaders})
    get_filename_component(header ${header} NAME)
    set(libproio.pb_ROOTMAP_HEADERS
        "header proio/${header}\n${libproio.pb_ROOTMAP_HEADERS}"
        )
endforeach()
foreach(header ${modelheaders})
    get_filename_component(header ${header} NAME)
    set(libproio.pb_ROOTMAP_HEADERS
        "header proio/model/${header}\n${libproio.pb_ROOTMAP_HEADERS}"
        )
endforeach()
foreach(header ${libraryheaders})
    get_filename_component(header ${header} NAME)
    set(libproio_ROOTMAP_HEADERS
        "header proio/${header}\n${libproio_ROOTMAP_HEADERS}"
        )
endforeach()
configure_file(${PROJECT_SOURCE_DIR}/lib/libproio.pb.rootmap.in
    ${CMAKE_CURRENT_BINARY_DIR}/lib/libproio.pb.rootmap
    @ONLY
    )
configure_file(${PROJECT_SOURCE_DIR}/lib/libproio.rootmap.in
    ${CMAKE_CURRENT_BINARY_DIR}/lib/libproio.rootmap
    @ONLY
    )
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/lib/libproio.pb.rootmap
    ${CMAKE_CURRENT_BINARY_DIR}/lib/libproio.rootmap
    DESTINATION lib
    )

# Install and export targets
install(EXPORT proioTargets
    FILE proioTargets.cmake
    DESTINATION lib/proio
    )

include(CMakePackageConfigHelpers)

set(TARGETS_INSTALL_PATH lib/proio/proioTargets.cmake)
set(proio_LIBRARY lib/libproio.so)
set(proio.pb_LIBRARY lib/libproio.pb.so)
CONFIGURE_PACKAGE_CONFIG_FILE(
    ${PROJECT_SOURCE_DIR}/cmake/proioConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/proioConfig.cmake
    INSTALL_DESTINATION lib/proio
    PATH_VARS TARGETS_INSTALL_PATH proio_INCLUDE_DIR proio_LIBRARY proio.pb_LIBRARY
    )

write_basic_package_version_file("proioConfigVersion.cmake"
    VERSION ${proio_VERSION}
    COMPATIBILITY SameMajorVersion
    )

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/proioConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/proioConfigVersion.cmake
    DESTINATION lib/proio
    )

# Code tests
enable_testing()

add_executable(pushgetinspect src/tests/pushgetinspect/main.cc)
target_link_libraries(pushgetinspect proio proio.pb)
add_test(PushGetInspect pushgetinspect)

add_executable(refderef src/tests/refderef/main.cc)
target_link_libraries(refderef proio proio.pb pthread)
add_test(RefDeref refderef)

add_executable(tagmanip src/tests/tagmanip/main.cc)
target_link_libraries(tagmanip proio proio.pb)
add_test(TagManip tagmanip)

add_executable(metadata src/tests/metadata/main.cc)
target_link_libraries(metadata proio proio.pb)
add_test(Metadata metadata)

add_executable(eicunset src/tests/eicunset/main.cc)
target_link_libraries(eicunset proio proio.pb)
add_test(EICUnset eicunset)

add_executable(serialize src/tests/serialize/main.cc)
target_link_libraries(serialize proio proio.pb pthread)
add_test(Serialize serialize)

if(${REPORT_COVERAGE})
    message("Enabling coverage reporting")
    set_target_properties(proio
        PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage"
                   LINK_FLAGS "-fprofile-arcs")
    set_target_properties(pushgetinspect refderef tagmanip metadata eicunset serialize
        PROPERTIES LINK_FLAGS "-fprofile-arcs")
endif()

