#include <iostream>
#include <fstream>
#include <chrono>

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

void qsort(int *A, int first, int last) {
    int x, count;
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

    std::ofstream fout;

    fout.open("Quick_sort_sorted.txt");
    std::cout << "Starting Quick sort" << std::endl;
    for (int n = 5000; n <= 5005000; n = n + 10000) {

        int *A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = i;
        }

        std::cout << n << "; ";
        fout << n << "; ";
        auto start = std::chrono::high_resolution_clock::now();
            qsort(A, 0, n-1);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        std::cout << nsec.count() << ";" << std::endl;
        fout << nsec.count() << ";" << std::endl;
        delete []A;
        }
    fout.close();

    fout.open("Insertion_sort_sorted.txt");
    std::cout << "Starting Insertion sort" << std::endl;
    int n = 1000;
    while (n <= 1000000) {

        int *A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = i;
        }

        std::cout << n << "; ";
        fout << n << "; ";
        auto start = std::chrono::high_resolution_clock::now();
            insertion_sort(A, n);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        std::cout << nsec.count() << ";" << std::endl;
        fout << nsec.count() << ";" << std::endl;
        delete []A;

        if (n < 10000) {
            n = n + 1000;
        } else if (n < 100000) {
            n = n + 10000;
        } else if (n < 500000) {
            n = 500000;
        } else if (n < 1000000) {
            n = 1000000;
        } else if (n = 1000000) {
            n = 1000001;
        }
    }
    fout.close();

    fout.open("Selection_sort_sorted.txt");
    std::cout << "Starting Selection sort" << std::endl;
    n = 1000;
    while (n <= 500000) {

        int *A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = i;
        }

        std::cout << n << "; ";
        fout << n << "; ";
        auto start = std::chrono::high_resolution_clock::now();
            selection_sort(A, n);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        std::cout << nsec.count() << ";" << std::endl;
        fout << nsec.count() << ";" << std::endl;
        delete []A;

        if (n < 10000) {
            n = n + 1000;
        } else if (n < 100000) {
            n = n + 10000;
        } else if (n < 500000) {
            n = 500000;
        } else if (n = 500000) {
            n = 500001;
        }
    }
    fout.close();

    fout.open("Bubble_sort_sorted.txt");
    std::cout << "Starting Bubble sort" << std::endl;
    n = 1000;
    while (n <= 500000) {

        int *A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = i;
        }

        std::cout << n << "; ";
        fout << n << "; ";
        auto start = std::chrono::high_resolution_clock::now();
            bubble_sort(A, n);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        std::cout << nsec.count() << ";" << std::endl;
        fout << nsec.count() << ";" << std::endl;
        delete []A;

        if (n < 10000) {
            n = n + 1000;
        } else if (n < 100000) {
            n = n + 10000;
        } else if (n < 500000) {
            n = 500000;
        } else if (n = 500000) {
            n = 500001;
        }
    }
    fout.close();

    return 0;
}
