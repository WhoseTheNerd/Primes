#ifndef BOOLEAN_VECTOR_H_INCLUDED
#define BOOLEAN_VECTOR_H_INCLUDED

#include <inttypes.h>
#include <stdbool.h>

struct boolean_vector
{
    uint8_t* list;
    uint64_t capacity;
};

void boolean_vector_init(struct boolean_vector* vector, uint64_t capacity);
void boolean_vector_set_all(struct boolean_vector* vector, bool state);
void boolean_vector_resize(struct boolean_vector* vector, uint64_t new_capacity);
bool boolean_vector_get(struct boolean_vector* vector, uint64_t index);
void boolean_vector_set_true(struct boolean_vector* vector, uint64_t index);
void boolean_vector_set_false(struct boolean_vector* vector, uint64_t index);
void boolean_vector_free(struct boolean_vector* vector);

#endif // BOOLEAN_VECTOR_H_INCLUDED
