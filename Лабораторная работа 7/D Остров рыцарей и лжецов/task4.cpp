#include <iostream>

using namespace std;

int main() {

    int N, news;
    cin >> N;
    cin >> news;

    string names[N];
    int who[N + 1];

    names[0] = "news";
    who[0] = news;

    for (int i = 1; i <= 2*N; i++) {
        cin >> names[i];
        cin >> who[i];
    }

    int M;
    cin >> M;

    for (int i = 1; i <= M; i++) {
        int curr = i % N;
        while (who[curr] == 2) { // состояние жителя №2 означает его смерть
            curr ++;
        }
        if ((news == 0) && (who[curr] == 1)) {
            who[curr] = 2;
        } else if ((news == 1) && (who[curr] == 0)) {
            who[curr] = 1;
        }
        
        int counter = 0;
        for (int j = 1; j <= N; j++) {
            if (who[j] != 2) {
                counter ++;
            }
        }
        if (counter == 1) {break;}
    }

    for (int i = 1; i <=N; i++) {
        if (who[i] != 2) {
            cout << names[i] << ' ' << who[i];
        }
    }

    for (int i = 1; i <=N; i++) {
        cout << names[i];
    }

    for (int i = 1; i <=N; i++) {
        cout << who[i];
    }

    return 0;

}