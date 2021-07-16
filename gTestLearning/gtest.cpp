#include <gtest/gtest.h>
#include <string>
#include <vector>

// using namespace std;

int add(int a,int b){
    return a+b;
}

int fib(int n){
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

TEST(addTestCase,functional){
    EXPECT_EQ(add(2,6),8);
    EXPECT_EQ(add(2,3),5);
    EXPECT_EQ(add(2,5),7);
}
TEST(fibTestCase,functional){
    EXPECT_EQ(fib(0),1);
    EXPECT_EQ(fib(1),1);
    EXPECT_EQ(fib(2),2);
    EXPECT_EQ(fib(3),3);
    EXPECT_EQ(fib(8),34);
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}