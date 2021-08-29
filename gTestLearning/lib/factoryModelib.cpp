#include "factoryModelib.h"
#include <string>

namespace simpleFactoryMode {
    derivedClassA::~derivedClassA(){};
    void derivedClassA::show(void){};
    std::string derivedClassA::getClassName(void){
        return "derivedClassA";
    }

    derivedClassB::~derivedClassB(){};
    void derivedClassB::show(void){};
    std::string derivedClassB::getClassName(void){
        return "derivedClassB";
    }

    derivedClassC::~derivedClassC(){};
    void derivedClassC::show(void){};
    std::string derivedClassC::getClassName(void){
        return "derivedClassC";
    }

    std::string baseClass::getClassName(void){
        return "baseClass";
    };
    baseClass::~baseClass(){};

    baseClass* simpleFactoryModeClassCreator::classCreator(classType tp){
            baseClass* res = nullptr;
            switch (tp){
                case A :{
                    res = new derivedClassA;
                    break;
                }
                case B :{
                    res = new derivedClassB;
                    break;
                }
                case C :{
                    res = new derivedClassC;
                    break;
                }
                default :{
                    break;
                }
            }
            return res;
        }
};

namespace factoryMethodMode{
    baseProductClass::~baseProductClass(){};
    baseFactoryClass::~baseFactoryClass(){};

    derivedClassA::~derivedClassA(){};
    void derivedClassA::show(void){};
    std::string derivedClassA::getClassName(void){
        return "derivedClassA";
    }

    derivedClassB::~derivedClassB(){};
    void derivedClassB::show(void){};
    std::string derivedClassB::getClassName(void){
        return "derivedClassB";
    }

    derivedFactiryA::~derivedFactiryA(){};
    baseProductClass* derivedFactiryA::produce(void){
        baseProductClass* ptr = new derivedClassA;
        return ptr;
    };

    derivedFactiryB::~derivedFactiryB(){};
    baseProductClass* derivedFactiryB::produce(void){
        baseProductClass* ptr = new derivedClassB;
        return ptr;
    };
};

namespace abstractFactoryMode{
    baseProductAClass::~baseProductAClass(){};
    baseProductBClass::~baseProductBClass(){};
    baseFactoryClass::~baseFactoryClass(){};

    derivedClassAA::~derivedClassAA(){};
    void derivedClassAA::show(void){};
    std::string derivedClassAA::getClassName(void){
        return "derivedClassAA";
    }
    derivedClassAB::~derivedClassAB(){};
    void derivedClassAB::show(void){};
    std::string derivedClassAB::getClassName(void){
        return "derivedClassAB";
    }

    derivedClassBA::~derivedClassBA(){};
    void derivedClassBA::show(void){};
    std::string derivedClassBA::getClassName(void){
        return "derivedClassBA";
    }
    derivedClassBB::~derivedClassBB(){};
    void derivedClassBB::show(void){};
    std::string derivedClassBB::getClassName(void){
        return "derivedClassBB";
    }

    factoryA::~factoryA(){};
    baseProductAClass* factoryA::produceA(void){
        baseProductAClass* res = new derivedClassAA;
        return res;
    }
    baseProductBClass* factoryA::produceB(void){
        baseProductBClass* res = new derivedClassBA;
        return res;
    }

    factoryB::~factoryB(){};
    baseProductAClass* factoryB::produceA(void){
        baseProductAClass* res = new derivedClassAB;
        return res;
    }
    baseProductBClass* factoryB::produceB(void){
        baseProductBClass* res = new derivedClassBB;
        return res;
    }
};

namespace templateFactoryMode{
    baseProductAClass::~baseProductAClass(){};
    baseProductBClass::~baseProductBClass(){};

    derivedClassAA::~derivedClassAA(){};
    void derivedClassAA::show(void){};
    std::string derivedClassAA::getClassName(void){
        return "derivedClassAA";
    }
    derivedClassAB::~derivedClassAB(){};
    void derivedClassAB::show(void){};
    std::string derivedClassAB::getClassName(void){
        return "derivedClassAB";
    }

    derivedClassBA::~derivedClassBA(){};
    void derivedClassBA::show(void){};
    std::string derivedClassBA::getClassName(void){
        return "derivedClassBA";
    }
    derivedClassBB::~derivedClassBB(){};
    void derivedClassBB::show(void){};
    std::string derivedClassBB::getClassName(void){
        return "derivedClassBB";
    }

    /*带模板的最好在头文件中实现，否则会无法连接*/
    // template<class abstractProduct>
    // abstractFactory<abstractProduct>::~abstractFactory<abstractProduct>(){};

    // template<class abstractProduct, class concreteProduct>
    // concreteFactory<abstractProduct, concreteProduct>::~concreteFactory<abstractProduct, concreteProduct>(){};
    // template<class abstractProduct, class concreteProduct>
    // abstractProduct* concreteFactory<abstractProduct, concreteProduct>::produce(){
    //     abstractProduct* res = new concreteProduct;
    //     return res;
    // };
};
