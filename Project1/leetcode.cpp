#define NULL 0
#include <string>
#include <vector>
using namespace std;
#if 0
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

#if 1
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum, leftSum;
        sum = leftSum = 0;
        int cnt = nums.size();
        if (cnt < 3) {
            return -1;
        }
        for (int i = 0; i < cnt; i++) {
            sum += nums[i];
        }
        //sum += nums[0];
        for (int i = 0; i < cnt; i++) {
            sum -= nums[i];
            if (leftSum == sum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int len = nums.size();
        while (i < len && nums[i] < target) {
            i++;
        }
        if (i == len) {
            nums.push_back(target);
            return i;
        }
        if (nums[i] == target) {
            return i;
        }
        nums.insert(nums.begin() + i, target);
        return i;
    }
    int strStr(string haystack, string needle) {
        int needleLen = needle.size();
        if (!needleLen) {
            return 0;
        }
        int haystackLen = haystack.size();
        vector<int>* next = getNext(needle);
        int i, j, total;
        i = 0; j = 0;
        //total = haystackLen - needleLen;
        while (i < haystackLen && j < needleLen) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++; j++;
            }
            else {
                j = (*next)[j];
            }
        }
        if (j == needleLen) {
            return i - j;
        }
        else {
            return -1;
        }
    }
    vector<int>* getNext(string& str) {
        int strLen = str.size();
        //int* res = new int(strLen);
        vector<int>* res = new vector<int>;
        //res[0] = -1;
        res->push_back(-1);
        int pos = 0;
        int cnt = -1;
        while (pos < strLen - 1) {
            if (cnt == -1 || str[pos] == str[cnt]) {
                ++cnt; ++pos;
                res->push_back(cnt);
                //res[pos] = cnt;
            }
            else {
                cnt = (*res)[cnt];
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution mysolution;
    //vector<int> inpt = {-1, -1, 0, -1, -1, 0};
    //vector<int> inpt = {1, 7, 3, 6, 5, 6};
    //vector<int> inpt = { 1, 3, 5, 6 };
    //string str("cock");
    //int i = str.size();
    //int** pos = new int* [i]; 
    //for (int j = 0; j < 9; j++) {
    //    pos[j] = new int[i];
    //}
    //int res = mysolution.searchInsert(inpt, 7);
    //int res = mysolution.pivotIndex(inpt);
    //string str = "abab";
    //string str = "ABCDABD";
    //vector<int> res = mysolution.getNext(str);
    string str1 = "aabaaabaaac";
    string str2 = "aabaaac";
    int res = mysolution.strStr(str1, str2);
    return 0;
}

#endif


