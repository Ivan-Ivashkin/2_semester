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

    for (int i = 1; i <= N; i++) {
        cin >> stair[i];
    }

    table[1] = stair[1];
    table[2] = max(stair[1], stair[2]);

    cout << '\n';

    for (int i = 3; i <= N+1; i++) {
        table[i] = stair[i] + max(table[i-1], table[i-2]);
    }

    cout << table[N] << '\n';
}
