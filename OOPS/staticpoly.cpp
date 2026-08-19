#include <iostream>
#include <string>

using namespace std;

class ManualCar
{
private:
    string brand;
    string model;
    bool isengineon;
    int speed;

public:
    ManualCar(string b, string m)
    {
        this->brand = b;
        this->model = m;
        this->isengineon = false;
        this->speed = 0;
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

    void accelerate()
    {
        if (isengineon)
        {   speed+=10;
            cout << brand << " " << model << " accelerated to " << speed << " km/h  " << endl;
        }
        else
        {
            cout << brand << " " << model << " Engine is off. Please start the engine first." << endl;
        }
    }

    void accelerate(int speedIncrease)
    {
        if (isengineon)
        {
            speed += speedIncrease;
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

    void brake(int speedDecrease)
    {
        if (speed > 0)
        {
            speed -= speedDecrease;
            cout << brand << " " << model << " decelerated to " << speed << " km/h" << endl;
        }
        else
        {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }

};    
    int main()
    {
        ManualCar* mymanualcar = new ManualCar("toyota", "corolla");
        mymanualcar->start();
        mymanualcar->accelerate();
        mymanualcar->accelerate(20);
        mymanualcar->brake();
        mymanualcar->brake(15);
        mymanualcar->stop();
        delete mymanualcar;
    }