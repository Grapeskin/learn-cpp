#include <iostream>

class Singleton {
   private:
    Singleton() {};
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

   public:
    ~Singleton() {};
    static Singleton& get_instance() {
        static Singleton instance;
        return instance;
    }

    void do_something() { std::cout << "do something" << std::endl; };
};

int main(int argc, char const* argv[]) {
    Singleton& s = Singleton::get_instance();
    printf("s=%p\n", &s);
    Singleton& s1 = Singleton::get_instance();
    printf("s1=%p\n", &s1);
    return 0;
}
