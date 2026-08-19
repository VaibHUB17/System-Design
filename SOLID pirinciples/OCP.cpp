#include <iostream>
#include <vector>

using namespace std;

// Product class representing any item of any ECommerce.
class Product
{
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

// Adhering to SRP: Each class has a single responsibility
// 1. ShoppingCart is responsible for managing products in the cart
class ShoppingCart{
private:
    vector<Product *> products;   // List of products in the cart

public:
    void addProduct(Product *p){     // Method to add a product to the cart
        products.push_back(p);
    }

    const vector<Product *> &getProducts(){  // Return a const reference to the products vector to prevent modification from outside
        return products;
    }

    double calculateTotal(){
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }
};

// 2. InvoicePrinter is responsible for printing invoices
class InvoicePrinter
{
private:
    ShoppingCart *cart;    // Dependency on ShoppingCart to access products and calculate total

public:
    InvoicePrinter(ShoppingCart *cart){       // dependency injection of ShoppingCart into InvoicePrinter
        this->cart = cart;
    }

    void printInvoice(){
        cout << "Shopping Cart Invoice: \n";

        for(auto p : cart->getProducts()){
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << cart->calculateTotal() << endl;
    }
};

class Persistance{ 
    private: 
      ShoppingCart *cart;

      public: 
        virtual void saveToDatabase() = 0; // Pure virtual function to enforce implementation in derived classes
};

class SQLPersistance : public Persistance{
    public: 
      void saveToDatabase() override {  
        cout<<"Saving shopping cart to SQL database..."<<endl;
      }
};
class MongoDBPersistance : public Persistance{
    public: 
      void saveToDatabase() override {  
        cout<<"Saving shopping cart to MOngoDB database..."<<endl;
      }
};
class FilePersistance : public Persistance{
    public: 
      void saveToDatabase() override {  
        cout<<"Saving shopping cart to a file..."<<endl;
      }
};

int main(){

    ShoppingCart *cart= new ShoppingCart();
    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    InvoicePrinter *printer = new InvoicePrinter(cart);
    printer->printInvoice();
    
    Persistance *db = new SQLPersistance();
    Persistance *mongo = new MongoDBPersistance();
    Persistance *file = new FilePersistance();
    
    db->saveToDatabase();
    mongo->saveToDatabase();
    file->saveToDatabase();
}