#define NULL 0
#include <string>
#include <vector>
#include <queue>
#include<unordered_set>
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
