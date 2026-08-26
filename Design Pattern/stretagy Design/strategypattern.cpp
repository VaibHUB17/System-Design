#include <iostream>
using namespace std;

// --- Strategy Interface for Walk ---
class WalkableRobot{
    public: 
    virtual void walk() = 0; 
    virtual ~WalkableRobot(){} 
};

//concrete strategy for walk
class NormalWalk : public WalkableRobot{
    public:
    void walk() override{
        cout << "Walking normally." << endl;
    }
};
class Nowalk : public WalkableRobot{
    public:
    void walk() override{
        cout << "Cannot walk." << endl;
    }
};

// --- Strategy Interface for Talk ---
class TalkableRobot{
  public: 
  virtual void talk() =0;
  virtual ~TalkableRobot(){}

};
//concrete strategy for talk
class NormalTalk : public TalkableRobot{
    public:
    void talk() override{
        cout << "Talking normally." << endl;
    }
};
class Notalk : public TalkableRobot{
    public:
    void talk() override{
        cout << "Cannot talk." << endl;
    }
};

// --- Strategy Interface for Fly ---
class FlyableRobot{
 public:
 virtual void fly() =0;
 virtual ~FlyableRobot(){}
};

//concrete strategy for fly
class NormalFly : public FlyableRobot{
    public:
    void fly() override{
        cout << "Flying normally." << endl;
    }
};
class NoFly : public FlyableRobot{
    public:
    void fly() override{
        cout << "Cannot fly." << endl;
    }
};

//robot interface
class Robot{
    protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;

    public: 
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) { 
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }
    void walk(){
        walkBehavior->walk();
    }
    void talk(){
        talkBehavior->talk();
    }
    void fly(){
        flyBehavior->fly();
    }

    virtual void projection()=0; //abstract method for robot projection
};

//concrete robot classes
class CompanionRobot : public Robot{
    public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w,t,f){}

    void projection() override{
        cout << "I am a companion robot." << endl;
    }
};
class WorkerRobot : public Robot{
    public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w,t,f){}
    void projection() override{
        cout << "I am a worker robot." << endl;
    }

};

int main(){
    Robot* robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->projection();
    robot1->walk();
    robot1->talk();
    robot1->fly();

    cout<< "---" << endl;


    Robot* robot2 = new WorkerRobot(new Nowalk(), new Notalk(), new NormalFly());
    robot2->projection();
    robot2->walk();
    robot2->talk();
    robot2->fly();

    return 0;

}