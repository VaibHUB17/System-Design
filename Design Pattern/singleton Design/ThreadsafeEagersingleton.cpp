#include  <iostream>
using namespace std;

class Singleton{ 
    private: 
       static Singleton* instance; 

       Singleton(){ 
           cout << "Singleton constructor called" << endl;
       }

   public: 
     static Singleton* getinstance(){ 
         return instance;
     }    
};

// initialize static member variable
Singleton* Singleton:: instance = new Singleton();

int main(){ 
    Singleton* s1 = Singleton:: getinstance();
    Singleton* s2 = Singleton:: getinstance();

    cout << (s1 == s2) << endl; // true
}

//eager initialization is a thread-safe way of creating a singleton instance. In this approach, the singleton instance is created at the time of class loading, which ensures that only one instance of the class is created and shared across all threads. This approach is simple and efficient, but it may lead to unnecessary resource usage if the singleton instance is not used frequently.

