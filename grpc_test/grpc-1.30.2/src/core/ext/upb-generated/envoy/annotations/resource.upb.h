/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/annotations/resource.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_ANNOTATIONS_RESOURCE_PROTO_UPB_H_
#define ENVOY_ANNOTATIONS_RESOURCE_PROTO_UPB_H_

#include "upb/generated_util.h"
#include "upb/msg.h"
#include "upb/decode.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct envoy_annotations_ResourceAnnotation;
typedef struct envoy_annotations_ResourceAnnotation envoy_annotations_ResourceAnnotation;
extern const upb_msglayout envoy_annotations_ResourceAnnotation_msginit;


/* envoy.annotations.ResourceAnnotation */

UPB_INLINE envoy_annotations_ResourceAnnotation *envoy_annotations_ResourceAnnotation_new(upb_arena *arena) {
  return (envoy_annotations_ResourceAnnotation *)upb_msg_new(&envoy_annotations_ResourceAnnotation_msginit, arena);
}
UPB_INLINE envoy_annotations_ResourceAnnotation *envoy_annotations_ResourceAnnotation_parse(const char *buf, size_t size,
                        upb_arena *arena) {
  envoy_annotations_ResourceAnnotation *ret = envoy_annotations_ResourceAnnotation_new(arena);
  return (ret && upb_decode(buf, size, ret, &envoy_annotations_ResourceAnnotation_msginit, arena)) ? ret : NULL;
}
UPB_INLINE char *envoy_annotations_ResourceAnnotation_serialize(const envoy_annotations_ResourceAnnotation *msg, upb_arena *arena, size_t *len) {
  return upb_encode(msg, &envoy_annotations_ResourceAnnotation_msginit, arena, len);
}

UPB_INLINE upb_strview envoy_annotations_ResourceAnnotation_type(const envoy_annotations_ResourceAnnotation *msg) { return UPB_FIELD_AT(msg, upb_strview, UPB_SIZE(0, 0)); }

UPB_INLINE void envoy_annotations_ResourceAnnotation_set_type(envoy_annotations_ResourceAnnotation *msg, upb_strview value) {
  UPB_FIELD_AT(msg, upb_strview, UPB_SIZE(0, 0)) = value;
}

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* ENVOY_ANNOTATIONS_RESOURCE_PROTO_UPB_H_ */
