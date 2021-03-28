#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int A[N];
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int min = N + 1;

    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
           for (int j = 1; i + j < N; j++) {
               if (-A[i] == A[i + j] && j < min) {
                   min = j;
               }
           }
        }
    }

    if (min != N + 1) { 
        cout << min;
    } else {
        cout << 0;
    }

    return 0;
}