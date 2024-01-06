#ifndef TESTVORBEREITEN_MYFUNCTION_H
#define TESTVORBEREITEN_MYFUNCTION_H

#include <time.h>

// Measures execution time of a function with no arguments and no return.
void time_function(void (*func_to_time)());

// Measures execution time of a function with no arguments and no return.
void cpu_time_function(void (*func_to_time)());

#endif //TESTVORBEREITEN_MYFUNCTION_H
