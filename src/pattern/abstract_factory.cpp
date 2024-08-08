#include <iostream>
#include <memory>
enum class Version { V1, V2 };

// product A
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

// product B
class BaseType {
   public:
    BaseType(std::string v) : type(v) {}
    std::string type;
};

class TypeA : public BaseType {
   public:
    TypeA() : BaseType("type A") {}
};

class TypeB : public BaseType {
   public:
    TypeB() : BaseType("type B") {}
};

// factory A
class VersionFactory {
   public:
    virtual ~VersionFactory() {};
    virtual std::unique_ptr<BaseVersion> createVersion() = 0;
};

class V1Factory : public VersionFactory {
   public:
    std::unique_ptr<BaseVersion> createVersion() {
        return std::unique_ptr<BaseVersion>(new V1());
    }
};
class V2Factory : public VersionFactory {
   public:
    std::unique_ptr<BaseVersion> createVersion() {
        return std::unique_ptr<BaseVersion>(new V2());
    }
};

// factory B
class TypeFactory {
   public:
    virtual ~TypeFactory() {};
    virtual std::unique_ptr<BaseType> createType() = 0;
};

class TypeAFactory : public TypeFactory {
   public:
    std::unique_ptr<BaseType> createType() {
        return std::unique_ptr<BaseType>(new TypeA());
    }
};
class TypeBFactory : public TypeFactory {
   public:
    std::unique_ptr<BaseType> createType() {
        return std::unique_ptr<BaseType>(new TypeB());
    }
};

// abstract factory
class AbstractFactory {
   public:
    virtual ~AbstractFactory() {}
    virtual std::unique_ptr<BaseVersion> createVersion() = 0;
    virtual std::unique_ptr<BaseType> createType() = 0;
};

// concrete factory
class ProductAFactory : public AbstractFactory {
   public:
    std::unique_ptr<BaseVersion> createVersion() override {
        auto v = std::unique_ptr<VersionFactory>(new V1Factory());
        return v->createVersion();
    }
    std::unique_ptr<BaseType> createType() override {
        auto v = std::unique_ptr<TypeFactory>(new TypeAFactory());
        return v->createType();
    }
};

class ProductBFactory : public AbstractFactory {
   public:
    std::unique_ptr<BaseVersion> createVersion() override {
        auto v = std::unique_ptr<VersionFactory>(new V2Factory());
        return v->createVersion();
    }
    std::unique_ptr<BaseType> createType() override {
        auto v = std::unique_ptr<TypeFactory>(new TypeBFactory());
        return v->createType();
    }
};

int main(int argc, char const* argv[]) {
    std::cout << "******* abstract factory *******" << std::endl;
    auto product_a_factory =
        std::unique_ptr<AbstractFactory>(new ProductAFactory());
    product_a_factory->createVersion();
    std::cout << product_a_factory->createVersion()->version << std::endl;
    std::cout << product_a_factory->createType()->type << std::endl;

    auto product_b_factory =
        std::unique_ptr<AbstractFactory>(new ProductBFactory());
    product_b_factory->createVersion();
    std::cout << product_b_factory->createVersion()->version << std::endl;
    std::cout << product_b_factory->createType()->type << std::endl;
    return 0;
}
