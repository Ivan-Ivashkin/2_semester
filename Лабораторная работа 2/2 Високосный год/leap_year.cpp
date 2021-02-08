#include <iostream>

main()
{
	int N;

	std::cin >> N;

	if ( (N % 4 == 0) && (N % 100 != 0) || (N % 400 == 0) ) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}

	return 0;
}