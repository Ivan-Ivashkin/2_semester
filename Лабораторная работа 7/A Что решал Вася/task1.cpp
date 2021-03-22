#include <iostream>

int main() {
    int a, b, c, d, x;

    std::cin >> a;
    std::cin >> b;

    std::cin >> c;
    std::cin >> d;

    std::cin >> x;

    int key1 = b - a;
    int key2 = d / c;

    if ( (key1 == x) && (key2 == x) ) {
        std::cout << 5;
    } else if ( (key1 == x) || (key2 == x) ) {
        std::cout << 4;
    } else if (x == 1024) {
        std::cout << 3;
    } else {std::cout << 2;}

    return 0;

}
