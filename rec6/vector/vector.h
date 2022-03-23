#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  size_t size, capacity;
  int *data;
} Vector;

/**
 * @brief Creates an empty %Vector.
 *
 * @return Vector* Points to the created %Vector.
 *
 * This function creates an empty %Vector on heap, with %size 0 and %capacity 0.
 */
inline Vector *vector_create() {
  Vector *ret = (Vector *)malloc(sizeof(Vector));
  ret->size = 0;
  ret->capacity = 0;
  ret->data = NULL;
  return ret;
}

/**
 * @brief Creates a %Vector from a given array.
 *
 * @param arr Points to the beginning of an array.
 * @param n The number of elements in the array.
 * @return Vector* Points to the created %Vector.
 *
 * This function creates a %Vector on heap, with elements copied from a given
 * array.
 */
inline Vector *vector_create_from_array(int *arr, size_t n) {
  Vector *ret = vector_create();
  ret->data = (int *)malloc(sizeof(int) * n);
  memcpy(ret->data, arr, sizeof(int) * n);
  ret->size = n;
  ret->capacity = n;
  return ret;
}

/**
 * @brief Creates an empty %Vector with storage reserved.
 *
 * @param n The %capacity needed.
 * @return Vector* Points to the created %Vector.
 *
 * This function creates a %Vector on heap and reserve the space for @a n
 * elements to be stored. The %capacity is set @a n.
 */
inline Vector *vector_create_reserve(size_t n) {
  Vector *ret = vector_create();
  ret->data = (int *)malloc(sizeof(int) * n);
  ret->size = 0;
  ret->capacity = n;
  return ret;
}

/**
 * @brief Reallocates memory for a %Vector.
 *
 * @param vector Points to the %Vector which needs reallocation.
 * @param new_cap The new capacity.
 *
 * This function reallocates the space that can contain @a new_cap number of
 * elements, and then copies the old elements into the new space. The memory
 * allocated for the old storage will be freed.
 */
inline void vector_reallocate(Vector *vector, size_t new_cap) {
  int *new_data = (int *)malloc(sizeof(int) * new_cap);
  memcpy(new_data, vector->data, vector->size * sizeof(int));
  free(vector->data);
  vector->capacity = new_cap;
  vector->data = new_data;
}

inline void vector_check_and_realloc(Vector *vector) {
  if (vector->size == vector->capacity)
    vector_reallocate(vector, vector->capacity ? vector->capacity * 2 : 1);
}

inline void vector_destroy(Vector *vector) {
  if (vector) {
    free(vector->data);
    free(vector);
  }
}

// Be careful with self-assignment.
inline void vector_assign(Vector *dest, Vector *source) {
  int *new_data = (int *)malloc(sizeof(int) * source->capacity);
  memcpy(new_data, source->data, source->size * sizeof(int));
  free(dest->data);
  dest->size = source->size;
  dest->capacity = source->capacity;
  dest->data = source->data;
}

inline void vector_push_back(Vector *vector, int v) {
  vector_check_and_realloc(vector);
  vector->data[vector->size++] = v;
}

inline void vector_pop_back(Vector *vector) {
  --vector->size;
}

inline int vector_access(Vector *vector, size_t n) {
  return vector->data[n];
}

inline void vector_shrink_to_fit(Vector *vector) {
  vector_reallocate(vector, vector->size);
}

#endif // _VECTOR_H_
