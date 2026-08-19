#include <iostream>
#include <string>

using namespace std;

class Car
{
protected:
    string brand;
    string model;
    bool isengineon;
    int speed;

public:
    Car(string b, string m)
    {
        this->brand = b;
        this->model = m;
        isengineon = false;
        speed = 0;
    }

    void start()
    {
        isengineon = true;
        cout << brand << " " << model << " Engine started" << endl;
    }

    void stop()
    {
        isengineon = false;
        speed = 0;
        cout << brand << " " << model << " Engine stopped" << endl;
    }

    virtual void accelerate() = 0; // Pure virtual function
    virtual void brake() = 0;      // Pure virtual function
    virtual ~Car() {}              // Virtual destructor to ensure proper cleanup of derived class objects

};

class ManualCar : public Car
{
private:
    int currentgear;

public:
    ManualCar(string b, string m) : Car(b, m)
    {
        currentgear = 0; // Start in neutral
    }
    void shiftGear(int gear)
    {
        currentgear = gear;
        cout << brand << " " << model << " shifted to gear " << gear << endl;
    }

    void accelerate()
    {
        if (isengineon)
        {
            speed += 10;
            cout << brand << " " << model << " accelerated to " << speed << " km/h  " << endl;
        }
        else
        {
            cout << brand << " " << model << " Engine is off. Please start the engine first." << endl;
        }
    }

    void brake()
    {
        if (speed > 0)
        {
            speed -= 10;
            cout << brand << " " << model << " decelerated to " << speed << " km/h" << endl;
        }
        else
        {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }
};

class ElectricCar : public Car
{
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m) : Car(b, m)
    {
        batteryLevel = 100; // Start with full battery
    }

    void accelerate()
    {
        if (isengineon)
        {
            speed += 15;
            batteryLevel -= 5; // Decrease battery level on acceleration
            cout << brand << " " << model << " accelerated to " << speed << " km/h. Battery level: " << batteryLevel << "%" << endl;
        }
        else
        {
            cout << brand << " " << model << " Engine is off. Please start the engine first." << endl;
        }
    }

    void brake()
    {
        if (speed > 0)
        {
            speed -= 15;
            cout << brand << " " << model << " decelerated to " << speed << " km/h" << endl;
        }
        else
        {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }
};

int main() {
 Car* mymanualcar= new ManualCar("toyota", "corolla");
    mymanualcar->start();
    mymanualcar->accelerate();

    // Downcasting to access ManualCar specific functionality
    ManualCar* manual = dynamic_cast<ManualCar*>(mymanualcar);
    if (manual) {
        manual->shiftGear(1);
    }
    mymanualcar->stop();
    mymanualcar->accelerate();
    mymanualcar->brake();
    mymanualcar->stop();

 Car* myelectriccar = new ElectricCar("Tesla", "Model S");
        myelectriccar->start();
        myelectriccar->accelerate();
        myelectriccar->accelerate();
        myelectriccar->brake();
        myelectriccar->stop();
    
        delete mymanualcar; // Clean up memory
        delete myelectriccar; // Clean up memory
    
        return 0;  

};