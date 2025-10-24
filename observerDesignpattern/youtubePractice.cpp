#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class ISubscribe{
    public:
    virtual void update()=0;
};

class IChannel{
    public:
    virtual void subscribe(ISubscribe*s)=0;
    virtual void unsubscribe(ISubscribe*s)=0;
    virtual void notify()=0;
};

class Channel:public IChannel{
    private:
    string name;
    string latestVideo;
    vector<ISubscribe*>subsribers;
    public:
    void subscribe(ISubscribe*s) override{
        auto it=find(subsribers.begin(),subsribers.end(),s);
        if(it==subsribers.end()){
            subsribers.push_back(s);
        }
    }
    void unsubscribe(ISubscribe*s) override{
        auto it=find(subsribers.begin(),subsribers.end(),s);
        if(it==subsribers.end()){
            subsribers.erase(it);
        }
    }
    void notifySubscribers(){
        for(ISubscribe*s:subsribers){
            s->update();
        }
    }
    void upoloadVideo(const string &title){
        latestVideo = title;
        cout << "\n[" << name << " uploaded \"" << title << "\"]\n";
        notifySubscribers();
    }
    string getVideData(){
        return "\nCheckout our new Video : " + latestVideo + "\n";
    }
};

class subscribe:public ISubscribe{
    private:
    string name;
    Channel*channel;
    public:
    subscribe(string&name,Channel*channel){
        this->name=name;
        this->channel=channel;
    }
    void update() override{
        cout << "Hey " << name << "," << this->channel->getVideoData();
    }
};

int main(){

}