#include <vector>
#include "genlib.h"



namespace genlib{
    ListNode* mergeListClass::mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(-1);
        ListNode* cur = root;
        while (l1 != nullptr || l2 != nullptr){
            if (l1 == nullptr){
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
            else if (l2 == nullptr){
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else if (l1->val <= l2->val){
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        cur = root->next;
        delete root;
        root = nullptr;
        return cur;
    }
    ListNode* vectorToListNode(std::vector<int>& nums){
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        for (int& num : nums){
            cur->next = new ListNode(num);
            cur = cur->next;
        }
        cur = head->next;
        delete head;
        head = nullptr;
        return cur;
    }
    void destoryList(ListNode*& root){
        if (root == nullptr){
            return;
        }
        destoryList(root->next);
        delete root;
        root = nullptr;
        return;
    }
}