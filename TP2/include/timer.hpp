#ifndef TIMER_HPP
#define TIMER_HPP

#include "sys/resource.h"

float userTime(struct rusage *start, struct rusage *end);

#endif  // TIMER_HPP