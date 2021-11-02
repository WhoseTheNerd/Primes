#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "primes_list.h"
#include "boolean_vector.h"

int main()
{
    const uint64_t N = 1e10;
    const uint64_t EXPECTED_PRIMES = N / log(N);
    printf("N is %lu and expect at least %lu primes.\n", N, EXPECTED_PRIMES);
    clock_t t1 = clock();

    struct primes_list primes = {0};
    primes_list_init(&primes, 1.5 * EXPECTED_PRIMES);

    struct boolean_vector sieve = {0};
    boolean_vector_init(&sieve, N);
    boolean_vector_set_all(&sieve, true);

    /* Sieve prime numbers and filter them as well */
    for (uint64_t i = 2; i < N; ++i)
    {
        if (boolean_vector_get(&sieve, i))
        {
            for (uint64_t x = i*i; x < N; x += i)
            {
                boolean_vector_set_false(&sieve, x);
            }
            primes_list_add(&primes, i);
        }
    }

    clock_t t2 = clock();
    double elapsed_time = ((double)(t2 - t1)) / (double)CLOCKS_PER_SEC;
    boolean_vector_free(&sieve);

    printf("Sieve of Eratosthenes took %f seconds and found %lu primes.\nWriting primes to a file.\n", elapsed_time, primes.length);

    FILE* file = fopen("primes.txt", "w");
    for (uint64_t i = 0; i < primes.length; ++i)
    {
        fprintf(file, "%lu\n", primes.array[i]);
    }
    fclose(file);

    primes_list_free(&primes);
    return 0;
}
