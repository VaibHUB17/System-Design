#include <iostream>
#include <string>

using namespace std;


class Car{
    //encapsulation: data members are private and accessed through public methods
    protected: 
    string brand;
    string model;
    bool isengineon;
    int speed;
    
    public:
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        this->isengineon = false;
        this->speed = 0;
    }

    void start(){
        isengineon = true;
        cout << brand << " " << model << " Engine started" << endl;
    }

    void stop(){
        isengineon = false;
        speed = 0;
        cout << brand << " " << model << " Engine stopped" << endl;
    }

    //abstraction: pure virtual functions to define an interface for derived classes
    virtual void accelerate() = 0; // Pure virtual function
    virtual void accelerate(int speedIncrease) = 0; // Overloaded pure virtual function
    virtual void brake() = 0;      // Pure virtual function
    virtual void brake(int speedDecrease) = 0; // Overloaded pure virtual function
    virtual ~Car() {} // Virtual destructor to ensure proper cleanup of derived class objects

};

//inheritance: ManualCar and ElectricCar inherit from Car
class ManualCar : public Car{
    private:
    int currentgear;
    public:
    ManualCar(string b,string m) : Car(b,m){
        this->currentgear=0; // Start with full battery
       
    }

    void shiftGear(int gear){
        currentgear = gear;
        cout << brand << " " << model << " shifted to gear " << gear << endl;
    }

    //polymorphism: overriding the accelerate and brake methods in derived classes
    void accelerate(){
        if(isengineon){
             speed += 30;
            cout << brand << " " << model << " accelerated to " << speed << " km/h  " << endl;
        } else {
            cout << brand << " " << model << " Engine is off. Please start the engine first." << endl;
        }
    }

    void accelerate(int speedIncrease){
        if(isengineon){
             speed += speedIncrease;
            cout << brand << " " << model << " accelerated to " << speed << " km/h  " << endl;
        } else {
            cout << brand << " " << model << " Engine is off. Please start the engine first." << endl;
        }
    }  
    
    void brake(){
        if(speed > 0){
             speed -= 30;
            cout << brand << " " << model << " decelerated to " << speed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }

    void brake(int speedDecrease){
        if(speed > 0){
             speed -= speedDecrease;
            cout << brand << " " << model << " decelerated to " << speed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }
};

class ElectricCar : public Car{
    private: 
    int batteryLevel;
    
    public: 

    ElectricCar(string b,string m) : Car(b,m){
       this->batteryLevel = 100; // Start with full battery
    }

    //polymorphism: overriding the accelerate and brake methods in derived classes
    void accelerate(){
        if(isengineon){
             speed += 20;
            cout << brand << " " << model << " accelerated to " << speed << " km/h  " << endl;
        } else {
            cout << brand << " " << model << " Engine is off. Please start the engine first." << endl;
        }
    }
    void accelerate(int speedIncrease){
        if(isengineon){
             speed += speedIncrease;
            cout << brand << " " << model << " accelerated to " << speed << " km/h  " << endl;
        } else {
            cout << brand << " " << model << " Engine is off. Please start the engine first." << endl;
        }
    }

    void brake(){
        if(speed > 0){
             speed -= 20;
            cout << brand << " " << model << " decelerated to " << speed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }

    void brake(int speedDecrease){
        if(speed > 0){
             speed -= speedDecrease;
            cout << brand << " " << model << " decelerated to " << speed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }
    
};

int main(){

    Car* myManualCar= new ManualCar("ferrari", "488");
    myManualCar->start();
    myManualCar->accelerate();
    myManualCar->accelerate(20);
    myManualCar->brake();
    myManualCar->brake(15);
    myManualCar->stop();

    Car* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->start();
    myElectricCar->accelerate();
    myElectricCar->accelerate(30);
    myElectricCar->brake();
    myElectricCar->brake(25);
    myElectricCar->stop();


    delete myManualCar;
    delete myElectricCar;

    return 0;

}


//abstraction: defining an interface for a sports car with specific behaviors
//encapsulation: data members are private and accessed through public methods
//inheritance: SportsCar inherits from Car
//polymorphism: overriding the accelerate and brake methods in SportsCar
//static polymorphism: overloading the accelerate and brake methods in SportsCar
//dynamic polymorphism: using base class pointers to call derived class methods