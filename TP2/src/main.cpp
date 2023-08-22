#include "../include/graham.hpp"  
#include "../include/timer.hpp"
#include "../include/jarvis.hpp"
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
    Point points[100000];
    
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

    cout << "Pontos da entrada:" << endl;
    for(int i = 0; i < n; i++){
        cout << "(" << points[i].getX() << " " << points[i].getY() << ")" << endl;
    }
    /* Stack stack = Stack();
    Point points[] = {{27,11}, {6,8}, {6,82}, {19,82}, {33,96}, {45,13}, {38,82}, {6,22}, {68,79}, {66,68}};
    int n = sizeof(points) / sizeof(points[0]); 

    cout<<n<<endl; */

    stack = convexHullMergesort(points, n);

    cout << "FECHO CONVEXO:" << endl;
    for(int i = 0; i < stack.getSize(); i++)
        cout << "(" << stack.getPoint(i).getX() << " " << stack.getPoint(i).getY() << ")" << endl;

    /* stack = convexHullInsertionSort(points, n);

    cout << "FECHO CONVEXO GRAHAM + INSERTION" << endl;
    for(int i = 0; i < stack.getSize(); i++)
        cout << "(" << stack.getPoint(i).getX() << " " << stack.getPoint(i).getY() << ")" << endl;

    stack = convexHullBucketSort(points, n);

    cout << "FECHO CONVEXO GRAHAM + BUCKET" << endl;
    for(int i = 0; i < stack.getSize(); i++)
        cout << "(" << stack.getPoint(i).getX() << " " << stack.getPoint(i).getY() << ")" << endl;

    stack = convexHullJarvis(points, n);

    cout << "FECHO CONVEXO JARVIS" << endl;
    for(int i = 0; i < stack.getSize(); i++)
        cout << "(" << stack.getPoint(i).getX() << " " << stack.getPoint(i).getY() << ")" << endl;

 */
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
    
    getrusage(RUSAGE_SELF, &start);
    stack = convexHullJarvis(points, n);
    getrusage(RUSAGE_SELF, &end);
    printf("JARVIS: %f\n", userTime(&start, &end));
    stack.clear();

    return 0;
}