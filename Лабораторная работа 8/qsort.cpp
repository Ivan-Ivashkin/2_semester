#include <iostream>
#include <random>

void qsort(int A[], int first, int last) {
    int i, j;
    i = first;
    j = last;

    int x = A[(first + last)/2]; // опорный элемент берется из середины
    int mem;
    
    do {
        while (A[i] < x) {i++;}
        while (A[j] > x) {j--;}
        if (i <= j) {
            if (i < j) {
                mem = A[i];
                A[i] = A[j];
                A[j] = mem;
            } else {
                i++;
                j--;
            }
        }
    } while (i <= j);

    if (i < last) {qsort(A, i, last);}
    if (first < j) {qsort(A, first, j);}

}

int main() {

    int n = 20;
    int A[n];

    std::mt19937 engine(134); // 134 - произвольное число

    for (int i = 0; i < n; i++) {
        std::uniform_int_distribution<int> int_dist(0, 10000);
        A[i] = int_dist(engine);
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