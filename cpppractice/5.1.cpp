#include <iostream>

using namespace std;

namespace NonVirtualExample {
class Vehicle {
public:
    double calcFuelConsumption(double distance) const {
        cout << "Non-virtual base Vehicle::calcFuelConsumption called." << endl;
        return distance * 0.0;
    }
};

class Car : public Vehicle {
private:
    double fuelPer100Km;

public:
    explicit Car(double fuelPer100) : fuelPer100Km(fuelPer100) {}

    double calcFuelConsumption(double kilometers) const {
        cout << "Car::calcFuelConsumption called directly." << endl;
        return kilometers * fuelPer100Km / 100.0;
    }
};

class Ship : public Vehicle {
private:
    double fuelPerNauticalMile;

public:
    explicit Ship(double fuelPerMile) : fuelPerNauticalMile(fuelPerMile) {}

    double calcFuelConsumption(double nauticalMiles) const {
        cout << "Ship::calcFuelConsumption called directly." << endl;
        return nauticalMiles * fuelPerNauticalMile;
    }
};

class Truck : public Car {
private:
    double fuelPer100Km;

public:
    explicit Truck(double fuelPer100)
        : Car(fuelPer100), fuelPer100Km(fuelPer100) {}

    double calcFuelConsumption(double kilometers) const {
        cout << "Truck::calcFuelConsumption called directly." << endl;
        return kilometers * fuelPer100Km / 100.0;
    }
};
}  // namespace NonVirtualExample

namespace VirtualExample {
class Vehicle {
public:
    virtual ~Vehicle() = default;

    virtual double calcFuelConsumption(double distance) const {
        cout << "Virtual base Vehicle::calcFuelConsumption called." << endl;
        return distance * 0.0;
    }
};

class Car : public Vehicle {
private:
    double fuelPer100Km;

public:
    explicit Car(double fuelPer100) : fuelPer100Km(fuelPer100) {}

    double calcFuelConsumption(double kilometers) const override {
        cout << "Virtual Car::calcFuelConsumption called." << endl;
        return kilometers * fuelPer100Km / 100.0;
    }
};

class Ship : public Vehicle {
private:
    double fuelPerNauticalMile;

public:
    explicit Ship(double fuelPerMile) : fuelPerNauticalMile(fuelPerMile) {}

    double calcFuelConsumption(double nauticalMiles) const override {
        cout << "Virtual Ship::calcFuelConsumption called." << endl;
        return nauticalMiles * fuelPerNauticalMile;
    }
};

class Truck : public Car {
private:
    double fuelPer100Km;

public:
    explicit Truck(double fuelPer100)
        : Car(fuelPer100), fuelPer100Km(fuelPer100) {}

    double calcFuelConsumption(double kilometers) const override {
        cout << "Virtual Truck::calcFuelConsumption called." << endl;
        return kilometers * fuelPer100Km / 100.0;
    }
};
}  // namespace VirtualExample

namespace AbstractExample {
class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual double calcFuelConsumption(double distance) const = 0;
};

class Car : public Vehicle {
private:
    double fuelPer100Km;

public:
    explicit Car(double fuelPer100) : fuelPer100Km(fuelPer100) {}

    double calcFuelConsumption(double kilometers) const override {
        cout << "Abstract-derived Car::calcFuelConsumption called." << endl;
        return kilometers * fuelPer100Km / 100.0;
    }
};

class Ship : public Vehicle {
private:
    double fuelPerNauticalMile;

public:
    explicit Ship(double fuelPerMile) : fuelPerNauticalMile(fuelPerMile) {}

    double calcFuelConsumption(double nauticalMiles) const override {
        cout << "Abstract-derived Ship::calcFuelConsumption called." << endl;
        return nauticalMiles * fuelPerNauticalMile;
    }
};

class Truck : public Car {
private:
    double fuelPer100Km;

public:
    explicit Truck(double fuelPer100)
        : Car(fuelPer100), fuelPer100Km(fuelPer100) {}

    double calcFuelConsumption(double kilometers) const override {
        cout << "Abstract-derived Truck::calcFuelConsumption called." << endl;
        return kilometers * fuelPer100Km / 100.0;
    }
};
}  // namespace AbstractExample

/*
    Comparison required by the experiment:
    1. Non-virtual version:
       When a base-class pointer points to a derived object, calling calcFuelConsumption
       uses the base-class version because binding is static.
    2. Virtual version:
       When a base-class pointer points to a derived object, the derived-class version
       is called because binding is dynamic (runtime polymorphism).
    3. Abstract-class version:
       Vehicle cannot be instantiated directly anymore because it contains a pure virtual
       function. Only derived classes that implement the function can create objects.
*/

int main() {
    cout << "===== 1. Non-virtual function test =====" << endl;
    NonVirtualExample::Car nonVirtualCar(8.5);
    NonVirtualExample::Ship nonVirtualShip(3.2);
    NonVirtualExample::Truck nonVirtualTruck(18.0);

    NonVirtualExample::Vehicle* nonVirtualVehicles[] = {
        &nonVirtualCar, &nonVirtualShip, &nonVirtualTruck
    };

    for (const auto* vehicle : nonVirtualVehicles) {
        cout << "Fuel consumption result: "
             << vehicle->calcFuelConsumption(100.0) << endl;
    }

    cout << "\n===== 2. Virtual function test =====" << endl;
    VirtualExample::Car virtualCar(8.5);
    VirtualExample::Ship virtualShip(3.2);
    VirtualExample::Truck virtualTruck(18.0);

    VirtualExample::Vehicle* virtualVehicles[] = {
        &virtualCar, &virtualShip, &virtualTruck
    };

    for (const auto* vehicle : virtualVehicles) {
        cout << "Fuel consumption result: "
             << vehicle->calcFuelConsumption(100.0) << endl;
    }

    cout << "\n===== 3. Abstract class test =====" << endl;
    AbstractExample::Car abstractCar(8.5);
    AbstractExample::Ship abstractShip(3.2);
    AbstractExample::Truck abstractTruck(18.0);

    AbstractExample::Vehicle* abstractVehicles[] = {
        &abstractCar, &abstractShip, &abstractTruck
    };

    for (const auto* vehicle : abstractVehicles) {
        cout << "Fuel consumption result: "
             << vehicle->calcFuelConsumption(100.0) << endl;
    }

    cout << "\nNote: AbstractExample::Vehicle cannot create objects directly." << endl;
    return 0;
}
