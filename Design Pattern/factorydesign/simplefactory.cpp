#include <iostream>

using namespace std;

class Burger {
    public:
    virtual void prepare()=0;
    virtual ~Burger(){} 
};

class BasicBurger : public Burger { 
    public: 
    void prepare() override {
        cout << "Preparing a basic burger." << endl;
    }
};
class StandardBurger : public Burger { 
    public: 
    void prepare() override {
        cout << "Preparing a Standard burger." << endl;
    }
};
class PremiumBurger : public Burger { 
    public: 
    void prepare() override {
        cout << "Preparing a Premium burger." << endl;
    }
};


class BurgerFactory { 
    public: 
    Burger* createBurger(string& type){
        if(type =="basic"){
            return new BasicBurger(); 
        } else if(type=="standard"){
            return new StandardBurger(); 
        } else if(type=="premium"){
            return new PremiumBurger(); 
        } else {
            return nullptr; 
        }

    }
};


int main(){ 
  string type= "basic";
    BurgerFactory* myFactory = new BurgerFactory();
    Burger* myBurger = myFactory->createBurger(type);
    myBurger->prepare();
    delete myBurger;
    delete myFactory;
};

