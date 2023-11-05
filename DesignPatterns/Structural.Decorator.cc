/*
Suppose you have Notifier class -- if you wantto have notifier of different types 
fr example -- we can have sms, fb, slack etc. 
One way to go about is to extend Notifier class. But if someone want more than 
    1 notification and then we try creating subclass that combines sevaral notification
    methods in 1 class. This quickly becomes bloat, not just our library code but 
    also client code.

    Solution:
        Extending class is 1st solution that comes to our mind. But it has sevaral 
        caveats. 
        -> Interitance is static.
        -> SubClasses can have just one parent class.

        Another way --> Using aggregation or composition. 
*/
#include <iostream>
#include <string>


class Component {
    public:
    virtual ~Component() {}
    virtual std::string Operation() const = 0;
};

class ConcreteComponent : public Component {
    public:
    std::string Operation() const override {
        return "ConcreteComponent";
    }
};

class Decorator : public Component {
    protected:
    Component* component_;

    public:
    Decorator(Component *component) : component_(component) {}

    std::string Operation() const override {
        return this->component_->Operation();
    }
};

class ConcreteDecoratorA : public Decorator {
    public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}
    std::string Operation() const override {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator {
    public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}
    std::string Operation() const override {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
    }
};

void ClientCode(Component *component) {
    std::cout << "Result: " << component->Operation();
}

int main() {
    Component *simple = new ConcreteComponent();
    std::cout << "Client: Got simple component:\n";
    ClientCode(simple);
    std::cout << "\n\n";
    Component *decorator1 = new ConcreteDecoratorA(simple);
    Component *decorator2 = new ConcreteDecoratorB(decorator1);
    std::cout << "Client: Got decorated component:\n";
    ClientCode(decorator2);
    std::cout << "\n";

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0; 
}