#include <iostream>
#include <vector>

int main()
{
    using std::vector;
    using std::max;
    using std::cin;
    using std::cout;

    int W, N;
    cin >> W >> N;

    vector <vector<int>> table(W + 1, vector<int>(N + 1, 0)); // расчетная таблица
    vector <vector<int>> key(2, vector<int>(N, 0)); // массы и стоимости

    for (int i = 0; i < N; i++) // заполнение стоимости
    {
        cin >> key[1][i];
    }

    for (int i = 0; i < N; i++) // заполнение весов
    {
        cin >> key[0][i];
    }

    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i >= key[0][j-1]) {

                if (table[i - key[0][j-1]][j-1] + key[1][j-1] >= table[i][j-1]) {

                    table[i][j] = table[i - key[0][j-1]][j-1] + key[1][j-1];

                } else{

                    table[i][j] = table[i][j-1];}
            } else{

                table[i][j] = table[i][j-1];}
        }
    }

    cout << '\n';

    for (int i = 0; i < 2; i++) // вспомогательный вывод таблицы-ключа
    {
        for (int j = 0; j < N; j++)
        {
            cout << key[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';

    for (int i = 0; i < W + 1; i++) // вывод расчетной таблицы
    {
        for (int j = 0; j < N + 1; j++)
        {
            cout << table[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';

    cout << "Answer: " << table[W][N] << '\n';

    return 0;
}
