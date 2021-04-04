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

    std::mt19937 engine(134); // 134 - произвольное число

    for (int i = 0; i < n; i++) {
        std::uniform_int_distribution<int> int_dist(0, 10000);
        A[i] = int_dist(engine);
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
