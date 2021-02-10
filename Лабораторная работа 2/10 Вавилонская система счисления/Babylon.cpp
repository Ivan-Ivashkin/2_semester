#include <iostream>
#include <string>

std::string digit(int a)
{
	std::string b;
	b = "";

	for (int i = 0; i < int(a / 10); i++) {
		b = b + "<";
	}

	for (int i = 0; i < a % 10; i++) {
		b = b + "v";
	}


	return b;
}


main()
{
	int N;
	std::cin >> N;

	std::string N_Bab;
	N_Bab = "";

	bool flag = true; // флаг первой итерации цикла (для отбрасывания точки в конце числа)

	while (N > 0) {
		int x;
		x = N % 60;
		if (flag) {
			N_Bab = digit(x) + N_Bab;
		} else {
			N_Bab = digit(x) + "." + N_Bab;
		}
		N = int(N / 60);
		flag = false;
	}
	
	std::cout << N_Bab;

	return 0;
}