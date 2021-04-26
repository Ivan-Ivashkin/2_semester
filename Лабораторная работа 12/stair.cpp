#include <iostream>
#include <vector>

int main(){

    using std::vector;
    using std::cout;
    using std::cin;
    using std::max;

    int N;
    cin >> N;

    vector <int> stair(N+1, 0);
    vector <int> table(N+1, 0);
    vector <bool> num(N+1, false);

    for (int i = 1; i <= N; i++) {
        cin >> stair[i];
    }

    table[1] = stair[1];
    table[2] = stair[2];

    for (int i = 3; i <= N; i++) {
        table[i] = stair[i] + max(table[i-1], table[i-2]);
    }

    int i = N;
    while (i > 1){
        if (max(table[i-1], table[i-2]) == table[i-1]) {
            num[i-1] = true;
            i = i-1;
        } else {
            num[i-2] = true;
            i = i-2;
        }
    }
    num[N] = true;

    cout << '\n';
    cout << table[N] << '\n';

    for (int i = 1; i <= N; i++){
        if(num[i]){
            cout << i << ' ';
        }
    }
}
