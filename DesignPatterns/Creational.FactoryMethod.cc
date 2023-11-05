/*
Factory Method is creational design pattern that provides an interface for creating objects
in a superclass but allows subclasses to alter type of object that will be created.
*/

#include <iostream>
#include <string>

class Product {
    public:
    virtual ~Product() {}
    virtual std::string Operation() const = 0;
};


class ConcreteProduct1: public Product {
    public:
    std::string Operation() const override {
        return "Result of the ConcreteProduct1";
    }
};

class ConcreteProduct2 : public Product {
    public:
    std::string Operation() const override {
        return "Result of the ConcreteProduct2";
    }
};

class Creator {
    public:
    virtual ~Creator() {};
    virtual Product* FactoryMethod() const = 0;

    std::string SomeOperation() const {
        Product* product = this->FactoryMethod();
        std::string res = "Creator: worked with " + product->Operation();
        delete product;
        return res;
    }
};

class ConcreteCreator1 : public Creator {
    public:
    Product* FactoryMethod() const override {return new ConcreteProduct1();}
};

class ConcreteCreator2 : public Creator {
    public:
    Product* FactoryMethod() const override {return new ConcreteProduct2();}
};

void ClientCode(const Creator& creator) {
    std::cout << "Client -- calling creator operation : " << creator.SomeOperation() 
        << std::endl;
}

int main() {

    std::cout << "App launched\n";
    Creator* creator1 = new ConcreteCreator1();
    ClientCode(*creator1);
    std::cout << std::endl;
    Creator* creator2 = new ConcreteCreator2();
    ClientCode(*creator2);

    delete creator1;
    delete creator2;

    return 0;
}