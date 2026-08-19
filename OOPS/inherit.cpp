#include <iostream>
#include <string>

using namespace std;

class Car{
    protected: 
    string brand;
    string model;
    bool isengineon;
    int speed;

    public:
    Car(string b, string m){
        this->brand=b;
        this->model=m;
        isengineon = false;
        speed = 0;
    }
    void start(){
        isengineon = true;
        cout << brand << " " << model << " Engine started" << endl;
    }
    void accelerate(){
        if(isengineon){
            speed += 10;
            cout << brand << " " << model << " accelerated to " << speed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " Engine is off. Please start the engine first." << endl;
        }
    }
    void stop(){
        isengineon = false;
        speed = 0;
        cout << brand << " " << model << " Engine stopped" << endl;
    }

    void brake(){
        if(speed > 0){
            speed -= 10;
            cout << brand << " " << model << " decelerated to " << speed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }

    virtual ~Car(){}
};

class ManualCar : public Car{
    private:
    int currentgear;

    public:
    ManualCar(string b, string m): Car(b,m){
        currentgear = 0; // Start in neutral
    }

    void shiftGear(int gear){
        currentgear = gear; 
        cout << brand << " " << model << " shifted to gear " << gear << endl;
    }
};


class ElectricCar : public Car{ 
    private: 
    int batteryLevel;

    public: 
    ElectricCar(string b, string m) : Car(b,m){
        batteryLevel = 100; // Assume battery starts fully charged
    }

    void chargeBattery(){
        batteryLevel = 100;
        cout << brand << " " << model << " Battery fully charged." << endl;
    }
};


int main(){
    ManualCar mymanualcar("Toyota", "Corolla");
    mymanualcar.start();
    mymanualcar.accelerate();
    mymanualcar.shiftGear(1);
    mymanualcar.accelerate();
    mymanualcar.brake();
    mymanualcar.stop();

    ElectricCar myelectriccar("Tesla", "Model 3");
    myelectriccar.start();
    myelectriccar.accelerate();
    myelectriccar.chargeBattery();
    myelectriccar.stop();  
}