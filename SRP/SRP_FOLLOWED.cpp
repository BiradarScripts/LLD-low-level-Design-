#include<iostream>

using namespace std;


class Product{
public:
    string name;
    int price;

    Product(string name, int price){
        this->name = name;
        this->price = price;
    }
};

//only has one responsibility which is to manage the shopping cart
class ShoppingCart{
private:
    vector<Product*> products;
public:
    void addProduct(Product *p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return this->products;
    }

    double calculateTotal(){
        double total;
        for(auto it:products){
            total += it->price;
        }
        return total;
    }
};


class cartInVoicePrint{
    ShoppingCart *cart;
public:
    cartInVoicePrint(ShoppingCart *cart){
        this->cart = cart;
    }
    void printInvoice(ShoppingCart *cart){
        cout<<"Invoice: "<<endl;
        for(auto it:cart->getProducts()){
            cout<<it->name<<" - "<<it->price<<endl;
        }
        cout<<"Total: "<<cart->calculateTotal()<<endl;
    }

};


class CartDbStorage{
    ShoppingCart *cart;
    public:
    CartDbStorage(ShoppingCart *cart){
        this->cart = cart;
    }
    void saveToDb(ShoppingCart *cart){
        // code to save the shopping cart to the database
        cout<<"Saving shopping cart to the database..."<<endl;
        return ;
    }
};

