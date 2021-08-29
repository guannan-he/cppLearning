#include <iostream>
#include <gtest/gtest.h>
#include "lib/factoryModelib.h"

class simpleFactoryTestSuite : public testing::Test{
    public:
    static void SetUpTestCase(){
        factory = new simpleFactoryMode::simpleFactoryModeClassCreator;
        return;
    }
    static void TearDownTestCase(){
        delete factory;
        factory = nullptr;
        return;
    }
    virtual void SetUp(){
        return;
    }
    virtual void TearDown(){
        if (ptr != nullptr){
            delete ptr;
            ptr = nullptr;
        }
        return;
    }
    protected:
    static simpleFactoryMode::simpleFactoryModeClassCreator* factory;
    simpleFactoryMode::baseClass* ptr = nullptr;;
};
simpleFactoryMode::simpleFactoryModeClassCreator* simpleFactoryTestSuite::factory = nullptr;

TEST_F(simpleFactoryTestSuite, AClass){
    ptr = factory->classCreator(simpleFactoryMode::classType::A);
    EXPECT_EQ(ptr->getClassName(), "derivedClassA");
}
TEST_F(simpleFactoryTestSuite, BClass){
    ptr = factory->classCreator(simpleFactoryMode::classType::B);
    EXPECT_EQ(ptr->getClassName(), "derivedClassB");
}
TEST_F(simpleFactoryTestSuite, CClass){
    ptr = factory->classCreator(simpleFactoryMode::classType::C);
    EXPECT_EQ(ptr->getClassName(), "derivedClassC");
}
TEST_F(simpleFactoryTestSuite, None){
    ptr = factory->classCreator(simpleFactoryMode::classType::None);
    EXPECT_EQ(ptr, nullptr);
    testing::FLAGS_gtest_death_test_style = "threadsafe";
    EXPECT_EXIT((ptr->getClassName(), exit(0)), testing::KilledBySignal(SIGSEGV), ".*");
}

TEST(factoryMethodMode, factoryA){
    factoryMethodMode::baseFactoryClass* fac = new factoryMethodMode::derivedFactiryA;
    factoryMethodMode::baseProductClass* product =  fac->produce();
    EXPECT_EQ(product->getClassName(), "derivedClassA");
    delete fac; fac = nullptr;
    delete product; product = nullptr;
}

TEST(factoryMethodMode, factoryB){
    factoryMethodMode::baseFactoryClass* fac = new factoryMethodMode::derivedFactiryB;
    factoryMethodMode::baseProductClass* product =  fac->produce();
    EXPECT_EQ(product->getClassName(), "derivedClassB");
    delete fac; fac = nullptr;
    delete product; product = nullptr;
}

TEST(abstractFactoryMode, factoryA){
    abstractFactoryMode::baseFactoryClass* fac = new abstractFactoryMode::factoryA;
    abstractFactoryMode::baseProductAClass* aClass = fac->produceA();
    abstractFactoryMode::baseProductBClass* bClass = fac->produceB();
    EXPECT_EQ(aClass->getClassName(), "derivedClassAA");
    EXPECT_EQ(bClass->getClassName(), "derivedClassBA");
}

TEST(abstractFactoryMode, factoryB){
    abstractFactoryMode::baseFactoryClass* fac = new abstractFactoryMode::factoryB;
    abstractFactoryMode::baseProductAClass* aClass = fac->produceA();
    abstractFactoryMode::baseProductBClass* bClass = fac->produceB();
    EXPECT_EQ(aClass->getClassName(), "derivedClassAB");
    EXPECT_EQ(bClass->getClassName(), "derivedClassBB");
}

TEST(templateFactoryMode, AAProduct){
    templateFactoryMode::concreteFactory<templateFactoryMode::baseProductAClass, templateFactoryMode::derivedClassAA>* fac = nullptr;
    fac = new templateFactoryMode::concreteFactory<templateFactoryMode::baseProductAClass, templateFactoryMode::derivedClassAA>;
    templateFactoryMode::baseProductAClass* ptr = fac->produce();
    EXPECT_EQ(ptr->getClassName(), "derivedClassAA");
}

TEST(templateFactoryMode, ABProduct){
    templateFactoryMode::concreteFactory<templateFactoryMode::baseProductAClass, templateFactoryMode::derivedClassAB>* fac = nullptr;
    fac = new templateFactoryMode::concreteFactory<templateFactoryMode::baseProductAClass, templateFactoryMode::derivedClassAB>;
    templateFactoryMode::baseProductAClass* ptr = fac->produce();
    EXPECT_EQ(ptr->getClassName(), "derivedClassAB");
}

TEST(templateFactoryMode, BAProduct){
    templateFactoryMode::concreteFactory<templateFactoryMode::baseProductBClass, templateFactoryMode::derivedClassBA>* fac = nullptr;
    fac = new templateFactoryMode::concreteFactory<templateFactoryMode::baseProductBClass, templateFactoryMode::derivedClassBA>;
    templateFactoryMode::baseProductBClass* ptr = fac->produce();
    EXPECT_EQ(ptr->getClassName(), "derivedClassBA");
}

TEST(templateFactoryMode, BBProduct){
    templateFactoryMode::concreteFactory<templateFactoryMode::baseProductBClass, templateFactoryMode::derivedClassBB>* fac = nullptr;
    fac = new templateFactoryMode::concreteFactory<templateFactoryMode::baseProductBClass, templateFactoryMode::derivedClassBB>;
    templateFactoryMode::baseProductBClass* ptr = fac->produce();
    EXPECT_EQ(ptr->getClassName(), "derivedClassBB");
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}