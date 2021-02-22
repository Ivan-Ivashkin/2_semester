#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int checker (int i, int j, int N, int M, int **arr) {
    int counter;
    counter = 0;

    for (int k = -1; k<=1; k++) {
        for (int l = -1; l<=1; l++) {
           if ( (i + k < N && i + k >= 0) && (j + l < M && j + l >= 0) && (arr[i + k][j + l] == -1) ) {counter++;}
        }
    }
    return counter;
}

int main() {
    int N;
    cin >> N; // ввод числа строк

    int M;
    cin >> M; // ввод числа столбцов

    int K;
    cin >> K; // ввод количества мин

    int **arr = new int*[N];
    for (int i=0; i<N; i++) {arr[i] = new int[M];} // создание двумерного массива

    for (int i=0; i<K; i++) {
        int x;
        int y;
        cin >> x;
        cin >> y; // ввод коррдинат мин

        arr[x-1][y-1] = -1;
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (arr[i][j] != -1) {arr[i][j] = checker(i, j, N, M, arr);}
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {cout << arr[i][j] << " ";}
        cout << endl;
    }

    delete [] arr;
}