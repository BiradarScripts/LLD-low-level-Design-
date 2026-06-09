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


    void printInvoice(){
        cout<<"Invoice: "<<endl;
        for(auto it:products){
            cout<<it->name<<" - "<<it->price<<endl;
        }
        cout<<"Total: "<<calculateTotal()<<endl;
    }

    void saveToDb(){
        // code to save the shopping cart to the database
        cout<<"Saving shopping cart to the database..."<<endl;
        return ;
    }
};


int main(){
    Product *p1=new Product("Laptop", 1000);
    Product *p2=new Product("Phone", 500);

    ShoppingCart cart;
    cart.addProduct(p1);
    cart.addProduct(p2);
    cart.calculateTotal();
    
    cart.printInvoice();

    return 0;

}