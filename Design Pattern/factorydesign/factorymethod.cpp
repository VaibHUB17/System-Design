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

class Basicwheatburger :public Burger { 
    public: 
    void prepare() override {
        cout << "Preparing a basic wheat burger." << endl;
    }
};

class Standardwheatburger :public Burger { 
    public: 
    void prepare() override {
        cout << "Preparing a standard wheat burger." << endl;
    }
};


class Premiumwheatburger :public Burger { 
    public: 
    void prepare() override {
        cout << "Preparing a premium wheat burger." << endl;
    }
};


class BurgerFactory{ 
  public: 
    virtual Burger* createBurger(string& type)= 0;
}; 



class MCD : public BurgerFactory{ 
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
};

class BurgerKing : public BurgerFactory{ 
    public:
    Burger* createBurger(string& type) override{ 
        if(type =="basic"){
            return new Basicwheatburger(); 
        } else if(type=="standard"){
            return new Standardwheatburger(); 
        } else if(type=="premium"){
            return new Premiumwheatburger(); 
        } else {
            return nullptr; 
        }
    }
};



int main(){
   string type = "basic";
    BurgerFactory* myFactory = new BurgerKing();
    Burger* myBurger = myFactory->createBurger(type);
    myBurger->prepare();

    delete myBurger;
    delete myFactory;

} 