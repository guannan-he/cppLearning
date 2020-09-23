#define NULL 0
#include <string>
#include <vector>
#include <queue>
#include<unordered_set>
#include<unordered_map>
#include<stack>
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



//队列
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
        if (!colSize) {//无元素则返回
            return 0;
        }
        int rolSize = grid[0].size();
        int total = colSize * rolSize;
        char** visited = visitedGen(colSize, rolSize);
        char** gridCopy = gridCopyFunc(grid, colSize, rolSize);
        queue<vector<int>> q;//队列保存下标向量
        int cur = 0;//下标计数
        int c, r;//下标
        int cnt = 0;//陆地计数
        int queueSize;
        vector<int> pos;
        pos.push_back(c); pos.push_back(r);
        while (cur < total) {
            //未访问过的压入队列
            c = cur / rolSize;
            r = cur % rolSize;
            cur++;
            //获取下标
            if (visited[c][r] == '1') {
                continue;//访问过跳过
            }
            visited[c][r] = '1';//根节点标记为访问过
            if (gridCopy[c][r] == '0') {
                continue;//跳过陆地
            }
            pos[0] = c; pos[1] = r;//保存陆地下标
            q.push(pos);//压入根节点
            while (!q.empty()) {
                queueSize = q.size();
                while (queueSize) {
                    pos = q.front();//读取头节点
                    c = pos[0]; r = pos[1];
                    if (c > 0 && visited[c - 1][r] == '0') {//上方节点
                        visited[c - 1][r] = '1';
                        if (gridCopy[c - 1][r] == '1') {
                            pos[0] = c - 1;
                            pos[1] = r;
                            q.push(pos);
                        }
                    }
                    if (r < rolSize - 1 && visited[c][r + 1] == '0') {//右方节点
                        visited[c][r + 1] = '1';
                        if (gridCopy[c][r + 1] == '1') {
                            pos[0] = c;
                            pos[1] = r + 1;
                            q.push(pos);
                        }
                    }
                    if (c < colSize - 1 && visited[c + 1][r] == '0') {//下方节点
                        visited[c + 1][r] = '1';
                        if (gridCopy[c + 1][r] == '1') {
                            pos[0] = c + 1;
                            pos[1] = r;
                            q.push(pos);
                        }
                    }
                    if (r > 0 && visited[c][r - 1] == '0') {//左方节点
                        visited[c][r - 1] = '1';
                        if (gridCopy[c][r - 1] == '1') {
                            pos[0] = c;
                            pos[1] = r - 1;
                            q.push(pos);
                        }
                    }

                    q.pop();//弹出头节点
                    queueSize--;
                }
            }
            cnt++;
        }
        visitedDelete(visited, colSize);
        visitedDelete(gridCopy, colSize);
        return cnt;
    }
    char** visitedGen(int colSize, int rolSize) {//生成访问标记矩阵
        char** visited = new char* [colSize];
        for (int i = 0; i < colSize; i++) {
            visited[i] = new char[rolSize];
        }
        for (int i = 0; i < colSize; i++) {
            for (int j = 0; j < rolSize; j++) {
                visited[i][j] = '0';//标记为为访问
            }
        }
        return visited;
    }
    void visitedDelete(char** visited, int colSize) {//删除标记矩阵
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
        q.push(current);//压入根节点
        vist.emplace(current);
        while (!q.empty()) {//队列里还有元素
            int queueLen = q.size();
            while (queueLen) {//出队列入队列
                current = q.front();
                if (vist.count(current)) {
                    return -1;//不该出现的出现了
                }
                if (current == target) {
                    return totalCnt;//找到目标
                }
                //要修改，分为两个方向，现在会数量几何增长
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
            while (qLen) {//出队列入队列
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



//栈
#if 0
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int colSize = matrix.size();
        if (!colSize) {//无元素则返回
            return matrix;
        }
        int rolSize = matrix[0].size();
        
        //可释放变量
        char** visited = visitedGen(colSize, rolSize);//访问标记
        queue<pair<int, int>>* q = new queue<pair<int, int>>;//下标队列

        //将所有零纳入到当问过数组中
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

        //后处理，释放
        visitedDelete(visited, colSize);
        delete q;
        return matrix;
    }
    char** visitedGen(int colSize, int rolSize) {//生成访问标记矩阵
        char** visited = new char* [colSize];
        for (int i = 0; i < colSize; i++) {
            visited[i] = new char[rolSize];
        }
        for (int i = 0; i < colSize; i++) {
            for (int j = 0; j < rolSize; j++) {
                visited[i][j] = '0';//标记为为访问
            }
        }
        return visited;
    }
    void visitedDelete(char** visited, int colSize) {//删除标记矩阵
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