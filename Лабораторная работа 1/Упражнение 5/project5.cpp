#include <iostream>

main()
{
	int N;
	std::cin >> N;

	for (int i = N; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			std::cout << '*';
		}
	std::cout << std::endl;
	}

	return 0;
}