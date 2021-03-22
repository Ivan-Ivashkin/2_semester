#include <iostream>

int main() {

    int N;
    std::cin >> N;

    bool flag = true;

    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;

        if ( (x % 4 == 0) && (x / 1000 != 4) && (x / 1000 != 5) ) {
            std::cout << x << '\n';
            flag = false;
        } else if ( (x % 7 == 0) && (x / 1000 != 7) && (x / 1000 != 1) ) {
            std::cout << x << '\n';
            flag = false;
        } else if ( (x % 9 == 0) && (x / 1000 != 9) && (x / 1000 != 8) ) {
            std::cout << x << '\n';
            flag = false;
        }

    }

    if (flag) {
        std::cout << 0;
    }

    return 0;

}