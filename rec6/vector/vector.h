#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* For in-class demonstration. The functions in this header do not check or
 * report any exception or error.
 */

typedef struct {
  size_t size, capacity;
  int *data;
} Vector;

/**
 * @brief Creates an empty %Vector.
 *
 * @return Vector* Points to the created %Vector.
 *
 * This function creates an empty %Vector on heap, with @c size 0 and @c capacity 0.
 */
Vector *vector_create() {
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
Vector *vector_create_from_array(int *arr, size_t n) {
  Vector *ret = vector_create();
  ret->data = (int *)malloc(sizeof(int) * n);
  for (size_t i = 0; i < n; ++i)
    ret->data[i] = arr[i];
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
 * elements to be stored. The @c capacity is set to @a n.
 */
Vector *vector_create_reserve(size_t n) {
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
void vector_reallocate(Vector *vector, size_t new_cap) {
  int *new_data = (int *)malloc(sizeof(int) * new_cap);
  for (size_t i = 0; i < vector->size; ++i)
    new_data[i] = vector->data[i];
  free(vector->data);
  vector->capacity = new_cap;
  vector->data = new_data;
}

/**
 * @brief Reallocate a larger block of memory if necessary.
 *
 * @param vector Points to the %Vector that might need reallocation.
 * This function checks whether a given %Vector is full, and reallocate a block
 * of memory twice as large as the original one if it is full.
 */
void vector_check_and_realloc(Vector *vector) {
  if (vector->size == vector->capacity)
    vector_reallocate(vector, vector->capacity ? vector->capacity * 2 : 1);
}

/**
 * @brief Frees the memory of a %Vector.
 *
 * @param vector Points to the %Vector that needs destruction.
 * This function frees not only the data of the given %Vector, but also the
 * memory storing the %Vector itself.
 */
void vector_destroy(Vector *vector) {
  free(vector->data);
  free(vector);
}

/**
 * @brief Assignment of %Vectors.
 *
 * @param dest Points to the %Vector being assigned to.
 * @param source Points to the %Vector assigned with.
 * After assignment, *dest is a copy of *source.
 */
void vector_assign(Vector *dest, Vector *source) {
  // Be careful with self-assignment.
  int *new_data = (int *)malloc(sizeof(int) * source->capacity);
  for (size_t i = 0; i < source->size; ++i)
    new_data[i] = source->data[i];
  free(dest->data);
  dest->size = source->size;
  dest->capacity = source->capacity;
  dest->data = source->data;
}

void vector_push_back(Vector *vector, int v) {
  vector_check_and_realloc(vector);
  vector->data[vector->size++] = v;
}

void vector_pop_back(Vector *vector) {
  --vector->size;
}

int vector_access(Vector *vector, size_t n) {
  return vector->data[n];
}

void vector_shrink_to_fit(Vector *vector) {
  vector_reallocate(vector, vector->size);
}

void vector_clear(Vector *vector) {
  vector->size = 0;
}

#endif // _VECTOR_H_
