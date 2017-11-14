#include <iostream>
#include "Car.h"

Car::Car(double capacity, double consumption, const Point& location, const std::string& model) {
	this->fuelAmount = 0;
	this->fuelCapacity = capacity;
	this->fuelConsumption = consumption;
	this->location = location;
	this->model = model;
}

Car::~Car() {}

double Car::getFuelAmount() const {
	return this->fuelAmount;
}

double Car::getFuelCapacity() const {
	return this->fuelCapacity;
}

double Car::getFuelConsumption() const {
	return this->fuelConsumption;
}

const Point& Car::getLocation() const {
	return this->location;
}

const std::string& Car::getModel() const {
	return this->model;
}

void Car::drive(const Point& destination) {
    if (this->fuelAmount == 0 || this->location.distance(destination) * this->fuelConsumption > this->fuelAmount) {
        throw OutOfFuel();
    }

    this->fuelAmount -= this->location.distance(destination) * this->fuelConsumption;
    this->location = destination;
}
void Car::drive(double x, double y) {
	const Point temp = Point(x,y);

	this->drive(temp);
}

void Car::refill(double fuel) {
	if (this->fuelAmount + fuel > fuelCapacity ) {
		throw ToMuchFuel();
	}

	this->fuelAmount + fuel;
}


std::ostream& operator<<(std::ostream& out, const Car& car) {
	
	out << "Model:" << car.getModel() << "; location:" << car.getLocation() << "; fuelCapacity:" << car.getFuelCapacity() 
	<< "; fuelConsumption:"	<< car.getFuelConsumption() << "; fuelAmount:" << car.getFuelAmount();
	
	return out;
}