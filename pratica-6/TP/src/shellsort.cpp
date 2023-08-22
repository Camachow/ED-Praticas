#include "../include/shellsort.hpp"

void shell_sort(std::vector<int> &v) {

    int h = 1;
    int i, j;
    int rep = 0;

    while (h < int(v.size())) {
       h = h*3+1;
    }

    while (h > 1) {
        h /= 3;

        for (i = h; i < int(v.size()); i++) {
            int aux = v[i];
            j = i;

            while (j >= h && aux < v[j-h]) {
                v[j] = v[j-h];
                j -= h;
                rep++;
            }

            v[j] = aux;
        }
    }
};