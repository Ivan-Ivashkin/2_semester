#include <iostream>

main()
{
	int x;
	x = 1; // произвольное ненулевое значение (для последующего сравнения)

	int max;
	max = 0;

	while (x != 0) {
		std::cin >> x;
		if (x % 2 == 0 && x > max) {
			max = x;
		}
	}

	std::cout << max;

	return 0;
}