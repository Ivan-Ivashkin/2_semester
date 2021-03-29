#include <iostream>
#include <random>
#include <chrono>

void buble_sort(int A[], int n) {
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

void qsort(int A[], int first, int last) {
    int i, j;
    i = first;
    j = last;
    int x = A[(first + last)/2]; // опорный элемент берется из середины
    int mem;
    do {
        while (A[i] < x) {i++;}
        std::cout << "---debug2---";
        while (A[j] > x) {j--;}
        std::cout << "---debug3---";
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
    std::cout << "---debug4---";
    if (i < last) {qsort(A, i, last);}
    std::cout << "---debug5---";
    if (first < j) {qsort(A, first, j);}
}

int main() {

    int n = 1000;

    while (n < 10000) {

    std::cout << n << "; ";

    int A[n], B[n];
    std::mt19937 engine(134); // 134 - произвольное число
    for (int i = 0; i < n; i++) {
        std::uniform_int_distribution<int> int_dist(0, 10000);
        A[i] = int_dist(engine);
    }

    {B[n] = A[n];
    auto start = std::chrono::high_resolution_clock::now();
        buble_sort(B, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto nsec = end - start;
    std::cout << nsec.count() << " ns; ";}
    
    {B[n] = A[n];
    auto start = std::chrono::high_resolution_clock::now();
        selection_sort(B, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto nsec = end - start;
    std::cout << nsec.count() << " ns; ";}

    {B[n] = A[n];
    auto start = std::chrono::high_resolution_clock::now();
        insertion_sort(B, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto nsec = end - start;
    std::cout << nsec.count() << " ns; ";}

    {B[n] = A[n];
    auto start = std::chrono::high_resolution_clock::now();
        std::cout << "---debug1---";
        qsort(B, 0, n-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto nsec = end - start;
    std::cout << nsec.count() << " ns;" << std::endl;}

    n = n + 10000;
    }

    return 0;
}