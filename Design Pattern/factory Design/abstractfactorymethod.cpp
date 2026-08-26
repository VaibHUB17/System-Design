#include <iostream> 
using namespace std;

//---product->1----
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


class BasicWheatburger :public Burger { 
    public: 
    void prepare() override {
        cout << "Preparing a basic wheat burger." << endl;
    }
};

class StandardWheatburger :public Burger { 
    public: 
    void prepare() override {
        cout << "Preparing a standard wheat burger." << endl;
    }
};

class PremiumWheatburger :public Burger { 
    public: 
    void prepare() override {
        cout << "Preparing a premium wheat burger." << endl;
    }
};


// ---product->2---

class GarlicBread{
    public: 
    virtual void prepare()=0;
    virtual ~GarlicBread(){}

};

class BasicGarlicBread : public GarlicBread{ 
    public: 
    void prepare() override {
        cout << "Preparing a basic garlic bread." << endl;
    }
};

class CheeseGarlicBread : public GarlicBread{ 
    public: 
    void prepare() override {
        cout << "Preparing a cheese garlic bread." << endl;
    }
};

class  BasicwheatGarlicBread : public GarlicBread{ 
    public: 
    void prepare() override {
        cout << "Preparing a basic wheat garlic bread." << endl;
    }
};

class CheeseWheatGarlicBread : public GarlicBread{ 
    public: 
    void prepare() override {
        cout << "Preparing a cheese wheat garlic bread." << endl;
    }
};


class MealFactory{
    public: 
    virtual Burger* createBurger(string& type)=0;
    virtual GarlicBread* createGarlicBread(string& type)=0;
};

class MCD : public MealFactory{ 
    public: 
    Burger* createBurger(string& type) override{
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

    GarlicBread* createGarlicBread(string& type) override{
        if(type =="basic"){
            return new BasicGarlicBread();
        } else if(type=="cheese"){
            return new CheeseGarlicBread();
        } else {
            return nullptr;     
        }
    }
};

class BurgerKing : public MealFactory{ 
    public: 
    Burger* createBurger(string& type) override{
         if(type =="basic"){
            return new BasicWheatburger();
        } else if(type=="standard"){
            return new StandardWheatburger();
        } else if(type=="premium"){
            return new PremiumWheatburger();
        } else {
            return nullptr;     
        }
    }

    GarlicBread* createGarlicBread(string& type) override{
        if(type =="basic"){
            return new BasicGarlicBread();
        } else if(type=="cheese"){
            return new CheeseGarlicBread();
        } else {
            return nullptr;     
        }
    }
};





int main(){ 
  string burgerType = "basic";
  string garlicBreadType = "cheese"; 

  MealFactory* myFactory = new MCD();
  MealFactory* myFactory2 = new BurgerKing();
  Burger* myburger = myFactory->createBurger(burgerType);
  Burger* myburger2 = myFactory2->createBurger(burgerType);
  GarlicBread* mygarlicbread = myFactory->createGarlicBread(garlicBreadType);

   myburger->prepare();
   myburger2->prepare();
   mygarlicbread->prepare();

}

