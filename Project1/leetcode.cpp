#define NULL 0
#include <string>
#include <vector>
#include <queue>
#include<unordered_set>
#include<unordered_map>
#include<stack>
using namespace std;

//����
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
        while (fast && fast->next) {//�ҵ�ǰ�벿��β��
            if (fast = fast->next->next) {
                slow = slow->next;
            }
            else {
                //fast = fast->next->next;
                break;
            }//slow���ǰ�벿��β��
        }
        fast = slow->next;
        while (fast && fast->next) {//��ת��벿������
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


//������ַ���
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



//����
#if 0

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
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int colSize = grid.size();
        if (!colSize) {//��Ԫ���򷵻�
            return 0;
        }
        int rolSize = grid[0].size();
        int total = colSize * rolSize;
        char** visited = visitedGen(colSize, rolSize);
        char** gridCopy = gridCopyFunc(grid, colSize, rolSize);
        queue<vector<int>> q;//���б����±�����
        int cur = 0;//�±����
        int c, r;//�±�
        int cnt = 0;//½�ؼ���
        int queueSize;
        vector<int> pos;
        pos.push_back(c); pos.push_back(r);
        while (cur < total) {
            //δ���ʹ���ѹ�����
            c = cur / rolSize;
            r = cur % rolSize;
            cur++;
            //��ȡ�±�
            if (visited[c][r] == '1') {
                continue;//���ʹ�����
            }
            visited[c][r] = '1';//���ڵ���Ϊ���ʹ�
            if (gridCopy[c][r] == '0') {
                continue;//����½��
            }
            pos[0] = c; pos[1] = r;//����½���±�
            q.push(pos);//ѹ����ڵ�
            while (!q.empty()) {
                queueSize = q.size();
                while (queueSize) {
                    pos = q.front();//��ȡͷ�ڵ�
                    c = pos[0]; r = pos[1];
                    if (c > 0 && visited[c - 1][r] == '0') {//�Ϸ��ڵ�
                        visited[c - 1][r] = '1';
                        if (gridCopy[c - 1][r] == '1') {
                            pos[0] = c - 1;
                            pos[1] = r;
                            q.push(pos);
                        }
                    }
                    if (r < rolSize - 1 && visited[c][r + 1] == '0') {//�ҷ��ڵ�
                        visited[c][r + 1] = '1';
                        if (gridCopy[c][r + 1] == '1') {
                            pos[0] = c;
                            pos[1] = r + 1;
                            q.push(pos);
                        }
                    }
                    if (c < colSize - 1 && visited[c + 1][r] == '0') {//�·��ڵ�
                        visited[c + 1][r] = '1';
                        if (gridCopy[c + 1][r] == '1') {
                            pos[0] = c + 1;
                            pos[1] = r;
                            q.push(pos);
                        }
                    }
                    if (r > 0 && visited[c][r - 1] == '0') {//�󷽽ڵ�
                        visited[c][r - 1] = '1';
                        if (gridCopy[c][r - 1] == '1') {
                            pos[0] = c;
                            pos[1] = r - 1;
                            q.push(pos);
                        }
                    }

                    q.pop();//����ͷ�ڵ�
                    queueSize--;
                }
            }
            cnt++;
        }
        visitedDelete(visited, colSize);
        visitedDelete(gridCopy, colSize);
        return cnt;
    }
    char** visitedGen(int colSize, int rolSize) {//���ɷ��ʱ�Ǿ���
        char** visited = new char* [colSize];
        for (int i = 0; i < colSize; i++) {
            visited[i] = new char[rolSize];
        }
        for (int i = 0; i < colSize; i++) {
            for (int j = 0; j < rolSize; j++) {
                visited[i][j] = '0';//���ΪΪ����
            }
        }
        return visited;
    }
    void visitedDelete(char** visited, int colSize) {//ɾ����Ǿ���
        for (int i = 0; i < colSize; i++) {
            delete[] visited[i];
        }
        delete[] visited;
        return;
    }
    char** gridCopyFunc(vector<vector<char>>& grid, int colSize, int rolSize) {
        char** visited = visitedGen(colSize, rolSize);
        for (int i = 0; i < colSize; i++) {
            for (int j = 0; j < rolSize; j++) {
                visited[i][j] = grid[i][j];
            }
        }
        return visited;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    int openLock(vector<string>& deadends, string target) {
        int deadEndCnt = deadends.size();
        int totalCnt = 0;
        int cur;
        int inVisit = 0;
        int tmpNum;
        queue<string> q;
        string current = "0000";
        string tmp = "0000";
        unordered_set<string> vist;
        vist.insert(deadends.begin(), deadends.end());
        q.push(current);//ѹ����ڵ�
        vist.emplace(current);
        while (!q.empty()) {//�����ﻹ��Ԫ��
            int queueLen = q.size();
            while (queueLen) {//�����������
                current = q.front();
                if (vist.count(current)) {
                    return -1;//���ó��ֵĳ�����
                }
                if (current == target) {
                    return totalCnt;//�ҵ�Ŀ��
                }
                //Ҫ�޸ģ���Ϊ�����������ڻ�������������
                for (cur = 0; cur < 4; cur++) {
                    tmp = current;
                    tmpNum = current[cur] - '0';
                    tmpNum = tmpNum < 9 ? (tmpNum + 1) : 0;
                    tmp[cur] = (tmpNum + '0');
                    if (!vist.count(tmp)) {
                        q.push(tmp);
                        vist.emplace(tmp);
                    }
                    tmp = current;
                    tmpNum = current[cur] - '0';
                    tmpNum = tmpNum > 0 ? (tmpNum - 1) : 9;
                    tmp[cur] = (tmpNum + '0');
                    if (!vist.count(tmp)) {
                        q.push(tmp);
                        vist.emplace(tmp);
                    }
                }
                q.pop();
                queueLen--;
            }
            totalCnt++;
        }
        return -1;
    }
    bool inDeadend(vector<string>& deadends, string current) {
        int deadEndCnt = deadends.size();
        for (int i = 0; i < deadEndCnt; i++) {
            if (current == deadends[i]) {
                return true;
            }
        }
        return false;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int numSquares(int n) {
        queue<int> q;
        unordered_set<int> calculated;
        q.push(n);
        calculated.emplace(n);
        int qLen = 0;
        int current = 0;
        int res = 0;
        int max = 0;
        int tmp;
        while (!q.empty()) {
            qLen = q.size();
            while (qLen) {//�����������
                current = q.front();
                if (current == 0) {
                    return res;
                }
                max = int(sqrt(current));
                while (max >= 0) {
                    tmp = current - max * max;
                    if (!calculated.count(tmp)) {
                        q.push(tmp);
                        calculated.emplace(tmp);
                    }
                    max--;
                }
                q.pop();
                qLen--;
            }
            res++;
        }
        return -1;
    }
};

void inptGen(vector<vector<char>>& inpt) {
    vector<char> tmp;
    //string s = "11000 11000 00100 00011 ";
    //string s = "11110 11010 11000 00000 ";
    string s = "8888";
    int sLen = s.size();
    int cur = 0;
    while (cur < sLen) {
        if (s[cur] == ' ') {
            inpt.push_back(tmp);
            tmp.clear();
        }
        else {
            tmp.push_back(s[cur]);
        }
        cur++;
    }
    return;
}
void deadEndGen(vector<string>& inpt) {
    string s = "0201 0101 0102 1212 2002 ";
    //string s = "8887 8889 8878 8898 8788 8988 7888 9888 ";
    int sLen = s.size();
    int cur = 0;
    string tmp;
    while (cur < sLen) {
        if (s[cur] == ' ') {
            inpt.push_back(tmp);
            tmp.clear();
        }
        else {
            tmp.push_back(s[cur]);
        }
        cur++;
    }
    return;
}


int main(int argc, char* argv[]) {
    /*MyCircularQueue* obj = new MyCircularQueue(6);
    obj->enQueue(6);
    obj->deQueue();
    obj->enQueue(5);*/
    Solution mySolution;
    //vector<vector<char>> inpt;
    vector<string> inpt;
    //inptGen(inpt);
    //mySolution.numIslands(inpt);
    deadEndGen(inpt);
    string target = "0009";
    //mySolution.openLock(inpt, target);
    mySolution.numSquares(8935);



    return 0;
}


#endif



//ջ
#if 0
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int colSize = matrix.size();
        if (!colSize) {//��Ԫ���򷵻�
            return matrix;
        }
        int rolSize = matrix[0].size();
        
        //���ͷű���
        char** visited = visitedGen(colSize, rolSize);//���ʱ��
        queue<pair<int, int>>* q = new queue<pair<int, int>>;//�±����

        //�����������뵽���ʹ�������
        int c, r;
        for (c = 0; c < colSize; c++){
            for (r = 0; r < rolSize; r++) {
                if (matrix[c][r] == 0) {
                    q->emplace(c, r);
                    visited[c][r] = '1';
                }
            }
        }

        //DFS
        int tmpC, tmpR;
        int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        while (!q->empty()) {
            c = q->front().first;
            r = q->front().second;
            for (int i = 0; i < 4; i++) {
                tmpC = c + dirs[i][0];
                tmpR = r + dirs[i][1];
                if (tmpC >= 0 && tmpC < colSize && tmpR >= 0 && tmpR < rolSize && visited[tmpC][tmpR] == '0') {
                    matrix[tmpC][tmpR] = matrix[c][r] + 1;
                    q->emplace(tmpC, tmpR);
                    visited[tmpC][tmpR] = '1';
                }
            }
            q->pop();
        }

        //�������ͷ�
        visitedDelete(visited, colSize);
        delete q;
        return matrix;
    }
    char** visitedGen(int colSize, int rolSize) {//���ɷ��ʱ�Ǿ���
        char** visited = new char* [colSize];
        for (int i = 0; i < colSize; i++) {
            visited[i] = new char[rolSize];
        }
        for (int i = 0; i < colSize; i++) {
            for (int j = 0; j < rolSize; j++) {
                visited[i][j] = '0';//���ΪΪ����
            }
        }
        return visited;
    }
    void visitedDelete(char** visited, int colSize) {//ɾ����Ǿ���
        for (int i = 0; i < colSize; i++) {
            delete[] visited[i];
        }
        delete[] visited;
        return;
    }
};

void inptGen(vector<vector<int>>& inpt) {
    vector<int> tmp;
    //string s = "11000 11000 00100 00011 ";
    //string s = "11110 11010 11000 00000 ";
    //string s = "000 010 000 ";
    string s = "01011 11001 00010 10111 10001 ";
    //string s = "000 010 111 ";
    //string s = "8888";
    int sLen = s.size();
    int cur = 0;
    while (cur < sLen) {
        if (s[cur] == ' ') {
            inpt.push_back(tmp);
            tmp.clear();
        }
        else {
            tmp.push_back(s[cur] - '0');
        }
        cur++;
    }
    return;
}

int main(int argc, char* argv[]) {
    Solution mySolution;
    vector<vector<int>> inpt;
    inptGen(inpt);
    mySolution.updateMatrix(inpt);
    return 0;
}
#endif

//������
#if 0



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Codec {
 public:

     // Encodes a tree to a single string.
     string serialize(TreeNode* root) {
         string res;
         queue<TreeNode*> que;
         que.push(root);
         while (!que.empty()) {
             int siz = que.size();
             while (siz--) {
                 TreeNode* cur = que.front();
                 que.pop();
                 if (cur == nullptr) {
                     res += "null,";
                 }
                 else {
                     string str_val = to_string(cur->val) + ",";
                     res += str_val;
                     que.push(cur->left);
                     que.push(cur->right);
                 }
             }
         }
         return res;
     }

     // Decodes your encoded data to tree.
     TreeNode* deserialize(string data) {
         queue<int>* valStack = pushStrVal(data);
         if (!valStack->size()) {
             return nullptr;
         }
         TreeNode* currentNode;
         int currentVal = valStack->front();
         if (currentVal == -888) {
             return nullptr;
         }
         valStack->pop();
         TreeNode* root = new TreeNode(currentVal);
         queue<TreeNode*> q;
         q.push(root);
         while (!q.empty()) {
             int qLen = q.size();
             while (qLen) {
                 currentNode = q.front();
                 q.pop();
                 qLen--;
                 if (currentNode == nullptr) {
                     continue;
                 }
                 currentVal = -888;
                 if (!valStack->empty()) {
                     currentVal = valStack->front();
                     valStack->pop();
                 }
                 if (currentVal != -888) {
                     currentNode->left = new TreeNode(currentVal);
                 }
                 q.push(currentNode->left);
                 currentVal = -888;
                 if (!valStack->empty()) {
                     currentVal = valStack->front();
                     valStack->pop();
                 }
                 if (currentVal != -888) {
                     currentNode->right = new TreeNode(currentVal);
                 }
                 q.push(currentNode->right);
             }
         }

         return root;
     }
     queue<int>* pushStrVal(string& data) {
         queue<int>* valStack = new queue<int>;
         int dataLen = data.size();
         int cur = 0;
         int tmpVal;
         int sign;
         while (cur < dataLen) {
             if (data[cur] == '[') {
                 cur++;
                 continue;
             }
             if (data[cur] == ']') {
                 cur++;
                 continue;
             }
             if (data[cur] == ',') {
                 cur++;
                 continue;
             }
             if (data[cur] == 'n') {
                 valStack->push(-888);
                 cur += 4;
                 continue;
             }
             sign = 1;
             tmpVal = 0;
             while (data[cur] != ',' && data[cur] != ']') {
                 if (data[cur] == '-') {
                     sign = -1;
                     cur++;
                     continue;
                 }
                 tmpVal = tmpVal * 10 + data[cur] - '0';
                 cur++;
             }
             tmpVal *= sign;
             valStack->push(tmpVal);
         }
         return valStack;
     }
 };

 // Your Codec object will be instantiated and called as such:
 // Codec ser, deser;
 // TreeNode* ans = deser.deserialize(ser.serialize(root));

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(int argc, char* argv[]) {
    Codec myCodec;
    string str = "[4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]";
    TreeNode* root = myCodec.deserialize(str);
    string res = myCodec.serialize(root);
    return 0;
}

#endif

//����������
#if 0

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        target = k;
        int numsLen = nums.size();
        int cur;
        for (cur = 0; cur < numsLen; cur++) {
            root = addToTree(root, nums[cur]);
        }
        return;
    }

    int add(int val) {
        root = addToTree(root, val);
        return getThLarge();
    }
private:
    struct treeNode {
        int val = 0;
        int cnt = 0;
        treeNode* left = nullptr;
        treeNode* right = nullptr;
    };
    int target = 0;
    treeNode* root = nullptr;
    treeNode* addToTree(treeNode* root, int val) {//�ݹ����������������
        if (root == nullptr) {
            treeNode* ans = new treeNode;
            ans->val = val;
            ans->cnt += 1;
            return ans;
        }
        int nodeVal = root->val;
        root->cnt += 1;
        if (val < nodeVal) {
            root->left = addToTree(root->left, val);
        }
        if (val > nodeVal) {
            root->right = addToTree(root->right, val);
        }
        return root;
    }
    int getThLarge() {//���صڼ����Ԫ��
        treeNode* cur = root;
        int k = target;
        int lCnt, rCnt, curCnt;
        while (1) {
            rCnt = (cur->right != nullptr) ? cur->right->cnt : 0;
            lCnt = (cur->left != nullptr) ? cur->left->cnt : 0;
            curCnt = cur->cnt - lCnt - rCnt;
            if (k > rCnt + curCnt) {
                k = k - curCnt - rCnt;
                cur = cur->left;
            }
            else if (k <= rCnt) {
                cur = cur->right;
            }
            else {
                return cur->val;
            }
        }
        return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


int main(int argc, char* argv[]) {
    int val = 2;
    vector<int> nums = {0};
    KthLargest kthLargest(val, nums);
    kthLargest.add(-1);
    kthLargest.add(1);
    kthLargest.add(-2);
    kthLargest.add(-4);
    kthLargest.add(3);
    return 0;
}

#endif

//ǰ׺��Trie
#if false

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        rootNode = new node;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int wordLen = word.size();
        node* cur = rootNode;
        char currentChar;
        for (int i = 0; i < wordLen; i++) {
            currentChar = word[i];
            if (!cur->children.count(currentChar)) {
                node* tmp = new node;
                tmp->val = currentChar;
                if (i == wordLen - 1) {
                    tmp->isWord = true;
                }
                cur->children.emplace(currentChar, tmp);
                cur = tmp;
            }
            else {
                cur = cur->children.find(currentChar)->second;
                if (i == wordLen - 1) {
                    cur->isWord = true;
                }
            }
        }
        return;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* cur = rootNode;
        int wordLen = word.size();
        for (int i = 0; i < wordLen; i++) {
            if (!cur->children.count(word[i])) {
                return false;
            }
            cur = cur->children.find(word[i])->second;
        }
        return cur->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* cur = rootNode;
        int wordLen = prefix.size();
        for (int i = 0; i < wordLen; i++) {
            if (!cur->children.count(prefix[i])) {
                return false;
            }
            cur = cur->children.find(prefix[i])->second;
        }
        return true;
    }
private:
    struct node {
        char val;
        bool isWord = false;
        unordered_map<char, node*> children;
    };
    node* rootNode;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        rootNode = new node;
        pushIntoTrie(dictionary);
        string ans;
        string inptTmp, ouptTmp;
        int sentenceLen = sentence.size();
        int i, j;
        i = j = 0;
        while (i < sentenceLen && j < sentenceLen) {
            while (j < sentenceLen && sentence[j] != ' ') {
                j++;
            }
            inptTmp = sentence.substr(i, j - i);
            ouptTmp = longToShort(inptTmp);
            if (!ouptTmp.size()) {
                ans = ans + inptTmp;
            }
            else {
                ans = ans + ouptTmp;
            }
            ans.push_back(' ');
            j++;
            i = j;
        }
        
        ans.pop_back();
        return ans;
    }
private:
    struct node {
        char val;
        bool isEnd = false;
        node* next[26] = {nullptr};
    };
    node* rootNode;
    void pushIntoTrie(vector<string>& dictionary) {//���ӵ�ǰ׺��
        string tmpStr;
        int dictLen = dictionary.size();
        int i, j, tmpStrLen;
        node* cur,* tmpNode;
        char currentChar;
        for (j = 0; j < dictLen; j++) {
            cur = rootNode;
            tmpStr = dictionary[j];
            tmpStrLen = tmpStr.size();
            for (i = 0; i < tmpStrLen; i++) {
                currentChar = tmpStr[i];
                if (!cur->next[currentChar - 'a']) {
                    tmpNode = new node;
                    tmpNode->val = currentChar;
                    if (i == tmpStrLen - 1) {
                        tmpNode->isEnd = true;
                    }
                    cur->next[currentChar - 'a'] = tmpNode;
                    cur = tmpNode;
                }
                else {
                    cur = cur->next[currentChar - 'a'];
                    if (i == tmpStrLen - 1) {
                        cur->isEnd = true;
                    }
                }
            }
        }
        return;
    }
    string longToShort(string& str) {
        string ans;
        int strLen = str.size();
        node* cur = rootNode;
        char currentChar;
        int i;
        for (i = 0; i < strLen; i++) {
            currentChar = str[i];
            if (!cur->next[currentChar - 'a']) {
                string nullstr;
                return nullstr;
            }
            cur = cur->next[currentChar - 'a'];
            ans = ans + cur->val;
            if (cur->isEnd) {
                break;
            }
        }
        return ans;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        rootNode = new node;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        int wordLen = word.size();
        node* cur = rootNode;
        node* tmp;
        char currentChar;
        for (int i = 0; i < wordLen; i++) {
            currentChar = word[i];
            if (!cur->next[currentChar - 'a']) {
                tmp = new node;
                tmp->val = word[i];
                if (i == wordLen - 1) {
                    tmp->isEnd = true;
                }
                cur->next[currentChar - 'a'] = tmp;
                cur = tmp;
            }
            else {
                cur = cur->next[currentChar - 'a'];
                if (i == wordLen - 1) {
                    cur->isEnd = true;
                }
            }
        }
        return;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        bool status = findSub(rootNode, word);
        return status;
    }
private:
    struct node {
        char val;
        bool isEnd = false;
        node* next[26] = { nullptr };
    };
    node* rootNode;
    bool findSub(node* root, string& str) {
        int strLen = str.size();
        if (strLen == 0) {
            if (root->isEnd) {
                return true;
            }
            else {
                return false;
            }
        }
        char currentChar = str[0];
        string nextStr = str.substr(1);
        if (currentChar == '.') {
            bool status = false;
            for (int i = 0; i < 26; i++) {
                if (root->next[i]) {
                    status = status || findSub(root->next[i], nextStr);
                }
            }
            return status;
        }
        else if (root->next[currentChar - 'a']) {
            return findSub(root->next[currentChar - 'a'], nextStr);
        }
        else {
            return false;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


int main(int argc, char* argv[]) {
    //Solution mySolution;
    //string inpt = "the cattle was rattled by the battery";
    //vector<string> dict = { "cat","bat","rat" };
    //mySolution.replaceWords(dict, inpt);
    WordDictionary myWordDictionary;
    myWordDictionary.addWord("bad");
    myWordDictionary.addWord("dad");
    myWordDictionary.addWord("mad");
    myWordDictionary.search(".ad");
    return 0;
}

#endif


#if false

class Solution {
public:
    Solution() {
        rootNode = new node;
        return;
    }
    int findMaximumXOR(vector<int>& nums) {
        int numsLen = nums.size();
        for (int i = 0; i < numsLen; i++) {
            pushIntoBinaryTree(nums[i]);
        }
        node* cur, *curL, *curR;
        cur = rootNode;
        while (!cur->left || !cur->right) {
            if (cur->left) {
                cur = cur->left;
            }
            else if (cur->right) {
                cur = cur->right;
            }
            else {
                return 0;
            }
        }//�޼����ɣ�ֱ����һ���ֲ�
        curL = cur->left;
        curR = cur->right;
        unsigned int ans = 1;
        searchMax(curL, curR, ans);
        return ans;
    }
private:
    struct node {
        node* left = nullptr;//0
        node* right = nullptr;//1
    };
    node* rootNode;
    void pushIntoBinaryTree(unsigned int num) {
        node* cur = rootNode;
        for (int i = 0; i < 32; i++) {
            int tmp = num & 0x80000000;
            num = num << 1;
            if (tmp == 0) {
                if (!cur->left) {
                    cur->left = new node;
                }
                cur = cur->left;
            }
            else {
                if (!cur->right) {
                    cur->right = new node;
                }
                cur = cur->right;
            }
        }
        return;
    }
    void searchMax(node* curL, node* curR, unsigned int& ans) {
        if (!curL->left && !curL->right && !curR->left && !curR->right) {
            return;
        }
        int r1 = 0, r2 = 0, r3 = 0;
        int tmp = ans;
        //����Ҳ�����1
        if (curL->left && curR->right) {//01
            ans = ans << 1;
            ans++;
            searchMax(curL->left, curR->right, ans);
            r1 = ans;
            ans = tmp;
        }
        if (curL->right && curR->left) {//10
            ans = ans << 1;
            ans++;
            searchMax(curL->right, curR->left, ans);
            r2 = ans;
            ans = tmp;
        }
        //��������0
        if (!((curL->left && curR->right) || (curL->right && curR->left))) {//00
            if (curL->left && curR->left) {
                ans = ans << 1;
                searchMax(curL->left, curR->left, ans);
                r3 = ans;
                ans = tmp;
            }
            if (curL->right && curR->right) {//11
                ans = ans << 1;
                searchMax(curL->right, curR->right, ans);
            }
        }
        if (r1 > ans) {
            ans = r1;
        }
        if (r2 > ans) {
            ans = r2;
        }
        if (r3 > ans) {
            ans = r3;
        }
        return;
    }
};


int main(int argc, char* argv[]) {
    vector<int> nums = { 3, 10, 5, 25, 2, 8 };
    //vector<int> nums = { 2, 4 };
    Solution mySolution;
    int res = mySolution.findMaximumXOR(nums);
    return 0;
}

#endif


#if false

class Solution {
public:
    Solution() {
        rootNode = new node;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int wordsNum = words.size();
        colSize = board.size();
        rolSize = colSize ? board[0].size() : 0;
        if (colSize == 0 || rolSize == 0) {
            return ans;
        }
        for (int i = 0; i < wordsNum; i++) {
            pushIntoTrie(words[i]);
        }
        for (int i = 0; i < colSize; i++) {
            for (int j = 0; j < rolSize; j++) {
                dfs(board, rootNode, i, j);
            }
        }

        return ans;
    }
private:
    struct node {
        string word;
        bool isWord = false;
        node* next[26] = { nullptr };
    };
    node* rootNode;
    int colSize = 0;
    int rolSize = 0;
    vector<string> ans;
    void pushIntoTrie(string& str) {
        int strLen = str.size();
        node* cur = rootNode;
        int nextCur;
        for (int i = 0; i < strLen; i++) {
            nextCur = str[i] - 'a';
            if (!cur->next[nextCur]) {
                cur->next[nextCur] = new node;
            }
            cur = cur->next[nextCur];
        }
        cur->isWord = true;
        cur->word = str;
        return;
    }
    void dfs(vector<vector<char>>& board, node* root, int c, int r) {
        char currentChar = board[c][r];
        if (currentChar == '-' || root->next[currentChar - 'a'] == nullptr) {//���ʹ����߲������ӽڵ�
            return;
        }
        root = root->next[currentChar - 'a'];
        if (root->isWord) {
            ans.push_back(root->word);
            root->isWord = false;
        }
        board[c][r] = '-';//ͬһ�������ڲ����ظ�ʹ��
        if (c > 0) {
            dfs(board, root, c - 1, r);
        }
        if (r > 0) {
            dfs(board, root, c, r - 1);
        }
        if (c + 1 < colSize) {
            dfs(board, root, c + 1, r);
        }
        if (r + 1 < rolSize) {
            dfs(board, root, c, r + 1);
        }
        board[c][r] = currentChar;
        return;
    }
};

int main(int argc, char* argv[]) {
    Solution mySolution;
    string str1 = "cock";
    string str2 = "cocks";
    //mySolution.pushIntoTrie(str1);
    //mySolution.pushIntoTrie(str2);
    return 0;
}

#endif

#if false

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int wordsNum = words.size();
        int i, j;
        vector<vector<int>> res;
        vector<int> tmp = { 0, 0 };
        for (i = 0; i < wordsNum; i++) {
            for (j = 0; j < wordsNum; j++) {
                if (i == j) {
                    continue;
                }
                bool push = false;
                int iLen = words[i].size();
                int jLen = words[j].size();
                if (iLen == jLen) {
                    int iCur = 0;
                    int jCur = jLen - 1;
                    while (iCur < iLen) {
                        if (words[i][iCur] != words[j][jCur]) {
                            break;
                        }
                        iCur++;
                        jCur--;
                    }
                    if (iCur == iLen) {
                        push = true;
                    }
                }
                else if (iLen > jLen) {
                    int iCur = 0;
                    int jCur = jLen - 1;
                    while (jCur >= 0) {
                        if (words[i][iCur] != words[j][jCur]) {
                            break;
                        }
                        iCur++;
                        jCur--;
                    }
                    if (jCur < 0) {
                        jCur = iLen - 1;
                        while (iCur < jCur) {
                            if (words[i][iCur] != words[i][jCur]) {
                                break;
                            }
                            iCur++;
                            jCur--;
                        }
                        if (iCur >= jCur) {
                            push = true;
                        }
                    }
                }
                else {
                    int iCur = 0;
                    int jCur = jLen - 1;
                    while (iCur < iLen) {
                        if (words[i][iCur] != words[j][jCur]) {
                            break;
                        }
                        iCur++;
                        jCur--;
                    }
                    if (iCur == iLen) {
                        iCur = 0;
                        while (iCur < jCur) {
                            if (words[j][jCur] != words[j][iCur]) {
                                break;
                            }
                            iCur++;
                            jCur--;
                        }
                        if (jCur <= iCur) {
                            push = true;
                        }
                    }
                }
                if (push) {
                    tmp[0] = i;
                    tmp[1] = j;
                    res.emplace_back(tmp);
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<string> inpt = { "a","b","c","ab","ac","aa" };
    Solution mySolution;
    mySolution.palindromePairs(inpt);
    return 0;
}

#endif

//hash ��ϣ��
#if true

class MyHashSet {
public:
    struct node {
        node* left = 0;
        node* right = 0;
        int val = 0;
        bool isDeleted = false;
    };
    /** Initialize your data structure here. */
    MyHashSet() {
        rootNode = nullptr;
    }

    void add(int key) {
        rootNode = addToTree(rootNode, key);
    }

    void remove(int key) {
        deleteElement(rootNode, key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return quary(rootNode, key);
    }
private:
    node* rootNode;
    node* addToTree(node* currentNode, int val) {
        if (currentNode == nullptr) {
            currentNode = new node;
            currentNode->val = val;
            return currentNode;
        }
        int nodeVal = currentNode->val;
        if (val < nodeVal) {
            currentNode->left = addToTree(currentNode->left, val);
        }
        if (val > nodeVal) {
            currentNode->right = addToTree(currentNode->right, val);
        }
        if (val == nodeVal) {
            currentNode->isDeleted = false;
        }
        return currentNode;
    }
    bool quary(node* currentNode, int val) {
        if (currentNode == nullptr) {
            return false;
        }
        if (currentNode->val == val) {
            if (currentNode->isDeleted) {
                return false;
            }
            else {
                return true;
            }
        }
        if (val < currentNode->val) {
            return quary(currentNode->left, val);
        }
        else {
            return quary(currentNode->right, val);
        }
    }
    void deleteElement(node* currentNode, int val) {
        if (currentNode == nullptr) {
            return;
        }
        if (currentNode->val == val) {
            currentNode->isDeleted = true;
        }
        if (val < currentNode->val) {
            deleteElement(currentNode->left, val);
        }
        else {
            deleteElement(currentNode->right, val);
        }
    }
};

class MyHashMap {
public:
    struct node {
        node* left = 0;
        node* right = 0;
        int key = -1;
        int val = -1;
        bool isDeleted = false;
    };
    /** Initialize your data structure here. */
    MyHashMap() {
        rootNode = nullptr;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        rootNode = addToTree(rootNode, key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return getFromTree(rootNode, key);
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        removeFromTree(rootNode, key);
    }
private:
    node* rootNode;
    node* addToTree(node* currentNode, int key, int val) {
        if (currentNode == nullptr) {
            currentNode = new node;
            currentNode->key = key;
            currentNode->val = val;
            return currentNode;
        }
        int currentKey = currentNode->key;
        if (key < currentKey) {
            currentNode->left = addToTree(currentNode->left, key, val);
        }
        else if (key > currentKey) {
            currentNode->right = addToTree(currentNode->right, key, val);
        }
        else {
            currentNode->val = val;
            currentNode->isDeleted = false;
        }
        return currentNode;
    }
    int getFromTree(node* currentNode, int key) {
        if (currentNode == nullptr) {
            return -1;
        }
        int currentKey = currentNode->key;
        if (key < currentKey) {
            return getFromTree(currentNode->left, key);
        }
        else if (key > currentKey) {
            return getFromTree(currentNode->right, key);
        }
        else {
            if (currentNode->isDeleted) {
                return -1;
            }
            else {
                return currentNode->val;
            }
        }
    }
    void removeFromTree(node* currentNode, int key) {
        if (currentNode == nullptr) {
            return;
        }
        int currentKey = currentNode->key;
        if (key == currentKey) {
            currentNode->isDeleted = true;
        }
        else if (key < currentKey) {
            removeFromTree(currentNode->left, key);
        }
        else{
            removeFromTree(currentNode->right, key);
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(int argc, char* argv[]) {
    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    hashMap.get(1);
    hashMap.get(3);
    hashMap.put(2, 1);
    hashMap.get(2);
    hashMap.remove(2);
    hashMap.get(2);
    return 0;
}
#endif