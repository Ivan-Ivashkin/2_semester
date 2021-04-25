#include <iostream>
#include <vector>
using std::vector;

void bubble_sort(vector <int> A) {
    for (int j = 0; j < A.size()-1; j++) {
        for (int i = 0; i < A.size()-1; i++) {
            int c;
            if (A[i+1] < A[i]) {
                c = A[i];
                A[i] = A[i+1];
                A[i+1] = c;
            }
        }
    }
}

int main()
{
    using std::min;
    using std::cin;
    using std::cout;

    int N;
    cin >> N;

    vector <int> nails(N + 2, 0); // координаты гвоздиков
    vector <int> table(N + 2, 0); // расчетная таблица

    for (int i = 0; i < N; i++)
    {
        cin >> nails[i];
    }

    nails[N] = 0;
    nails[N+1] = 0;

    table[N] = 0;
    table[N+1] = 0;

    cout << '\n';

    bubble_sort(nails); // сортировка гвоздиков по возрастанию

    for (int i = N-1; i >=0; i--)
    {
        table[i] = min(table[i+1], table[i+2]) + abs(nails[i] - nails[i+1]);
    }

    cout << table[0] << '\n';

    return 0;
}
