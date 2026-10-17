#ifndef VECTOR_HELPERS_H
#define VECTOR_HELPERS_H

#include <stdlib.h>
#include <assert.h>

#define VEC_RESIZE(vec, _cap) do { \
  (vec)->data = realloc((vec)->data, (_cap) * sizeof((vec)->data[0])); \
  assert((vec)->data != NULL); \
  (vec)->cap = (_cap); \
} while (0)

#define VEC_GROW(vec, _cap) do { if ((vec)->cap < (_cap)) { VEC_RESIZE((vec), (_cap)); } } while (0)

#define VEC_PUSH(vec, el) do { \
  if ((vec)->cap == (vec)->len) { VEC_RESIZE((vec), ((vec)->len == 0 ? 20 : (vec)->len * 2)); } \
  (vec)->data[(vec)->len++] = (el); \
} while (0)

#define VEC_POP(vec) do { (vec)->len--; } while (0)
#define VEC_BACK(vec) ((vec)->data[(vec)->len - 1])
#define VEC_FREE(vec) do { if ((vec)->data != NULL) { free((vec)->data); (vec)->data = NULL; } } while (0)

#endif
