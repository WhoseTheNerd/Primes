#include "primes_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void primes_list_init(struct primes_list* list, uint64_t capacity)
{
    list->array = (uint64_t*)calloc(capacity, sizeof(uint64_t));
    list->capacity = capacity;
    list->length = 0;
}

void primes_list_add(struct primes_list* list, uint64_t data)
{
    if (list->length >= list->capacity) {
        primes_list_resize(list, 1.5 * list->capacity);
    }

    list->array[list->length] = data;
    list->length += 1;
}

void primes_list_resize(struct primes_list* list, uint64_t new_capacity)
{
    uint64_t length = list->length;
    uint64_t* new_array = (uint64_t*)calloc(new_capacity, sizeof(uint64_t));
    memcpy(new_array, list->array, length);
    free(list->array);
    list->array = new_array;
    list->capacity = new_capacity;
    list->length = length;
}

void primes_list_free(struct primes_list* list)
{
    free(list->array);
    list->capacity = 0;
    list->length = 0;
}
