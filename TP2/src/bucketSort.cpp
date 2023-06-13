#include "../include/bucketSort.hpp"
#include "../include/insertionSort.hpp"
#include <math.h>

void bucketSort(Point* points, int n)  {
    Point biggest = Point();
    Point smallest = Point();

    int pos = 0;

    biggest = smallest = points[0];

    for (int i = 0; i < n; i++) {
        if (getAngle(points[i]) > getAngle(biggest)) {
            biggest = points[i];
        }
        if (getAngle(points[i]) < getAngle(smallest)) {
            smallest = points[i];
        }
    }

    //intialize buckets
    int numBuckets = floor(getAngle(biggest) - getAngle(smallest) / TAM_BUCKET + 1);
    Bucket *bucket = new Bucket[numBuckets * sizeof(Bucket)];

    for (int i = 0; i < numBuckets; i++) {
        bucket[i].size = 0;
    }

    //fill buckets
    for (int i = 0; i < n; i++) {
        pos = (getAngle(points[i]) - getAngle(smallest) / TAM_BUCKET);
        bucket[pos].values[bucket[pos].size++] = points[i];
    }

    pos = 0;

    //sort buckets
    for (int i = 0; i < numBuckets; i++) {
        insertionSort(bucket[i].values, bucket[i].size); //Ordena os baldes
        for(int j = 0; j < bucket[i].size; j++) {
            points[pos++] = bucket[i].values[j]; //Coloca os baldes ordenados no vetor
        }
    }
    delete[] bucket;
}