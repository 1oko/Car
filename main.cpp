#include <iostream>
#include "Car.h"
#include "Point.h"

int main () {

	Car car;
	Car car2;

	car2.refill(59);

	std::cout << car << std::endl;

	// car2.drive(Point(2, 2));

	std::cout << car2 << std::endl;

	return 0;
}
