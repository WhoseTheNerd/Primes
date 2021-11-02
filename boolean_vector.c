#include "boolean_vector.h"

#include <stdlib.h>
#include <string.h>

void boolean_vector_init(struct boolean_vector* vector, uint64_t capacity)
{
    capacity /= 8;
    capacity += 1;

    vector->list = (uint8_t*)calloc(capacity, sizeof(uint8_t));
    vector->capacity = capacity;
}

void boolean_vector_set_all(struct boolean_vector* vector, bool state)
{
    uint8_t value = state * 0xff;
    memset(vector->list, value, vector->capacity);
}

void boolean_vector_resize(struct boolean_vector* vector, uint64_t new_capacity)
{
    new_capacity /= 8;
    new_capacity += 1;
    uint8_t* new_list = (uint8_t*)calloc(new_capacity, sizeof(uint8_t));
    memcpy(new_list, vector->list, vector->capacity);
    free(vector->list);
    vector->list = new_list;
    vector->capacity = new_capacity;
}

bool boolean_vector_get(struct boolean_vector* vector, uint64_t index)
{
    uint8_t byte = vector->list[index / 8];
    uint8_t bit = index % 8;
    return byte & (1 << bit);
}

void boolean_vector_set_true(struct boolean_vector* vector, uint64_t index)
{
    uint8_t byte = vector->list[index / 8];
    uint8_t bit = index % 8;
    byte |= (1 << bit);
    vector->list[index / 8] = byte;
}

void boolean_vector_set_false(struct boolean_vector* vector, uint64_t index)
{
    uint8_t byte = vector->list[index / 8];
    uint8_t bit = index % 8;
    byte &= ~(1 << bit);
    vector->list[index / 8] = byte;
}

void boolean_vector_free(struct boolean_vector* vector)
{
    vector->capacity = 0;
    free(vector->list);
}
