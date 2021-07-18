#include <gtest/gtest.h>
#include <string>
#include <vector>

// using namespace std;

int add(int a,int b){// 一个函数
    return a+b;
}

int fib(int n){// 一个函数
    if (n < 2){
        return 1;
    }
    int n_1 = 1, n_2 = 1, res = 2;
    while (n-- > 1){
        res = n_1 + n_2;
        n_2 = n_1;
        n_1 = res;
    }
    return res;
}

void Foo(){// 报错函数
    std::vector<int> data;
    data[2] = 0;
    return;
}

class addClass{// 一个 functional class
public:
    addClass(){};
    addClass(int a, int b){
        setA(a);
        setB(b);
        return;
    }
    void setA(int a){
        a_ = a;
        initializedA_ = true;
        return;
    }
    void setB(int b){
        b_ = b;
        initializedB_ = true;
        return;
    }
    int exec(void){
        if (!(initializedA_ && initializedB_)){
            throw("init first");
        }
        return a_ + b_;
    }
protected:
    bool initializedA_ = false;
    bool initializedB_ = false;
    int a_ = 0;
    int b_ = 0;
};

class isPrimeClass{
    public:
    bool isPrime(int n){
        return n % 2 != 0;
    }
};

class testEnv : public testing::Environment{// 全局类事件
// 全局的, 所有案例执行前后
public:
    virtual void SetUp(){
        std::cout << "-------------------------set up-------------------------" << std::endl;
        return;
    }
    virtual void TearDown(){
        std::cout << "------------------------teardown------------------------" << std::endl;
        return;
    }
};

class testCase_addClass : public testing::Test{// 一个 testcase
public:
// TestCase级别的, 每个TestCase前后
    virtual void SetUp(){
        adder_ = new addClass;
        return;
    }
    virtual void TearDown(){
        delete adder_;
        adder_ = nullptr;
        return;
    }
protected:
    addClass* adder_;
};

class testSuite_addClass : public testing::Test{// 一个test suite
protected:
// TestSuite级别的, 在某一批案例中第一个案例前, 最后一个案例执行后
    static void SetUpTestCase(){
        adder_ = new addClass;
        return;
    }
    static void TearDownTestCase(){
        delete adder_;
        adder_ = nullptr;
        return;
    }
    bool methodAvail(void){
        return adder_ != nullptr;
    }
    static addClass* adder_;// 内部只进行声明
};
addClass* testSuite_addClass::adder_ = nullptr;
// static 成员变量属于类，不属于某个具体的对象
// static 成员变量必须在类声明的外部初始化
// static 成员变量是在初始化时分配内存的，程序结束时释放内存

class testSuiteCase_addClass : public testing::Test{
protected:
    static void SetUpTestCase(){
        adderStatic_ = new addClass;
        return;
    }
    static void TearDownTestCase(){
        delete adderStatic_;
        adderStatic_ = nullptr;
        return;
    }
    virtual void SetUp(){
        adder_ = new addClass;
        return;
    }
    virtual void TearDown(){
        delete adder_;
        adder_ = nullptr;
        return;
    }
    static addClass* adderStatic_;
    addClass* adder_ = nullptr;
};
addClass* testSuiteCase_addClass::adderStatic_ = nullptr;

class isPrimeParamTest : public testing::TestWithParam<int>{// 一个代参数测试
// 同样可以使用SetUp(TearDown)/SetUpTestCase(TearDownTestCase) 选择test case/test suite 模式
    public:
    virtual void SetUp(){
        isprime_ = new isPrimeClass;
        std::cout << "new instance" << std::endl;
        return;
    }
    virtual void TearDown(){
        delete isprime_;
        isprime_ = nullptr;
        return;
    }
    protected:
    isPrimeClass* isprime_ = nullptr;
};

TEST(functional, addTestCase){// 函数级别测试
    EXPECT_EQ(add(2,6),8);
    EXPECT_EQ(add(2,3),5);
    EXPECT_EQ(add(2,5),7);
}
TEST(functional, fibTestCase){// 函数级别测试
    EXPECT_EQ(fib(0),1);
    EXPECT_EQ(fib(1),1);
    EXPECT_EQ(fib(2),2);
    EXPECT_EQ(fib(3),3);
    EXPECT_EQ(fib(8),34);
}

TEST_F(testSuite_addClass, normal){// test suite 级别测试，一个类共享一个实例
    adder_->setA(1);
    adder_->setB(1);
    EXPECT_NO_THROW(adder_->exec());
    EXPECT_EQ(adder_->exec(), 2);
    adder_->setB(2);
    EXPECT_EQ(adder_->exec(), 3);
}

TEST_F(testSuite_addClass, initfail){// test suite 级别测试，一个类共享一个实例
    adder_->setA(3);
    // adder->setB(1);
    ASSERT_NO_THROW(adder_->exec());// 因为共享一个实例，所以并无异常抛出
    EXPECT_EQ(adder_->exec(), 5);
}

TEST_F(testCase_addClass, normal){// test case 级别测试，每一个单独实例
    // 每一个testcase一个实例
    adder_->setA(1);
    adder_->setB(1);
    EXPECT_NO_THROW(adder_->exec());
    EXPECT_EQ(adder_->exec(), 2);
    adder_->setB(2);
    EXPECT_EQ(adder_->exec(), 3);
}

TEST_F(testCase_addClass, initfail){// test case 级别测试，每一个单独实例
    // 每一个testcase一个实例
    adder_->setA(1);
    ASSERT_ANY_THROW(adder_->exec());// 因为单独实例，所以期待有异常抛出
}

TEST_F(testSuiteCase_addClass, normal){
    adder_->setA(1);
    adder_->setB(1);
    EXPECT_NO_THROW(adder_->exec());
    adderStatic_->setA(1);
    adderStatic_->setB(1);
    EXPECT_NO_THROW(adderStatic_->exec());

}

TEST_F(testSuiteCase_addClass, staticInitFail){
    EXPECT_ANY_THROW(adder_->exec());// 重新生成一个实例，期待抛出
    EXPECT_NO_THROW(adderStatic_->exec());// 共用实例，无抛出
}

TEST_P(isPrimeParamTest, trueReturn){// 参数化测试
    int n = GetParam();
    EXPECT_EQ(isprime_->isPrime(n), n % 2 != 0);
}


INSTANTIATE_TEST_CASE_P(trueCondition, isPrimeParamTest, testing::Range(0, 10, 1));

// testing::Values
// testing::ValuesIn stl迭代器中取值
// testing::Bool
// testing::Combine  只在提供了<tr1/tuple>头的系统中有效.


TEST(FooDeathTest, Demo){// 死亡测试
    EXPECT_DEATH(Foo(), "");
}

int main(int argc, char* argv[]){
    testEnv* env = nullptr;
    testing::AddGlobalTestEnvironment(env = new testEnv);// 全局事件，RUN_ALL_TESTS()开始前调用setup， RUN_ALL_TESTS()结束后调用teardown
    testing::InitGoogleTest(&argc,argv);
    /*
    总结一下gtest的事件一共有3种:
    全局的, 所有案例执行前后
    TestSuite级别的, 在某一批案例中第一个案例前, 最后一个案例执行后
    TestCase级别的, 每个TestCase前后
    */
    int a[][5] = {0, 0, 0, 0, 0, 0, 0};
    int res = RUN_ALL_TESTS();
    return res;
}