# proio for C++
[![Build Status](https://travis-ci.org/proio-org/cpp-proio.svg?branch=master)](https://travis-ci.org/proio-org/cpp-proio)
[![codecov](https://codecov.io/gh/proio-org/cpp-proio/branch/master/graph/badge.svg)](https://codecov.io/gh/proio-org/cpp-proio)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/ad338e9f8dad4cdbb54d664a742f3a81)](https://www.codacy.com/app/proio-org/cpp-proio?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=proio-org/cpp-proio&amp;utm_campaign=Badge_Grade)


Proio is an event-oriented streaming data format based on Google's [protocol
buffers](https://developers.google.com/protocol-buffers/) (protobuf).  Proio
aims to add event structure and additional compression to protobuf in a way
that supports event data model serialization in medium- and high-energy
physics.  Additionally, proio
* supports self-descriptive data,
* is stream compatible,
* is language agnostic,
* and brings along many advantages of protobuf, including forward/backward
  compatibility.

For detailed information on the proio format and introductory information on
the software implementations, please see [DOI
10.1016/j.cpc.2019.03.018](https://doi.org/10.1016/j.cpc.2019.03.018).  This
work was inspired and influenced by [LCIO](https://github.com/iLCSoft/LCIO),
ProMC (Sergei Chekanov), and EicMC (Alexander Kiselev)

Also see the [main proio repository](https://github.com/proio-org/proio) for
additional information information.

## API
The API documentation is generated using Doxygen, and can be found
[here](https://proio-org.github.io/cpp-proio-docs/).

## Installation
### Requirements
* Protobuf 3.1+
* LZ4 1.8+

### Building the code
First thing to note is that cpp-proio uses git submodules to pull in the
language-independent proio files.  This means that you will have to initialize
and pull the submodule.
```shell
git submodule update --init
```

Once, the proio submodule is up-to-date, standard CMake practices apply, so
make sure you have CMake installed.  Create a build directory (e.g.
cpp-proio/build), and `cd` into it.  Then, run `cmake` on the directory with
`CMakeLists.txt` (this directory).
```shell
mkdir build
cd build
cmake ../
make
make test
sudo make install
```

If you need to point CMake to dependencies in non-standard locations, please
set the
[`CMAKE_PREFIX_PATH`](https://cmake.org/cmake/help/v3.0/variable/CMAKE_PREFIX_PATH.html)
variable.  For example, if you build and install the required Protobuf and LZ4
libraries into subdirectories of `/opt`, your `cmake` command might look like
the following:
```shell
cmake \
    -DCMAKE_PREFIX_PATH="/opt/protobuf;/opt/lz4" \
    -DCMAKE_INSTALL_PREFIX=/opt/proio \
    ../
```

### Installing LZ4 from github
The following installs to the default installation prefix.
```
git clone https://github.com/lz4/lz4.git && cd lz4
make cmake
sudo cmake --build contrib/cmake_unofficial/.  -- install
```

