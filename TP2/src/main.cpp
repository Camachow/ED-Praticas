#include "../include/graham.hpp"   

int main() {
     // Exemplo de pontos de entrada
Point points[] = {{0, 0}, {1, 1}, {2, 2}, {3, 1}, {4, 4}, {1, 2}, {0, 3}};
    int n = sizeof(points) / sizeof(points[0]);

    // Exemplo de pontos de entra   da
    
    cout<<n<<endl;

    convexHull(points, n);

    return 0;
}