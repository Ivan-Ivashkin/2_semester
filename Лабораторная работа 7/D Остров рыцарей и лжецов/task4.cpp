#include <iostream>

using namespace std;

int main() {
    int N, news;
    cin >> N;
    cin >> news;

    int island[N][3];
    string names[N];

    int i = 0;
    while (i < N) {
        string x;
        cin >> names[N];
        cin >> island[i][1];
        i++;
    }

    island[0][2] = news; // новость сообщается первому жителю

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int j = 0;
        while (island[j][2] == 2 || island[j][2] == -2) {
            j++;
        }
        
        int k = 1;
        while (island[(j + k) % N][2] == -2) {
            k++;
        }

        island[(j + k) % N][2] = island[j][2]*island[j][1];
        
        if (island[(j + k) % N][2] == 0 && island[j][1] == 1) {
            island[j][2] == -2;
        } else if (island[(j + k) % N][2] == 1 && island[j][1] == 0) {
            island[j][1] == 1;
        }

        int counter = 0;
        for (int p = 0; p < N; p++) {
            if (island[p][2] != -2) {
                counter++;
            }
        }

        if (counter == 1) {break;}

    }

    for (int i = 0; i < N; i++) {
         cout << names[i] << ' ' << island[i][1] << '\n';
    }

    return 0;

}