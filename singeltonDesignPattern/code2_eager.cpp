#include<iostream>

using namespace std;

class SingleTon{
    private:
    static SingleTon*instancePointer;
    SingleTon(){
        cout<<"hi i am constructor"<<endl;
    }
    public:
    static SingleTon* getInstance(){
        return instancePointer;
    }

};

SingleTon* SingleTon :: instancePointer=new SingleTon();

int main(){
    SingleTon*s1=SingleTon :: getInstance();
    SingleTon*s2=SingleTon :: getInstance();

    cout<<(s1==s2)<<endl;
}

//here this method of allocation is not good because, what if the Singleton class is to obig and if we are not using it during th eexecution
//then it is of no use of allocating it.