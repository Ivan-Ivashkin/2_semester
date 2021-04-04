#include <iostream>
#include <random>

void qsort(float *A, int first, int last) {
    float x, count;
    int i = first, j = last;
    x = A[(i+j)/2]; // опорный берется из середины
    do {
        while (A[i] < x) {i++;}
        while (A[j] > x) {j--;}
        if (i <= j) {
            count = A[i];
            A[i] = A[j];
            A[j] = count;
            i++;
            j--;
        }
    } while (i < j);
    if (first < j) {qsort(A, first, j);}
    if (i < last) {qsort(A, i, last);}
}

int main() {

    int n = 20;
    float A[n];

    std::mt19937 engine(134); // 134 - произвольное число

    for (int i = 0; i < n; i++) {
        std::uniform_real_distribution<float> real_dist(0.0, 10000.0);
        A[i] = real_dist(engine);
    }

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << ' ';
    }
    std::cout << '\n';

    qsort(A, 0, n-1);

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << ' ';
    }

    return 0;
}
