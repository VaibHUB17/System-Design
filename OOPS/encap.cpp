#include <iostream>
#include <string>

using namespace std;

class SportsCar {
 private:
    string brand;
    string model;
    bool isengineon;
    int speed;
    int currentgear;

    //Introduce new variable to explain setters and getters
    string tyre;

    public:

    SportsCar(string b, string m){
        this->brand =b;
        this->model=m;
        isengineon = false;
        speed = 0;
        currentgear = 0;
        tyre = "All-season";
    }
    // getter and setter for the new variable tyre
    int getSpeed(){
        return speed;
    }

    string getTyre(){
        return tyre;
    }

    void setTyre(string tyre){
        // can add validation here if needed, for example, to check if the tyre type is valid
        this->tyre = tyre;
    }

    //behavior of the car --> methods
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

    void brake(){
        if(isengineon){
            speed -= 10;
            cout << brand << " " << model << " brake applied. Speed reduced to " << speed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " Engine is off. Please start the engine first." << endl;
        }
    }

    void stopEngine(){
        isengineon = false;
        cout << brand << " " << model << " Engine stopped" << endl;
    }

};


int main(){
    SportsCar* mycar= new SportsCar("Ferrari", "488 Spider");
    mycar->start();
    mycar->shiftGear(1);
    mycar->accelerate();
    mycar->shiftGear(2);
    mycar->accelerate();
    mycar->accelerate();
    mycar->accelerate();
    mycar->accelerate();
    mycar->accelerate();
    cout << "Current speed: " << mycar->getSpeed() << " km/h" << endl;
    mycar->brake();
    mycar->brake();
    mycar->brake();
    mycar->brake();
    mycar->brake();
    mycar->brake();
    mycar->stopEngine();
    mycar->setTyre("Performance");
    cout << "Current tyre type: " << mycar->getTyre() << endl;
}