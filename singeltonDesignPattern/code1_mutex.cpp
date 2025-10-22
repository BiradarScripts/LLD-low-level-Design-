#include<iostream>
using namespace std;

//not thread safe
class Singleton{
    private:
    static Singleton*instancePointer;
    static mutex mtx;
    Singleton(){
        cout<<"hi i am constructor"<<endl;
    }
    public:
    static Singleton* getSingleton(){
        //critical section
        if(instancePointer==nullptr){
            //lock for thread safety
            lock_guard<mutex>lock(mtx);
            if(instancePointer==nullptr){
                instancePointer=new  Singleton();
            }
        }
        return instancePointer;
    }
};

//always need to initialize static variables
Singleton*Singleton::instancePointer=nullptr;
mutex Singleton::mtx;
int main(){
    Singleton *s1=Singleton :: getSingleton();
    Singleton *s2=Singleton :: getSingleton();

    cout<< (s1==s2);
}