#include <iostream>
#include <string>

using namespace std; 

//Real life Car;
 
// virtual function is a function that is declared in the base class and is overridden in the derived class.
class Car {
   public:
    virtual void start() = 0;
    virtual void accelerate() = 0; 
    virtual void brake()=0;
    virtual void shiftGear(int gear) = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {} // Virtual destructor to ensure proper cleanup of derived class objects
};

class SportsCar : public Car {
    public: 
    string brand;
    string model;
    bool isengineon;
    int speed;
    int currentgear;
    
    SportsCar(string b, string m){
        this->brand =b;
        this->model = m;
        isengineon = false;
        speed = 0;
        currentgear = 0;
    }

    void start(){
        isengineon = true;
        cout << brand << " " << model << " Engine started" << endl;
    }

    void shiftGear(int gear){
        currentgear = gear; 
        cout << brand << " " << model << " shifted to gear " << gear << endl;
    }

    void accelerate(){
        if(isengineon){
            speed += 10;
            cout << brand << " " << model << " accelerated to " << speed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " Engine is off. Please start the engine first." << endl;
        }
    }

    void brake() { 
        if(isengineon && speed > 0){
            speed -= 10;
            cout << brand << " " << model << " decelerated to " << speed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " is already stopped or engine is off." << endl;
        }
    }

    void stopEngine(){
        isengineon = false;
        speed = 0;
        currentgear = 0;
        cout << brand << " " << model << " Engine stopped and car is now stationary." << endl;
    }
};

int main(){
    Car* myCar = new SportsCar("Ferrari", "488 Spider");
    myCar->start();
    myCar->shiftGear(1);    
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
    delete myCar; 

    return 0;
}