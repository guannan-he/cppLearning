#define NULL 0
#include <string>
#include <vector>
using namespace std;

//链表
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


//数组和字符串
#if 0
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



//队列、栈
#if 1

struct node {
    int val = 0;
    node* next = 0;
};
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
        rootNode = new node[k];
        currentNode = rootNode;
        return;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        currentNode->next = new node;
        currentNode = currentNode->next;
        currentNode->val = value;
        member++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        node* tmp = rootNode->next;
        rootNode->next = tmp->next;
        delete tmp;
        member--;
        if (isEmpty()) {
            currentNode = rootNode;
        }
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return rootNode->next->val;
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return currentNode->val;
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return member == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return member == size;
    }
private:
    node* rootNode, * currentNode;
    int size = 0;
    int member = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


int main(int argc, char* argv[]) {
    MyCircularQueue* obj = new MyCircularQueue(6);
    obj->enQueue(6);
    obj->deQueue();
    obj->enQueue(5);

    return 0;
}


#endif
