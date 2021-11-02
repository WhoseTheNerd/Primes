#ifndef PRIMES_LIST_H_INCLUDED
#define PRIMES_LIST_H_INCLUDED

#include <inttypes.h>

struct primes_list
{
    uint64_t* array;
    uint64_t capacity;
    uint64_t length;
};

void primes_list_init(struct primes_list* list, uint64_t capacity);
void primes_list_add(struct primes_list* list, uint64_t data);
void primes_list_resize(struct primes_list* list, uint64_t new_capacity);
void primes_list_free(struct primes_list* list);

#endif // PRIMES_LIST_H_INCLUDED
