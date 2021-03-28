#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    int A[N][N];
    int B[N][N];

    // Заполнение матрицы А
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    // Транспонирование матрицы A (результат - в матрицу B)
    for (int i = 0; i <N; i++) {
        for (int j = 0; j <N; j++) {
            B[j][i] = A[i][j];
        }
    }

    // Отражение матрицы B (результат - в матрицу A)
    for (int i = 0; i <N; i++) {
        for (int j = 0; j <N; j++) {
            A[i][j] = B[i][N-(j+1)];
        }
    }

    // Вывод матрицы А
    for (int i = 0; i <N; i++) {
        for (int j = 0; j <N; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;

}