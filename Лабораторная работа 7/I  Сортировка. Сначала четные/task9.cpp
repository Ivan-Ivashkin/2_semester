#include <iostream>
#include <random>

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

    int n;
    std::cin >> n;

    int A[n]; // четные
    int j = 0;

    int B[n]; // нечетные
    int k = 0;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (x % 2 == 0) {
           A[j] = x;
           j++;
        } else if (x % 2 != 0) {
           B[k] = x;
           k++;
        }
    }

    qsort(A, 0, j);
    qsort(B, 0, k);

    int point_ch = 0, point_nch = 0l;
    if (k > j) {point_ch = 1;}
    else if (k < j) {point_nch = 1;}

    for (int i = point_nch; i < j + point_nch; i++) {
        std::cout << A[i] << ' ';
    }

    for (int i = point_ch; i < k + point_ch; i++) {
        std::cout << B[i] << ' ';
    }

    return 0;
}
