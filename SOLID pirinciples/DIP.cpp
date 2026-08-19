#include <iostream>
using namespace std;

// Interface Segregation Principle (ISP) states that clients should not be forced to depend on interfaces they do not use.
//abstaction (interface)
class Database { 
    public: 
     virtual void save(string data) =0; 
};

// MySQL implementation (Low-level module)
class MySQLDatabase : public Database{ 
    public: 
      void save (string data) override { 
        cout << "Saving data to MySQL Database: " << data << endl;
      }
};

// MongoDB implementation (Low-level module)
class MongoDBDatabase : public Database{ 
    public: 
      void save (string data) override { 
        cout << "Saving data to MongoDB Database: " << data << endl;
      }
};


// high level module (Application) depends on low level module (MySQLDatabase, MongoDBDatabase) through abstraction (Database interface).
class Application {
    private:
     Database* db; // Dependency injection
     public: 
     Application(Database* database) { 
        db = database;  
     }

     void storeuser(string user){
        db->save(user); 
     }
}; 

int main(){ 
    MySQLDatabase mysql;
    MongoDBDatabase mongo;

    Application app1(&mysql);
    app1.storeuser("John Doe");

    Application app2(&mongo);
    app2.storeuser("Jane Smith");
}