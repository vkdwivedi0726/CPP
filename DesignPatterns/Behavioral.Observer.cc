#include <iostream>
#include <list>
#include <string>

class IObserver {
    public:
    virtual ~IObserver() {}
    virtual void Update(const std::string &msg_from_subject) = 0;
};

class ISubject {
    public:
    virtual ~ISubject() {}
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

class Subject : public ISubject {
    public:
    virtual ~Subject() {std::cout << "Bye!\n";}
    
    void Attach(IObserver *observer) override {
        list_observer_.push_back(observer);
    }

    void Detach(IObserver *observer) override {
        list_observer_.remove(observer);
    }

    void Notify() override {
        std::list<IObserver *>::iterator iter = list_observer_.begin();
        HowManyObserver();
        while(iter != list_observer_.end()) {
            (*iter)->Update(message_);
            ++iter;
        }
    }

    void CreateMessage(std::string message = "empty") {
        this->message_ = message;
        Notify();
    }

    void HowManyObserver() {
        std::cout << "There are " << list_observer_.size() << " observer\n";
    }

    void SomeBusinessLogic() {
        this->message_ = "change message message";
        Notify();
        std::cout << "About to something imp!\n";
    }

    private:
    std::list<IObserver *> list_observer_;
    std::string message_;
};


class Observer : public IObserver {
    public:
    Observer(Subject &sub) : sub_(sub) {
        this->sub_.Attach(this);
        std::cout << "Observer no. " << ++Observer::static_number_ << ".\n";
        this->num_ = static_number_;
    }

    virtual ~Observer() {
        std::cout << "Bye! O! " << this->num_ << ".\n";
    }

    void Update(const std::string &msg_from_sub) override {
        msg_from_sub_ = msg_from_sub;
        PrintInfo();
    }

    void RemoveFromList() {
        sub_.Detach(this);
        std::cout << "Observer: " << num_ << " removed !\n"; 
    }

    void PrintInfo() {
        std::cout << "Observer: " << this->num_ << " a new msg: " 
            << this->msg_from_sub_ << std::endl;
    }

    private:
    std::string msg_from_sub_;
    Subject &sub_;
    static int static_number_;
    int num_;
};

int Observer::static_number_ = 0;

void ClientCode() {
    Subject *sub = new Subject();
    Observer *o1 = new Observer(*sub);
    Observer *o2 = new Observer(*sub);
    Observer *o3 = new Observer(*sub);
    Observer *o4;
    Observer *o5;

    sub->CreateMessage("Hi");
    o3->RemoveFromList();

    sub->CreateMessage("Weather is nice!");
    o4 = new Observer(*sub);

    o2->RemoveFromList();
    o5 = new Observer(*sub);

    o4->RemoveFromList();
    o1->RemoveFromList();

    delete o5;
    delete o4;
    delete o3;
    delete o2;
    delete o1;
    delete sub;
}

int main() {
    ClientCode();
    return 0;
}