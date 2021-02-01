#include <iostream>
#include <cmath>

int main()
{
	double a;
	double b;

	std::cin >> a >> b;
	double c = sqrt(a*a + b*b);

	std::cout << c;
	return 0;
}