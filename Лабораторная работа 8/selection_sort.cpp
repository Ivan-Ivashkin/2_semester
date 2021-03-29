#include <iostream>
#include <random>

void selection_sort(int A[], int n) {
    for (int curr = 0; curr < n; curr++) {
        int min = curr;
        for (int i = curr; i < n; i++) {
            if (A[i] < A[min]) {
                min = i;
            }
        }
        int c;
        c = A[curr];
        A[curr] = A[min];
        A[min] = c;
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

    selection_sort(A, n);

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << ' ';
    }

    return 0;
}