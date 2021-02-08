#include <iostream>

main()
{
	int N;
	std::cin >> N;

	int i;
	i = 1;

	while (i < N) {
		i = i*2;
		}

	if (i == N) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}

	return 0;
}