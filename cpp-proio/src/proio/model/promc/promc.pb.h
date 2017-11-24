// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: model/promc/promc.proto

#ifndef PROTOBUF_model_2fpromc_2fpromc_2eproto__INCLUDED
#define PROTOBUF_model_2fpromc_2fpromc_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace proio {
namespace model {
namespace promc {
class Particle;
class ParticleDefaultTypeInternal;
extern ParticleDefaultTypeInternal _Particle_default_instance_;
}  // namespace promc
}  // namespace model
}  // namespace proio

namespace proio {
namespace model {
namespace promc {

namespace protobuf_model_2fpromc_2fpromc_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_model_2fpromc_2fpromc_2eproto

// ===================================================================

class Particle : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:proio.model.promc.Particle) */ {
 public:
  Particle();
  virtual ~Particle();

  Particle(const Particle& from);

  inline Particle& operator=(const Particle& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Particle(Particle&& from) noexcept
    : Particle() {
    *this = ::std::move(from);
  }

  inline Particle& operator=(Particle&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Particle& default_instance();

  static inline const Particle* internal_default_instance() {
    return reinterpret_cast<const Particle*>(
               &_Particle_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Particle* other);
  friend void swap(Particle& a, Particle& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Particle* New() const PROTOBUF_FINAL { return New(NULL); }

  Particle* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Particle& from);
  void MergeFrom(const Particle& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Particle* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated uint64 parents = 8;
  int parents_size() const;
  void clear_parents();
  static const int kParentsFieldNumber = 8;
  ::google::protobuf::uint64 parents(int index) const;
  void set_parents(int index, ::google::protobuf::uint64 value);
  void add_parents(::google::protobuf::uint64 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
      parents() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
      mutable_parents();

  // repeated uint64 children = 9;
  int children_size() const;
  void clear_children();
  static const int kChildrenFieldNumber = 9;
  ::google::protobuf::uint64 children(int index) const;
  void set_children(int index, ::google::protobuf::uint64 value);
  void add_children(::google::protobuf::uint64 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
      children() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
      mutable_children();

  // uint32 gen_id = 1;
  void clear_gen_id();
  static const int kGenIdFieldNumber = 1;
  ::google::protobuf::uint32 gen_id() const;
  void set_gen_id(::google::protobuf::uint32 value);

  // sint32 pdg_id = 2;
  void clear_pdg_id();
  static const int kPdgIdFieldNumber = 2;
  ::google::protobuf::int32 pdg_id() const;
  void set_pdg_id(::google::protobuf::int32 value);

  // uint64 mass = 4;
  void clear_mass();
  static const int kMassFieldNumber = 4;
  ::google::protobuf::uint64 mass() const;
  void set_mass(::google::protobuf::uint64 value);

  // sint64 Px = 5;
  void clear_px();
  static const int kPxFieldNumber = 5;
  ::google::protobuf::int64 px() const;
  void set_px(::google::protobuf::int64 value);

  // sint64 Py = 6;
  void clear_py();
  static const int kPyFieldNumber = 6;
  ::google::protobuf::int64 py() const;
  void set_py(::google::protobuf::int64 value);

  // uint32 status = 3;
  void clear_status();
  static const int kStatusFieldNumber = 3;
  ::google::protobuf::uint32 status() const;
  void set_status(::google::protobuf::uint32 value);

  // sint32 barcode = 10;
  void clear_barcode();
  static const int kBarcodeFieldNumber = 10;
  ::google::protobuf::int32 barcode() const;
  void set_barcode(::google::protobuf::int32 value);

  // sint64 Pz = 7;
  void clear_pz();
  static const int kPzFieldNumber = 7;
  ::google::protobuf::int64 pz() const;
  void set_pz(::google::protobuf::int64 value);

  // sint32 X = 11;
  void clear_x();
  static const int kXFieldNumber = 11;
  ::google::protobuf::int32 x() const;
  void set_x(::google::protobuf::int32 value);

  // sint32 Y = 12;
  void clear_y();
  static const int kYFieldNumber = 12;
  ::google::protobuf::int32 y() const;
  void set_y(::google::protobuf::int32 value);

  // sint32 Z = 13;
  void clear_z();
  static const int kZFieldNumber = 13;
  ::google::protobuf::int32 z() const;
  void set_z(::google::protobuf::int32 value);

  // uint32 T = 14;
  void clear_t();
  static const int kTFieldNumber = 14;
  ::google::protobuf::uint32 t() const;
  void set_t(::google::protobuf::uint32 value);

  // uint64 weight = 15;
  void clear_weight();
  static const int kWeightFieldNumber = 15;
  ::google::protobuf::uint64 weight() const;
  void set_weight(::google::protobuf::uint64 value);

  // sint64 energy = 17;
  void clear_energy();
  static const int kEnergyFieldNumber = 17;
  ::google::protobuf::int64 energy() const;
  void set_energy(::google::protobuf::int64 value);

  // sint32 charge = 16;
  void clear_charge();
  static const int kChargeFieldNumber = 16;
  ::google::protobuf::int32 charge() const;
  void set_charge(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proio.model.promc.Particle)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 > parents_;
  mutable int _parents_cached_byte_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 > children_;
  mutable int _children_cached_byte_size_;
  ::google::protobuf::uint32 gen_id_;
  ::google::protobuf::int32 pdg_id_;
  ::google::protobuf::uint64 mass_;
  ::google::protobuf::int64 px_;
  ::google::protobuf::int64 py_;
  ::google::protobuf::uint32 status_;
  ::google::protobuf::int32 barcode_;
  ::google::protobuf::int64 pz_;
  ::google::protobuf::int32 x_;
  ::google::protobuf::int32 y_;
  ::google::protobuf::int32 z_;
  ::google::protobuf::uint32 t_;
  ::google::protobuf::uint64 weight_;
  ::google::protobuf::int64 energy_;
  ::google::protobuf::int32 charge_;
  mutable int _cached_size_;
  friend struct protobuf_model_2fpromc_2fpromc_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Particle

// uint32 gen_id = 1;
inline void Particle::clear_gen_id() {
  gen_id_ = 0u;
}
inline ::google::protobuf::uint32 Particle::gen_id() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.gen_id)
  return gen_id_;
}
inline void Particle::set_gen_id(::google::protobuf::uint32 value) {
  
  gen_id_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.gen_id)
}

// sint32 pdg_id = 2;
inline void Particle::clear_pdg_id() {
  pdg_id_ = 0;
}
inline ::google::protobuf::int32 Particle::pdg_id() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.pdg_id)
  return pdg_id_;
}
inline void Particle::set_pdg_id(::google::protobuf::int32 value) {
  
  pdg_id_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.pdg_id)
}

// uint32 status = 3;
inline void Particle::clear_status() {
  status_ = 0u;
}
inline ::google::protobuf::uint32 Particle::status() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.status)
  return status_;
}
inline void Particle::set_status(::google::protobuf::uint32 value) {
  
  status_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.status)
}

// uint64 mass = 4;
inline void Particle::clear_mass() {
  mass_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Particle::mass() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.mass)
  return mass_;
}
inline void Particle::set_mass(::google::protobuf::uint64 value) {
  
  mass_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.mass)
}

// sint64 Px = 5;
inline void Particle::clear_px() {
  px_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Particle::px() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.Px)
  return px_;
}
inline void Particle::set_px(::google::protobuf::int64 value) {
  
  px_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.Px)
}

// sint64 Py = 6;
inline void Particle::clear_py() {
  py_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Particle::py() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.Py)
  return py_;
}
inline void Particle::set_py(::google::protobuf::int64 value) {
  
  py_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.Py)
}

// sint64 Pz = 7;
inline void Particle::clear_pz() {
  pz_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Particle::pz() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.Pz)
  return pz_;
}
inline void Particle::set_pz(::google::protobuf::int64 value) {
  
  pz_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.Pz)
}

// repeated uint64 parents = 8;
inline int Particle::parents_size() const {
  return parents_.size();
}
inline void Particle::clear_parents() {
  parents_.Clear();
}
inline ::google::protobuf::uint64 Particle::parents(int index) const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.parents)
  return parents_.Get(index);
}
inline void Particle::set_parents(int index, ::google::protobuf::uint64 value) {
  parents_.Set(index, value);
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.parents)
}
inline void Particle::add_parents(::google::protobuf::uint64 value) {
  parents_.Add(value);
  // @@protoc_insertion_point(field_add:proio.model.promc.Particle.parents)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
Particle::parents() const {
  // @@protoc_insertion_point(field_list:proio.model.promc.Particle.parents)
  return parents_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
Particle::mutable_parents() {
  // @@protoc_insertion_point(field_mutable_list:proio.model.promc.Particle.parents)
  return &parents_;
}

// repeated uint64 children = 9;
inline int Particle::children_size() const {
  return children_.size();
}
inline void Particle::clear_children() {
  children_.Clear();
}
inline ::google::protobuf::uint64 Particle::children(int index) const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.children)
  return children_.Get(index);
}
inline void Particle::set_children(int index, ::google::protobuf::uint64 value) {
  children_.Set(index, value);
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.children)
}
inline void Particle::add_children(::google::protobuf::uint64 value) {
  children_.Add(value);
  // @@protoc_insertion_point(field_add:proio.model.promc.Particle.children)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
Particle::children() const {
  // @@protoc_insertion_point(field_list:proio.model.promc.Particle.children)
  return children_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
Particle::mutable_children() {
  // @@protoc_insertion_point(field_mutable_list:proio.model.promc.Particle.children)
  return &children_;
}

// sint32 barcode = 10;
inline void Particle::clear_barcode() {
  barcode_ = 0;
}
inline ::google::protobuf::int32 Particle::barcode() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.barcode)
  return barcode_;
}
inline void Particle::set_barcode(::google::protobuf::int32 value) {
  
  barcode_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.barcode)
}

// sint32 X = 11;
inline void Particle::clear_x() {
  x_ = 0;
}
inline ::google::protobuf::int32 Particle::x() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.X)
  return x_;
}
inline void Particle::set_x(::google::protobuf::int32 value) {
  
  x_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.X)
}

// sint32 Y = 12;
inline void Particle::clear_y() {
  y_ = 0;
}
inline ::google::protobuf::int32 Particle::y() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.Y)
  return y_;
}
inline void Particle::set_y(::google::protobuf::int32 value) {
  
  y_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.Y)
}

// sint32 Z = 13;
inline void Particle::clear_z() {
  z_ = 0;
}
inline ::google::protobuf::int32 Particle::z() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.Z)
  return z_;
}
inline void Particle::set_z(::google::protobuf::int32 value) {
  
  z_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.Z)
}

// uint32 T = 14;
inline void Particle::clear_t() {
  t_ = 0u;
}
inline ::google::protobuf::uint32 Particle::t() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.T)
  return t_;
}
inline void Particle::set_t(::google::protobuf::uint32 value) {
  
  t_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.T)
}

// uint64 weight = 15;
inline void Particle::clear_weight() {
  weight_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Particle::weight() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.weight)
  return weight_;
}
inline void Particle::set_weight(::google::protobuf::uint64 value) {
  
  weight_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.weight)
}

// sint32 charge = 16;
inline void Particle::clear_charge() {
  charge_ = 0;
}
inline ::google::protobuf::int32 Particle::charge() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.charge)
  return charge_;
}
inline void Particle::set_charge(::google::protobuf::int32 value) {
  
  charge_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.charge)
}

// sint64 energy = 17;
inline void Particle::clear_energy() {
  energy_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Particle::energy() const {
  // @@protoc_insertion_point(field_get:proio.model.promc.Particle.energy)
  return energy_;
}
inline void Particle::set_energy(::google::protobuf::int64 value) {
  
  energy_ = value;
  // @@protoc_insertion_point(field_set:proio.model.promc.Particle.energy)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace promc
}  // namespace model
}  // namespace proio

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_model_2fpromc_2fpromc_2eproto__INCLUDED
