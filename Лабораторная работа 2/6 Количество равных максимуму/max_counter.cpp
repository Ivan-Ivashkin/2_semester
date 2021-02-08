#include <iostream>

main()
{
	int x;
	x = 1; // произвольное ненулевое значение (для последующего сравнения)

	int max;
	max = 0;

	int i;
	i = 1;

	while (x != 0) {
		std::cin >> x;
		if (x > max) {
			max = x;
			i = 1;
		} else if (x == max) {
				i ++;
			}
	}

	std::cout << i;

	return 0;
}