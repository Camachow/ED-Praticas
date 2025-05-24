// include/metricsTracker.h
#ifndef METRICSTRACKER_H
#define METRICSTRACKER_H

#include <stdint.h>

typedef struct
{
  int64_t comparisons;
  int64_t movements;
  int64_t functionCalls;
} MetricsTracker;

#endif // METRICSTRACKER_H
