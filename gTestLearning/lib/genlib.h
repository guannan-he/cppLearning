#ifndef _GENLIB_H_
#define _GENLIB_H_

namespace genlib {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
    class mergeListClass {
        public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    };
    ListNode* vectorToListNode(std::vector<int>& nums);
    void destoryList(ListNode*& root);
}

#endif