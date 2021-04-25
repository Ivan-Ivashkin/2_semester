#include <iostream>
#include <vector>

int main()
{
    using std::vector;
    using std::min;
    using std::cin;
    using std::cout;

    int S, N;
    cin >> S >> N;

    vector <vector<int>> table(S + 1, vector<int>(N + 1, 0)); // ��������� �������
    vector <int> key(N, 0); // �������� �����

    for (int i = 0; i < N; i++) // ���������� ���������
    {
        cin >> key[i];
    }

    cout << '\n';

    for (int i = 0; i < S + 1; i++) // ��������������� ���������� ��������� �������
    {
        table[i][0] = 2*S;
    }

    for (int i = 1; i < S + 1; i++) // �������� ���������� ��������� �������
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (i < key[j-1]) {
                    table[i][j] = table[i][j-1];
            }else {table[i][j] = min(table[i][j-1], table[ i - key[j-1] ][j] + 1);
                }
        }
    }

    cout << "Answer: " << table[S][N] << '\n';

    return 0;
}
