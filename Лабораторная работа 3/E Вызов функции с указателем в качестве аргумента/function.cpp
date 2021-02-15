#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int x;
    cin >> x;

    int y;
    cin >> y;

    int result;
    result = do_some_awesome_work(&x, &y);

    cout << result;

    return 0;
}