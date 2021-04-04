#include <iostream>
#include <random>

void insertion_sort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int x = A[i];
        int j = i;
        while (j > 0 && A[j-1] > x) {
            A[j] = A[j-1];
            j = j - 1;
        }
        A[j] = x;
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

    insertion_sort(A, n);

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << ' ';
    }

    return 0;
}