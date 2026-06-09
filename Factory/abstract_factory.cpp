#include<iostream>

using namespace std;

class Burger{
    public:
        virtual void prepare()=0;
        virtual ~Burger() {}
};


class GarlicBread{
    public:
        virtual void prepare()=0;
        virtual ~GarlicBread() {}
};


class BasicBurger : public Burger{
    public:
        void prepare() override {
            cout << "Preparing basic burger" << endl;
        }
};

class StandardBurger : public Burger{
    public:
        void prepare() override {
            cout << "Preparing standard burger" << endl;
        }
};

class PremiumBurger : public Burger{
    public:
        void prepare() override {
            cout << "Preparing premium burger" << endl;
        }
};

class BasicWheatBurger : public Burger{
    public:
        void prepare() override {
            cout << "Preparing basic wheat burger" << endl;
        }
};

class StandardWheatBurger : public Burger{
    public:
        void prepare() override {
            cout << "Preparing standard wheat burger" << endl;
        }
};

class PremiumWheatBurger : public Burger{
    public:
        void prepare() override {
            cout << "Preparing premium wheat burger" << endl;
        }
};



class BasicGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout << "Preparing basic garlic bread" << endl;
        }
};

class StandardGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout << "Preparing standard garlic bread" << endl;
        }
};


class PremiumGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout << "Preparing premium garlic bread" << endl;
        }
};

class BasicWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout << "Preparing basic wheat garlic bread" << endl;
        }
};

class StandardWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout << "Preparing standard wheat garlic bread" << endl;
        }
};

class PremiumWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout << "Preparing premium wheat garlic bread" << endl;
        }
};


class Factory{
    public:
        virtual Burger* createBurger(string name)=0;
        virtual GarlicBread* createGarlicBread(string name)=0;
        virtual ~Factory() {}
};

class SinghsFactory : public Factory{
    public:
        Burger* createBurger(string name) override {
            if(name == "basic") return new BasicBurger();
            else if(name == "standard") return new StandardBurger();
            else if(name == "premium") return new PremiumBurger();
            else if(name == "basic wheat") return new BasicWheatBurger();
            else if(name == "standard wheat") return new StandardWheatBurger();
            else if(name == "premium wheat") return new PremiumWheatBurger();
            else return nullptr;
        }

        GarlicBread* createGarlicBread(string name) override {
            if(name == "basic") return new BasicGarlicBread();
            else if(name == "standard") return new StandardGarlicBread();
            else if(name == "premium") return new PremiumGarlicBread();
            else if(name == "basic wheat") return new BasicWheatGarlicBread();
            else if(name == "standard wheat") return new StandardWheatGarlicBread();
            else if(name == "premium wheat") return new PremiumWheatGarlicBread();
            else return nullptr;
        }
};

class KingFactory : public Factory{
    public:
        Burger* createBurger(string name) override {
            if(name == "basic") return new BasicBurger();
            else if(name == "standard") return new StandardBurger();
            else if(name == "premium") return new PremiumBurger();
            else if(name == "basic wheat") return new BasicWheatBurger();
            else if(name == "standard wheat") return new StandardWheatBurger();
            else if(name == "premium wheat") return new PremiumWheatBurger();
            else return nullptr;
        }

        GarlicBread* createGarlicBread(string name) override {
            if(name == "basic") return new BasicGarlicBread();
            else if(name == "standard") return new StandardGarlicBread();
            else if(name == "premium") return new PremiumGarlicBread();
            else if(name == "basic wheat") return new BasicWheatGarlicBread();
            else if(name == "standard wheat") return new StandardWheatGarlicBread();
            else if(name == "premium wheat") return new PremiumWheatGarlicBread();
            else return nullptr;
        }
};