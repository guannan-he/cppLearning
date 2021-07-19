#include <gtest/gtest.h>
#include "lib/genlib.h"

class mergeListTestSuite : public testing::Test{
    public:
    void setNums1(std::vector<int>& nums){
        genlib::ListNode* tmp = genlib::vectorToListNode(nums);
        list1_ = genlib::vectorToListNode(nums);
        return;
    }
    void setNums2(std::vector<int>& nums){
        list2_ = genlib::vectorToListNode(nums);
        return;
    }
    genlib::ListNode* exec(void){
        res_ = func_->mergeTwoLists(list1_, list2_);
        return res_;
    }
    void deleteList(genlib::ListNode*& list){
        if (list == nullptr){
            return;
        }
        genlib::destoryList(list);
        list = nullptr;
        return;
    }
    protected:
    virtual void SetUp(){
        return;
    }
    virtual void TearDown(){
        if (res_ != nullptr){
            deleteList(res_);
        }
        else{
            deleteList(list1_);
            deleteList(list2_);
        }
        return;
    }
    static void SetUpTestCase(){
        func_ = new genlib::mergeListClass;
        return;
    }
    static void TearDownTestCase(){
        delete func_;
        return;
    }
    genlib::ListNode* list1_ = nullptr;
    genlib::ListNode* list2_ = nullptr;
    genlib::ListNode* res_ = nullptr;
    static genlib::mergeListClass* func_;
};
genlib::mergeListClass* mergeListTestSuite::func_ = nullptr;

TEST_F(mergeListTestSuite, allNullptrInput){
    ASSERT_EQ(this->list1_, nullptr);
    ASSERT_EQ(this->list2_, nullptr);
    EXPECT_EQ(this->exec(), nullptr);
}

TEST_F(mergeListTestSuite, buildList){
    ASSERT_EQ(this->list1_, nullptr);
    std::vector<int> nums = {1, 2, 3, 4};
    this->setNums1(nums);
    ASSERT_NE(this->list1_, nullptr);
    genlib::ListNode* cur = this->list1_;
    for (int i = 0; i < 4; i++){
        ASSERT_NE(cur, nullptr);
        EXPECT_EQ(cur->val, nums[i]);
        cur = cur->next;
    }
    EXPECT_EQ(cur, nullptr);
}

TEST_F(mergeListTestSuite, destoryList){
    ASSERT_EQ(this->list1_, nullptr);
    std::vector<int> nums = {1};
    this->setNums1(nums);
    ASSERT_NE(this->list1_, nullptr);
    this->deleteList(this->list1_);
    EXPECT_EQ(this->list1_, nullptr);
}

TEST_F(mergeListTestSuite, oneNullptrInput){
    ASSERT_EQ(this->list1_, nullptr);
    std::vector<int> nums = {1, 2, 3, 4};
    this->setNums2(nums);
    ASSERT_NE(this->exec(), nullptr);
    genlib::ListNode* cur = this->res_;
    for (int i = 0; i < 4; i++){
        ASSERT_NE(cur, nullptr);
        EXPECT_EQ(cur->val, nums[i]);
        cur = cur->next;
    }
    EXPECT_EQ(cur, nullptr);
}

TEST_F(mergeListTestSuite, merge){
    std::vector<int> nums = {0, 2, 5, 7, 9};
    this->setNums1(nums);
    std::vector<int> nums2 = {1, 3, 4, 6, 8};
    this->setNums2(nums2);
    ASSERT_NE(this->exec(), nullptr);
    genlib::ListNode* cur = this->res_;
    for (int i = 0; i < 10; i++){
        ASSERT_NE(cur, nullptr);
        EXPECT_EQ(cur->val, i);
        cur = cur->next;
    }
    ASSERT_EQ(cur, nullptr);
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}