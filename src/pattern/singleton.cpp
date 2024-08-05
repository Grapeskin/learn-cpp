#include <iostream>

class singleton {
   private:
    singleton() {};
    singleton(const singleton&) = delete;
    singleton& operator=(const singleton&) = delete;

   public:
    ~singleton() {};
    static singleton& get_instance() {
        static singleton instance;
        return instance;
    }

    void do_something() { std::cout << "do something" << std::endl; };
};

int main(int argc, char const* argv[]) {
    printf("%x\n", singleton::get_instance());
    printf("%x\n", singleton::get_instance());
    return 0;
}
