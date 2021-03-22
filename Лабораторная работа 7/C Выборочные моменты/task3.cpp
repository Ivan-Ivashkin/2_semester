#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    double x; // произвольное значение для входа в цикл

    float counter, summ, summ_sq = 0;

    while (x != 0) {
        std::cin >> x;
        counter ++;
        summ = summ + x;
        summ_sq = summ_sq + x*x;
    }

    double M, M_sq, D;
    M = summ/(counter-1);
    M_sq = summ_sq/(counter-1);
    D = M_sq - M*M;

    cout.precision(3);
    cout << std::fixed << M << ' ' << D;

    return 0;

}