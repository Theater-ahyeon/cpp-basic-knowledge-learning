#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

class Vehicle {
public:
    Vehicle() {
        cout << "[Constructor] Vehicle created." << endl;
        system("pause");
    }

    ~Vehicle() {
        cout << "[Destructor] Vehicle destroyed." << endl;
        system("pause");
    }

    double calcFuelConsumption(double distance) const {
        cout << "Vehicle base function has no concrete fuel-consumption rule." << endl;
        return distance * 0.0;
    }
};

class Car : public Vehicle {
protected:
    double tankCapacity;
    double fuelPer100Km;

public:
    Car(double tank, double fuelPer100)
        : tankCapacity(tank), fuelPer100Km(fuelPer100) {
        cout << "[Constructor] Car created." << endl;
        system("pause");
    }

    ~Car() {
        cout << "[Destructor] Car destroyed." << endl;
        system("pause");
    }

    double calcFuelConsumption(double kilometers) const {
        return kilometers * fuelPer100Km / 100.0;
    }
};

class Ship : public Vehicle {
private:
    double tankCapacity;
    double fuelPerNauticalMile;

public:
    Ship(double tank, double fuelPerMile)
        : tankCapacity(tank), fuelPerNauticalMile(fuelPerMile) {
        cout << "[Constructor] Ship created." << endl;
        system("pause");
    }

    ~Ship() {
        cout << "[Destructor] Ship destroyed." << endl;
        system("pause");
    }

    double calcFuelConsumption(double nauticalMiles) const {
        return nauticalMiles * fuelPerNauticalMile;
    }
};

class Truck : public Car {
private:
    double loadLimit;

public:
    Truck(double tank, double fuelPer100, double load)
        : Car(tank, fuelPer100), loadLimit(load) {
        cout << "[Constructor] Truck created." << endl;
        system("pause");
    }

    ~Truck() {
        cout << "[Destructor] Truck destroyed." << endl;
        system("pause");
    }

    double calcFuelConsumption(double kilometers) const {
        return kilometers * fuelPer100Km / 100.0;
    }
};

/*
    Explanation required by the experiment:
    1. When a Car object is created, Vehicle is constructed first, then Car.
    2. When a Ship object is created, Vehicle is constructed first, then Ship.
    3. When a Truck object is created, the order is Vehicle -> Car -> Truck,
       because Truck is derived from Car, and Car is derived from Vehicle.
    4. Destruction order is exactly the reverse of construction:
       Truck -> Car -> Vehicle, and similarly for other derived objects.
*/

int main() {
    cout << fixed << setprecision(2);

    Car car(55.0, 8.5);
    Ship ship(600.0, 3.2);
    Truck truck(120.0, 18.0, 12.0);

    cout << "\nCar fuel consumption for 120 km: "
         << car.calcFuelConsumption(120.0) << " L" << endl;
    cout << "Ship fuel consumption for 35 nautical miles: "
         << ship.calcFuelConsumption(35.0) << " L" << endl;
    cout << "Truck fuel consumption for 200 km: "
         << truck.calcFuelConsumption(200.0) << " L" << endl;

    cout << "\nMore test data:" << endl;
    cout << "Car fuel consumption for 300 km: "
         << car.calcFuelConsumption(300.0) << " L" << endl;
    cout << "Ship fuel consumption for 80 nautical miles: "
         << ship.calcFuelConsumption(80.0) << " L" << endl;
    cout << "Truck fuel consumption for 450 km: "
         << truck.calcFuelConsumption(450.0) << " L" << endl;

    return 0;
}
