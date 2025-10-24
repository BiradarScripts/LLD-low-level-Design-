#include<iostream>
#include<string>

using namespace std;

class ICharacter{
    public:
    virtual string getAbilities()=0;
};

class Mario:public ICharacter{
    public:
    string getAbilities() override{
        return "Mario";
    }
};

class CharacterDecorator:public ICharacter{
    protected:
    ICharacter*character;
    public:
    CharacterDecorator(ICharacter*c){
        this->character=c;
    }
};

class HeightUp:public CharacterDecorator{
    public:
    HeightUp(ICharacter*c):CharacterDecorator(c){}

    string getAbilities() override{
        return character->getAbilities()+"with HeightUp";
    }
};
class GunPowerUp:public CharacterDecorator{ 
    public:
    GunPowerUp(ICharacter*c):CharacterDecorator(c){}

    string getAbilities() override{
        return character->getAbilities()+"with GunPowerUp";
    }
};

class StarPowerUp:public CharacterDecorator{ 
    public:
    StarPowerUp(ICharacter*c):CharacterDecorator(c){}

    string getAbilities() override{
        return character->getAbilities()+"with HeightUp";
    }
};


int main(){
    ICharacter*mario=new Mario();
    cout << "Basic Character: " << mario->getAbilities() << endl;

    // mario=new HeightUp(mario);
    // cout << "After HeightUp: " << mario->getAbilities() << endl;

    mario=new HeightUp(new GunPowerUp(new StarPowerUp(mario)));
    cout<<"after every wrap"<<mario->getAbilities()<<endl;
}