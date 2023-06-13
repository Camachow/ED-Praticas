#include "../include/timer.hpp"
#include <iostream>

float userTime(struct rusage *start, struct rusage *end) {
    return (float)(end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
           (float)1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}