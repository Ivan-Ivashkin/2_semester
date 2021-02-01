#include <iostream>

main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		if ( (N % 2 == 0 && i > N/2) || (N % 2 != 0 && i > (N+1)/2) ) {
			break;
		}
		for (int j = 1; j <= N; j++) {
			if (j <= i-1 || j > N-i+1) {
				std::cout << ' ';
			} else {
				std::cout << '*';
			}
		}
	std::cout << std::endl;
	}

	return 0;
}