#include <iostream>
#include <string>

class Car {
public:
    std::string name;
    std::string model;
    int year;

    Car(std::string n, std::string m, int y) : name(n), model(m), year(y) {}

    void displayInfo() {
        std::cout << "Car Information: " << year << " " << name << " " << model;
    }
};

class ElectricCar : public Car {
public:
    double batteryCapacity;
    ElectricCar(std::string n, std::string m, int y, double battery) : Car(n, m, y), batteryCapacity(battery) {}

    void displayInfo() {
        Car::displayInfo();
        std::cout << " Battery Capacity: " << batteryCapacity << " kWh\n";
    }
};

class GasCar : public Car {
public:
    int fuelEfficiency;
    GasCar(std::string n, std::string m, int y, int efficiency) : Car(n, m, y), fuelEfficiency(efficiency) {}

    void displayInfo() {
        Car::displayInfo();
        std::cout << " Fuel Efficiency: " << fuelEfficiency << " MPG\n";
    }
};

int main() {
    std::string carType;
    std::cout << "Enter car type (Electric/Gas): ";
    std::cin >> carType;

    std::string name, model;
    int year;

    std::cout << "Enter Name: ";
    std::cin >> name;

    std::cout << "Enter model: ";
    std::cin >> model;

    std::cout << "Enter year: ";
    std::cin >> year;

    if (carType == "Electric") {
        double batteryCapacity;
        std::cout << "Enter battery capacity (kWh): ";
        std::cin >> batteryCapacity;

        ElectricCar electricCar(name, model, year, batteryCapacity);
        electricCar.displayInfo();
    } else if (carType == "Gas") {
        int fuelEfficiency;
        std::cout << "Enter fuel efficiency (MPG): ";
        std::cin >> fuelEfficiency;

        GasCar gasCar(name, model, year, fuelEfficiency);
        gasCar.displayInfo();
    } else {
        std::cout << "Invalid car type.\n";
    }

    return 0;
}
