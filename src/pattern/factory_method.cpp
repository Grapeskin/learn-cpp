#include <iostream>
enum class Version { V1, V2 };

class BaseVersion {
   public:
    BaseVersion(std::string v) : version(v) {}
    std::string version;
};

class V1 : public BaseVersion {
   public:
    V1() : BaseVersion("v1") {}
};

class V2 : public BaseVersion {
   public:
    V2() : BaseVersion("v2") {}
};
class BaseFactory {
   public:
    virtual ~BaseFactory() {};
    virtual BaseVersion* createVersion() = 0;
};

class V1Factory : public BaseFactory {
   public:
    BaseVersion* createVersion() { return new V1(); }
};
class V2Factory : public BaseFactory {
   public:
    BaseVersion* createVersion() { return new V2(); }
};

int main(int argc, char const* argv[]) {
    std::cout << "******* factory method *******" << std::endl;
    BaseFactory* v1_factory = new V1Factory();
    BaseVersion* v1 = v1_factory->createVersion();
    std::cout << v1->version << std::endl;
    delete v1;
    delete v1_factory;

    BaseFactory* v2_factory = new V2Factory();
    BaseVersion* v2 = v2_factory->createVersion();
    std::cout << v2->version << std::endl;
    delete v2;
    delete v2_factory;
    return 0;
}
