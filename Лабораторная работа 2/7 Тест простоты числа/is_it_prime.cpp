#include <iostream>

main()
{
	int N;
	std::cin >> N;

	int i;
	i = 2;

	while (N % i != 0) {
		i++;
	}

	if (i == N) {
		std::cout << 1;
	} else {
		std::cout << 0;
	}

	return 0;
}