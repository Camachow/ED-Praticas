#ifndef BUCKET_SORT_HPP
#define BUCKET_SORT_HPP
#define TAM_BUCKET 30

#include "point.hpp"
#include "stack.hpp"

class Bucket {
    public:
        Point values[TAM_BUCKET];
        int size;
};

void bucketSort(Point* points, int n);

#endif  // BUCKET_SORT_HPP