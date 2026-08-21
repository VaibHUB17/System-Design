#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
private:
    static Singleton *instance; // static member variable
    static mutex mtx;           // static mutex for thread safety introducing lock

    Singleton()
    {
        cout << "Singleton constructor called" << endl;
    }

public:
    static Singleton *getinstance()
    {

        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx); // lock the mutex for thread safety
            if (instance == nullptr)
            { // double-checked locking
                instance = new Singleton();
            }
        }
        return instance;
    }
};

// initialize static member variable
Singleton *Singleton::instance = nullptr;
mutex Singleton:: mtx; 
int main()
{
    Singleton *s1 = Singleton::getinstance();
    Singleton *s2 = Singleton::getinstance();

    cout << (s1 == s2) << endl;
}

// locking and unlocking is an expensive operation, so we can use double-checked locking to reduce the overhead of acquiring a lock by first checking the locking criterion without actually acquiring the lock. Only if the check indicates that locking is required does the actual lock proceed.

// why nested if??
// To make sure on the first instance creation if we have multiple thread trying to create the instance and they came to the lock thread1 will make the instance will unlock the lock and thread2 will wait for the lock to be get released and will use it, So to prevent this we use nested if to prevent the seconf thread to create the instance again.