#include <iostream>

main()
{
	int a;
	int b;

	std::cin >> a;
	std::cin >> b;

	while (a != b) {
		if (a > b) {
			a = a - b;
		} else if (a < b) {
				b = b - a;
			}
	}

	std::cout << a;

	return 0;
}