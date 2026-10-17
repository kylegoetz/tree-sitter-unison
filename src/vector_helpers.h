#ifndef VECTOR_HELPERS_H
#define VECTOR_HELPERS_H

#include <stdlib.h>
#include <assert.h>

#define VEC_RESIZE(vec, _cap) do { \
  (vec)->data = realloc((vec)->data, (_cap) * sizeof((vec)->data[0])); \
  assert((vec)->data != NULL); \
  (vec)->cap = (_cap); \
} while (0)

#define VEC_RESIZE_LM(vec, _cap) do { \
  (vec)->list_marker_stack = realloc((vec)->list_marker_stack, (_cap) * sizeof((vec)->list_marker_stack[0])); \
  assert((vec)->list_marker_stack != NULL); \
  (vec)->lm_cap = (_cap); \
} while (0)

#define VEC_GROW(vec, _cap) do { if ((vec)->cap < (_cap)) { VEC_RESIZE((vec), (_cap)); } } while (0)

#define VEC_GROW_LM(vec, _cap) do { if ((vec)->lm_cap < (_cap)) { VEC_RESIZE_LM((vec), (_cap)); } } while (0)

#define VEC_PUSH(vec, el) do { \
  if ((vec)->cap == (vec)->len) { VEC_RESIZE((vec), ((vec)->len == 0 ? 20 : (vec)->len * 2)); } \
  (vec)->data[(vec)->len++] = (el); \
} while (0)

#define VEC_PUSH_LM(vec, el) do { \
  if ((vec)->lm_cap == (vec)->lm_len) { VEC_RESIZE_LM((vec), ((vec)->lm_len == 0 ? 20 : (vec)->lm_len * 2)); } \
  (vec)->list_marker_stack[(vec)->lm_len++] = (el); \
} while (0)

#define VEC_POP(vec) do { (vec)->len--; } while (0)
#define VEC_POP_LM(vec) do { (vec)->lm_len--; } while (0)
#define VEC_BACK(vec) ((vec)->data[(vec)->len - 1])

#define START_LIST(vec) do { \
	VEC_PUSH_LM(vec, (vec)->len); \
} while (0)

#endif
