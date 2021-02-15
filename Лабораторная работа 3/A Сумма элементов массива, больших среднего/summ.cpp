#include <iostream>

main()
{
	int n;
	std::cin >> n;

	int s;
	s = 0;

	int * arr = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		s = s + arr[i];
	}
	
	float sr;
	sr = s / n;

	s = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > sr) {
			s = s + arr[i];
		}
	}

	std::cout << s;

	delete [] arr;
	arr = NULL;

	return 0;
}