#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

class Singleton {
    private:
    static Singleton *instance_;
    static std::mutex mutex_;

    protected:
    Singleton(const std::string val): val_(val) {}
    ~Singleton() {}
    std::string val_;

    public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;
    static Singleton *GetInstance(const std::string &val);
    void SomeBusinessLogic() {}

    std::string value() const {return val_;}
};

Singleton *Singleton::instance_ {nullptr};
std::mutex Singleton::mutex_;

Singleton *Singleton::GetInstance(const std::string &val) {
    std::lock_guard<std::mutex> lock(mutex_);
    if(instance_ == nullptr) {
        instance_ = new Singleton(val);
    }
    return instance_;
}

void ThreadFoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}

int main() {
    std::cout << "Result:\n";
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);

    t1.join();
    t2.join();

    return 0;
}
