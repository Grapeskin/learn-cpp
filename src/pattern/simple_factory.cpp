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
class Factory {
   public:
    Factory() {}
    ~Factory() {}
    static BaseVersion* createVersion(Version v) {
        switch (v) {
            case Version::V1:
                return new V1();
            case Version::V2:
                return new V2();
            default:
                return nullptr;
                break;
        }
    }
};
int main(int argc, char const* argv[]) {
    std::cout << "******* simple factory *******" << std::endl;
    BaseVersion* v1 = Factory::createVersion(Version::V1);
    std::cout << v1->version << std::endl;
    delete v1;

    BaseVersion* v2 = Factory::createVersion(Version::V2);
    std::cout << v2->version << std::endl;
    delete v2;
    return 0;
}
