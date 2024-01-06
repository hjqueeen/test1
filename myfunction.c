#include "myfunction.h"
#include <stdio.h>
#include <stdint.h>

// Measures and prints the execution time of 'func_to_time' using clock_gettime().
void time_function(void (*func_to_time)()) {
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    func_to_time();
    clock_gettime(CLOCK_MONOTONIC, &end);

    uint64_t duration = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
    printf("Execution time: %llu ns\n", duration);
}

// This function takes another function as an argument and measures its execution time
void cpu_time_function(void (*func_to_time)()) {
    clock_t start = clock();
    func_to_time();
    clock_t end = clock();

    // Calculate the time taken in seconds
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to execute the function: %f seconds\n", time_taken);
}