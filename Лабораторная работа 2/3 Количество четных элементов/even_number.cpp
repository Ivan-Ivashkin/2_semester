#include <iostream>

main()
{
	int x;
	x = 1; // произвольное ненулевое значение (для последующего сравнения)

	int i;
	i = 0;

	while (x != 0) {
		std::cin >> x;
		if (x % 2 == 0 && x != 0) {
			i ++;
		}
	}

	std::cout << i;

	return 0;
}