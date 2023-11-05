/*
Creational design pattern that let you produce families of related objects without 
    specifying their concrete classes.
*/
#include <iostream>
#include <string>

class AbstractProductA {
    public:
    virtual ~AbstractProductA() {}
    virtual std::string UsefulFunctionA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA {
    public:
    std::string UsefulFunctionA() const override {
        return "Result of product A1.";
    }
};

class ConcreteProductA2 : public AbstractProductA {
    public:
    std::string UsefulFunctionA() const override {
        return "Result of product A2.";
    }
};

class AbstractProductB {
    public:
    virtual ~AbstractProductB() {}
    virtual std::string UsefulFunctionB() const = 0;
    virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collab) const = 0;
};

class ConcreteProductB1 : public AbstractProductB {
    public:
    std::string UsefulFunctionB() const override {
        return "Result of product B1.";
    }
    std::string AnotherUsefulFunctionB(const AbstractProductA &collab) const override {
        const std::string res = collab.UsefulFunctionA();
        return "Result of B1 collab with " + res;
    }
};

class ConcreteProductB2 : public AbstractProductB {
    public:
    std::string UsefulFunctionB() const override {
        return "Result of product B2.";
    }
    std::string AnotherUsefulFunctionB(const AbstractProductA &collab) const override {
        const std::string res = collab.UsefulFunctionA();
        return "Result of B2 collab with " + res;
    }
};


class AbstractFactory {
    public:
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};

class ConcreteFactory1 : public AbstractFactory {
    public:
    AbstractProductA *CreateProductA() const override {
        return new ConcreteProductA1();
    }

    AbstractProductB *CreateProductB() const override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
    public:
    AbstractProductA *CreateProductA() const override {
        return new ConcreteProductA2();
    }

    AbstractProductB *CreateProductB() const override {
        return new ConcreteProductB2();
    }
};

void ClientCode(const AbstractFactory &factory) {
    const AbstractProductA *productA = factory.CreateProductA();
    const AbstractProductB *productB = factory.CreateProductB();

    std::cout << productB->UsefulFunctionB() << "\n";
    std::cout << productB->AnotherUsefulFunctionB(*productA);
    delete productA;
    delete productB;
}

int main() {
    std::cout << "Client: Testing client code with 1st factory\n";
    ConcreteFactory1 *f1 = new ConcreteFactory1();
    ClientCode(*f1);
    delete f1;
    std::cout << std::endl;
    std::cout << "Client: Testing client code with 2nd factory\n";
    ConcreteFactory2 *f2 = new ConcreteFactory2();
    ClientCode(*f2);
    delete f2;
    std::cout << std::endl;
}