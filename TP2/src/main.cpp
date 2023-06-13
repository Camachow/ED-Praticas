#include "../include/graham.hpp"  
#include "../include/timer.hpp"
#include "bits/getopt_core.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int arg, char **argv) {
    if (arg < 2) {
        cout << "Erro: Nenhum nome de arquivo fornecido" << endl;
        return 1;
    }

    Stack stack = Stack();
    Point points[10000];
    
    ifstream file(argv[1]);

    if(!file.is_open()) {
        cout << "Erro ao abrir o arquivo" << endl;
        return 0;
    }

    int n = 0;
    char line[10000];
    while(file.getline(line, 10000))
    {
        int x, y;
        sscanf(line, "%d %d", &x, &y);
        Point p = Point(x, y);
        points[n] = p;
        n++;
    }

    n = sizeof(points) / sizeof(points[0]);

    cout<<n<<endl;

    stack = convexHullMergesort(points, n);

    cout << "FECHO CONVEXO:" << endl;
    for(int i = 0; i < stack.getSize(); i++)
        cout << "(" << stack.getPoint(i).getX() << " " << stack.getPoint(i).getY() << ")" << endl;

    stack = convexHullInsertionSort(points, n);

    cout << "FECHO CONVEXO GRAHAM + INSERTION" << endl;
    for(int i = 0; i < stack.getSize(); i++)
        cout << "(" << stack.getPoint(i).getX() << " " << stack.getPoint(i).getY() << ")" << endl;

    stack = convexHullBucketSort(points, n);

    cout << "FECHO CONVEXO GRAHAM + BUCKET" << endl;
    for(int i = 0; i < stack.getSize(); i++)
        cout << "(" << stack.getPoint(i).getX() << " " << stack.getPoint(i).getY() << ")" << endl;



    struct rusage start, end;

    getrusage(RUSAGE_SELF, &start);
    stack = convexHullMergesort(points, n);
    getrusage(RUSAGE_SELF, &end);
    printf("GRAHAM + MERGESORT: %f\n", userTime(&start, &end));
    stack.clear();

    getrusage(RUSAGE_SELF, &start);
    stack = convexHullInsertionSort(points, n);
    getrusage(RUSAGE_SELF, &end);
    printf("GRAHAM + INSERTIONSORT: %f\n", userTime(&start, &end));
    stack.clear();

    getrusage(RUSAGE_SELF, &start);
    stack = convexHullBucketSort(points, n);
    getrusage(RUSAGE_SELF, &end);
    printf("GRAHAM + BUCKETSORT: %f\n", userTime(&start, &end));
    stack.clear();

    return 0;
}