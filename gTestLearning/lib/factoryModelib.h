#include <string>

namespace simpleFactoryMode{
    //简单工厂模式
    //拓展性差，增加产品需要修改工厂类
    enum classType {
        A,
        B,
        C,
        None
    };
    class baseClass{
        public:
        virtual ~baseClass() = 0;
        virtual void show(void) = 0;
        virtual std::string getClassName(void);
    };
    class derivedClassA : public  baseClass{
        public:
        virtual ~derivedClassA();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class derivedClassB : public  baseClass{
        public:
        virtual ~derivedClassB();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class derivedClassC : public  baseClass{
        public:
        virtual ~derivedClassC();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class simpleFactoryModeClassCreator{
        public:
        baseClass* classCreator(classType tp);
    };
};

namespace factoryMethodMode{
    //工厂方法模式
    //具有抽象工厂类
    //新增产品需要新增工厂类
    class baseProductClass{
        public:
        virtual ~baseProductClass() = 0;
        virtual void show(void) = 0;
        virtual std::string getClassName(void) = 0;
    };
    class derivedClassA : public  baseProductClass{
        public:
        virtual ~derivedClassA();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class derivedClassB : public  baseProductClass{
        public:
        virtual ~derivedClassB();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class baseFactoryClass{
        public:
        virtual ~baseFactoryClass() = 0;
        virtual baseProductClass* produce(void) = 0;
    };
    class derivedFactiryA : public baseFactoryClass{
        public:
        virtual ~derivedFactiryA();
        virtual baseProductClass* produce(void);
    };
    class derivedFactiryB : public baseFactoryClass{
        public:
        virtual ~derivedFactiryB();
        virtual baseProductClass* produce(void);
    };
};

namespace abstractFactoryMode{
    //一个接口创建多个产品族对象
    //增加新产品需要修改具体工厂类
    class baseProductAClass{
        public:
        virtual ~baseProductAClass() = 0;
        virtual void show(void) = 0;
        virtual std::string getClassName(void) = 0;
    };
    class baseProductBClass{
        public:
        virtual ~baseProductBClass() = 0;
        virtual void show(void) = 0;
        virtual std::string getClassName(void) = 0;
    };
    class derivedClassAA : public  baseProductAClass{
        public:
        virtual ~derivedClassAA();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class derivedClassAB : public  baseProductAClass{
        public:
        virtual ~derivedClassAB();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class derivedClassBA : public  baseProductBClass{
        public:
        virtual ~derivedClassBA();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class derivedClassBB : public  baseProductBClass{
        public:
        virtual ~derivedClassBB();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class baseFactoryClass{
        public:
        virtual ~baseFactoryClass() = 0;
        virtual baseProductAClass* produceA(void) = 0;
        virtual baseProductBClass* produceB(void) = 0;
    };
    class factoryA : public baseFactoryClass{
        public:
        ~factoryA();
        baseProductAClass* produceA(void);
        baseProductBClass* produceB(void);
    };
    class factoryB : public baseFactoryClass{
        public:
        ~factoryB();
        baseProductAClass* produceA(void);
        baseProductBClass* produceB(void);
    };
};

namespace templateFactoryMode{
    //模板工厂，遵循开闭原则，对扩展开放，对修改封闭
    class baseProductAClass{
        public:
        virtual ~baseProductAClass() = 0;
        virtual void show(void) = 0;
        virtual std::string getClassName(void) = 0;
    };
    class baseProductBClass{
        public:
        virtual ~baseProductBClass() = 0;
        virtual void show(void) = 0;
        virtual std::string getClassName(void) = 0;
    };
    class derivedClassAA : public  baseProductAClass{
        public:
        virtual ~derivedClassAA();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class derivedClassAB : public  baseProductAClass{
        public:
        virtual ~derivedClassAB();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class derivedClassBA : public  baseProductBClass{
        public:
        virtual ~derivedClassBA();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    class derivedClassBB : public  baseProductBClass{
        public:
        virtual ~derivedClassBB();
        virtual void show(void);
        virtual std::string getClassName(void);
    };
    template<class abstractProduct>
    class abstractFactory{
        public:
        virtual ~abstractFactory(){};
        virtual abstractProduct* produce() = 0;
    };
    template<class abstractProduct, class concreteProduct>
    class concreteFactory : public abstractFactory<abstractProduct>{
        public:
        virtual ~concreteFactory(){};
        virtual abstractProduct* produce(){
            abstractProduct* res = new concreteProduct;
            return res;
        };
    };
};
