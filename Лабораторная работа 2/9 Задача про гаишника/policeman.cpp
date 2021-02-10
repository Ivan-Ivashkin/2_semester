#include <iostream>
#include <string>

int fine(std::string number)
{
	if (number[1] == number[2] && number[2] == number[3]) {
		return 1000;
	} else if (number[1] == number[2] || number[2] == number[3] || number[1] == number[3]) {
		return 500;
	} else {
		return 100;
	}
}


main()
{
	int salary;
	salary = 0;

	std::string speed;
	std::string number;
	
	do {
		std::cin >> speed;
		std::cin >> number;
		
		if (atoi(speed.c_str()) > 60 && number != "A999AA") {
			salary = salary + fine(number);
		}
		
	} while (number != "A999AA");

	std::cout << salary;

	return 0;
}