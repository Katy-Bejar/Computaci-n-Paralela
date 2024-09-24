#include <iostream>
#include <chrono>

#define MAX 10000
using namespace std;

double A[MAX][MAX], x[MAX], y[MAX];

void reset_y() {
    for (int i = 0; i < MAX; ++i) {
        y[i] = 0.0;
    }
}

void bucle_1() {
    for (int i = 0; i < MAX; i++ ) {
        for (int j = 0; j < MAX; j++ ) {
            y[i] += A[i][j] * x[j];
        }
    }
}

void bucle_2() {
    for (int j = 0; j < MAX; j++ ) {
        for (int i = 0; i < MAX; i++ ) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    
    auto start1 = chrono::high_resolution_clock::now();
    bucle_1();
    auto stop1 = chrono::high_resolution_clock::now();
    
    reset_y();
    
    auto start2 = chrono::high_resolution_clock::now();
    bucle_2();
    auto stop2 = chrono::high_resolution_clock::now();

    auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);

    cout << "Tiempo empleado por bucle_1: " << duration1.count() << " milisegundos" << endl;
    cout << "Tiempo empleado por bucle_2: " << duration2.count() << " milisegundos" << endl;

    return 0;
}