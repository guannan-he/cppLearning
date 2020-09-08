#define NULL 0
#include <string>
using namespace std;
#if 1
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        ListNode* fast, * slow, * tmp;
        fast = slow = head;
        while (fast && fast->next) {//找到前半部分尾巴
            if (fast = fast->next->next) {
                slow = slow->next;
            }
            else {
                //fast = fast->next->next;
                break;
            }//slow变成前半部分尾巴
        }
        fast = slow->next;
        while (fast && fast->next) {//反转后半部分链表
            tmp = fast->next;
            fast->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;

        }
        fast = slow->next;
        slow = head;
        while (fast && fast->val == slow->val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast) {
            return false;
        }
        else {
            return true;
        }

    }
    
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* tmpA, * tmpB, * lastA, * tmp, * rootNode;
        rootNode = new ListNode(0);
        rootNode->next = l1;
        tmpA = l1;
        tmpB = l2;
        lastA = rootNode;
        while (tmpA && tmpB) {
            if (tmpA->val >= tmpB->val) {
                tmp = tmpB;
                tmpB = tmpB->next;
                tmp->next = tmpA;
                lastA->next = tmp;
                lastA = lastA->next;
            }
            else {
                lastA = tmpA;
                tmpA = tmpA->next;
            }
        }
        tmp = rootNode->next;
        delete rootNode;
        return tmp;
    }

};

ListNode* listGen(string& str) {
    ListNode* tmp;
    ListNode* rootNode = new ListNode(0);
    tmp = rootNode;
    for (int i = 0; i < str.length(); i++) {
        tmp->next = new ListNode(str[i] - '0');
        tmp = tmp->next;
    }
    tmp = rootNode->next;
    delete rootNode;
    return tmp;
}

int main(int argc, char* argv[]) {
    string str1("124");
    string str2("134");
    ListNode* newList1 = listGen(str1);
    ListNode* newList2 = listGen(str2);
    Solution newSolution;
    ListNode* res = newSolution.mergeTwoLists(newList1, newList2);
    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif