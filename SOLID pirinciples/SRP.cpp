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

// 3. CartStorage is responsible for saving the cart to a database
class CartStorage{
    private: 
     ShoppingCart* cart;
    
    public: 
        CartStorage(ShoppingCart* cart){          //dependency injection of ShoppingCart into CartStorage
        this->cart=cart;
      }

      void saveToDataBase(){
        cout<<"Saving shopping cart to database..."<<endl;
      }
     
};

int main(){  
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    InvoicePrinter *printer = new InvoicePrinter(cart);
    printer->printInvoice();

    CartStorage *storage = new CartStorage(cart);
    storage->saveToDataBase();

    return 0;
}