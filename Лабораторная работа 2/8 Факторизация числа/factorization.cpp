#include <iostream>

bool is_it_prime(int x) 
{
	int i;
	i = 2;

	while (x % i != 0) {
		i++;
	}

	if (i == x) {
		return true;
	} else {
		return false;
	}
}

main()
{
	int N;
	std::cin >> N;
	
	int j;
	j = 2;

	while (N > 1) {
		if (is_it_prime(j) && (N % j == 0)) {
			N = N / j;
			std::cout << j << '\n';
		} else {
			j++;
		}
	}

}