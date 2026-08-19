#include <iostream>

using namespace std;


class Shape2D { 
    public: 
      virtual double area()= 0;
};
class Shape3D { 
    public: 
      virtual double area()= 0;
      virtual double volume()= 0;
};

class Circle : public Shape2D { 
    private: 
     double radius;
    public: 
      Circle(double r) : radius(r) {}
      double area() override { 
        return 3.14 * radius * radius;
      }
};

class Rectangle : public Shape2D{
    private:
        double length, width;
    public:
     Rectangle(double l, double w) : length(l),width(w) {}
        double area() override { 
            return length * width;
        }
     
};

class Cube: public Shape3D{
    private:
        double side;
    public: 
        Cube(double s) : side(s) {}
        double area() override { 
            return 6 * side * side;
        }
        double volume() override { 
            return side * side * side;
        }
};

int main(){
    Shape2D* circle = new Circle(5);
    cout << "Area of Circle: " << circle->area() << endl;
    Shape2D* rectangle = new Rectangle(4, 6);
    cout << "Area of Rectangle: " << rectangle->area() << endl;
    Shape3D* cube = new Cube(3);
    cout << "Area of Cube: " << cube->area() << endl;
    cout << "Volume of Cube: " << cube->volume() << endl;
    return 0;
}