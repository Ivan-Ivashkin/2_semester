#include <iostream>
#include <random>

void bubble_sort(int A[], int n) {
    for (int j = 0; j < n-1; j++) {
        for (int i = 0; i < n-1; i++) {
            int c;
            if (A[i+1] < A[i]) {
                c = A[i];
                A[i] = A[i+1];
                A[i+1] = c;
            }
        }
    }
}

int main() {

    int n = 20;
    int A[n];

    for (int i = 0; i < n; i++) {
            A[i] = i;
        }

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << ' ';
    }
    std::cout << '\n';

    bubble_sort(A, n);

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << ' ';
    }

    return 0;
}
