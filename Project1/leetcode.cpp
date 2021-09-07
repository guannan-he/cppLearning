#define NULL 0
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <math.h>
#include <stack>
#include <list>
#include <iostream>
#include <set>
#include <numeric>
#include <algorithm>
#include <sstream>
using namespace std;

//链表
#if 0
 //Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
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
		for (c = 0; c < colSize; c++) {
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

//二叉树
#if 0



struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
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

//二叉搜索树
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
	treeNode* addToTree(treeNode* root, int val) {//递归二叉搜索树向添加
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
	int getThLarge() {//返回第几大的元素
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
	vector<int> nums = { 0 };
	KthLargest kthLargest(val, nums);
	kthLargest.add(-1);
	kthLargest.add(1);
	kthLargest.add(-2);
	kthLargest.add(-4);
	kthLargest.add(3);
	return 0;
}

#endif

//前缀树Trie
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
		node* next[26] = { nullptr };
	};
	node* rootNode;
	void pushIntoTrie(vector<string>& dictionary) {//添加到前缀树
		string tmpStr;
		int dictLen = dictionary.size();
		int i, j, tmpStrLen;
		node* cur, * tmpNode;
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
		node* cur, * curL, * curR;
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
		}//修剪主干，直到第一个分岔
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
		//异或右侧添加1
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
		//否则添加0
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
		if (currentChar == '-' || root->next[currentChar - 'a'] == nullptr) {//访问过或者不存在子节点
			return;
		}
		root = root->next[currentChar - 'a'];
		if (root->isWord) {
			ans.push_back(root->word);
			root->isWord = false;
		}
		board[c][r] = '-';//同一个单词内不能重复使用
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

//hash 哈希表
#if false

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
		else {
			removeFromTree(currentNode->right, key);
		}
		return;
	}
};

//class Solution { //重复数
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        unordered_set<int> hashSet;
//        for (auto num : nums) {
//            if (hashSet.count(num) > 0) {
//                return true;
//            }
//            hashSet.insert(num);
//        }
//        return false;
//    }
//};

//class Solution { //单一数
//public:
//    int singleNumber(vector<int>& nums) {
//        unordered_set<int> hashSet;
//        for (auto num : nums) {
//            if (hashSet.count(num) > 0) {
//                hashSet.erase(num);
//                continue;
//            }
//            hashSet.emplace(num);
//        }
//        return *(hashSet.begin());
//    }
//};

//class Solution { //快乐数
//public:
//    bool isHappy(int n) {
//        string tmp;
//        unordered_set<string> history;
//        while (true) {
//            tmp.clear();
//            while (n != 0) {
//                tmp.push_back(n % 10);
//                n /= 10;
//            }
//            for (auto bit : tmp) {
//                n += bit * bit;
//            }
//            if (n == 1) {
//                return true;
//            }
//            if (history.count(tmp) > 0) {
//                return false;
//            }
//            history.insert(tmp);
//        }
//    }
//};

//class Solution { //两数之和
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int, int> numsMap;
//        vector<int> res;
//        for (int i = 0; i < nums.size(); i++) {
//            if (numsMap.count(target - nums[i]) > 0) {
//                res.push_back(i);
//                res.push_back(numsMap[target - nums[i]]);
//                return res;
//            }
//            numsMap.emplace(make_pair(nums[i], i));
//        }
//        return res;
//    }
//};

//class Solution {  //判断字符串结构(abb, cdd)
//public:
//    bool isIsomorphic(string s, string t) {
//        unordered_map<char, int> str1Map, str2Map;
//        vector<int> str1Key, str2Key;
//        for (int i = 0; i < s.size(); i++) {
//            if (str1Map.count(s[i]) > 0) {
//                str1Key.emplace_back(str1Map[s[i]]);
//            }
//            else {
//                str1Map.emplace(make_pair(s[i], i));
//                str1Key.emplace_back(i);
//            }
//            if (str2Map.count(t[i]) > 0) {
//                str2Key.emplace_back(str2Map[t[i]]);
//            }
//            else {
//                str2Map.emplace(make_pair(t[i], i));
//                str2Key.emplace_back(i);
//            }
//        }
//        return str1Key == str2Key;
//    }
//};

//class Solution { //最小索引和
//public:
//    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
//        vector<string> res;
//        int lsit1Len = list1.size();
//        int lsit2Len = list2.size();
//        int total = 32767;
//        int tmp = 0;
//        unordered_map<string, int> list1Map, resultMap;
//        for (int i = 0; i < lsit1Len; i++) {  //压入hash图
//            list1Map.emplace(make_pair(list1[i], i));
//        }
//        for (int i = 0; i < lsit2Len; i++) {  //求最小索引和,并把符合要求的压入hash图
//            if (list1Map.count(list2[i]) > 0) {
//                tmp = list1Map[list2[i]] + i;
//                total = (tmp < total) ? tmp : total;
//                resultMap.emplace(make_pair(list2[i], tmp));
//            }
//        }
//        for (auto resItem : resultMap) {
//            if (resItem.second == total) {
//                res.push_back(resItem.first);
//            }
//        }
//
//        return res;
//    }
//};

//class Solution {
//public:
//    int firstUniqChar(string s) {
//        int res = 32768;
//        int sLen = s.size();
//        unordered_map<char, int> content;
//        for (int i = 0; i < sLen; i++) {
//            if (content.count(s[i]) < 1) {
//                content[s[i]] = 1;
//                continue;
//            }
//            content[s[i]] += 1;
//        }
//        for (auto contentItem : content) {
//            res = contentItem.second < res ? contentItem.second : res;
//        }
//        if (res != 1) {
//            return -1;
//        }
//        for (int i = 0; i < sLen; i++) {
//            if (content[s[i]] == 1) {
//                return i;
//            }
//        }
//        return -1;
//    }
//};

//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        vector<vector<string>> res;
//        vector<string> tmp;
//        unordered_map<string, vector<string>> strsMap;
//        string strCopy;
//        for (auto str : strs) {
//            strCopy = sortString(str);
//            if (strsMap.count(strCopy) < 1) {
//                strsMap[strCopy] = tmp;
//            }
//            strsMap[strCopy].emplace_back(str);
//        }
//        for (auto it = strsMap.begin(); it != strsMap.end(); it++) {
//            res.emplace_back((*it).second);
//        }
//        return res;
//    }
//private:
//    string sortString(string s) {
//        sort(s.begin(), s.end());
//        return s;
//    }
//};

//class Solution { //不重复字符字串
//public:
//    int lengthOfLongestSubstring(string s) {
//        int sLen = s.size();
//        char currentChar;
//        int setSize;
//        int maxLen = 0;
//        unordered_set<char> charSet;
//        int cur = 0; //字符串开始地方
//        for (int i = 0; i < sLen; i++) {
//            currentChar = s[i];
//            if (charSet.count(currentChar) < 1) {
//                charSet.emplace(currentChar);
//                continue;
//            }
//            setSize = charSet.size();
//            maxLen = setSize > maxLen ? setSize : maxLen;
//            while (cur < sLen && s[cur] != currentChar) {
//                charSet.erase(s[cur]);
//                cur++;
//            }
//            if (s[cur] == currentChar) {
//                cur++;
//                continue;
//            }
//            charSet.emplace(currentChar);
//        }
//        setSize = charSet.size();
//        maxLen = setSize > maxLen ? setSize : maxLen;
//        return maxLen;
//    }
//};

class Solution {//前k个高频词
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> numsMap;
		unordered_map<int, vector<int>> freqMap;
		int maxFreq = 0;
		vector<int> res(k);
		for (auto num : nums) {
			numsMap[num]++;
		}
		for (auto it = numsMap.begin(); it != numsMap.end(); it++) {
			freqMap[(*it).second].emplace_back((*it).first);
			maxFreq = (*it).second > maxFreq ? (*it).second : maxFreq;
		}
		while (k > 0) {
			if (freqMap.count(maxFreq)) {
				int len = freqMap[maxFreq].size() - 1;
				while (len > -1) {
					res[k - 1] = freqMap[maxFreq][len];
					k--;
					len--;
				}
			}
			maxFreq--;
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	vector<int> input = { 1, 2 };
	mySolution.topKFrequent(input, 2);
	return 0;
}
#endif

//图解数据结构
#if false

//字符串替换

//class Solution {
//public:
//    string replaceSpace(string s) {
//        int slowCur = 0, fastCur = 0;
//        int sLen = s.size();
//        string res;
//        while (fastCur < sLen) {
//            while (fastCur < sLen && s[fastCur] != ' ') {
//                fastCur++;
//            }
//            res += s.substr(slowCur, fastCur - slowCur);
//            if (s[fastCur] == ' ') {
//                res += +"%20";
//            }
//            fastCur++;
//            slowCur = fastCur;
//        }
//        return res;
//    }
//};

//有限状态自动机

//class Solution {//判断数字是否合法， 确定有限状态自动机
//public:
//    bool isNumber(string s) {
//        int len = s.length();
//        State st = STATE_INITIAL;
//        for (int i = 0; i < len; i++) {
//            CharType typ = toCharType(s[i]);
//            if (transfer[st].find(typ) == transfer[st].end()) {
//                return false;
//            }
//            else {
//                st = transfer[st][typ];
//            }
//        }
//        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
//    }
//private:
//    enum State {
//        STATE_INITIAL,
//        STATE_INT_SIGN,
//        STATE_INTEGER,
//        STATE_POINT,
//        STATE_POINT_WITHOUT_INT,
//        STATE_FRACTION,
//        STATE_EXP,
//        STATE_EXP_SIGN,
//        STATE_EXP_NUMBER,
//        STATE_END,
//    };
//
//    enum CharType {
//        CHAR_NUMBER,
//        CHAR_EXP,
//        CHAR_POINT,
//        CHAR_SIGN,
//        CHAR_SPACE,
//        CHAR_ILLEGAL,
//    };
//
//    unordered_map<State, unordered_map<CharType, State>> transfer{
//            {
//                STATE_INITIAL, {
//                    {CHAR_SPACE, STATE_INITIAL},
//                    {CHAR_NUMBER, STATE_INTEGER},
//                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
//                    {CHAR_SIGN, STATE_INT_SIGN},
//                }
//            }, {
//                STATE_INT_SIGN, {
//                    {CHAR_NUMBER, STATE_INTEGER},
//                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
//                }
//            }, {
//                STATE_INTEGER, {
//                    {CHAR_NUMBER, STATE_INTEGER},
//                    {CHAR_EXP, STATE_EXP},
//                    {CHAR_POINT, STATE_POINT},
//                    {CHAR_SPACE, STATE_END},
//                }
//            }, {
//                STATE_POINT, {
//                    {CHAR_NUMBER, STATE_FRACTION},
//                    {CHAR_EXP, STATE_EXP},
//                    {CHAR_SPACE, STATE_END},
//                }
//            }, {
//                STATE_POINT_WITHOUT_INT, {
//                    {CHAR_NUMBER, STATE_FRACTION},
//                }
//            }, {
//                STATE_FRACTION,
//                {
//                    {CHAR_NUMBER, STATE_FRACTION},
//                    {CHAR_EXP, STATE_EXP},
//                    {CHAR_SPACE, STATE_END},
//                }
//            }, {
//                STATE_EXP,
//                {
//                    {CHAR_NUMBER, STATE_EXP_NUMBER},
//                    {CHAR_SIGN, STATE_EXP_SIGN},
//                }
//            }, {
//                STATE_EXP_SIGN, {
//                    {CHAR_NUMBER, STATE_EXP_NUMBER},
//                }
//            }, {
//                STATE_EXP_NUMBER, {
//                    {CHAR_NUMBER, STATE_EXP_NUMBER},
//                    {CHAR_SPACE, STATE_END},
//                }
//            }, {
//                STATE_END, {
//                    {CHAR_SPACE, STATE_END},
//                }
//            }
//    };
//
//    CharType toCharType(char ch) {
//        if (ch >= '0' && ch <= '9') {
//            return CHAR_NUMBER;
//        }
//        else if (ch == 'e' || ch == 'E') {
//            return CHAR_EXP;
//        }
//        else if (ch == '.') {
//            return CHAR_POINT;
//        }
//        else if (ch == '+' || ch == '-') {
//            return CHAR_SIGN;
//        }
//        else if (ch == ' ') {
//            return CHAR_SPACE;
//        }
//        else {
//            return CHAR_ILLEGAL;
//        }
//    }
//};


class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		return;
	}

	void push(int x) {
		if (x < minVal) {
			minVal = x;
			minHist.push(minVal);
		}
		data.push(x);
		return;
	}

	void pop() {
		if (minHist.top() == data.top()) {
			minHist.pop();
			minVal = minHist.top();
		}
		data.pop();
		return;
	}

	int top() {
		return data.top();
	}

	int min() {
		return minVal;
	}
private:
	stack<int> data, minHist;
	int minVal = 2147483647;
};

class Solution {
public:
	int strToInt(string str) {
		int strLen = str.size();
		int cur = 0;
		while (str[cur] == ' ') {
			cur++;
		}
		bool neg = false;
		if (str[cur] == '+') {
			cur++;
		}
		else if (str[cur] == '-') {
			neg = true;
			cur++;
		}
		while (str[cur] == '0') {
			cur++;
		}
		int lim = cur + 8;
		long res = 0;
		while (cur < strLen) {
			char currentChar = str[cur];
			if (currentChar > '9' || currentChar < '0') {
				break;
			}
			currentChar -= '0';
			if (cur > lim) {
				if (res > 214748364) {
					if (neg) {
						return -2147483648;
					}
					else {
						return 2147483647;
					}
				}
				else if (res == 214748364) {
					if (neg && currentChar > 8) {
						return -2147483648;
					}
					if (!neg && currentChar > 7) {
						return 2147483647;
					}
				}
			}
			res = res * 10 + currentChar;
			cur++;
		}
		if (neg && res > 0) {
			res *= -1;
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution mySoltuion;
	mySoltuion.strToInt("2147483648");
	return 0;
}

#endif

//初级算法
#if false
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {//去除重复
		int numsLen = nums.size();
		if (numsLen < 2) {
			return numsLen;
		}
		sort(nums.begin(), nums.end());
		int slowCur = 0, fastCur = 1;
		while (fastCur < numsLen) {
			if (nums[slowCur] != nums[fastCur]) {
				slowCur++;
				nums[slowCur] = nums[fastCur];
			}
		}
		return slowCur + 1;
	}
	int maxProfit(vector<int>& prices) {//股票交易
		size_t priceLen = prices.size();
		int res = 0;
		for (size_t cur = 0; cur < priceLen - 1; cur++) {
			if (prices[cur + 1] > prices[cur]) {
				res += prices[cur + 1] - prices[cur];
			}
		}
		return res;
	}
	void rotate(vector<int>& nums, int k) {//旋转数组
		size_t numsLen = nums.size();
		k = k % numsLen;
		vector <int> tmp1(nums.end() - k, nums.end());
		vector <int> tmp2(nums.begin(), nums.end() - k);
		tmp1.insert(tmp1.end(), tmp2.begin(), tmp2.end());
		nums = tmp1;
		return;
	}
	vector<int> plusOne(vector<int>& digits) {
		size_t digitLen = digits.size();
		int aux = 1;
		vector<int> res(digits.begin(), digits.end());
		for (int i = digitLen - 1; i > -1; i--) {
			res[i] += aux;
			aux = 0;
			if (res[i] > 9) {
				res[i] %= 10;
				aux = 1;
			}
		}
		if (aux == 1) {
			vector<int> tmp = { 1 };
			res.insert(res.begin(), tmp.begin(), tmp.end());
		}
		return res;
	}
	int reverse(int x) {
		int res = 0;
		bool isNeg = false;
		if (x < 0) {
			isNeg = true;
			if (x == -2147483648) {
				return 0;
			}
			x = 0 - x;
		}
		int tmp = 0;
		while (x != 0) {
			tmp = x % 10;
			if (res > 214748364) {
				return 0;
			}
			else if (res == 214748364) {
				if (isNeg) {
					if (tmp > 7) {
						return 0;
					}
				}
				else if (tmp > 8) {
					return 0;
				}
			}
			x /= 10;
			res = res * 10 + tmp;
		}
		if (isNeg) {
			res = -res;
		}
		return res;
	}
	bool isPalindrome(string s) {
		int sLen = s.size();
		int frontCur = 0, rearCur = sLen - 1;
		while (frontCur < rearCur) {
			char front = s[frontCur], rear = s[rearCur];
			if (!isalnum(front)) {
				frontCur++;
				continue;
			}
			if (!isalnum(rear)) {
				rearCur--;
				continue;
			}
			front = isupper(front) ? front + 32 : front;
			rear = isupper(rear) ? rear + 32 : rear;
			if (front != rear) {
				return false;
			}
			frontCur++;
			rearCur--;
		}
		return true;
	}
	int myAtoi(string s) {
		int sLen = s.size();
		int cur = 0;
		while (cur < sLen && s[cur] == ' ') {
			cur++;
		}
		bool isNeg = false;
		if (s[cur] == '-') {
			isNeg = true;
			cur++;
		}
		else if (s[cur] == '+') {
			cur++;
		}
		if (s[cur] > '9' || s[cur] < '0') {
			return 0;
		}
		int res = 0;
		while (cur < sLen) {
			char tmp = s[cur];
			if (tmp > '9' || tmp < '0') {
				break;
			}
			tmp -= '0';
			if (res > 214748364) {
				if (isNeg) {
					return -2147483648;
				}
				return 2147483647;
			}
			if (res == 214748364) {
				if (isNeg) {
					if (tmp > 7) {
						return -2147483648;
					}
				}
				if (!isNeg) {
					if (tmp > 7) {
						return 2147483647;
					}
				}
			}
			res = res * 10 + tmp;
			cur++;
		}
		if (isNeg) {
			res *= -1;
		}
		return res;
	}
	int strStr(string haystack, string needle) {
		int needleLen = needle.size();
		if (needleLen == 0) {
			return 0;
		}
		int hayLen = haystack.size();
		vector<int>* next = getNext(haystack);
		int hCur = 0, nCur = 0;
		while (hCur < hayLen && nCur < needleLen) {
			if (nCur == -1 || haystack[hCur] == needle[nCur]) {
				hCur++;
				nCur++;
			}
			else {
				nCur = (*next)[nCur];
			}
		}
		if (nCur == needleLen) {
			return hCur - nCur;
		}
		return -1;
	}
	vector<int>* getNext(string s) {
		int sLen = s.size();
		vector<int>* next = new vector<int>(sLen);
		(*next)[0] = -1;
		int pos = 0, cnt = -1;
		while (pos < sLen - 1) {
			if (cnt == -1 || s[pos] == s[cnt]) {
				cnt++;
				pos++;
				(*next)[pos] = cnt;
			}
			else {
				cnt = (*next)[cnt];//回到-1
			}
		}
		return next;
	}
	string countAndSay(int n) {
		string res = "1";
		while (n > 1) {
			res = describeStr(res);
			n--;
		}
		return res;
	}
	string describeStr(string str) {
		string res;
		int strLen = str.size();
		int slowCur = 0, fastCur = 0;
		while (fastCur < strLen) {
			if (str[fastCur] == str[slowCur]) {
				fastCur++;
				continue;
			}
			res.push_back(fastCur - slowCur + '0');
			res.push_back(str[slowCur]);
			slowCur = fastCur;
			fastCur++;
		}
		res.push_back(fastCur - slowCur + '0');
		res.push_back(str[slowCur]);
		return res;
	}
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		stack<int> resStack;
		size_t cur1 = 0, cur2 = 0;
		int tmp = 0;
		while (cur1 < m && cur2 < n) {
			if (nums1[cur1] < nums2[cur2]) {
				tmp = nums1[cur1];
				cur1++;
			}
			else {
				tmp = nums2[cur2];
				cur2++;
			}
			resStack.push(tmp);
		}
		while (cur1 < m) {
			tmp = nums1[cur1];
			resStack.push(tmp);
			cur1++;
		}
		while (cur2 < n) {
			tmp = nums2[cur2];
			resStack.push(tmp);
			cur2++;
		}
		for (int i = n + m - 1; i > -1; i--) {
			nums1[i] = resStack.top();
			resStack.pop();
		}
		return;
	}
};

int main(int argc, char* argv[]) {
	vector<int> nums1 = { 1 }, nums2;
	Solution mySolution;
	mySolution.merge(nums1, 1, nums2, 0);
	return 0;
}
#endif

//初级算法-动态规划
#if fasle

class Solution {
public:
	int climbStairs(int n) {//爬楼梯
		if (n < 4) {
			return n;
		}
		int n_2 = 1, n_1 = 2;
		int current = 3, tmp = 0;
		for (int i = 3; i < n; i++) {
			tmp = current + n_1;
			n_1 = current;
			n_2 = n_1;
			current = tmp;
		}
		return current;
	}
	int maxSubArray(vector<int>& nums) {//返回最大子数组之和
		int numsLen = nums.size();
		if (numsLen == 0) {
			return 0;
		}
		if (numsLen == 1) {
			return nums[0];
		}
		int pre = nums[0];
		int maxVal = pre;
		for (size_t i = 1; i < numsLen; i++) {
			pre = max(pre + nums[i], nums[i]);//前面元素对数列起到负作用
			maxVal = pre > maxVal ? pre : maxVal;
		}
		return maxVal;
	}
	int rob(vector<int>& nums) { //打家劫舍
		size_t numsLen = nums.size();
		switch (numsLen) {
		case 0:
			return 0;
		case 1:
			return nums[0];
		case 2:
			return max(nums[0], nums[1]);
		default:
			break;
		}
		//偷或不偷
		int n_1 = nums[1];
		int n_2 = nums[0];
		int tmp = 0;
		for (size_t i = 2; i < numsLen; i++) {
			tmp = n_1 > n_2 ? n_1 : n_2;
			n_1 = nums[i] + n_2;
			n_2 = tmp;
		}
		return n_1 > n_2 ? n_1 : n_2;
	}
};

int main(int argc, char* argv[]) {
	vector<int> nums = { 2, 1, 1, 2 };
	Solution mySolution;
	mySolution.rob(nums);
	return 0;
}
#endif

//初级算法-设计问题
#if false

class Solution {
public:
	Solution(vector<int>& nums) {
		org = new vector<int>(nums);
		numsLen = nums.size();
		return;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return *org;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> res(numsLen, -1);
		for (size_t i = numsLen; i > 0; i--) {
			size_t cur = rand() % (numsLen);
			while (res[cur] != -1) {
				cur = rand() % (numsLen);
			}
			res[cur] = (*org)[i - 1];
		}
		return res;
	}
private:
	vector<int>* org;
	size_t numsLen;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main(int argc, char* argv[]) {
	vector<int> inpt = { 1, 2, 3 };
	Solution mySolution(inpt);
	mySolution.reset();
	mySolution.shuffle();
	return 0;
}
#endif

//初级算法-其他
#if false

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> bitMap(n, true);
		int res = 0;
		for (size_t i = 2; i < n; i++) {
			if (bitMap[i]) {
				res++;
				for (size_t cur = i + i; cur < n; cur += i) {
					bitMap[cur] = false;
				}
			}
		}
		return res;
	}
	bool isPowerOfThree(int n) {
		if (n < 1) {
			return false;
		}
		while (n != 0) {
			if (n % 3 != 0 && n != 1) {
				return false;
			}
			n /= 3;
		}
		return true;
	}
	//转罗马数字
	//有限状态机解法
	//FSM
	enum type { TYPE_I, TYPE_V, TYPE_X, TYPE_L, TYPE_C, TYPE_D, TYPE_M };
	enum state {
		STA_START = 0,
		STA_1 = 1, STA_5 = 5, STA_10 = 10, STA_50 = 50, STA_100 = 100, STA_500 = 500, STA_1000 = 1000,
		STA_4 = 4, STA_9 = 9,
		STA_40 = 40, STA_90 = 90,
		STA_400 = 400, STA_900 = 900
	};
	unordered_map<state, unordered_map<type, state>> transfer = {
		{
			STA_START, {
				{TYPE_I, STA_1},
				{TYPE_V, STA_5},
				{TYPE_X, STA_10},
				{TYPE_L, STA_50},
				{TYPE_C, STA_100},
				{TYPE_D, STA_500},
				{TYPE_M, STA_1000}
			}
		},
		{
			STA_1, {
				{TYPE_V, STA_4},
				{TYPE_X, STA_9}
			}
		},
		{
			STA_10, {
				{TYPE_L, STA_40},
				{TYPE_C, STA_90}
			}
		},
		{
			STA_100, {
				{TYPE_D, STA_400},
				{TYPE_M, STA_900}
			}
		}
	};
	unordered_map<char, type> getType = {
		{'I', TYPE_I},
		{'V', TYPE_V},
		{'X', TYPE_X},
		{'L', TYPE_L},
		{'C', TYPE_C},
		{'D', TYPE_D},
		{'M', TYPE_M}
	};
	int romanToInt(string s) {
		int numsLen = s.size();
		int res = 0, tmp = 0;
		state currentState = STA_START;
		type currentType;
		for (int i = 0; i < numsLen; i++) {
			currentType = getType[s[i]];
			if (transfer[currentState][currentType] < 1) {
				currentState = STA_START;
				res += tmp;
				tmp = 0;
			}
			currentState = transfer[currentState][currentType];
			tmp = currentState;
		}
		res += tmp;
		return res;
	}
	bool isValid(string s) {
		int sLen = s.size();
		stack<char> columStack;
		for (int i = 0; i < sLen; i++) {
			char tmp = s[i];
			if (tmp == '{' || tmp == '[' || tmp == '(') {
				columStack.push(tmp);
				continue;
			}
			if (tmp == '}' || tmp == ']' || tmp == ')') {
				if (columStack.empty()) {
					return false;
				}
				char stackTopDiff = tmp - columStack.top();
				if (stackTopDiff == 1 || stackTopDiff == 2) {
					columStack.pop();
					continue;
				}
				return false;
			}
		}
		if (!columStack.empty()) {
			return false;
		}
		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	mySolution.isValid("()");
	return 0;
}
#endif

//数组类算法
#if false

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {//去除重复项2
		size_t numsLen = nums.size(), slowCur = 0, fastCur = 1;
		if (numsLen < 2) {
			return numsLen;
		}
		while (fastCur < numsLen) {
			if (nums[slowCur] == nums[fastCur]) {
				if (slowCur > 0 && nums[slowCur - 1] == nums[fastCur]) {
					fastCur++;
					continue;
				}
			}
			slowCur++;
			nums[slowCur] = nums[fastCur];
			fastCur++;
		}
		return slowCur + 1;
	}
	void quickSort(vector<int>& inptArray, size_t left, size_t right) {//递归快速排列
		if (left < right) {
			size_t mid = partition(inptArray, left, right);
			if (mid > 1) {
				quickSort(inptArray, left, mid - 1);
			}
			quickSort(inptArray, mid + 1, right);
		}
		return;
	}
	size_t partition(vector<int>& inptArray, size_t left, size_t right) {
		int pivot = inptArray[left];
		size_t i = left + 1, j = right;
		while (i < j) {
			if (inptArray[i] <= pivot) {//找左面第一个大于锚点的坐标
				i++;
				continue;
			}
			if (inptArray[j] >= pivot) {//找右面第一个小于锚点的坐标
				j--;
				continue;
			}
			//交换
			int tmp = inptArray[i];
			inptArray[i] = inptArray[j];
			inptArray[j] = tmp;
		}
		j--;
		inptArray[left] = inptArray[j];
		inptArray[j] = pivot;
		return j;
	}
	int maxArea(vector<int>& height) {//最大容量
		size_t heightLen = height.size(), frontCur = 0, rearCur = heightLen - 1;
		int res = 0, tmpArea;
		while (frontCur < rearCur) {
			tmpArea = (rearCur - frontCur) * min(height[frontCur], height[rearCur]);
			res = tmpArea > res ? tmpArea : res;
			if (height[frontCur] < height[rearCur]) {
				frontCur++;
			}
			else {
				rearCur--;
			}
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	vector<int> inpt = { 1,8,6,2,5,4,8,3,7 };
	vector<int> inptSort = { 8, 4, 6, 3, 5, 234, 456, 3, 45, 645, 75, 678, 857 };
	//mySolution.quickSort(inptSort, 0, inptSort.size() - 1);
	//mySolution.removeDuplicates(inpt);
	//priority_queue<int> inptHeap;
	mySolution.maxArea(inpt);
	return 0;
}
#endif

//查找表类算法
#if false

class Solution {
public:
	string frequencySort(string s) {//根据字符出现频率排序
		string res;
		int sLen = s.size();
		unordered_map<char, int> freqCnt;
		unordered_map<int, vector<char>> freqMap;
		priority_queue<int> freqHeap;
		vector<char> tmp;
		for (int i = 0; i < sLen; i++) {
			freqCnt[s[i]]++;
		}
		for (auto it = freqCnt.begin(); it != freqCnt.end(); it++) {
			if (freqMap.count(it->second) < 1) {
				freqMap.emplace(make_pair(it->second, tmp));
			}
			freqMap[it->second].emplace_back(it->first);
			freqHeap.push(it->second);
		}
		while (!freqHeap.empty()) {
			int cnt = freqHeap.top();
			char toAdd = freqMap[cnt].back();
			freqMap[cnt].pop_back();
			freqHeap.pop();
			while (cnt) {
				res.push_back(toAdd);
				cnt--;
			}
		}
		return res;
	}
	vector<vector<int>> threeSum(vector<int>& nums) {
		size_t numsLen = nums.size();
		vector<vector<int>> res;
		vector<int> tmp(3);
		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < numsLen; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {//排序过后，所以能确保枚举不同
				continue;
			}
			size_t k = numsLen - 1;
			for (size_t j = i + 1; j < numsLen; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}
				while (k > j && nums[i] + nums[j] + nums[k] > 0) {
					k--;
				}
				if (j == k) {
					break;
				}
				if (nums[i] + nums[j] + nums[k] == 0) {
					tmp[0] = nums[i]; tmp[1] = nums[j]; tmp[2] = nums[k];
					res.emplace_back(tmp);
				}
			}
		}
		return res;
	}
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		size_t numsLen = nums.size();
		if (numsLen < 4) {
			return res;
		}
		sort(nums.begin(), nums.end());
		int sum;
		for (size_t i = 0; i < numsLen - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			//适当的剪枝操作使得运行事件从~120ms降到~16ms
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {//剪枝
				break;
			}
			if (nums[i] + nums[numsLen - 1] + nums[numsLen - 2] + nums[numsLen - 3] < target) {//剪枝
				continue;
			}
			for (size_t j = i + 1; j < numsLen - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {//剪枝
					break;
				}
				if (nums[i] + nums[j] + nums[numsLen - 1] + nums[numsLen - 2] < target) {//剪枝
					continue;
				}
				size_t l = numsLen - 1;
				size_t k = j + 1;
				while (k < l) {
					if (l < numsLen - 1 && nums[l] == nums[l + 1]) {
						l--;
						continue;
					}
					if (k > j + 1 && nums[k] == nums[k - 1]) {
						k++;
						continue;
					}
					sum = nums[i] + nums[j] + nums[k] + nums[l];
					if (sum > target) {
						l--;
						continue;
					}
					if (sum < target) {
						k++;
						continue;
					}
					res.push_back({ nums[i], nums[j], nums[k], nums[l] });
					l--;
				}
			}
		}
		return res;
	}
	int numberOfBoomerangs(vector<vector<int>>& points) {
		size_t pointLen = points.size();
		unordered_map<int, int> dist;
		int res = 0;
		vector<vector<int>> distMap(pointLen, vector<int>(pointLen));
		for (size_t i = 0; i < pointLen; i++) {
			dist.clear();
			for (size_t j = 0; j < pointLen; j++) {
				if (j == i) {
					continue;
				}
				if (j > i) {
					int distance = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
					distMap[i][j] = distance;
					distMap[j][i] = distMap[i][j];
				}
				dist[distMap[i][j]]++;
			}
			for (auto it = dist.begin(); it != dist.end(); it++) {
				int cnt = (*it).second;
				res += cnt * (cnt - 1);
			}
		}
		return res;
	}
	int maxPoints(vector<vector<int>>& points) {//最多点在线上
		size_t pointLen = points.size();
		int res = 0;
		if (pointLen < 3) {
			return pointLen;
		}
		unordered_map<string, unordered_set<int>> lineMap;
		for (size_t i = 0; i < pointLen; i++) {
			for (size_t j = i + 1; j < pointLen; j++) {
				string* cur = getID(points[i], points[j]);
				lineMap[*cur].emplace(i);
				lineMap[*cur].emplace(j);
			}
		}
		for (auto it = lineMap.begin(); it != lineMap.end(); it++) {
			res = (*it).second.size() > res ? (*it).second.size() : res;
		}
		return res;
	}
	inline string* getID(vector<int>& p1, vector<int>& p2) {//求线ID
		double_t k = 0, b;
		string* res = new string;
		int x1 = p1[0], x2 = p2[0], y1 = p1[1], y2 = p2[1], dy = y2 - y1, dx = x2 - x1;
		if (dx < 0) {
			dx = -dx;
			dy = -dy;
		}
		int tmp = gcd(dx, dy);
		if (tmp != 0) {
			dx /= tmp;
			dy /= tmp;
		}
		if (dx == 0) {
			b = x1;
		}
		else {
			b = y1 - 1.0 * dy / dx * x1;
		}
		*res = to_string(dy) + '/' + to_string(dx) + '@' + to_string(b);
		return res;
	}
	inline int gcd(int a, int b) {//辗转相除求最大公约数
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

};

vector<vector<int>> strToMatrix(string s) {
	int sLen = s.size();
	vector<int> tmp;
	vector<vector<int>> res;
	for (int i = 0; i < sLen; i++) {
		if (s[i] == '[' || s[i] == ']' || s[i] == ',') {
			continue;
		}
		tmp.emplace_back(s[i] - '0');
		if (tmp.size() == 2) {
			res.emplace_back(tmp);
			tmp.clear();
		}
	}
	return res;
}

int main(int argc, char* argv[]) {
	Solution mySolution;
	vector<int> inpt = { 1, 3 };
	//vector<vector<int>> inptBoom = { {0,0},{1,0},{-1,0}, {0, 1}, {0, -1} };
	//mySolution.frequencySort("tree");
	//mySolution.numberOfBoomerangs(inptBoom);
	//mySolution.mySqrt(46339);
	//vector<vector<int>> linePoint = { {0,0 }, {1, 1},{1, -1} };
	//mySolution.maxPoints(linePoint);
	//vector<int> p1 = { 1,1 };
	//vector<int> p2 = { 1,2 };
	//mySolution.getKB(p1, p2);
	return 0;
}
#endif

//二分法
#if false

class Solution {
public:
	//int search(vector<int>& nums, int target) {//二分查找
	//	int frontCur = 0, rearCur = nums.size() - 1, currentCur = (frontCur + rearCur) / 2;
	//	while (frontCur <= rearCur) {
	//		currentCur = (frontCur + rearCur) / 2;
	//		if (nums[currentCur] > target) {
	//			rearCur = currentCur - 1;
	//			continue;
	//		}
	//		if (nums[currentCur] < target) {
	//			frontCur = currentCur + 1;
	//			continue;
	//		}
	//		return currentCur;
	//	}
	//	if (nums[currentCur] == target) {
	//		return currentCur;
	//	}
	//	return -1;
	//}
	int mySqrt(int x) {//二分查平方根
		int left = 0, right = x < 46339 ? x : 46339, current = 0;
		while (left <= right) {
			current = left + (right - left) / 2;
			int tmp = current * current;
			if (tmp == x) {
				break;
			}
			else if (tmp > x) {
				right = current - 1;
			}
			else {
				left = current + 1;
			}
		}
		if (current * current > x) {
			return current - 1;
		}
		return current;
	}
	int search(vector<int>& nums, int target) {
		size_t numsLen = nums.size(), i;
		int left, right, mid = 0;
		for (i = 1; i < numsLen; i++) {
			if (nums[i] < nums[i - 1]) {
				break;
			}
		}
		if (i != numsLen) {
			if (nums[numsLen - 1] < target) {
				left = 0;
				right = i - 1;
			}
			else {
				left = i;
				right = numsLen - 1;
			}
		}
		else {
			left = 0;
			right = numsLen - 1;
		}
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				return mid;
			}
		}
		if (nums[mid] == target) {
			return mid;
		}
		return -1;
	}
	vector<int> searchRange(vector<int>& nums, int target) {//右点难，注意结束条件
		int left = 0, right = nums.size() - 1, mid;
		vector<int> res(2, -1);
		if (right == -1) {
			return res;
		}
		if (nums[0] == target) {
			res[0] = 0;
		}
		if (nums[right] == target) {
			res[1] = right;
		}
		if (res[0] == -1) {
			while (left < right) {
				mid = left + (right - left) / 2;
				if (nums[mid] >= target) {
					right = mid;
				}
				else {
					left = mid + 1;
				}
			}
			if (nums[left] == target) {
				res[0] = left;
			}
		}
		if (res[0] == -1) {
			return res;
		}
		if (res[1] == -1) {
			left = res[0]; right = nums.size() - 1;
			while (left < right) {
				mid = left + (right - left) / 2;
				if (nums[mid] > target) {
					right = mid;
				}
				else {
					left = mid + 1;
				}
			}
			res[1] = left - 1;
		}
		return res;
	}
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		//https://leetcode-cn.com/problems/find-k-closest-elements/solution/658-zhao-dao-k-ge-zui-jie-jin-de-yuan-su-cer-fen-s/
		size_t left = 0, right = arr.size() - k, mid;
		//mid是数组起点
		while (left < right) {
			mid = left + (right - left) / 2;
			if (x - arr[mid] > arr[mid + k] - x) {
				//增序数组，两边界差相差不大
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return vector<int>(arr.begin() + left, arr.begin() + left + k);
	}
	int findPeakElement(vector<int>& nums) {//求极大值
		size_t numsLen = nums.size();
		if (numsLen == 1 || nums[0] > nums[1]) {
			return 0;
		}
		if (nums[numsLen - 1] > nums[numsLen - 2]) {
			return numsLen - 1;
		}
		size_t left = 0, right = numsLen - 1, mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (nums[mid] < nums[mid + 1]) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		if (nums[mid] < nums[mid + 1]) {
			return mid + 1;
		}
		return mid;
	}
	int getKthLarg(vector<int>& nums1, vector<int>& nums2, int k) {//双数组求第几大
		int cur1 = 0, cur2 = 0, nums1Len = nums1.size(), nums2Len = nums2.size();
		while (true) {
			//退出机制
			if (cur1 == nums1Len) {
				return nums2[cur2 + k - 1];
			}
			if (cur2 == nums2Len) {
				return nums1[cur1 + k - 1];
			}
			if (k == 1) {
				return min(nums1[cur1], nums2[cur2]);
			}
			//防止访问越界
			int cur1Tmp = min(cur1 + k / 2 - 1, nums1Len - 1);
			int cur2Tmp = min(cur2 + k / 2 - 1, nums2Len - 1);
			int nums1Tmp = nums1[cur1Tmp], nums2Tmp = nums2[cur2Tmp];
			//扣除真实偏移
			if (nums1Tmp <= nums2Tmp) {
				k -= cur1Tmp - cur1 + 1;
				cur1 = cur1Tmp + 1;
			}
			else {
				k -= cur2Tmp - cur2 + 1;
				cur2 = cur2Tmp + 1;
			}
		}
		return 0;
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {//双数组求中值
		size_t totalLen = nums1.size() + nums2.size();
		if (totalLen % 2 == 1) {
			return getKthLarg(nums1, nums2, (totalLen + 1) / 2);
		}
		else {
			return (getKthLarg(nums1, nums2, totalLen / 2) + getKthLarg(nums1, nums2, totalLen / 2 + 1)) / 2.0;
		}

	}
	double myPow(double x, int n) {//二分法幂函数
		if (n == 0) {
			return 1.0;
		}
		bool xIsNeg = x < 0 ? true : false;
		bool nIsNeg = n < 0 ? true : false;
		double nCopy;
		if (xIsNeg) {
			x = -x;
			if (n % 2 == 0) {
				xIsNeg = false;
			}
		}
		if (nIsNeg) {
			nCopy = -1.0 * n;
		}
		else {
			nCopy = n;
		}
		unsigned long powTime = 1;
		double res = x;
		while (powTime * 2 < nCopy) {
			powTime *= 2;
			res *= res;
		}
		if (powTime * 2 - nCopy < nCopy - powTime) {
			powTime *= 2;
			res *= res;
		}
		while (powTime < nCopy) {
			powTime++;
			res *= x;
		}
		while (powTime > nCopy) {
			powTime--;
			res /= x;
		}
		if (nIsNeg) {
			res = 1 / res;
		}
		if (xIsNeg) {
			res = -res;
		}
		return res;
	}
	bool isPerfectSquare(int num) {
		int left = 0, right = num < 46340 ? num : 46340, mid;
		while (left <= right) {
			mid = left + (right - left) / 2;
			int tmp = mid * mid;
			if (tmp == num) {
				return true;
			}
			else if (tmp > num) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return false;
	}
	char nextGreatestLetter(vector<char>& letters, char target) {
		int left = 0, right = letters.size() - 1, mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (letters[mid] <= target) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		if (left == letters.size() - 1 && letters[left] <= target) {
			return letters[0];
		}
		if (left < letters.size() - 1 && letters[left] <= target) {
			return letters[left + 1];
		}
		return letters[left];
	}
	//int smallestDistancePair(vector<int>& nums, int k) {//找出第 k 小的距离对， 暴力算法超时
	//	sort(nums.begin(), nums.end());
	//	size_t numsLen = nums.size();
	//	priority_queue<int, vector<int>, greater<int>> distQue;
	//	for (size_t i = 0; i < numsLen; i++) {
	//		for (size_t j = i + 1; j < numsLen; j++) {
	//			distQue.push(nums[j] - nums[i]);
	//		}
	//	}
	//	while (k > 1) {
	//		distQue.pop();
	//		k--;
	//	}
	//	return distQue.top();
	//}
	unordered_map<int, int>* kthMap;
	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int left = 0, right = nums[nums.size() - 1] - nums[0], mid;
		kthMap = new unordered_map<int, int>;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (getCount(nums, mid) >= k) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		delete kthMap;
		return left;
	}
	int getCount(vector<int>& nums, int val) {
		//统计差小于k的对数,双指针思想
		//nums[j] - nums[i] < val, 那么i, j之间所有差都小于val
		if (kthMap->count(val) > 0) {
			return (*kthMap)[val];
		}
		size_t left = 0, right, res = 0, numsLen = nums.size();
		for (right = 1; right < numsLen; right++) {
			while (nums[right] - nums[left] > val) {
				left++;
			}
			res += right - left;
		}
		(*kthMap)[val] = res;
		return res;
	}
	int splitArray(vector<int>& nums, int m) {
		int left = 0, right = 0, mid;
		size_t numsLen = nums.size();
		for (size_t i = 0; i < numsLen; i++) {
			right += nums[i];
			if (left < nums[i]) {
				left = nums[i];
			}
		}
		while (left < right) {
			mid = left + (right - left) / 2;
			if (check(nums, mid, m)) {
				//能分割，进一步压缩最大值限制
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
	bool check(vector<int>& nums, int val, int m) {
		//检查能不能以val为最大值，将数组分割成m段
		long sum = 0;
		int cnt = 1;
		size_t numsLen = nums.size();
		for (size_t i = 0; i < numsLen; i++) {
			//存在性
			if (sum + nums[i] > val) {
				cnt++;
				sum = nums[i];
			}
			else {
				sum += nums[i];
			}
		}
		return cnt <= m;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	vector<int> inpt = { 7, 2, 5, 10, 8 };
	vector<char> inpt2 = { 'e', 'e', 'e', 'e', 'n', 'n' };
	mySolution.splitArray(inpt, 2);
	return 0;

}

#endif

//递归
#if false

class Solution {
public:
	//递归杨辉三角，使用map降低重复计算
	unordered_map<int, unordered_map<int, int>> dpRes;
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		vector<int> tmp;
		for (size_t i = 0; i < numRows; i++) {
			tmp.clear();
			for (size_t j = 0; j < i + 1; j++) {
				tmp.push_back(pascalNumber(i + 1, j + 1));
			}
			res.push_back(tmp);
		}
		return res;
	}
	int pascalNumber(int i, int j) {
		if (dpRes.count(i) > 0 && (dpRes[i].count(j) > 0 || dpRes[i].count(i + 1 - j) > 0)) {
			return dpRes[i][j];
		}
		if (i <= 1 || j <= 1 || i == j) {
			return 1;
		}
		int tmp = pascalNumber(i - 1, j - 1) + pascalNumber(i - 1, j);
		dpRes[i][j] = tmp;
		dpRes[i][i + 1 - j] = tmp;
		return tmp;
	}
	//递归生成杨辉三角特定行， 直接返回向量
	vector<int> getRow(int rowIndex) {
		if (rowIndex == 0) {
			return vector<int>(1, 1);
		}
		vector<int> res = getRow(rowIndex - 1);
		for (size_t i = rowIndex - 1; i > 0; i--) {
			res[i] = res[i] + res[i - 1];
		}
		res.push_back(1);
		return res;
	}
	//斐波那契数列，带记忆递归
	unordered_map<int, int> fibMap;
	int fib(int N) {
		if (fibMap.count(N) > 0) {
			return fibMap[N];
		}
		if (N < 2) {
			fibMap[N] = N;
			return N;
		}
		int res = fib(N - 1) + fib(N - 2);
		fibMap[N] = res;
		return res;
	}
	//尾递归，xor
	int kthGrammar(int N, int K) {
		if (N == 1) {
			return 0;
		}
		int bitCnt = 1 << (N - 1);
		if (K > bitCnt / 2) {
			return kthGrammar(N - 1, K - bitCnt / 2) ^ 1;
		}
		return kthGrammar(N - 1, K);
	}
	//生成所有搜索二叉树


	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) {
			return {};
		}
		return generateSubTree(1, n);
	}
	vector<TreeNode*> generateSubTree(int start, int end) {
		if (start > end) {
			return { nullptr };
		}
		vector<TreeNode*> allTree;
		for (int i = start; i <= end; i++) {
			vector<TreeNode*> leftTree = generateSubTree(start, i - 1);
			vector<TreeNode*> rightTree = generateSubTree(i + 1, end);
			for (auto& left : leftTree) {
				for (auto& right : rightTree) {
					TreeNode* currentTree = new TreeNode(i, left, right);
					allTree.emplace_back(currentTree);
				}
			}
		}
		return allTree;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	mySolution.generateTrees(3);
	return 0;
}

#endif

//中级算法
#if false

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	//三数之和
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		size_t numsLen = nums.size();
		for (size_t i = 0; i < numsLen; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			size_t k = numsLen - 1;
			for (size_t j = i + 1; j < numsLen; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}
				while (k > j && nums[i] + nums[j] + nums[k] > 0) {
					k--;
				}
				if (j == k) {
					break;
				}
				if (nums[i] + nums[j] + nums[k] == 0) {
					res.emplace_back(vector<int>({ nums[i], nums[j], nums[k] }));
				}
			}
		}
		return res;
	}
	//长度为 3 的递增子序列
	bool increasingTriplet(vector<int>& nums) {
		size_t numsLen = nums.size();
		if (numsLen < 3) {
			return false;
		}
		int small = 65535, mid = 65535;
		for (auto num : nums) {
			if (num <= small) {
				small = num;
			}
			else if (num <= mid) {
				mid = num;
			}
			else if (num > mid) {
				return true;
			}
		}
		return false;
	}
	//中序和前序构造二叉树
	/*TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		size_t nodeCnt = preorder.size();
		if (nodeCnt == 0) {
			return nullptr;
		}
		TreeNode* res = new TreeNode(preorder[0]);
		if (nodeCnt == 1) {
			return res;
		}
		size_t i;
		for (i = 0; i < nodeCnt; i++) {
			if (inorder[i] == preorder[0]) {
				break;
			}
		}
		vector<int> preleft(preorder.begin() + 1, preorder.begin() + i + 1);
		vector<int> inleft(inorder.begin(), inorder.begin() + i);
		vector<int> preright(preorder.begin() + i + 1, preorder.end());
		vector<int> inright(inorder.begin() + i + 1, inorder.end());
		res->left = buildTree(preleft, inleft);
		res->right = buildTree(preright, inright);
		return res;
	}*/
	//中序和前序构造二叉树--优化
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		size_t nodeCnt = preorder.size();
		return buildSubTree(preorder, 0, nodeCnt - 1, inorder, 0, nodeCnt - 1);
	}
	TreeNode* buildSubTree(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight) {
		if (preLeft > preRight) {
			return nullptr;
		}
		TreeNode* res = new TreeNode(preorder[preLeft]);
		if (preLeft == preRight) {
			return res;
		}
		size_t i;
		for (i = 0; i + inLeft < inRight; i++) {
			if (inorder[i + inLeft] == preorder[preLeft]) {
				break;
			}
		}
		res->left = buildSubTree(preorder, preLeft + 1, preLeft + i, inorder, inLeft, inLeft + i - 1);
		res->right = buildSubTree(preorder, preLeft + i + 1, preRight, inorder, inLeft + i + 1, inRight);
		return res;
	}
	//电话号码字母组合
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		int digitLen = digits.size();
		if (digitLen < 1) {
			return res;
		}
		unordered_map<char, string> dialMap = {
			{'2', "abc"},
			{'3', "def"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"}
		};
		for (char ch : digits) {
			string tmp = dialMap[ch];
			if (res.size() == 0) {
				for (size_t i = 0; i < tmp.size(); i++) {
					res.push_back({ tmp[i] });
				}
				continue;
			}
			vector<string> resCopy = res;
			res.clear();
			for (string str : resCopy) {
				for (char tmpCh : tmp) {
					res.push_back(str + tmpCh);
				}
			}
		}
		return res;
	}
	//有效括号组合
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n < 1) {
			return res;
		}
		unordered_set<string> resCand;
		res.push_back("()");
		resCand.insert("()");
		while (n > 1) {
			vector<string> resCopy = res;
			res.clear();
			for (string tmp : resCopy) {
				int tmpLen = tmp.size();
				for (int i = 1; i < tmpLen + 1; i++) {
					string tmpRes = tmp.substr(0, i) + "()" + tmp.substr(i, tmpLen - 1);
					if (resCand.count(tmpRes) > 0) {
						continue;
					}
					resCand.emplace(tmpRes);
					res.emplace_back(tmpRes);
				}
			}
			n--;
		}
		return res;
	}
	//没有重复 数字的序列
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		size_t numsLen = nums.size();
		if (numsLen < 1) {
			return res;
		}
		res.emplace_back(vector<int>{nums[0]});
		for (size_t i = 1; i < numsLen; i++) {
			vector<vector<int>> resCopy = res;
			res.clear();
			int tmpInt = nums[i];
			for (vector<int> tmp : resCopy) {
				size_t tmpLen = tmp.size();
				for (size_t j = 0; j <= tmpLen; j++) {
					vector<int> tmpAdd = tmp;
					tmpAdd.insert(tmpAdd.begin() + j, tmpInt);
					res.emplace_back(tmpAdd);
				}
			}
		}
		return res;
	}
	//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res = { {} };
		size_t numsLen = nums.size();
		if (numsLen < 1) {
			return res;
		}
		int bitPos = pow(2, numsLen) - 1;
		vector<int> tmp;
		while (bitPos > 0) {
			tmp.clear();
			int bitPosCopy = bitPos;
			for (size_t i = 0; i < numsLen; i++) {
				if (bitPosCopy & 0x1) {
					tmp.emplace_back(nums[i]);
				}
				bitPosCopy /= 2;
			}
			res.emplace_back(tmp);
			bitPos--;
		}
		return res;
	}
	//单词搜索 这个方法效率太低，虽然可行
	vector<vector<bool>>* vist;
	bool exist(vector<vector<char>>& board, string word) {
		size_t colLen = board.size();
		if (colLen < 1) {
			return false;
		}
		size_t rolLen = board[0].size();
		if (rolLen < 1) {
			return false;
		}
		vist = new vector<vector<bool>>(colLen, vector<bool>(rolLen, false));
		for (size_t i = 0; i < colLen; i++) {
			for (size_t j = 0; j < rolLen; j++) {
				if (exploreGrid(board, word, 0, i, j)) {
					delete vist;
					return true;
				}
			}
		}
		delete vist;
		return false;
	}
	// 原先版本， 未剪枝，超时
	/*bool exploreGrid(vector<vector<char>>& board, string word, int n, int col, int rol) {
		size_t colLen = board.size(), rolLen = board[0].size();
		int wordLen = word.size();
		if (col < 0 || col >= colLen || rol < 0 || rol >= rolLen || board[col][rol] != word[n]) {
			return false;
		}
		if ((*vist)[col][rol]) {
			return false;
		}
		(*vist)[col][rol] = true;
		if (n == wordLen - 1) {
			return true;
		}
		bool upper = exploreGrid(board, word, n + 1, col - 1, rol);
		bool lower = exploreGrid(board, word, n + 1, col + 1, rol);
		bool left = exploreGrid(board, word, n + 1, col, rol - 1);
		bool right = exploreGrid(board, word, n + 1, col, rol + 1);
		(*vist)[col][rol] = false;
		return upper || lower || left || right;
	}*/
	// 新版本，找到后立即返回，剪枝，且只有匹配成功的会被标记
	bool exploreGrid(vector<vector<char>>& board, string& word, int n, int col, int rol) {
		size_t colLen = board.size(), rolLen = board[0].size();
		int wordLen = word.size();
		if (board[col][rol] != word[n]) {
			return false;
		}
		if (n == wordLen - 1) {
			return true;
		}
		(*vist)[col][rol] = true;
		vector<pair<int, int>> directions{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
		for (pair<int, int> dir : directions) {
			int newCol = col + dir.first, newRol = rol + dir.second;
			if (newCol >= 0 && newCol < colLen && newRol >= 0 && newRol < rolLen) {
				if (!(*vist)[newCol][newRol]) {
					if (exploreGrid(board, word, n + 1, newCol, newRol)) {
						(*vist)[col][rol] = false;
						return true;
					}
				}
			}
		}
		(*vist)[col][rol] = false;
		return false;
	}
	//三种颜色分类
	void sortColors(vector<int>& nums) {
		size_t numsLen = nums.size();
		if (numsLen < 2) {
			return;
		}
		size_t frontCur = 0, currentCur = 0, rearCur = numsLen - 1;
		for (currentCur = 0; currentCur <= rearCur; currentCur++) {
			while (currentCur <= rearCur && nums[currentCur] == 2) {
				swapElem(nums, rearCur, currentCur);
				rearCur--;
				if (rearCur == 0) {
					break;
				}
			}
			if (nums[currentCur] == 0) {
				swapElem(nums, frontCur, currentCur);
				frontCur++;
			}
		}
		return;
	}
	inline void swapElem(vector<int>& nums, int i, int j) {
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
		return;
	}
	//在未排序的数组中找到第 k 个最大的元素
	int findKthLargest(vector<int>& nums, int k) {
		size_t numsLen = nums.size();
		quickSort(nums, 0, numsLen - 1);
		return nums[numsLen - k];
	}
	void quickSort(vector<int>& nums, int front, int rear) {
		if (front >= rear) {
			return;
		}
		int pivot = nums[rear];
		int cur = front;
		for (int i = front; i < rear; i++) {
			if (nums[i] <= pivot) {
				swapElem(nums, cur, i);
				cur++;
			}
		}
		swapElem(nums, cur, rear);
		quickSort(nums, front, cur - 1);
		quickSort(nums, cur + 1, rear);
		return;
	}
	//搜索二维矩阵 II
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		size_t colSize = matrix.size();
		if (colSize == 0) {
			return false;
		}
		size_t rolSize = matrix[0].size();
		if (rolSize == 0) {
			return false;
		}
		size_t col = colSize - 1, rol = 0;
		while (col >= 0 && rol <= rolSize - 1) {
			if (target == matrix[col][rol]) {
				return true;
			}
			else if (target < matrix[col][rol]) {
				col--;
			}
			else {
				rol++;
			}
		}
		return false;
	}
	//跳跃游戏--贪心
	bool canJump(vector<int>& nums) {
		size_t numsLen = nums.size();
		if (numsLen < 2) {
			return true;
		}
		size_t maxPos = 0;
		for (size_t i = 0; i < numsLen; i++) {
			size_t tmp = i + nums[i];
			if (i > maxPos) {
				return false;
			}
			maxPos = tmp > maxPos ? tmp : maxPos;
			if (maxPos >= numsLen - 1) {
				return true;
			}
		}
		return false;
	}
	//不同路径--递归动态规划
	//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角
	//问总共有多少条不同的路径
	/*unordered_map<int, unordered_map<int, int>> pathVal;
	int uniquePaths(int m, int n) {
		if (m == 1 || n == 1) {
			return 1;
		}
		size_t val1, val2;
		if (pathVal.count(m - 1) > 0 && pathVal[m - 1].count(n) > 0) {
			val1 = pathVal[m - 1][n];
		}
		else if (pathVal.count(n) > 0 && pathVal[n].count(m - 1) > 0) {
			val1 = pathVal[n][m - 1];
		}
		else {
			val1 = uniquePaths(m - 1, n);
			pathVal[m - 1][n] = val1;
		}
		if (pathVal.count(m) > 0 && pathVal[m].count(n - 1) > 0) {
			val2 = pathVal[m][n - 1];
		}
		else if (pathVal.count(n - 1) > 0 && pathVal[n - 1].count(m) > 0) {
			val2 = pathVal[n - 1][m];
		}
		else {
			val2 = uniquePaths(m, n - 1);
			pathVal[m][n - 1] = val2;
		}
		return val1 + val2;
	}*/
	//不同路径--迭代动态规划
	//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角
	//问总共有多少条不同的路径
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 0));
		for (size_t i = 0; i < m; i++) {
			for (size_t j = 0; j < n; j++) {
				if (i == 0 || j == 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
	//零钱兑换
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (int i = 0; i <= amount; i++) {
			for (int coin : coins) {
				if (coin <= i) {
					dp[i] = min(dp[i], dp[i - coin] + 1);
				}
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}
	//最长上升子序列
	int lengthOfLIS(vector<int>& nums) {
		size_t numsLen = nums.size();
		if (numsLen < 2) {
			return numsLen;
		}
		vector<int> dp(numsLen);
		int res = 0;
		for (size_t i = 0; i < numsLen; i++) {
			dp[i] = 1;
			for (size_t j = 0; j < i; j++) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			res = dp[i] > res ? dp[i] : res;
		}
		return res;
	}
	//阶乘后的零
	int trailingZeroes(int n) {
		int res = 0;
		int tmp = 5;
		while (n >= tmp) {
			res += n / tmp;
			tmp *= 5;
		}
		return res;
	}
	//Excel表列序号
	int titleToNumber(string s) {
		int sLen = s.size();
		int res = 0;
		for (int i = 0; i < sLen; i++) {
			res *= 26;
			res += s[i] - 'A' + 1;
		}
		return res;
	}
	//快速幂
	double myPow(double x, int n) {
		bool isNeg = n < 0 ? true : false;
		if (n == 0x7fffffff) {
			if (x == 1.0 || x == 1.0) {
				return x;
			}
		}
		int i = 31;
		double res = 1.0, tmp = x;
		while (n != 0) {
			if (n % 2) {
				res *= tmp;
			}
			tmp *= tmp;
			n = n / 2;
		}
		if (isNeg) {
			res = 1 / res;
		}
		return res;
	}
	//二分法除法，要求不使用乘法、除法和 mod 运算符
	int divide(int dividend, int divisor) {
		long long res = 0;
		if (divisor == 0) {
			return 0x7fffffff;
		}
		if (dividend == 0) {
			return 0;
		}
		bool isNeg = false;
		if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) {
			isNeg = true;
		}
		long long dividendCopy = abs(dividend);
		long long divisorCopy = abs(divisor);
		while (dividendCopy >= divisorCopy) {
			long long tmp = divisorCopy;
			long long cnt = 1;
			while (tmp << 1 < dividendCopy) {
				cnt += cnt;
				tmp = tmp << 1;
			}
			dividendCopy -= tmp;
			res += cnt;
		}
		if (isNeg) {
			if (-res < INT_MIN) {
				return INT_MIN;
			}
			else {
				return -res;
			}
		}
		if (res > INT_MAX) {
			return INT_MAX;
		}
		return res;
	}
	//分数到小数
	string fractionToDecimal(int numerator, int denominator) {
		if (denominator == 0) {
			return "";
		}
		if (numerator == 0) {
			return "0";
		}
		string res;
		if ((numerator > 0) ^ (denominator > 0)) {
			res.push_back('-');
		}
		long long numCopy = abs(numerator), denCopy = abs(denominator);
		res.append(to_string(numCopy / denCopy));
		numCopy %= denCopy;
		if (numCopy == 0) {
			return res;
		}
		res.push_back('.');
		unordered_map<int, int> fracMap;
		int index = res.size();
		while (numCopy != 0 && fracMap.count(numCopy) == 0) {
			fracMap[numCopy] = index;
			index++;
			numCopy *= 10;
			res += to_string(numCopy / denCopy);
			numCopy %= denCopy;
		}
		if (fracMap.count(numCopy) > 0) {
			res.insert(fracMap[numCopy], "(");
			res += ')';
		}
		return res;
	}
	int getSum(int a, int b) {
		while (b) {
			auto carry = ((unsigned int)(a & b)) << 1;//进位
			a ^= b;//不进位的结果
			b = carry;
		}
		return a;
	}
	int evalRPN(vector<string>& tokens) {
		stack<int> op;
		for (auto token : tokens) {
			if (token.size() == 1 && (token[0] < '0' || token[0] > '9')) {
				int op1 = op.top();
				op.pop();
				int op2 = op.top();
				op.pop();
				if (token[0] == '+') {
					op1 = op1 + op2;
				}
				else if (token[0] == '-') {
					op1 = op2 - op1;
				}
				else if (token[0] == '*') {
					op1 = op1 * op2;
				}
				else {
					op1 = op2 / op1;
				}
				op.push(op1);
			}
			else {
				op.push(atoi(token.c_str()));
			}
		}
		return op.top();
	}
	//多数元素:Boyer–Moore majority vote algorithm
	//如果候选人不是maj 则 maj,会和其他非候选人一起反对 会反对候选人,所以候选人一定会下台(maj==0时发生换届选举)
	//如果候选人是maj, 则maj 会支持自己，其他候选人会反对，同样因为maj 票数超过一半，所以maj 一定会成功当选
	int majorityElement(vector<int>& nums) {
		int cand = -1, cnt = 0;
		for (int num : nums) {
			if (num == cand) {
				cnt++;
			}
			else if (--cnt < 0) {
				cand = num;
				cnt = 1;
			}
		}
		return cand;
	}
	//任务调度器
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int> freq;
		for (char ch : tasks) {
			freq[ch]++;
		}
		int maxExec = 0, maxCnt = 0;
		for (auto it = freq.begin(); it != freq.end(); it++) {
			if (it->second > maxExec) {
				maxExec = it->second;
				maxCnt = 1;
			}
			else if (it->second == maxExec) {
				maxCnt++;
			}
		}
		return max((maxExec - 1) * (n + 1) + maxCnt, int(tasks.size()));
	}
};
class Codec {
	//二叉树的序列化与反序列化
public:

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
			char tmp = data[cur];
			if (tmp == '[' || tmp == ']' || tmp == ',') {
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

int main(int argc, char* argv[]) {
	vector<int> inptF = { 3,2,3,1,2,4,5,5,6 }, inptM = { 3, 2, 1 };
	vector<int> nums = { 2,2,1,1,1,2,2 };
	Solution mySolution;
	string digits = "ASF";
	vector<vector<int>> matrix = {
		{1,4,7,11,15},
		{2,5,8,12,19},
		{3,6,9,16,22},
		{10,13,14,17,24},
		{18,21,23,26,30} };
	Codec myCodec;
	string s = "AB";
	vector<string> polInpt = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	vector<char> tasks = { 'A','A','A','B','B','B' };
	mySolution.leastInterval(tasks, 2);
	return 0;
}
#endif

//高级算法--字符串数组
#if false

class Solution {
public:
	//除自身以外数组的乘积
	vector<int> productExceptSelf(vector<int>& nums) {
		size_t numsLen = nums.size();
		vector<int> res(numsLen);
		res[0] = 1;
		for (size_t i = 1; i < numsLen; i++) {
			res[i] = res[i - 1] * nums[i - 1];
		}
		int tmp = 1;
		for (int i = numsLen - 1; i > -1; i--) {
			res[i] *= tmp;
			tmp *= nums[i];
		}
		return res;
	}
	//螺旋矩阵
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		size_t colSize = matrix.size();
		if (colSize == 0) {
			return {};
		}
		size_t rolSize = matrix[0].size();
		size_t lim = min(colSize, rolSize);
		if (lim == 1) {
			lim = 1;
		}
		else if (lim % 2 == 1) {
			lim = lim / 2 + 1;
		}
		else {
			lim = lim / 2;
		}
		vector<int> res;
		for (size_t i = 0; i < lim; i++) {
			vector<int> tmp = getSub(matrix, i, colSize, rolSize);
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
		return res;
	}
	vector<int> getSub(vector<vector<int>>& matrix, size_t nth, size_t col, size_t rol) {
		vector<int> res;
		for (size_t i = nth; i < rol - nth; i++) {
			res.emplace_back(matrix[nth][i]);
		}
		if (nth + 1 == col - nth) {//只有一行，剪枝
			return res;
		}
		for (size_t i = nth + 1; i < col - nth; i++) {
			res.emplace_back(matrix[i][rol - nth - 1]);
		}
		if (nth + 1 == rol - nth) {//只有一列，剪枝
			return res;
		}
		for (size_t i = nth + 2; i < rol - nth; i++) {
			res.push_back(matrix[col - nth - 1][rol - i]);
		}
		for (size_t i = nth + 1; i < col - nth; i++) {
			res.push_back(matrix[col - i][nth]);
		}
		return res;
	}
	//生命游戏
	void gameOfLife(vector<vector<int>>& board) {
		size_t colSize = board.size();
		if (colSize == 0) {
			return;
		}
		size_t rolSize = board[0].size();
		vector<vector<int>> boardCopy(board);
		for (size_t i = 0; i < colSize; i++) {
			for (size_t j = 0; j < rolSize; j++) {
				int convRes = conv(boardCopy, i, j, colSize, rolSize);
				if (convRes > 3 || convRes < 2) {//死亡
					board[i][j] = 0;
				}
				else if (convRes == 3) {//复活
					board[i][j] = 1;
				}
			}
		}
		return;
	}
	vector<vector<int>> directions = {
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1} };
	int conv(vector<vector<int>>& boardCopy, size_t col, size_t rol, size_t colSize, size_t rolSize) {//卷积
		int res = 0;
		for (vector<int>& dir : directions) {
			int colCur = col + dir[0], rolCur = rol + dir[1];
			if (colCur < 0 || colCur >= colSize || rolCur < 0 || rolCur >= rolSize) {
				continue;
			}
			res += boardCopy[colCur][rolCur];
		}
		return res;
	}
	//缺失的第一个正数
	//自定义哈希表
	int firstMissingPositive(vector<int>& nums) {
		size_t numsLen = nums.size();
		for (size_t i = 0; i < numsLen; i++) {
			if (nums[i] <= 0) {
				nums[i] = numsLen + 1;
			}
		}
		for (size_t i = 0; i < numsLen; i++) {
			int tmp = abs(nums[i]);
			if (tmp <= numsLen) {
				nums[tmp - 1] = -abs(nums[tmp - 1]);
			}
		}
		for (size_t i = 0; i < numsLen; i++) {
			if (nums[i] > 0) {
				return i + 1;
			}
		}
		return numsLen + 1;
	}
	int longestConsecutive(vector<int>& nums) {
		size_t numsLen = nums.size();
		unordered_set<int> numsSet;
		for (int num : nums) {
			numsSet.emplace(num);
		}
		int res = 0;
		for (auto numElem : numsSet) {
			if (numsSet.count(numElem - 1) > 0) {
				continue;
			}
			int current = numElem;
			while (numsSet.count(current + 1) > 0) {
				current++;
			}
			res = (current - numElem + 1) > res ? (current - numElem + 1) : res;
		}
		return res;
	}
	void myQuickSort(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}
		int pivot = nums[right];
		int cur = left;
		for (int i = left; i <= right; i++) {
			if (nums[i] <= pivot) {
				int tmp = nums[cur];
				nums[cur] = nums[i];
				nums[i] = tmp;
				cur++;
			}
		}
		cur--;
		myQuickSort(nums, left, cur - 1);
		myQuickSort(nums, cur + 1, right);
		return;
	}
	//基本计算器
	//这种垃圾算法还真是第一次遇到（没错，是我写的！）
	int calculate(string s) {
		int sLen = s.size();
		stack<int> opNum;
		stack<char> oper;
		for (int i = 0; i < sLen; i++) {//提取操作数和操作符
			if (s[i] == ' ') {
				continue;
			}
			if (s[i] > '9' || s[i] < '0') {
				oper.push(s[i]);
				continue;
			}
			int tmp = 0;
			while (s[i] >= '0' && s[i] <= '9') {
				tmp *= 10;
				tmp += s[i] - '0';
				i++;
			}
			i--;
			opNum.push(tmp);
		}
		int res = 0;
		stack<int> opNumPN;
		stack<char> operPN;
		int tmp;
		//逆序栈
		while (!oper.empty()) {
			operPN.push(oper.top());
			oper.pop();
		}
		while (!opNum.empty()) {
			opNumPN.push(opNum.top());
			opNum.pop();
		}
		while (!operPN.empty()) {//处理乘除法
			char op = operPN.top();
			operPN.pop();
			tmp = opNumPN.top();
			opNumPN.pop();
			if (op == '*') {
				tmp *= opNumPN.top();
				opNumPN.pop();
			}
			else if (op == '/') {
				tmp /= opNumPN.top();
				opNumPN.pop();
			}
			else {
				oper.push(op);
				opNum.push(tmp);
				continue;
			}
			opNumPN.push(tmp);
		}
		if (!opNumPN.empty()) {
			opNum.push(opNumPN.top());
		}
		//逆序栈
		while (!oper.empty()) {
			operPN.push(oper.top());
			oper.pop();
		}
		while (!opNum.empty()) {
			opNumPN.push(opNum.top());
			opNum.pop();
		}
		res = opNumPN.top();
		opNumPN.pop();
		while (!operPN.empty()) {
			char op = operPN.top();
			operPN.pop();
			tmp = opNumPN.top();
			opNumPN.pop();
			if (op == '+') {
				res += tmp;
			}
			else {
				res -= tmp;
			}
		}
		return res;
	}
	//滑动窗口最大值
	//动态规划
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		size_t numsLen = nums.size();
		vector<int> res(numsLen - k + 1), left(numsLen), right(numsLen);
		int tmpL, tmpR;
		for (size_t i = 0; i < numsLen; i++) {
			if (i % k == 0) {
				tmpL = nums[i];
			}
			else {
				tmpL = nums[i] > tmpL ? nums[i] : tmpL;
			}
			left[i] = tmpL;//左侧滑动窗口
			if (i % k == numsLen % k || i == 0) {
				tmpR = nums[numsLen - 1 - i];
			}
			else {
				tmpR = nums[numsLen - 1 - i] > tmpR ? nums[numsLen - 1 - i] : tmpR;
			}
			right[numsLen - 1 - i] = tmpR;//右侧滑动窗口
		}
		for (size_t i = 0; i < numsLen - k + 1; i++) {
			res[i] = max(right[i], left[i + k - 1]);//到当前窗口结尾，下一个窗口开始到下一个窗口长度
		}
		return res;
	}
	//最小覆盖子串
	unordered_map<char, int> tMap, cntMap;
	bool check(void) {//检查是否包含
		for (const auto& p : tMap) {
			if (cntMap[p.first] < p.second) {
				return false;
			}
		}
		return true;
	}
	string minWindow(string s, string t) {
		int sLen = s.size();
		for (const char& tCh : t) {
			tMap[tCh]++;
		}
		int lCur = 0, rCur = 0, ansL = -1, ansR = -1, len = sLen + 1;
		while (rCur < sLen) {
			if (tMap.count(s[rCur]) > 0) {//是单词中的字母
				cntMap[s[rCur]]++;
			}
			while (check()) {//左侧缩短字符串
				if (rCur - lCur + 1 < len) {
					len = rCur - lCur + 1;
					ansL = lCur;
				}
				if (tMap.count(s[lCur]) > 0 && cntMap[s[lCur]] != 0) {//如果是单词中的话就排除
					cntMap[s[lCur]]--;
				}
				lCur++;
			}
			rCur++;
		}
		if (ansL == -1) {
			return "";
		}
		string res = s.substr(ansL, len);
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	vector<int>nums = { 1,3,-1,-3,5,3,6,7 };
	vector<vector<int>> matrix = {
		{1,4,7,11,15},
		{2,5,8,12,19},
		{3,6,9,16,22},
		{10,13,14,17,24},
		{18,21,23,26,30} };
	vector<vector<int>> matrix2 = { {3}, {2} };
	vector<vector<int>> matrixlive = {
		{0, 1, 0},
		{0, 0, 1},
		{1, 1, 1},
		{0, 0, 0} };
	string inpt = " 1-1+1 ";
	string s = "A";
	string t = "AA";
	mySolution.minWindow(s, t);
	return 0;
}
#endif

//高级算法--链表
#if false

class Solution {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
public:
	////合并K个排序链表 暴力算法~800ms
	////新建节点版本，效率低（构造函数调用过多）
	//bool check(vector<ListNode*>& lists) {
	//	for (const ListNode* listHead : lists) {//换成序列访问，能快10%
	//		if (listHead != nullptr) {
	//			return true;
	//		}
	//	}
	//	return false;
	//}
	//ListNode* mergeKLists(vector<ListNode*>& lists) {
	//	ListNode* root, * current;
	//	root = new ListNode;
	//	current = root;
	//	size_t listLen = lists.size();
	//	while (check(lists)) {
	//		int minVal = INT_MAX, pos = -1;
	//		for (size_t i = 0; i < listLen; i++) {
	//			if (lists[i] == nullptr) {
	//				continue;
	//			}
	//			if (lists[i]->val < minVal) {
	//				pos = i;
	//				minVal = lists[i]->val;
	//			}
	//		}
	//		lists[pos] = lists[pos]->next;
	//		current->next = new ListNode(minVal);
	//		current = current->next;
	//		//连接节点版本，内存占用下降
	//		/*current->next = lists[pos];
	//		lists[pos] = lists[pos]->next;
	//		current = current->next;*/
	//	}
	//	return root->next;
	//}


	//分治法~80ms
	//合并两个链表
	ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
		if (a == nullptr || b == nullptr) {
			return a == nullptr ? b : a;
		}
		ListNode* root = new ListNode;
		ListNode* current = root;
		while (a != nullptr && b != nullptr) {
			if (a->val < b->val) {
				current->next = a;
				a = a->next;
			}
			else {
				current->next = b;
				b = b->next;
			}
			current = current->next;
		}
		current->next = a == nullptr ? b : a;
		return root->next;
	}
	ListNode* merge(vector<ListNode*>& lists, int left, int right) {
		if (left == right) {
			return lists[left];
		}
		if (left > right) {
			return nullptr;
		}
		int mid = (left + right) / 2;
		return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return merge(lists, 0, lists.size() - 1);
	}

	//排序链表--快速排序
	//超出时间限制
	void listQuickSort(vector<ListNode*>& lists, int left, int right) {
		if (left >= right) {
			return;
		}
		int pivot = lists[left]->val;
		int frontCur = left, rearCur = right;
		while (frontCur != rearCur) {
			while (frontCur != rearCur && lists[rearCur]->val >= pivot) {
				rearCur--;
			}
			while (frontCur != rearCur && lists[frontCur]->val <= pivot) {
				frontCur++;
			}
			if (frontCur < rearCur) {
				ListNode* tmp = lists[frontCur];
				lists[frontCur] = lists[rearCur];
				lists[rearCur] = tmp;
			}
		}
		ListNode* tmp = lists[left];
		lists[left] = lists[frontCur];
		lists[frontCur] = tmp;
		listQuickSort(lists, left, frontCur - 1);
		listQuickSort(lists, frontCur + 1, right);
		return;
	}
	/*ListNode* sortList(ListNode* head) {
		vector<ListNode*> lists;
		while (head != nullptr) {
			lists.emplace_back(head);
			head = head->next;
		}
		size_t listLen = lists.size();
		listQuickSort(lists, 0, listLen - 1);
		lists.emplace_back(nullptr);
		for (size_t i = 0; i < listLen; i++) {
			lists[i]->next = lists[i + 1];
		}
		return lists[0];
	}*/
	//分治
	ListNode* sortList(ListNode* head) {
		vector<ListNode*> lists;
		while (head != nullptr) {
			ListNode* tmp = head;
			lists.emplace_back(head);
			head = head->next;
			tmp->next = nullptr;
		}
		return merge(lists, 0, lists.size() - 1);
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	mySolution.sortList(nullptr);
	return 0;
}
#endif

//高级算法--树和图
#if false

class Solution {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
public:
	//单词接龙
	unordered_map<string, int> wordID;
	vector<vector<int>> edge;
	int nodeCnt = 0;
	void addWord(string& word) {
		if (wordID.count(word) < 1) {
			wordID[word] = nodeCnt;
			edge.emplace_back();
			nodeCnt++;
		}
		return;
	}
	void addEdge(string& word) {
		addWord(word);
		int id1 = wordID[word];
		for (char& ch : word) {
			char tmp = ch;
			//替换状态，新建虚拟节点，虚拟节点之间相连，单词之间不直接相连
			ch = '*';
			addWord(word);
			int id2 = wordID[word];
			edge[id1].emplace_back(id2);
			edge[id2].emplace_back(id1);
			//结束替换状态
			ch = tmp;
		}
		return;
	}
	//双向搜索平均时间降低25%
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		for (string& word : wordList) {
			addEdge(word);
		}
		addEdge(beginWord);
		if (wordID.count(endWord) < 1) {//list 中没有endword
			return 0;
		}
		//前向搜索
		int beginID = wordID[beginWord];
		vector<int> disBegin(nodeCnt, INT_MAX);
		disBegin[beginID] = 0;//记录边数量
		queue<int> queBegin;
		queBegin.push(beginID);
		//反向搜索
		int endID = wordID[endWord];
		vector<int> disEnd(nodeCnt, INT_MAX);
		disEnd[endID] = 0;
		queue<int> queEnd;
		queEnd.push(endID);
		//开始搜索
		while (!queBegin.empty() && !queEnd.empty()) {
			//前向搜索
			int queBeginLen = queBegin.size();
			for (int i = 0; i < queBeginLen; i++) {
				int curBegin = queBegin.front();
				queBegin.pop();
				if (disEnd[curBegin] != INT_MAX) {//后向搜索到了该点
					return (disBegin[curBegin] + disEnd[curBegin]) / 2 + 1;
				}
				for (int& it : edge[curBegin]) {
					if (disBegin[it] == INT_MAX) {
						disBegin[it] = disBegin[curBegin] + 1;
						queBegin.push(it);
					}
				}
			}
			//反向搜索
			int queEndLen = queEnd.size();
			for (int i = 0; i < queEndLen; i++) {
				int curEnd = queEnd.front();
				queEnd.pop();
				if (disBegin[curEnd] != INT_MAX) {//前向搜索到了该点
					return (disBegin[curEnd] + disEnd[curEnd]) / 2 + 1;
				}
				for (int& it : edge[curEnd]) {
					if (disEnd[it] == INT_MAX) {
						disEnd[it] = disEnd[curEnd] + 1;
						queEnd.push(it);
					}
				}
			}
		}
		return 0;
	}
	//被围绕的区域
	//内存占用可以优化：不用vist矩阵，将board修改为其他值
	/*vector<vector<int>> direction = {
		{-1, 0},
		{0, 1},
		{1, 0},
		{0, -1} };*/
	void solve(vector<vector<char>>& board) {
		int colSize = board.size();
		if (colSize == 0) {
			return;
		}
		int rolSize = board[0].size();
		vector<vector<bool>> vist(colSize, vector<bool>(rolSize, false));
		//标记靠边区块
		for (int i = 0; i < colSize; i++) {
			for (int j = 0; j < rolSize; j++) {
				//不是边缘跳过
				if (i != 0 && j != 0 && i != colSize - 1 && j != rolSize - 1) {
					continue;
				}
				//未访问过的白块，BFS
				if (board[i][j] == 'O' && vist[i][j] == false) {
					vist[i][j] = true;
					queue<pair<int, int>> que;
					que.push(make_pair(i, j));
					while (!que.empty()) {
						int qLen = que.size();
						while (qLen != 0) {
							int colCurBase = que.front().first;
							int rolCurBase = que.front().second;
							que.pop();
							qLen--;
							for (int dirCnt = 0; dirCnt < 4; dirCnt++) {
								int colCur = colCurBase + direction[dirCnt][0];
								int rolCur = rolCurBase + direction[dirCnt][1];
								if (colCur < 0 || rolCur < 0 || colCur >= colSize || rolCur >= rolSize) {
									continue;
								}
								if (vist[colCur][rolCur] == true || board[colCur][rolCur] == 'X') {
									continue;
								}
								vist[colCur][rolCur] = true;
								que.push(make_pair(colCur, rolCur));
							}
						}
					}
				}
			}
		}
		//根据vist 标记
		for (int i = 0; i < colSize; i++) {
			for (int j = 0; j < rolSize; j++) {
				if (vist[i][j] == false && board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
		return;
	}
	//二叉树中的最大路径和
	int maxPathVal = INT_MIN;
	int maxPathSum(TreeNode* root) {
		maxGain(root);
		return maxPathVal;
	}
	int maxGain(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int leftGain = max(maxGain(root->left), 0);
		int rightGain = max(maxGain(root->right), 0);
		int currentGain = leftGain + rightGain + root->val;
		if (currentGain > maxPathVal) {
			maxPathVal = currentGain;
		}
		return root->val + max(rightGain, leftGain);
	}
	//朋友圈
	//BFS效率稍低，128ms，时间复杂度0(n^2)，空间复杂度0(n)
	int findCircleNum(vector<vector<int>>& M) {
		int mSize = M.size();
		if (mSize < 2) {
			return mSize;
		}
		int res = 0;
		queue<int> q;
		for (int i = 0; i < mSize; i++) {
			for (int j = 0; j < mSize; j++) {
				if (M[i][j] == 0 || M[i][j] == 2) {
					continue;
				}
				M[i][j] = 2;
				q.push(j);
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					for (int k = 0; k < mSize; k++) {
						if (M[cur][k] == 0 || M[cur][k] == 2) {
							continue;
						}
						M[cur][k] = 2;
						q.push(k);
					}
				}
				res++;
			}
		}

		return res;
	}
	//课程表
	//拓扑排序，判断是否存在环：排序后结点数量大于源节点数量
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> inDegree(numCourses, false);
		vector<vector<int>> edges(numCourses);
		for (vector<int>& req : prerequisites) {
			//0:子节点
			//1:父节点
			edges[req[1]].push_back(req[0]);
			inDegree[req[0]]++;
		}
		queue<int> q;
		for (size_t i = 0; i < numCourses; i++) {
			if (inDegree[i] == 0) {
				q.push(i);
			}
		}
		int vistCnt = 0;
		while (!q.empty()) {
			int u = q.front();
			vistCnt++;//模拟出队列
			q.pop();
			for (int i : edges[u]) {
				inDegree[i]--;
				if (inDegree[i] == 0) {
					q.push(i);
				}
			}
		}
		return vistCnt == numCourses;
	}
	//课程表 II
	//靠入度决定顺序
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> inDegree(numCourses, false);
		vector<vector<int>> edges(numCourses);
		for (vector<int>& req : prerequisites) {
			//0:子节点
			//1:父节点
			edges[req[1]].push_back(req[0]);
			inDegree[req[0]]++;
		}
		queue<int> q;
		for (size_t i = 0; i < numCourses; i++) {
			if (inDegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> res;
		int vistCnt = 0;
		while (!q.empty()) {
			int u = q.front();
			res.push_back(u);
			vistCnt++;
			q.pop();
			for (int i : edges[u]) {
				inDegree[i]--;
				if (inDegree[i] == 0) {
					q.push(i);
				}
			}
		}
		return vistCnt == numCourses ? res : vector<int>{};
	}
	//矩阵中的最长递增路径
	//DFS，回溯
	//超出时间限制
	//加上memo记忆矩阵，完成
	vector<vector<int>> direction = {
		{-1, 0},
		{0, 1},
		{1, 0},
		{0, -1} };
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int colSize = matrix.size();
		if (colSize == 0) {
			return 0;
		}
		int rolSize = matrix[0].size();
		unordered_set<int> numbers;
		vector<vector<bool>> vist(colSize, vector<bool>(rolSize, false));
		vector<vector<int>> memo(colSize, vector<int>(rolSize, 0));
		int res = 0;
		for (int i = 0; i < colSize; i++) {
			for (int j = 0; j < rolSize; j++) {
				res = max(lipDFS(matrix, vist, colSize, rolSize, i, j, memo), res);
			}
		}
		return res + 1;
	}
	int lipDFS(vector<vector<int>>& matrix, vector<vector<bool>>& vist, int colSize, int rolSize, int colCur, int rolCur, vector<vector<int>>& memo) {
		vist[colCur][rolCur] = true;
		int current = matrix[colCur][rolCur];
		int res = -1;
		for (size_t i = 0; i < 4; i++) {
			int col = colCur + direction[i][0];
			int rol = rolCur + direction[i][1];
			if (col < 0 || rol < 0 || col >= colSize || rol >= rolSize) {
				continue;
			}
			if (vist[col][rol] == true) {
				continue;
			}
			int tmp = matrix[col][rol];
			if (tmp > current) {
				if (memo[col][rol] == 0) {
					memo[col][rol] = lipDFS(matrix, vist, colSize, rolSize, col, rol, memo);
				}
				res = max(memo[col][rol], res);
			}
		}
		vist[colCur][rolCur] = false;
		return res + 1;
	}
	//计算右侧小于当前元素的个数
	//计算节点出度
	//时间复杂度0(n^2)，超时
	/*vector<int> countSmaller(vector<int>& nums) {
		size_t numslen = nums.size();
		vector<int> res(numslen, 0);
		for (size_t i = 0; i < numslen; i++) {
			int tmp = nums[i];
			for (size_t j = 0; j < i; j++) {
				if (tmp < nums[j]) {
					res[j]++;
				}
			}
		}
		return res;
	}*/
	//离散化树状数组
	//超时而且答案看不懂
	//vector<int> countSmaller(vector<int>& nums) {
	//	size_t numslen = nums.size();
	//	vector<int> res(numslen, 0);
	//	unordered_map<int, int> numCnt;
	//	for (int i = numslen - 1; i > -1; i--) {
	//		numCnt[nums[i]]++;
	//		for (auto& it : numCnt) {//主要是这里费时间
	//			if (it.first < nums[i]) {
	//				res[i] += it.second;
	//			}
	//		}
	//	}
	//	return res;
	//}

	//抄的答案
	//树状数组计算浅醉和，区间和
	//原数组为nums，
	//将nums离散化，此处是排序+去重，转化为数组a
	vector<int> a;
	//将nums对应a的元素update到树状数组c
	vector<int> c;

	//resize树状数组大小
	void init(int len) {
		c.resize(len);
	}

	//lowbit为二进制中最低位的1的值
	int lowbit(int x) {
		return x & (-x);
	}

	//单点更新，从子节点更新到所有父节点(祖父节点等一直往上到上限c.size())
	void update(int pos) {
		while (pos < c.size()) {
			c[pos] += 1;
			pos += lowbit(pos);
		}
	}

	//查询，实际是求和[0,...,pos]，即求1~pos的元素数量
	//如c[8]，在update时，a[1],a[2],a[3],...,a[8]都会使c[8]增加一个value（该题中我们设置为1）
	//res += c[8]，然后8减去lowbit为0。
	//也可以拿c[6]举例，c[6] =a[5]+a[6]，lowbit后，c[4] = a[1]+a[2]+a[3]+a[4]
	int query(int pos) {
		int res = 0;
		while (pos) {
			res += c[pos];
			pos -= lowbit(pos);
		}
		return res;
	}

	//离散化处理
	void Discretization(vector<int>& nums) {
		//拷贝数组 [5,4,5,3,2,1,1,1,1,1]
		a.assign(nums.begin(), nums.end());
		//排序[1,1,1,1,1,2,3,4,5,5]
		sort(a.begin(), a.end());
		//去重[1,2,3,4,5]
		a.erase(unique(a.begin(), a.end()), a.end());
	}

	int getId(int x) {
		//lower_bound返回第一个不小于x的迭代器
		//[1,2,3,4,5]中1，减去begin()再加1，得到id（1-5）
		return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
	}
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> res;
		int n = nums.size();
		//题解是+5，其实+1就够了，树状数组中我们不使用0下标，所以需扩展1位空间
		//当然直接用n结果也是对的。这里再推敲推敲
		init(n + 1);

		//将nums转化为a
		Discretization(nums);

		for (int i = n - 1; i >= 0; --i) {
			//倒序处理
			int id = getId(nums[i]);
			//查询严格小于id的元素数量，所以使用id-1
			res.push_back(query(id - 1));
			//更新id，其实更新也可以提前，因为查询是id-1，所以更新操作不影响当前结果
			update(id);
		}
		//倒序处理再倒序回来。如果不是用push_back，直接用下标可以不用在这里再倒序
		reverse(res.begin(), res.end());
		return res;
	}
};

int main(int argc, char* argv[]) {
	vector<string> wordList = { "bit" };
	string beginWord = "hit", endWord = "bit";
	Solution mySolution;
	vector<vector<char>> matrix = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'} };
	vector<vector<int>> M = {//2
		{1, 1, 0},
		{1, 1, 0},
		{0, 0, 1} };
	vector<vector<int>> M2 = {//1
		{1, 0, 0, 1},
		{0, 1, 1, 0},
		{0, 1, 1, 1},
		{1, 0, 1, 1} };
	vector<vector<int>> course = {
		{0, 1},
		{1, 0},
		{1, 2}
	};
	vector<vector<int>> nums = {
		{9, 9, 4},
		{6, 6, 8},
		{2, 1, 1}
	};
	vector<int> inptNums = { 5,2,6,1 };
	mySolution.countSmaller(inptNums);
	return 0;
}
#endif

//高级算法-回溯
#if false

class Solution {
public:
	//分割回文串
	//最耗时地方是判断回文
	vector<vector<string>> res;
	vector<string> path;
	vector<vector<string>> partition(string s) {
		cutString(s, 0, s.size());
		return res;
	}
	void cutString(string& s, int startIndex, int sLen) {
		if (startIndex == sLen) {
			res.push_back(path);
			return;
		}
		for (int i = startIndex; i < sLen; i++) {
			if (isPalindrome(s, startIndex, i)) {
				string str = s.substr(startIndex, i - startIndex + 1);
				path.push_back(str);
				cutString(s, i + 1, sLen);
				path.pop_back();
			}
		}
		return;
	}
	bool isPalindrome(string& s, int left, int right) {
		while (left < right) {
			if (s[left] != s[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
	//删除无效的括号
	//去重靠跳过相等字符
	vector<string> removeInvalidParentheses(string s) {
		int left = 0, right = 0;
		vector<string> res;
		int sLen = 0;
		for (char& ch : s) {
			if (ch == '(') {
				left++;
			}
			else if (ch == ')') {
				if (left > 0) {
					left--;
				}
				else {
					right++;
				}
			}
			sLen++;
		}
		dfs(s, 0, left, right, res);
		return res;
	}
	void dfs(string s, int start, int l, int r, vector<string>& res) {
		if (l == 0 && r == 0) {//不需要删除的括号为零
			if (isValid(s)) {
				res.push_back(s);
			}
			return;
		}
		size_t sLen = s.size();
		for (size_t i = start; i < sLen; i++) {
			if (i != start && s[i] == s[i - 1]) {//去重
				continue;
			}
			if (s[i] == '(' && l > 0) {
				dfs(s.substr(0, i) + s.substr(i + 1, sLen - i - 1), i, l - 1, r, res);
			}
			if (s[i] == ')' && r > 0) {
				dfs(s.substr(0, i) + s.substr(i + 1, sLen - i - 1), i, l, r - 1, res);
			}
		}
		return;
	}
	bool isValid(string& s) {//判断字符串是否有效
		int cnt = 0;
		for (char& c : s) {
			if (c == '(') {
				cnt++;
			}
			else if (c == ')') {
				cnt--;
				if (cnt < 0) {
					return false;
				}
			}
		}
		return cnt == 0;
	}
	//通配符匹配
	//动态规划
	//bool isMatch(string s, string p) {
	//	size_t sLen = s.size(), pLen = p.size();
	//	vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
	//	dp[0][0] = true;//dp[i][j] 表示字符串 s 的前 i 个字符和模式 p 的前 j 个字符是否能匹配
	//	for (size_t i = 1; i <= pLen; i++) {
	//		if (p[i - 1] == '*') {
	//			dp[0][i] = true;
	//		}
	//		else {
	//			break;//找到第一个不是*的p[i]
	//		}
	//	}
	//	for (size_t i = 1; i <= sLen; i++) {
	//		for (size_t j = 1; j <= pLen; j++) {
	//			if (p[j - 1] == '*') {
	//				dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
	//			}
	//			else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
	//				dp[i][j] = dp[i - 1][j - 1];
	//			}
	//		}
	//	}
	//	return dp[sLen][pLen];
	//}
	//正则表达式匹配
	bool isMatch(string s, string p) {
		size_t sLen = s.size(), pLen = p.size();
		vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
		dp[0][0] = true;
		for (size_t i = 1; i <= pLen; i++)
		{
			if (i >= 2 && p[i - 1] == '*' && dp[0][i - 2]) // 记得加 i >= 2的判断 
				dp[0][i] = true;
		}
		for (size_t i = 1; i < sLen + 1; i++) {
			for (size_t j = 1; j < pLen + 1; j++) {
				if (p[j - 1] == '*' && j > 1) {
					if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
						dp[i][j] = dp[i][j - 2];
					else
						dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
				}
				else if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) {//全字符匹配
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}
		return dp[sLen][pLen];
	}
};

int main(int argc, char* argv[]) {
	string s = "aa";
	string p = "a*";
	Solution mySolution;
	mySolution.isMatch(s, p);
	return 0;
}
#endif

//高级算法-搜索和排序
#if false

class Solution {
public:
	//摆动排序 II
	//其实就是找中位数
	//抄代码真香
	void wiggleSort(vector<int>& nums) {
		size_t numsLen = nums.size();
		auto midPtr = nums.begin() + numsLen / 2;
		nth_element(nums.begin(), midPtr, nums.end());
		int mid = *midPtr;
		size_t i = 0, j = 0, k = numsLen - 1;
		while (j < k) {
			if (nums[j] > mid) {
				swap(nums[j], nums[k]);
				k--;
			}
			else if (nums[j] < mid) {
				swap(nums[j], nums[i]);
				i++;
				j++;
			}
			else {
				j++;
			}
		}
		if (numsLen % 2 == 1) {
			midPtr++;
		}
		vector<int> tmpL(nums.begin(), midPtr);
		vector<int> tmpU(midPtr, nums.end());
		size_t tmpLLen = tmpL.size();
		size_t tmpULen = tmpU.size();
		for (size_t i = 0; i < tmpLLen; i++) {
			nums[2 * i] = tmpL[tmpLLen - 1 - i];
		}
		for (size_t i = 0; i < tmpULen; i++) {
			nums[2 * i + 1] = tmpU[tmpULen - 1 - i];
		}
		return;
	}
	//有序矩阵中第K小的元素
	//矩阵行列递增
	//用二分查找
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int matrixDegree = matrix.size();
		int lwr = matrix[0][0], upr = matrix[matrixDegree - 1][matrixDegree - 1];
		while (lwr < upr) {
			int mid = lwr + (upr - lwr) / 2;
			if (check(matrix, matrixDegree, mid, k)) {
				upr = mid;
			}
			else {
				lwr = mid + 1;
			}
		}
		return lwr;
	}
	bool check(vector<vector<int>>& matrix, int matrixDegree, int mid, int k) {
		int colCur = matrixDegree - 1, rolCur = 0, res = 0;
		while (colCur > -1 && rolCur < matrixDegree) {
			if (matrix[colCur][rolCur] <= mid) {
				res += colCur + 1;
				rolCur++;
			}
			else {
				colCur--;
			}
		}
		return res >= k;
	}
};

int main(int argc, char* argv[]) {
	string s = "aa";
	string p = "a*";
	Solution mySolution;
	vector<int> nums1 = { 1, 5, 1, 1, 6, 4 };
	vector<int> nums2 = { 1, 3, 2, 2, 3, 1 };
	vector<vector<int>> marrix = {
		{1, 5, 9},
		{10, 11, 13},
		{12, 13, 15} };
	mySolution.kthSmallest(marrix, 8);
	return 0;
}
#endif

//高级算法-动态规划
#if false

class Solution {
public:
	//乘积最大子数组
	int maxProduct(vector<int>& nums) {
		size_t numsLen = nums.size();
		int maxVal = nums[0], minVal = nums[0], res = nums[0];
		for (size_t i = 1; i < numsLen; i++) {
			int maxTmp = maxVal, minTmp = minVal;
			maxVal = max(maxTmp * nums[i], max(nums[i], minTmp * nums[i]));
			minVal = min(minTmp * nums[i], min(nums[i], maxTmp * nums[i]));
			res = max(maxVal, res);
		}
		return res;
	}
	//最佳买卖股票时机含冷冻期
	int maxProfit(vector<int>& nums) {
		size_t numsLen = nums.size();
		if (numsLen < 1) {
			return 0;
		}
		//vector<vector<int>> dp(3, vector<int>(numsLen));
		int dp0 = -nums[0], dp1 = 0, dp2 = 0;
		//dp[0][0] = -nums[0];//买入负收益,持有状态
		//dp[1][0] = 0;//冷却期累计收益，非持有
		//dp[2][0] = 0;//非冷却期累计收益，非持有
		for (size_t i = 1; i < numsLen; i++) {
			//dp[0][i] = max(dp[0][i - 1], dp[2][i - 1] - nums[i]);//今天结束时持有，可能是昨天持有或者今天买入的
			//dp[1][i] = dp[0][i - 1] + nums[i];//今天结束时在冷静期，肯定是今天卖了
			//dp[2][i] = max(dp[1][i - 1], dp[2][i - 1]);//今天结束时没持有且不在冷静期，昨天可能是冷静期或者不是冷静期
			int dp0n = max(dp0, dp2 - nums[i]);
			int dp1n = dp0 + nums[i];
			int dp2n = max(dp1, dp2);
			dp0 = dp0n, dp1 = dp1n, dp2 = dp2n;
		}
		//return max(dp[1][numsLen - 1], dp[2][numsLen - 1]);
		return max(dp1, dp2);
	}
	//完全平方数
	//动态规划，转移方程：dp[i] = min(dp[i - k^2]) + 1, 其中i >= k^2
	int numSquares(int n) {
		vector<int> dp(n + 1);
		dp[0] = 0;
		dp[1] = 1;
		for (size_t i = 2; i <= n; i++) {
			int minCnt = 5;
			size_t tmp = 1;
			for (tmp = 1; i >= tmp * tmp; tmp++) {
				minCnt = min(minCnt, dp[i - tmp * tmp]);
			}
			dp[i] = minCnt + 1;
		}
		return dp[n];
	}
	//单词拆分
	//能拆分的单词总是等于前一个已拆分的加上一个在词典中的单词
	//如果改成从后往前推可能会更快一些
	/*bool wordBreak(string s, vector<string>& wordDict) {
		size_t sLen = s.size();
		unordered_set<string> dictSet;
		for (string& str : wordDict) {
			dictSet.emplace(str);
		}
		vector<bool> dp(sLen + 1, false);
		dp[0] = true;
		string tmp;
		for (size_t i = 0; i < sLen; i++) {
			for (size_t j = 0; j <= i; j++) {
				if (dp[j]) {
					tmp = s.substr(j, i + 1 - j);
					if (dictSet.count(tmp) > 0) {
						dp[i + 1] = true;
						break;
					}
				}
			}
		}
		return dp[sLen];
	}*/
	//单词拆分 II
	//递归没剪枝
	/*unordered_set<string>* dictSet;
	size_t sLen;
	vector<string> res;
	string tmp;
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		sLen = s.size();
		dictSet = new unordered_set<string>(wordDict.begin(), wordDict.end());
		sliceString(s, 0);
		return res;
	}
	void sliceString(string& s, size_t cur) {
		if (cur >= sLen) {
			tmp.pop_back();
			res.emplace_back(tmp);
			return;
		}
		string local;
		for (size_t i = cur; i <= sLen; i++) {
			local = s.substr(cur, i - cur);
			if (dictSet->count(local) > 0) {
				size_t tmpLen = tmp.size();
				tmp.append(local);
				tmp.push_back(' ');
				sliceString(s, i);
				tmp = tmp.substr(0, tmpLen);
			}
		}
		return;
	}*/
	//优化递归
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		vector<string> res;
		return backtrack(s, 0, dict);
	}
	unordered_map<int, vector<string>> memo;//记忆化
	vector<string> backtrack(string& s, int start, unordered_set<string>& dict) {
		if (start == s.size()) {
			return { "" };
		}

		if (memo.count(start)) {//这个位置以后的所有单词排列组合
			return memo[start];
		}

		vector<string> res;
		for (size_t i = start; i < s.size(); i++) {
			auto prefix = s.substr(start, i - start + 1);//前缀单词
			if (dict.count(prefix)) {
				auto suffixes = backtrack(s, i + 1, dict);//后缀单词表排列组合
				for (const auto& suffix : suffixes) {
					auto str = prefix;//新建一个排列
					if (!suffix.empty()) {
						str += ' ' + suffix;
					}
					res.push_back(str);
				}
			}
		}

		memo[start] = res;//储存后缀排列组合并返回
		return memo[start];
	}
	//戳气球
	//关键点在于最后一个戳破的气球，开区间中任意一个戳破的气球
	int maxCoins(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		vector<int> numsCopy(1, 1);
		numsCopy.insert(numsCopy.end(), nums.begin(), nums.end());
		numsCopy.push_back(1);
		size_t numsLen = numsCopy.size();
		vector<vector<int>> dp(numsLen, vector<int>(numsLen, 0));//头尾各一个1
		size_t lenUb = numsLen + 1;
		for (size_t len = 3; len < lenUb; len++) {//区间长度循环
			size_t curUb = numsLen - len + 1;
			for (size_t cur = 0; cur < curUb; cur++) {//起始位置循环
				size_t posUb = cur + len - 1;
				int maxVal = -1;
				for (size_t j = cur + 1; j < posUb; j++) {//区间内循环
					int left = dp[cur][j];
					int right = dp[j][posUb];
					int sum = left + right + numsCopy[cur] * numsCopy[j] * numsCopy[posUb];
					if (sum > maxVal) {
						maxVal = sum;
					}
				}
				dp[cur][posUb] = maxVal;
			}
		}
		return dp[0][numsLen - 1];
	}
};

int main(int argc, char* argv[]) {
	string s = "aa";
	string p = "a*";
	string word = "catsanddog";
	string word2 = "a";
	vector<string> dict = { "cat", "cats", "and", "sand", "dog" };
	vector<string> dict2 = { "a" };
	Solution mySolution;
	vector<int> nums1 = { 1, 5, 1, 1, 6, 4 };
	vector<int> nums2 = { 1, 3, 2, 2, 3, 1 };
	vector<int> nums = { 3,1,5,8 };
	vector<vector<int>> marrix = {
		{1, 5, 9},
		{10, 11, 13},
		{12, 13, 15} };
	mySolution.maxCoins(nums);
	return 0;
}
#endif

//高级算法-设计问题
#if false

class LRUCache {//LRU缓存机制
public:
	//读取写入都算一次访问
	LRUCache(int capacity) {//设置缓存容量
		capLim = capacity;
		map = new unordered_map<int, node*>;
		head = new node;
		tail = new node;
		head->rear = tail;
		tail->front = head;
		return;
	}

	int get(int key) {
		if (map->count(key) < 1) {
			return -1;
		}
		moveToFront((*map)[key]);
		return (*map)[key]->val;
	}

	void put(int key, int value) {
		int cnt = map->size();
		if (map->count(key) < 1) {//添加元素
			addFront(key, value);
			if (cnt == capLim) {
				deleteTail();
			}
			(*map)[key] = head->rear;
		}
		else {//更新元素
			(*map)[key]->val = value;
			moveToFront((*map)[key]);
		}
		return;
	}
private:
	struct node {//双向链表，高频访问在前
		node* front = nullptr, * rear = nullptr;
		int key = -1;
		int val = -1;
	};
	int capLim = -1;
	//两个假节点
	node* head = nullptr;
	node* tail = nullptr;
	unordered_map<int, node*>* map;//加速缓存
	void moveToFront(node* cur) {//访问过就提到最前
		if (cur == head->rear) {
			return;
		}
		cur->front->rear = cur->rear;
		cur->rear->front = cur->front;
		cur->rear = head->rear;
		head->rear->front = cur;
		cur->front = head;
		head->rear = cur;
		return;
	}
	void deleteTail() {//删除最低频访问数据
		node* tmp = tail->front;
		tail->front = tmp->front;
		tmp->front->rear = tail;
		map->erase(tmp->key);//注意删除节点
		delete tmp;
		return;
	}
	void addFront(int key, int val) {//添加一个新元素
		node* tmp = new node;
		tmp->key = key;
		tmp->val = val;
		tmp->rear = head->rear;
		head->rear->front = tmp;
		tmp->front = head;
		head->rear = tmp;
		return;
	}
};

class Trie {//实现 Trie (前缀树)
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new treeNode;
		return;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		treeNode* current = root;
		for (char& ch : word) {
			if (current->next.count(ch) < 1) {
				current->next[ch] = new treeNode;
				current->next[ch]->val = ch;
			}
			current = current->next[ch];
		}
		current->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		treeNode* current = root;
		for (char& ch : word) {
			if (current->next.count(ch) > 0) {
				current = current->next[ch];
			}
			else {
				return false;
			}
		}
		return current->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		treeNode* current = root;
		for (char& ch : prefix) {
			if (current->next.count(ch) > 0) {
				current = current->next[ch];
			}
			else {
				return false;
			}
		}
		return current->isWord || current->next.size() != 0;
	}
private:
	struct treeNode {
		char val = '*';
		bool isWord = false;
		unordered_map<char, treeNode*> next;
	};
	treeNode* root;
};

class MedianFinder {//数据流的中位数
public:
	/** initialize your data structure here. */
	MedianFinder() {
		return;
	}

	void addNum(int num) {
		lo.push(num);
		hi.push(lo.top());
		lo.pop();
		if (lo.size() < hi.size()) {//只有一个元素的时候
			lo.push(hi.top());
			hi.pop();
		}
		return;
	}

	double findMedian() {
		return lo.size() > hi.size() ? lo.top() : (lo.top() + hi.top()) * 0.5;
	}
private:
	priority_queue<int> lo; //大顶 小数
	priority_queue<int, vector<int>, greater<int>> hi;//小顶 大数
};

int main(int argc, char* argv[]) {
	LRUCache cacheDesign(2);
	Trie myTrie;
	myTrie.insert("apple");
	myTrie.search("apple");
	myTrie.search("app");
	myTrie.startsWith("app");
	myTrie.insert("app");
	myTrie.search("app");
	return 0;
}
#endif

//高级算法-数学
#if false
int Larger(int a, int b) {
	string s1 = to_string(a);
	string s2 = to_string(b);
	return (s1 + s2) > (s2 + s1);
}
class Solution {
public:
	string largestNumber(vector<int>& nums) {//最大数
		size_t numsLen = nums.size();
		string res;
		if (numsLen == 0) {
			return res;
		}
		if (numsLen == 1) {
			return to_string(nums[0]);
		}
		sort(nums.begin(), nums.end(), Larger);//将函数作为参数
		if (nums[0] == 0) {
			return "0";
		}
		for (size_t i = 0; i < numsLen; i++) {
			res += to_string(nums[i]);
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	vector<int> nums = { 3,30,34,5,9 };
	mySolution.largestNumber(nums);
	return 0;
}
#endif

//高级算法-其他
#if false
int compare(vector<int>& a, vector<int>& b) {
	return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
}
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		size_t peopleCnt = people.size();
		sort(people.begin(), people.end(), compare);
		vector<vector<int>> res(peopleCnt);
		for (auto& it : people) {
			int blnk = it[1] + 1;
			for (size_t i = 0; i < peopleCnt; i++) {
				if (res[i].empty()) {
					blnk--;
					if (blnk == 0) {
						res[i] = it;
						break;
					}
				}
			}
		}
		return res;
	}
	int trapBrutal(vector<int>& height) {//从低到高灌水超时
		size_t heitCnt = height.size();
		if (heitCnt < 3) {
			return 0;
		}
		int res = 0;
		int currentHeit = height[0];
		int maxVal = -1, minVal = 65535;
		for (size_t i = 0; i < heitCnt; i++) {
			maxVal = max(height[i], maxVal);
			minVal = min(height[i], minVal);
		}
		size_t left = 0, right = heitCnt - 1;
		for (size_t i = minVal; i <= maxVal; i++) {
			while (height[left] < i) {
				left++;
			}
			while (height[right] < i) {
				right--;
			}
			for (size_t j = left; j <= right; j++) {
				if (height[j] < i) {
					height[j]++;
					res++;
				}
			}
		}
		return res;
	}
	int trapDualPointer(vector<int>& height) {//双指针
		size_t heitCnt = height.size();
		if (heitCnt < 3) {
			return 0;
		}
		int res = 0;
		size_t leftCur = 0, rightCur = heitCnt - 1;
		while (leftCur < rightCur) {
			int heit = min(height[leftCur], height[rightCur]);
			for (size_t i = leftCur + 1; i < rightCur; i++) {
				if (height[i] < heit) {
					res += heit - height[i];
					height[i] = heit;
				}
			}
			if (height[leftCur] <= height[rightCur]) {
				leftCur++;
			}
			else {
				rightCur--;
			}
		}
		return res;
	}
	int trap(vector<int>& height) {//动态规划接雨水
		size_t heitCnt = height.size();
		if (heitCnt < 3) {
			return 0;
		}
		int res = 0;
		vector<int> left(heitCnt), right(heitCnt);
		int currentLeft = height[0], currentRight = height[heitCnt - 1];
		for (size_t i = 0; i < heitCnt; i++) {
			if (height[i] > currentLeft) {
				currentLeft = height[i];
			}
			left[i] = currentLeft;
			if (height[heitCnt - i - 1] > currentRight) {
				currentRight = height[heitCnt - i - 1];
			}
			right[heitCnt - i - 1] = currentRight;
		}
		for (size_t i = 0; i < heitCnt; i++) {
			res += min(left[i], right[i]) - height[i];
		}
		return res;
	}
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		vector<vector<int>> res;
		multiset<pair<int, int>> all;//自动排序可重复
		for (vector<int>& building : buildings) {
			all.insert(make_pair(building[0], -building[2]));
			all.insert(make_pair(building[1], building[2]));
		}
		multiset<int> height({ 0 });//保持一个默认值，防止暴雷
		vector<int> last(2);
		for (auto& it : all) {
			if (it.second < 0) {
				height.insert(-it.second);
			}
			else {
				height.erase(height.find(it.second));
			}
			auto maxHeight = *height.rbegin();
			if (last[1] != maxHeight) {
				last[0] = it.first;
				last[1] = maxHeight;
				res.push_back(last);
			}
		}
		return res;
	}
	int largestRectangleArea(vector<int>& heights) {
		size_t heitCnt = heights.size();
		if (heitCnt == 1) {
			return heights[0];
		}
		stack<int> stk;
		int res = 0;
		for (size_t i = 0; i < heitCnt; i++) {
			while (!stk.empty() && heights[stk.top()] > heights[i]) {
				int ht = heights[stk.top()];
				stk.pop();
				int len = i;
				if (!stk.empty()) {
					len = i - stk.top() - 1;
				}
				res = max(res, len * ht);
			}
			stk.push(i);
		}
		while (!stk.empty()) {
			int ht = heights[stk.top()];
			stk.pop();
			int len = heitCnt;
			if (!stk.empty()) {
				len = heitCnt - stk.top() - 1;
			}
			res = max(res, len * ht);
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	vector<vector<int>> buildings = {
		{2,9,10},
		{3,7,15},
		{5,12,12},
		{15,20,10},
		{19,24,8} };
	vector<int> heit1 = { 2,1,5,6,2,3 };
	vector<int> heit2 = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	mySolution.largestRectangleArea(heit1);
	return 0;
}
#endif

//目标和-补充
#if false

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {//目标和--动态规划
		size_t numsLen = nums.size();
		vector<vector<int>> dp(numsLen, vector<int>(2001));//dp[i][j]:前i个数和为j的方案数
		dp[0][1000 + nums[0]] = 1;
		dp[0][1000 - nums[0]] += 1;
		for (size_t i = 1; i < numsLen; i++) {
			for (int j = 0; j < 2001; j++) {
				int tmpMinus = j - nums[i] >= 0 ? dp[i - 1][j - nums[i]] : 0;
				int tmpPosit = j + nums[i] < 2001 ? dp[i - 1][j + nums[i]] : 0;
				dp[i][j] = tmpMinus + tmpPosit;
			}
		}
		return S > 1000 || S < -1000 ? 0 : dp[numsLen - 1][S + 1000];
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	vector<int> nums = { 1, 999 };
	mySolution.findTargetSumWays(nums, 998);
	return 0;
}
#endif

//面试问题
#if false

class Solution {
public:
	int superEggDrop(int K, int N) {//鸡蛋掉落
		if (N == 1) {
			return 1;
		}
		vector<vector<int>> dp(N + 1, vector<int>(K + 1));//抛i次， j个鸡蛋能确定的最高楼层
		for (size_t i = 1; i <= K; i++) {
			dp[1][i] = 1;
		}
		int ans = -1;
		for (size_t i = 2; i <= N; i++) {
			for (size_t j = 1; j <= K; j++) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + 1;
			}
			if (dp[i][K] >= N) {
				ans = i;
				break;
			}
		}
		return ans;
	}
	int longestSubstring(string s, int k) {
		size_t sLen = s.size();
		unordered_map<char, int> sMap;
		for (char& ch : s) {
			sMap[ch]++;
		}
		vector<int> split;
		for (size_t i = 0; i < sLen; i++) {
			if (sMap[s[i]] < k) {
				split.push_back(i);
			}
		}
		split.push_back(sLen);
		size_t splitLen = split.size();
		if (splitLen == 1) {
			return sLen;
		}
		int ans = 0, left = 0;
		for (size_t i = 0; i < splitLen; i++) {
			int len = split[i] - left;
			if (len > ans) {
				ans = max(ans, longestSubstring(s.substr(left, len), k));
			}
			left = split[i] + 1;
		}
		return ans;
	}
	int longestSubstring2(string s, int k) {
		unordered_map<char, int> umap;
		for (auto c : s) umap[c]++;
		vector<int> split;
		for (int i = 0; i < s.size(); i++) {
			if (umap[s[i]] < k) split.push_back(i);
		}
		if (split.size() == 0) return s.length();
		int ans = 0, left = 0;
		split.push_back(s.length());
		for (int i = 0; i < split.size(); i++) {
			int len = split[i] - left;
			if (len > ans) ans = max(ans, longestSubstring2(s.substr(left, len), k));
			left = split[i] + 1;
		}
		return ans;
	}
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {//加油站-贪心
		size_t gasCnt = gas.size();
		int minVal = INT_MAX;
		int res = 0;
		int spareGas = 0;
		for (size_t i = 0; i < gasCnt; i++) {//剩余油量折线图在平面上下左右平移
			spareGas += gas[i] - cost[i];
			if (spareGas < minVal) {
				res = i;
				minVal = spareGas;
			}
		}
		return spareGas < 0 ? -1 : (res + 1) % gasCnt;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string s = "weitong";
	vector<int> gas = { 1,2,3,4,5 };
	vector<int> cost = { 3,4,5,1,2 };
	mySolution.canCompleteCircuit(gas, cost);
	return 0;
}
#endif

//cookBook-数组
#if false 

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {//最接近的三数之和
		size_t numsLen = nums.size();
		sort(nums.begin(), nums.end());
		int diff = INT_MAX;
		int res = -1;
		for (size_t i = 0; i < numsLen; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			size_t leftCur = i + 1, rightCur = numsLen - 1;
			while (leftCur < rightCur) {
				int sum = nums[i] + nums[leftCur] + nums[rightCur];
				if (sum == target) {
					return target;
				}
				if (abs(sum - target) < diff) {
					diff = abs(sum - target);
					res = sum;
				}
				if (sum > target) {
					size_t rightCurBak = rightCur - 1;
					while (rightCurBak > leftCur && nums[rightCur] == nums[rightCurBak]) {
						rightCurBak--;
					}
					rightCur = rightCurBak;
				}
				else {
					size_t leftCurBak = leftCur + 1;
					while (leftCurBak < rightCur && nums[leftCur] == nums[leftCurBak]) {
						leftCurBak++;
					}
					leftCur = leftCurBak;
				}
			}
		}
		return res;
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {//组合总和--回溯
		sort(candidates.begin(), candidates.end());
		size_t candLen = candidates.size();
		vector<int> tmp;
		vector<vector<int>> res;
		dfs1(res, candidates, 0, tmp, target, candLen);
		return res;
	}
	void dfs1(vector<vector<int>>& res, vector<int>& candidates, int cur, vector<int>& combine, int target, size_t candLen) {
		if (cur == candLen) {
			return;
		}
		if (target == 0) {
			res.emplace_back(combine);
			return;
		}
		dfs1(res, candidates, cur + 1, combine, target, candLen);//不取当前的
		if (target - candidates[cur] >= 0) {
			combine.emplace_back(candidates[cur]);
			dfs1(res, candidates, cur, combine, target - candidates[cur], candLen);
			combine.pop_back();
		}
		return;
	}
	//与上一题一样，有重复元素， 结果不允许重复
	vector<pair<int, int>> freq;
	vector<vector<int>> res;
	vector<int> tmp;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		for (int& num : candidates) {
			if (freq.empty() || freq.back().first != num) {
				freq.push_back(make_pair(num, 1));
			}
			else {
				freq.back().second++;
			}
		}
		size_t freqLen = freq.size();
		dfs2(0, freqLen, target);
		return res;
	}
	void dfs2(size_t pos, size_t freqLen, int target) {
		if (target == 0) {
			res.push_back(tmp);
			return;
		}
		if (pos == freqLen || freq[pos].first > target) {
			return;
		}
		dfs2(pos + 1, freqLen, target);
		int most = min(target / freq[pos].first, freq[pos].second) + 1;//重复数量上限
		for (size_t i = 1; i < most; i++) {
			tmp.push_back(freq[pos].first);
			dfs2(pos + 1, freqLen, target - i * freq[pos].first);
		}
		for (size_t i = 1; i < most; i++) {
			tmp.pop_back();
		}
		return;
	}
	vector<vector<int>> generateMatrix(int n) {//螺旋矩阵输出
		vector<vector<int>> res(n, vector<int>(n));
		int start = 1;
		for (size_t i = 0; i < n / 2; i++) {
			start = buildMatrix(i, n, start, res);
		}
		if (n % 2 == 1) {
			res[n / 2][n / 2] = start;
		}
		return res;
	}
	int buildMatrix(size_t cur, size_t dim, int begin, vector<vector<int>>& res) {
		for (size_t i = cur; i < dim - cur - 1; i++) {
			res[cur][i] = begin++;
		}
		for (size_t i = cur; i < dim - cur - 1; i++) {
			res[i][dim - cur - 1] = begin++;
		}
		for (size_t i = dim - cur - 1; i > cur; i--) {
			res[dim - cur - 1][i] = begin++;
		}
		for (size_t i = dim - cur - 1; i > cur; i--) {
			res[i][cur] = begin++;
		}
		return begin;
	}
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {//不同路径 II--动态规划
		size_t col = obstacleGrid.size(), rol = obstacleGrid[0].size();
		for (size_t i = 0; i < col; i++) {
			for (size_t j = 0; j < rol; j++) {
				if (obstacleGrid[i][j] == 1) {
					obstacleGrid[i][j] = -1;
				}
			}
		}
		for (size_t i = 0; i < col; i++) {
			if (obstacleGrid[i][0] == -1) {
				break;
			}
			obstacleGrid[i][0] = 1;
		}
		for (size_t j = 0; j < rol; j++) {
			if (obstacleGrid[0][j] == -1) {
				break;
			}
			obstacleGrid[0][j] = 1;
		}
		for (size_t i = 1; i < col; i++) {
			for (size_t j = 1; j < rol; j++) {
				if (obstacleGrid[i][j] == -1) {
					continue;
				}
				int op1 = obstacleGrid[i - 1][j] == -1 ? 0 : obstacleGrid[i - 1][j];
				int op2 = obstacleGrid[i][j - 1] == -1 ? 0 : obstacleGrid[i][j - 1];
				obstacleGrid[i][j] = op1 + op2;
			}
		}
		return obstacleGrid[col - 1][rol - 1] == -1 ? 0 : obstacleGrid[col - 1][rol - 1];
	}
	int minPathSum(vector<vector<int>>& grid) {//最小路径和
		size_t col = grid.size(), rol = grid[0].size();
		for (size_t i = 1; i < col; i++) {
			grid[i][0] += grid[i - 1][0];
		}
		for (size_t i = 1; i < rol; i++) {
			grid[0][i] += grid[0][i - 1];
		}
		for (size_t i = 1; i < col; i++) {
			for (size_t j = 1; j < rol; j++) {
				grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
			}
		}
		return grid[col - 1][rol - 1];
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {//搜索二维矩阵, 二分法
		size_t col = matrix.size();
		if (col == 0) {
			return false;
		}
		size_t rol = matrix[0].size();
		int left = 0, right = col * rol - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int val = matrix[mid / rol][mid % rol];
			if (val == target) {
				return true;
			}
			else if (val > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return false;
	}
	bool search(vector<int>& nums, int target) {//搜索旋转排序数组 II--二分法
		int numsLen = nums.size();
		int pivot = 0;
		for (int i = 1; i < numsLen; i++) {
			if (nums[i - 1] > nums[i]) {
				pivot = i - 1;
				break;
			}
		}
		int left = 0, right = pivot;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int val = nums[mid];
			if (val == target) {
				return true;
			}
			else if (val > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		left = pivot + 1;
		right = numsLen - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int val = nums[mid];
			if (val == target) {
				return true;
			}
			else if (val > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return false;
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {//子集 II--位操作
		sort(nums.begin(), nums.end());
		size_t numsLen = nums.size();
		size_t curReg = 1 << numsLen;//表
		vector<int> tmp;
		vector<vector<int>> res;
		for (size_t i = 0; i < curReg; i++) {
			tmp.clear();
			bool flag = true;
			for (size_t j = 0; j < numsLen; j++) {
				if (i & (1 << j)) {//取每一位
					if (j != 0 && nums[j] == nums[j - 1] && ((i & (1 << (j - 1))) == 0)) {//确保取的是100，110，111这种
						flag = false;
						break;
					}
					tmp.push_back(nums[j]);
				}
			}
			if (flag) {
				res.push_back(tmp);
			}
		}
		return res;
	}
	int minimumTotal(vector<vector<int>>& triangle) {//三角形最小路径和--dp
		size_t triStep = triangle.size();
		for (size_t i = 1; i < triStep; i++) {
			triangle[i][0] += triangle[i - 1][0];
			triangle[i][i] += triangle[i - 1][i - 1];
			for (size_t j = 1; j < i; j++) {
				triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
			}
		}
		int res = INT_MAX;
		for (size_t i = 0; i < triStep; i++) {
			res = min(res, triangle[triStep - 1][i]);
		}
		return res;
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {//单词接龙 II--BFS
		int id = 0;
		size_t sLen = wordList[0].size();
		size_t wordCnt = wordList.size();
		for (string& str : wordList) {
			if (nodeMap.count(str) < 1) {//入库并分配ID
				nodeMap[str] = id++;
				idWord.push_back(str);
			}
		}
		if (nodeMap.count(endWord) < 1) {
			return {};
		}
		if (nodeMap.count(beginWord) < 1) {
			nodeMap[beginWord] = id++;
			idWord.push_back(beginWord);
		}
		//添加边
		edges.resize(idWord.size());
		for (size_t i = 0; i < id; i++) {
			for (size_t j = i + 1; j < id; j++) {
				if (checkSibil(idWord[i], idWord[j], sLen)) {
					edges[i].push_back(j);
					edges[j].push_back(i);
				}
			}
		}
		int endID = nodeMap[endWord];
		vector<vector<string>> res;
		queue<vector<int>> q;
		vector<int> cost(id, 1 << 10);
		q.push(vector<int>{nodeMap[beginWord]});//挤一个进去，开始ID
		cost[nodeMap[beginWord]] = 0;//储存begin变换到位所需次数
		while (!q.empty()) {
			vector<int> current = q.front();
			q.pop();
			int last = current.back();
			if (last == endID) {//跳到了就没必要往下跳了
				vector<string> tmp;//结果
				for (int index : current) {
					tmp.push_back(idWord[index]);
				}
				res.push_back(tmp);
			}
			else {
				size_t lastSize = edges[last].size();
				for (size_t i = 0; i < lastSize; i++) {//只有找到了更近的距离，cost才会更新
					int to = edges[last][i];
					if (cost[last] + 1 <= cost[to]) {
						cost[to] = cost[last] + 1;
						vector<int> tmp(current);//保存整个过程ID
						tmp.push_back(to);
						q.push(tmp);
					}
				}
			}
		}
		return res;
	}
	bool checkSibil(string& str1, string& str2, size_t sLen) {
		int diff = 0;
		for (size_t i = 0; i < sLen && diff < 2; i++) {
			if (str1[i] != str2[i]) {
				diff++;
			}
		}
		return diff == 1;
	}
	unordered_map<string, int> nodeMap;
	vector<string> idWord;
	vector<vector<int>> edges;
	vector<vector<int>> combinationSum3(int k, int n) {//组合总和 III
		vector<vector<int>> res;
		vector<int> tmp;
		combinationSum3DFS(1, 9, k, n, res, tmp);//当前枚举，枚举上限，数量，总和
		return res;
	}
	void combinationSum3DFS(int cur, int n, int k, int sum, vector<vector<int>>& res, vector<int>& tmp) {
		if (tmp.size() + (n - cur + 1) < k || tmp.size() > k) {//数量不够或数量多了
			return;
		}
		if (tmp.size() == k && accumulate(tmp.begin(), tmp.end(), 0) == sum) {
			res.push_back(tmp);
			return;
		}
		tmp.push_back(cur);
		combinationSum3DFS(cur + 1, n, k, sum, res, tmp);
		tmp.pop_back();
		combinationSum3DFS(cur + 1, n, k, sum, res, tmp);
		return;
	}
	vector<int> majorityElement(vector<int>& nums) {//求众数 II--投票法
		int num1 = -1, num2 = -1;
		int num1Cnt = 0, num2Cnt = 0;
		for (int& num : nums) {
			if (num == num1) {
				num1Cnt++;
			}
			else if (num == num2) {
				num2Cnt++;
			}
			else if (num1Cnt == 0) {
				num1 = num;
				num1Cnt++;
			}
			else if (num2Cnt == 0) {
				num2 = num;
				num2Cnt++;
			}
			else {
				num1Cnt--;
				num2Cnt--;
			}
		}
		vector<int> res;
		num1Cnt = 0;
		num2Cnt = 0;
		for (int& num : nums) {
			if (num == num1) {
				num1Cnt++;
			}
			else if (num == num2) {
				num2Cnt++;
			}
		}
		if (num1Cnt > nums.size() / 3) {
			res.push_back(num1);
		}
		if (num2Cnt > nums.size() / 3) {
			res.push_back(num2);
		}
		return res;
	}
	int thirdMax(vector<int>& nums) {//第三大的数
		int max3 = INT_MIN, max2 = INT_MIN, max1 = INT_MIN;
		int tmp1 = nums[0], tmp2 = nums[0], tmp3 = nums[0];
		for (int& num : nums) {
			if (num != tmp1) {//得到3个不同的数
				if (tmp1 != tmp2) {
					tmp3 = num;
				}
				else {
					tmp2 = num;
				}
			}
			if (num == max1 || num == max2 || num == max3) {
				continue;
			}
			if (num > max1) {
				max3 = max2;
				max2 = max1;
				max1 = num;
			}
			else if (num > max2) {
				max3 = max2;
				max2 = num;
			}
			else if (num > max3) {
				max3 = num;
			}
		}
		if (tmp1 == tmp2 || tmp2 == tmp3 || tmp1 == tmp3) {
			return max1;
		}
		return max3;
	}
	vector<int> findDisappearedNumbers(vector<int>& nums) {//找到所有数组中消失的数字
		size_t numsLen = nums.size();
		for (size_t i = 0; i < numsLen; i++) {
			int cur = abs(nums[i]) - 1;
			nums[cur] = -abs(nums[cur]);
		}
		vector<int> res;
		for (int i = 0; i < numsLen; i++) {
			if (nums[i] > 0) {
				res.push_back(i + 1);
			}
		}
		return res;
	}
	bool circularArrayLoop(vector<int>& nums) {//环形数组循环
		const size_t numsLen = nums.size();
		for (int i = 0; i < numsLen; i++) {
			if (nums[i] == 0) {
				continue;
			}
			int dir = nums[i] > 0 ? 1 : -1;
			if (circularArrayLoopDFS(nums, i, numsLen, dir)) {
				return true;
			}
		}
		return false;
	}
	bool circularArrayLoopDFS(vector<int>& nums, int i, int numsLen, int dir) {
		if (nums[i] == 0) {//
			return false;
		}
		if (nums[i] == INT_MAX) {//形成闭环
			return true;
		}
		int ndir = nums[i] > 0 ? 1 : -1;
		if (ndir == dir) {
			int j = (numsLen + (nums[i] + i) % numsLen) % numsLen;
			nums[i] = INT_MAX;//考察过程中
			if (j != i && circularArrayLoopDFS(nums, j, numsLen, dir)) {
				return true;
			}
			else {
				nums[i] = 0;//确定不符合条件不能成环
				return false;
			}
		}
		return false;
	}
	int islandPerimeterBFS(vector<vector<int>>& grid) {//岛屿的周长--BFS
		size_t col = grid.size();
		if (col == 0) {
			return 0;
		}
		size_t rol = grid[0].size();
		queue<pair<int, int>> q;
		for (size_t i = 0; i < col; i++) {
			for (size_t j = 0; j < rol; j++) {
				if (grid[i][j] == 1) {
					q.push(make_pair(i, j));//从一个角开始
					break;
				}
			}
			if (!q.empty()) {
				break;
			}
		}
		int res = 0;
		vector<vector<int>> dir = {
			{-1, 0},
			{0, 1},
			{1, 0},
			{0, -1} };
		while (!q.empty()) {
			int colCur = q.front().first;
			int rolCur = q.front().second;
			q.pop();
			int remain = 4;
			if (grid[colCur][rolCur] == 2) {
				continue;
			}
			grid[colCur][rolCur] = 2;
			for (size_t i = 0; i < 4; i++) {
				int tmpCol = colCur + dir[i][0];
				int tmpRol = rolCur + dir[i][1];
				if (tmpCol < 0 || tmpCol >= col || tmpRol < 0 || tmpRol >= rol) {
					continue;
				}
				if (grid[tmpCol][tmpRol] == 2) {
					remain--;
					continue;
				}
				if (grid[tmpCol][tmpRol] == 1) {
					remain--;
					q.push(make_pair(tmpCol, tmpRol));
				}
			}
			res += remain;
		}
		return res;
	}
	int islandPerimeter(vector<vector<int>>& grid) {//岛屿的周长--暴力法
		size_t col = grid.size();
		if (col == 0) {
			return 0;
		}
		size_t rol = grid[0].size();
		int res = 0;
		vector<vector<int>> dir = {
			{-1, 0},
			{0, 1},
			{1, 0},
			{0, -1} };
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < rol; j++) {
				if (grid[i][j] == 1) {
					int remain = 4;
					for (size_t k = 0; k < 4; k++) {
						int tmpCol = i + dir[k][0];
						int tmpRol = j + dir[k][1];
						if (tmpCol < 0 || tmpCol >= col || tmpRol < 0 || tmpRol >= rol) {
							continue;
						}
						if (grid[tmpCol][tmpRol] == 2) {
							remain--;
							continue;
						}
						if (grid[tmpCol][tmpRol] == 1) {
							remain--;
						}
					}
					res += remain;
				}
			}
		}
		return res;
	}
	int findPairs(vector<int>& nums, int k) {//数组中的 k-diff 数对
		unordered_map<int, int> numMap;
		for (int& num : nums) {
			numMap[num]++;
		}
		int res = 0;
		if (k != 0) {
			for (auto& it : numMap) {
				if (numMap.count(it.first + k) > 0) {
					res++;
				}
			}
		}
		else {
			for (auto& it : numMap) {
				if (it.second > 1) {
					res++;
				}
			}
		}
		return res;
	}
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {//重塑矩阵
		size_t rol = nums.size();
		if (rol == 0) {
			return nums;
		}
		size_t col = nums[0].size();
		if (c >= col && r >= rol) {
			return nums;
		}
		vector<vector<int>> res(r, vector<int>(c));
		size_t total = col * rol;
		for (size_t i = 0; i < total; i++) {
			res[i / c][i % c] = nums[i / col][i % col];
		}
		return res;
	}
	int maximumProductBak(vector<int>& nums) {//三个数的最大乘积--暴力排序
		sort(nums.begin(), nums.end());
		size_t numsLen = nums.size();
		return max(nums[0] * nums[1] * nums[numsLen - 1], nums[numsLen - 1] * nums[numsLen - 2] * nums[numsLen - 3]);
	}
	int maximumProduct(vector<int>& nums) {//三个数的最大乘积--维护3个最大值和两个最小值
		int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
		int min1 = INT_MAX, min2 = INT_MAX;
		for (int& num : nums) {
			if (num > max1) {
				max3 = max2;
				max2 = max1;
				max1 = num;
			}
			else if (num > max2) {
				max3 = max2;
				max2 = num;
			}
			else if (num > max3) {
				max3 = num;
			}
			if (num < min1) {
				min2 = min1;
				min1 = num;
			}
			else if (num < min2) {
				min2 = num;
			}
		}
		return max(max1 * max2 * max3, max1 * min1 * min2);
	}
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {//图片平滑器(卷积核)--可以优化，分区处理，不处理了
		size_t rol = M.size();
		if (rol == 0) {
			return M;
		}
		size_t col = M[0].size();
		vector<vector<int>> res(M);
		for (int i = 0; i < rol; i++) {
			for (int j = 0; j < col; j++) {
				int core = 0;
				int cnt = 0;
				for (int tmpRol = i - 1; tmpRol < i + 2; tmpRol++) {
					for (int tmpCol = j - 1; tmpCol < j + 2; tmpCol++) {
						if (tmpRol < 0 || tmpRol >= rol || tmpCol < 0 || tmpCol >= col) {
							continue;
						}
						core += M[tmpRol][tmpCol];
						cnt++;
					}
				}
				res[i][j] = core / cnt;
			}
		}
		return res;
	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int rol = grid.size();
		if (rol == 0) {
			return 0;
		}
		int col = grid[0].size();
		int res = 0;
		for (size_t i = 0; i < rol; i++) {
			for (size_t j = 0; j < col; j++) {
				res = max(res, maxAreaOfIslandBFS(grid, i, j, rol, col));
			}
		}
		return res;
	}
	vector<vector<int>> dir = {
			{-1, 0},
			{0, 1},
			{1, 0},
			{0, -1} };
	int maxAreaOfIslandBFS(vector<vector<int>>& grid, int rolCur, int colCur, int rol, int col) {
		if (grid[rolCur][colCur] == 2 || grid[rolCur][colCur] == 0) {
			return 0;
		}
		int res = 0;
		queue<pair<int, int>> q;
		q.push(make_pair(rolCur, colCur));
		while (!q.empty()) {
			rolCur = q.front().first;
			colCur = q.front().second;
			q.pop();
			if (grid[rolCur][colCur] == 2) {//有可能在入队列过程中被其他人访问
				continue;
			}
			res++;
			grid[rolCur][colCur] = 2;
			for (size_t i = 0; i < 4; i++) {
				int tmpRol = rolCur + dir[i][0];
				int tmpCol = colCur + dir[i][1];
				if (tmpRol < 0 || tmpRol >= rol || tmpCol < 0 || tmpCol >= col) {
					continue;
				}
				if (grid[tmpRol][tmpCol] == 1) {
					q.push(make_pair(tmpRol, tmpCol));
				}
			}
		}
		return res;
	}
	int findShortestSubArray(vector<int>& nums) {//数组的度
		unordered_map<int, int> numMap;
		for (int& num : nums) {
			numMap[num]++;
		}
		int cnt = 0;
		vector<int> cand;
		for (auto& it : numMap) {
			if (it.second > cnt) {
				cand.clear();
				cnt = it.second;
			}
			if (it.second == cnt) {
				cand.push_back(it.first);
			}
		}
		int res = INT_MAX;
		size_t numsLenLim = nums.size() - 1;
		for (int& it : cand) {
			size_t left = 0, right = numsLenLim;
			while (nums[left] != it) {
				left++;
			}
			while (nums[right] != it) {
				right--;
			}
			int current = right - left + 1;
			res = min(res, current);
		}
		return res;
	}
	int numSubarrayProductLessThanKBAK(vector<int>& nums, int k) {//乘积小于K的子数组--动态规划n^2
		size_t numsLen = nums.size();
		vector<vector<int>> dp(numsLen, vector<int>(numsLen, k));
		for (size_t i = 0; i < numsLen; i++) {
			if (nums[i] < k) {
				dp[i][i] = nums[i];
			}
		}
		for (size_t i = 0; i < numsLen; i++) {
			for (size_t j = i + 1; j < numsLen; j++) {
				if (dp[i][j - 1] > k) {//剪枝
					break;
				}
				dp[i][j] = dp[i][j - 1] * dp[j][j];
			}
		}
		int res = 0;
		for (size_t i = 0; i < numsLen; i++) {
			for (size_t j = i; j < numsLen; j++) {
				res += dp[i][j] < k ? 1 : 0;
			}
		}
		return res;
	}
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {//双指针
		if (k < 2) {
			return 0;
		}
		size_t numsLen = nums.size();
		int tmp = 1, res = 0;
		size_t left = 0;
		for (size_t right = 0; right < numsLen; right++) {
			tmp *= nums[right];
			while (tmp >= k) {
				tmp /= nums[left++];
			}
			res += right - left + 1;//右到左相乘的都小于
		}
		return res;
	}
	int maxProfitBAK(vector<int>& prices, int fee) {//买卖股票的最佳时机含手续费--动态规划
		size_t pricesCnt = prices.size();
		vector<vector<int>> dp(2, vector<int>(pricesCnt));//当天只有两种操作，买入和卖出
		//只有交易时才会计算价值变动
		dp[0][0] = 0;//没有股票收益
		dp[1][0] = -prices[0];//持有股票收益
		for (size_t i = 1; i < pricesCnt; i++) {
			dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i] - fee);
			dp[1][i] = max(dp[0][i - 1] - prices[i], dp[1][i - 1]);
		}
		return dp[0][pricesCnt - 1];
	}
	int maxProfit(vector<int>& prices, int fee) {//买卖股票的最佳时机含手续费--动态规划--空间优化
		size_t pricesCnt = prices.size();
		//当天只有两种操作，买入和卖出
		//只有交易时才会计算价值变动
		int noStock = 0;//没有股票收益
		int haveStock = -prices[0];//持有股票收益
		for (size_t i = 1; i < pricesCnt; i++) {
			int noStockBak = noStock;
			int haveStockBak = haveStock;
			noStock = max(noStockBak, haveStockBak + prices[i] - fee);
			haveStock = max(noStockBak - prices[i], haveStockBak);
		}
		return noStock;
	}
	bool isOneBitCharacter(vector<int>& bits) {//1比特与2比特字符,跳位
		size_t bitsCnt = bits.size();
		size_t cur = 0;
		while (cur < bitsCnt - 1) {
			if (bits[cur] == 1) {
				cur++;
			}
			cur++;
		}
		return cur == bitsCnt - 1;
	}
	int minCostClimbingStairs(vector<int>& cost) {//使用最小花费爬楼梯--动态规划
		size_t costCnt = cost.size();
		int dp_1 = 0;
		int dp_2 = 0;
		int dp = 0;
		for (size_t i = 2; i <= costCnt; i++) {
			dp = min(dp_1 + cost[i - 1], dp_2 + cost[i - 2]);
			dp_2 = dp_1;
			dp_1 = dp;
		}
		return dp;
	}
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {//托普利茨矩阵
		size_t rol = matrix.size();
		size_t col = matrix[0].size();
		size_t limL = min(rol, col);
		size_t limU = max(rol, col);
		for (size_t i = 0; i < rol; i++) {
			if (!exploreThis(matrix, i, 0, rol, col)) {//验证竖着的
				return false;
			}
		}
		for (size_t i = 1; i < col; i++) {
			if (!exploreThis(matrix, 0, i, rol, col)) {//验证横着的
				return false;
			}
		}
		return true;
	}
	bool exploreThis(vector<vector<int>>& matrix, size_t rolCur, size_t colCur, size_t rol, size_t col) {
		int target = matrix[rolCur][colCur];
		while (rolCur < rol && colCur < col) {
			if (matrix[rolCur][colCur] != target) {
				return false;
			}
			rolCur++;
			colCur++;
		}
		return true;
	}
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {//翻转图像
		int rol = A.size();
		int col = A[0].size();
		for (int i = 0; i < rol; i++) {
			int left = 0, right = col - 1;
			while (left <= right) {
				if (A[i][left] == A[i][right]) {
					A[i][left] = A[i][left] == 0;
					A[i][right] = A[i][left];
				}
				left++;
				right--;
			}
		}
		return A;
	}
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {//公平的糖果交换
		unordered_set<int> ASet, BSet;
		int ASum = 0, BSum = 0;
		for (int& num : A) {
			ASet.emplace(num);
			ASum += num;
		}
		for (int& num : B) {
			BSet.emplace(num);
			BSum += num;
		}
		int target = (ASum - BSum) / 2;
		vector<int> res(2);
		for (const int& num : ASet) {
			if (BSet.count(num - target)) {
				res[0] = num;
				res[1] = num - target;
				break;
			}
		}
		return res;
	}
	int sumSubseqWidths(vector<int>& nums) {//子序列宽度之和
		sort(nums.begin(), nums.end());//排序不改变结果
		//A[i]是左侧2^i个区间的右边界，右侧2^N-i-1个左边界，右边界贡献为正，左边界贡献为负
		size_t numsLen = nums.size();
		size_t left = 0, right = 1;
		int res = 0;
		vector<long> pow2(numsLen);
		pow2[0] = 1;
		for (size_t i = 1; i < numsLen; i++) {
			pow2[i] = pow2[i - 1] * 2 % 1000000007;
		}
		for (size_t i = 0; i < numsLen; i++) {
			res = (res + nums[i] * (pow2[i] - pow2[numsLen - i - 1])) % 1000000007;
		}
		return res;
	}
	bool isMonotonic(vector<int>& nums) {//单调数列
		size_t numsLen = nums.size();
		if (numsLen < 2) {//单个元素
			return true;
		}
		size_t i = 1;
		while (i < numsLen&& nums[i] == nums[i - 1]) {//去除开头重复
			i++;
		}
		if (i == numsLen) {//全相等
			return true;
		}
		bool grater = nums[i] > nums[i - 1];
		while (i < numsLen) {//主业务
			if (nums[i] == nums[i - 1]) {
				i++;
				continue;
			}
			if (grater ^ (nums[i] > nums[i - 1])) {
				return false;
			}
			i++;
		}
		return true;
	}
	int sumSubarrayMins(vector<int>& nums) {//子数组的最小值之和
		int numsLen = nums.size();
		vector<int> left(numsLen), right(numsLen);//最小值区间下标
		for (int i = 0; i < numsLen; i++) {
			left[i] = right[i] = i;
		}
		stack<int> stk;
		for (int i = numsLen - 1; i > -1; i--) {
			while (!stk.empty() && nums[stk.top()] >= nums[i]) {
				right[i] = right[stk.top()];
				stk.pop();
			}
			stk.push(i);
		}
		while (!stk.empty()) {
			stk.pop();
		}
		for (int i = 0; i < numsLen; i++) {
			while (!stk.empty() && nums[stk.top()] > nums[i]) {
				left[i] = left[stk.top()];
				stk.pop();
			}
			stk.push(i);
		}
		int res = 0;
		for (int i = 0; i < numsLen; i++) {
			res = (res + 1LL * (i - left[i] + 1) * (right[i] - i + 1) * nums[i]) % 1000000007;
		}
		return res;
	}
	bool hasGroupsSizeX(vector<int>& deck) {
		unordered_map<int, int> cardSet;
		int minCnt = INT_MAX;
		for (int& card : deck) {
			cardSet[card]++;
		}
		int g = 0;
		for (auto& it : cardSet) {
			if (g != 0) {
				g = gcd(g, it.second);
			}
			else {
				g = it.second;
			}
		}
		return g > 1;
	}
	inline int gcd(int a, int b) {//求最大公约数
		int r;
		while (b > 0) {
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
	int maxSubarraySumCircularBAK(vector<int>& A) {//环形子数组的最大和--暴力动态规划--超时
		vector<int> B(A);
		vector<int> dp(A);
		size_t numsLen = A.size();
		A.insert(A.end(), B.begin(), B.end());
		int res = INT_MIN;
		for (size_t i = 0; i < numsLen; i++) {
			size_t lim = i + numsLen;
			int current = A[i];
			int last = A[i];
			for (size_t cur = i + 1; cur < lim; cur++) {
				current = max(A[cur], A[cur] + current);
				last = max(last, current);
			}
			dp[i] = max(current, last);
		}
		for (int& num : dp) {
			res = max(res, num);
		}
		return res;
	}
	int maxSubarraySumCircular(vector<int>& A) {//环形子数组的最大和
		int maxVal = A.front(), currentMax = A.front(), minVal = A.front(), currentMin = A.front(), sum = A.front();
		size_t numsLen = A.size();
		for (size_t i = 1; i < numsLen; i++) {//最大和最小子列和
			currentMax = max(A[i], currentMax + A[i]);
			maxVal = max(maxVal, currentMax);
			currentMin = min(A[i], currentMin + A[i]);
			minVal = min(minVal, currentMin);
			sum += A[i];
		}
		if (sum == minVal) {
			return maxVal;
		}
		return max(maxVal, sum - minVal);
	}
	vector<int> sortArrayByParityII(vector<int>& nums) {//按奇偶排序数组 II
		size_t numsLen = nums.size();
		size_t eveCur = 0, oddCur = 1;
		vector<int> res(nums);
		for (size_t i = 0; i < numsLen; i++) {
			if (nums[i] % 2 == 0) {
				res[eveCur] = nums[i];
				eveCur += 2;
			}
			else {
				res[oddCur] = nums[i];
				oddCur += 2;
			}
		}
		return res;
	}
	vector<int> sortedSquares(vector<int>& nums) {//有序数组的平方
		vector<int> res;
		int aproixZeroCur = 0;
		int numsLen = nums.size();
		for (int i = 0; i < numsLen; i++) {
			if (abs(nums[i]) > abs(nums[aproixZeroCur])) {
				break;
			}
			else {
				aproixZeroCur = i;
			}
		}
		res.push_back(nums[aproixZeroCur] * nums[aproixZeroCur]);
		int left = aproixZeroCur - 1, right = aproixZeroCur + 1;
		while (left > -1 || right < numsLen) {
			if (left == -1) {
				res.push_back(nums[right] * nums[right]);
				right++;
				continue;
			}
			if (right == numsLen) {
				res.push_back(nums[left] * nums[left]);
				left--;
				continue;
			}
			int minVal;
			if (abs(nums[left]) < abs(nums[right])) {
				minVal = abs(nums[left]);
				left--;
			}
			else {
				minVal = abs(nums[right]);
				right++;
			}
			res.push_back(minVal * minVal);
		}
		return res;
	}
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {//查询后的偶数和
		int sum = 0;
		for (int& num : A) {
			if (num % 2 == 0) {
				sum += num;
			}
		}
		vector<int> res;
		for (vector<int>& qur : queries) {
			int val = qur[0];
			size_t index = qur[1];
			if (A[index] % 2 != 0) {//未改变前为奇数
				if (val % 2 != 0) {//改完变成偶数
					A[index] += val;
					sum += A[index];
				}
				else {//改完还是奇数
					A[index] += val;
				}
			}
			else {//未改变前是偶数
				if (val % 2 != 0) {//改完变奇数了
					sum -= A[index];
					A[index] += val;
				}
				else {//改完还是偶数
					sum += val;
					A[index] += val;
				}
			}
			res.push_back(sum);
		}
		return res;
	}
	int numRookCaptures(vector<vector<char>>& board) {//可以被一步捕获的棋子数
		int res = 0;
		int rol = 0, col = 0;
		bool done = false;
		for (int i = 0; i < 8; i++) {//找车
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'R') {
					done = true;
					rol = i;
					col = j;
					break;
				}
			}
			if (done) {
				break;
			}
		}
		int tmpRol = rol;
		while (tmpRol < 8) {
			if (board[tmpRol][col] == 'B') {
				break;
			}
			if (board[tmpRol][col] == 'p') {
				res++;
				break;
			}
			tmpRol++;
		}
		tmpRol = rol;
		while (tmpRol > -1) {
			if (board[tmpRol][col] == 'B') {
				break;
			}
			if (board[tmpRol][col] == 'p') {
				res++;
				break;
			}
			tmpRol--;
		}
		int tmpCol = col;
		while (tmpCol < 8) {
			if (board[rol][tmpCol] == 'B') {
				break;
			}
			if (board[rol][tmpCol] == 'p') {
				res++;
				break;
			}
			tmpCol++;
		}
		tmpCol = col;
		while (tmpCol > -1) {
			if (board[rol][tmpCol] == 'B') {
				break;
			}
			if (board[rol][tmpCol] == 'p') {
				res++;
				break;
			}
			tmpCol--;
		}
		return res;
	}
	int maxTurbulenceSize(vector<int>& nums) {//最长湍流子数组
		size_t numsLen = nums.size();
		vector<int> dp(numsLen);
		dp[0] = 0;
		for (size_t i = 1; i < numsLen; i++) {
			if (nums[i - 1] < nums[i]) {
				dp[i] = 1;
			}
			if (nums[i - 1] > nums[i]) {
				dp[i] = -1;
			}
		}
		int res = 0;
		int current = 0;
		for (size_t i = 0; i < numsLen; i++) {
			if (dp[i] == 0) {
				current = 1;
			}
			else if (dp[i] == -dp[i - 1] || dp[i - 1] == 0) {
				current++;
			}
			else {
				current = 2;
			}
			res = max(res, current);
		}
		return res;
	}
	int threeSumMulti(vector<int>& nums, int target) {//三数之和的多种可能--三指针
		sort(nums.begin(), nums.end());
		int mod = 1000000007;
		int res = 0;
		int numsLen = nums.size();
		for (int i = 0; i < numsLen - 2 && nums[i] <= target; i++) {
			int left = i + 1, right = numsLen - 1;
			while (nums[left] < nums[right]) {//left,right数不相等
				if (nums[i] + nums[left] + nums[right] == target) {
					int leftBak = left, rightBak = right;
					while (nums[left] == nums[leftBak]) {
						left++;
					}
					while (nums[right] == nums[rightBak]) {
						right--;
					}
					res += (left - leftBak) * (rightBak - right);
					res %= mod;
				}
				else if (nums[i] + nums[left] + nums[right] < target) {
					left++;
				}
				else {
					right--;
				}
			}
			if (nums[left] == nums[right] && nums[i] + nums[left] + nums[right] == target) {
				int d = right - left + 1;
				res += d * (d - 1) / 2;
				res %= mod;
			}
		}
		return res;
	}
	vector<string> commonChars(vector<string>& A) {//查找常用字符
		unordered_map<char, int> charMapA, charMapB;
		for (char& ch : A[0]) {
			charMapA[ch]++;
		}
		size_t wordCnt = A.size();
		for (string& str : A) {
			charMapB = charMapA;
			charMapA.clear();
			for (char& ch : str) {
				if (charMapB[ch] > 0) {
					charMapA[ch]++;
					charMapB[ch]--;
				}
			}
		}
		vector<string> res;
		string tmp;
		for (auto& it : charMapA) {
			tmp.clear();
			tmp += it.first;
			while (it.second > 0) {
				it.second--;
				res.emplace_back(tmp);
			}
		}
		return res;
	}
	int shipWithinDays(vector<int>& weights, int D) {//在 D 天内送达包裹的能力--二分法
		//货物必须按照给定的顺序装运
		int minLim = 0;
		int maxLim = 0;
		for (int& weight : weights) {
			maxLim += weight;
			minLim = max(minLim, weight);
		}
		int left = minLim, right = maxLim;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (canShip(weights, D, mid)) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
	inline bool canShip(vector<int>& weights, int D, int wLim) {
		int tmp = 0;
		for (int& wt : weights) {
			if (tmp + wt > wLim) {
				tmp = 0;
				D--;
			}
			if (D == 0) {
				return false;
			}
			tmp += wt;
		}
		return true;
	}
	int heightChecker(vector<int>& heights) {//高度检查器--桶n，如果使用排序的话是nlogn
		vector<int> bucket(101, 0);
		for (int& height : heights) {
			bucket[height]++;//有序的
		}
		int res = 0;
		int cnt = 0;
		for (size_t i = 1; i < 101; i++) {
			while (bucket[i] > 0) {
				if (heights[cnt] != i) {
					res++;
				}
				bucket[i]--;
				cnt++;
			}
		}
		return res;
	}
	void duplicateZeros(vector<int>& nums) {
		size_t numsLen = nums.size();
		int cnt = 0;
		for (size_t i = 0; i < numsLen; i++) {
			if (nums[i] == 0) {
				nums.insert(nums.begin() + i, 0);
				cnt++;
				i++;
			}
		}
		while (cnt > 0) {
			nums.pop_back();
			cnt--;
		}
		return;
	}
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {//等价多米诺骨牌对的数量
		vector<vector<int>> dominoeMap(11, vector<int>(11, 0));
		int res = 0;
		for (vector<int>& dominoe : dominoes) {
			if (dominoe[0] <= dominoe[1]) {
				res += dominoeMap[dominoe[0]][dominoe[1]]++;
			}
			else {
				res += dominoeMap[dominoe[1]][dominoe[0]]++;
			}
		}
		return res;
	}
	string dayOfTheWeek(int day, int month, int year) {//一周中的第几天
		//首先我们知道1971.1.1是Friday
		vector<string> weekDayRes = { "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday" };
		vector<int> monthDatCnt = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
		int dayCnt = 0;
		for (int i = 1971; i < year; i++) {
			dayCnt += 365;
			if (isLapYear(i)) {
				dayCnt++;
			}
		}
		dayCnt += monthDatCnt[month];
		if (isLapYear(year) && month > 2) {
			dayCnt++;
		}
		dayCnt += day - 1;
		return weekDayRes[dayCnt % 7];
	}
	inline bool isLapYear(int year) {
		if (year % 400 == 0) {
			return true;
		}
		if (year % 100 == 0) {
			return false;
		}
		if (year % 4 == 0) {
			return true;
		}
		return false;
	}
	int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {//公交站间的距离
		int sum1 = 0;
		int sum2 = 0;
		size_t distCnt = distance.size();
		size_t lb = min(start, destination);
		size_t ub = max(start, destination);
		for (int i = 0; i < distCnt; i++) {
			sum1 += distance[i];
		}
		for (int i = lb; i < ub; i++) {
			sum2 += distance[i];
		}
		return min(sum2, sum1 - sum2);
	}
	vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {//比较字符串最小字母出现频次
		unordered_map<int, int> wordMap;
		for (string& word : words) {
			wordMap[getNum(word)]++;
		}
		vector<int> res;
		for (string& qury : queries) {
			int quryNum = getNum(qury);
			int cnt = 0;
			for (auto& it : wordMap) {
				if (quryNum < it.first) {
					cnt += it.second;
				}
			}
			res.push_back(cnt);
		}
		return res;
	}
	inline int getNum(string& str) {
		char chCur = 'z';
		int cnt = 0;
		for (char& ch : str) {
			if (ch < chCur) {
				chCur = ch;
				cnt = 0;
			}
			if (ch == chCur) {
				cnt++;
			}
		}
		return cnt;
	}
	int countCharacters(vector<string>& words, string chars) {//拼写单词
		unordered_map<char, int> charMap;
		for (char& ch : chars) {
			charMap[ch]++;
		}
		int res = 0;
		for (string& word : words) {
			unordered_map<char, int> tmp = charMap;
			bool isCap = true;
			for (char& ch : word) {
				if (tmp.count(ch)) {
					if (tmp[ch] == 0) {
						isCap = false;
						break;
					}
					tmp[ch]--;
				}
				else {
					isCap = false;
					break;
				}
			}
			if (isCap) {
				res += word.size();
			}
		}
		return res;
	}
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {//最小绝对差
		sort(arr.begin(), arr.end());
		size_t numsLen = arr.size();
		vector<int> arrCopy(numsLen);
		vector<vector<int>> res;
		int val = INT_MAX;
		for (size_t i = 1; i < numsLen; i++) {
			arrCopy[i] = arr[i] - arr[i - 1];
			val = min(val, arrCopy[i]);
		}
		for (size_t i = 1; i < numsLen; i++) {
			if (arrCopy[i] == val) {
				res.push_back({ arr[i - 1] , arr[i] });
			}
		}
		return res;
	}
	int minCostToMoveChips(vector<int>& position) {//玩筹码
		int numsLen = position.size();
		int cnt = 0;
		for (int& num : position) {
			if (num % 2 != 0) {
				cnt++;
			}
		}
		return min(cnt, numsLen - cnt);
	}
	bool checkStraightLine(vector<vector<int>>& coordinates) {//缀点成线
		int paraA = coordinates[1][1] - coordinates[0][1];
		int paraB = coordinates[0][0] - coordinates[1][0];
		int paraComp = coordinates[0][0] * coordinates[1][1] - coordinates[1][0] * coordinates[0][1];
		size_t coordCnt = coordinates.size();
		for (size_t i = 2; i < coordCnt; i++) {
			if (paraA * coordinates[i][0] + paraB * coordinates[i][1] != paraComp) {
				return false;
			}
		}
		return true;
	}
	int oddCells(int n, int m, vector<vector<int>>& indices) {//奇数值单元格的数目
		vector<int> rol(n), col(m);
		for (vector<int>& indc : indices) {
			rol[indc[0]]++;
			col[indc[1]]++;
		}
		int res = 0;
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				if ((rol[i] + col[j]) % 2 != 0) {
					res++;
				}
			}
		}
		return res;
	}
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {//二维网格迁移
		vector<vector<int>> res(grid);
		size_t rol = grid.size();
		size_t col = grid[0].size();
		for (size_t i = 0; i < rol; i++) {
			for (size_t j = 0; j < col; j++) {
				size_t newRol = (i + (k + j) / col) % rol;
				size_t newCol = (j + k) % col;
				res[newRol][newCol] = grid[i][j];
			}
		}
		return res;
	}
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {//访问所有点的最小时间
		int currentX = points[0][0];
		int currentY = points[0][1];
		int res = 0;
		for (vector<int>& point : points) {
			res += max(abs(point[1] - currentY), abs(point[0] - currentX));
			currentX = point[0];
			currentY = point[1];
		}
		return res;
	}
	string tictactoe(vector<vector<int>>& moves) {
		vector<string> res = { "A", "B", "Draw", "Pending" };
		size_t moveCnt = moves.size();
		vector<vector<int>> grid(3, vector<int>(3, 0));
		//下棋
		for (size_t i = 0; i < moveCnt; i++) {
			if (i % 2 == 0) {
				grid[moves[i][0]][moves[i][1]] = 1;
			}
			else {
				grid[moves[i][0]][moves[i][1]] = 2;
			}
		}
		//检查赢家
		for (size_t i = 0; i < 3; i++) {
			if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
				if (grid[i][0] == 0) {
					continue;
				}
				if (grid[i][0] == 1) {
					return res[0];
				}
				if (grid[i][0] == 2) {
					return res[1];
				}
			}
			if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
				if (grid[0][i] == 0) {
					continue;
				}
				if (grid[0][i] == 1) {
					return res[0];
				}
				if (grid[0][i] == 2) {
					return res[1];
				}
			}
		}
		if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
			if (grid[1][1] == 1) {
				return res[0];
			}
			if (grid[1][1] == 2) {
				return res[1];
			}
		}
		if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]) {
			if (grid[1][1] == 1) {
				return res[0];
			}
			if (grid[1][1] == 2) {
				return res[1];
			}
		}
		if (moveCnt == 9) {
			return res[2];
		}
		return (res[3]);
	}
	int findSpecialInteger(vector<int>& arr) {//有序数组中出现次数超过25%的元素
		size_t targetLen = arr.size() / 4;
		int target = arr[0];
		int cnt = 0;
		for (int& num : arr) {
			if (num == target) {
				cnt++;
			}
			else {
				target = num;
				cnt = 1;
			}
			if (cnt > targetLen) {
				return target;
			}
		}
		return -1;
	}
	int findNumbers(vector<int>& nums) {//统计位数为偶数的数字
		int res = 0;
		for (int& num : nums) {
			int cnt = 0;
			while (num != 0) {
				num /= 10;
				cnt++;
			}
			if (cnt % 2 == 0) {
				res++;
			}
		}
		return res;
	}
	vector<int> replaceElements(vector<int>& arr) {//将每个元素替换为右侧最大元素
		vector<int> res(arr);
		int numsLen = arr.size();
		res[numsLen - 1] = -1;
		for (int i = numsLen - 2; i > -1; i--) {
			res[i] = max(res[i + 1], arr[i + 1]);
		}
		return res;
	}
	int findBestValue(vector<int>& arr, int target) {//转变数组后最接近目标值的数组和
		int numsLen = arr.size();
		if (numsLen == 0) {
			return 0;
		}
		sort(arr.begin(), arr.end());
		for (int i = 0; i < numsLen; i++) {
			double tmp = 1.0 * target / (numsLen - i);
			int mean = tmp;
			if (tmp - mean - 0.5 >= 0) {
				mean++;
			}
			if (arr[i] >= mean) {
				if (abs(target - (mean - 1) * (numsLen - i)) <= abs(target - mean * (numsLen - i))) {
					return mean - 1;
				}
				return mean;
			}
			target -= arr[i];
		}
		return arr[numsLen - 1];
	}
	vector<int> sumZero(int n) {//和为零的N个唯一整数
		vector<int> res(n);
		int lim = n / 2;
		for (int i = 1; i <= lim; i++) {
			res[i - 1] = -i;
			res[n - i] = i;
		}
		return res;
	}
	bool canReach(vector<int>& arr, int start) {//跳跃游戏 III--回溯
		if (start < 0 || start >= arr.size()) {
			return false;
		}
		if (arr[start] == 0) {
			return true;
		}
		if (arr[start] == -1) {
			return false;
		}
		int arrCopy = arr[start];
		arr[start] = -1;
		bool left = canReach(arr, start + arrCopy);
		bool right = canReach(arr, start - arrCopy);
		arr[start] = arrCopy;
		return left || right;
	}
	vector<int> decompressRLElist(vector<int>& nums) {//解压缩编码列表
		int numsLen = nums.size();
		vector<int> res;
		int cur = 0;
		while (cur < numsLen) {
			int freq = nums[cur];
			int val = nums[cur + 1];
			while (freq > 0) {
				res.push_back(val);
				freq--;
			}
			cur += 2;
		}
		return res;
	}
	vector<int> getNoZeroIntegers(int n) {//将整数转换为两个无零整数的和
		vector<int> res(2);
		int part1 = n;
		int part2 = 0;
		while (part2 < n) {
			part1 = n - part2;
			if ((to_string(part1) + to_string(part2)).find('0') == string::npos) {
				res[0] = part1;
				res[1] = part2;
				break;
			}
			part2++;
		}
		return res;
	}
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {//矩阵中的幸运数
		size_t rol = matrix.size();
		size_t col = matrix[0].size();
		vector<int> res;
		vector<int> rolMem(rol), colMem(col);
		for (size_t i = 0; i < rol; i++) {
			int target = INT_MAX;
			for (size_t j = 0; j < col; j++) {
				target = min(target, matrix[i][j]);
			}
			rolMem[i] = target;
		}
		for (size_t i = 0; i < col; i++) {
			int target = INT_MIN;
			for (size_t j = 0; j < rol; j++) {
				target = max(target, matrix[j][i]);
			}
			colMem[i] = target;
		}
		for (size_t i = 0; i < rol; i++) {
			for (size_t j = 0; j < col; j++) {
				if (rolMem[i] == colMem[j]) {
					res.push_back(rolMem[i]);
				}
			}
		}
		return res;
	}
	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {//两个数组间的距离值
		int res = 0;
		for (int& num1 : arr1) {
			bool isOK = true;
			for (int& num2 : arr2) {
				if (abs(num1 - num2) <= d) {
					isOK = false;
					break;
				}
			}
			if (isOK) {
				res++;
			}
		}
		return res;
	}
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {//按既定顺序创建目标数组
		vector<int> res;
		size_t numsLen = nums.size();
		for (size_t i = 0; i < numsLen; i++) {
			res.insert(res.begin() + index[i], nums[i]);
		}
		return res;
	}
	int maxProduct(vector<int>& nums) {//数组中两元素的最大乘积
		sort(nums.begin(), nums.end());
		return max((nums[0] - 1) * (nums[1] - 1), (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1));
	}
	vector<int> shuffle(vector<int>& nums, int n) {//重新排列数组
		vector<int> res(nums);
		size_t gap = nums.size() / 2;
		for (size_t i = 0; i < gap; i++) {
			res[2 * i] = nums[i];
			res[2 * i + 1] = nums[gap + i];
		}
		return res;
	}
};
class MyCalendar {
public:
	MyCalendar() {
		return;
	}
	bool book(int start, int end) {
		auto it = timeMap.lower_bound(start);//k <= ?的迭代器,迭代器指向->?
		if (it != timeMap.end() && it->first < end) {
			return false;
		}
		if (it != timeMap.begin() && (--it)->second > start) {
			return false;
		}
		timeMap[start] = end;//添加或更新
		return true;
	}
private:
	map<int, int> timeMap;//红黑树
};

class MajorityChecker {//子数组中占绝大多数的元素--摩尔投票+线段树,赞数超时
	//解答思路：
	//线段树是把一个大的区间拆分成很多个小区间
	//每个小区间内使用摩尔投票，最终把所有小区间合并起来再用一次摩尔投票
public:
	MajorityChecker(vector<int>& arr) {
		nums = arr;
		numsLen = nums.size();
		for (size_t i = 0; i < numsLen; i++) {
			curMap[arr[i]].push_back(i);
		}
		root = buildTree(0, numsLen - 1);
		return;
	}
	int query(int left, int right, int threshold) {//线段树
		//vector<int> tmp = queryTree(left, right, root);
		int key = 0;
		int count = 0;
		queryTree(left, right, root, key, count);
		if (key == 0 || curMap[key].size() < threshold) {
			return -1;
		}
		auto it_l = lower_bound(curMap[key].begin(), curMap[key].end(), left);
		auto it_r = upper_bound(curMap[key].begin(), curMap[key].end(), right);
		int cnt = it_r - it_l;
		return cnt >= threshold ? key : -1;
	}
private:
	struct node {
		int val = -1;//胜选者ID
		int cnt = -1;//胜选票数
		int leftCur = -1;//区间开始小标
		int rightCur = -1;//区间结束下标
		node* left = nullptr;
		node* right = nullptr;
	};
	vector<int> nums;
	unordered_map<int, vector<int>> curMap;
	size_t numsLen;
	node* root = nullptr;
	node* buildTree(int left, int right) {//递归构造线段树
		if (left > right) {
			return nullptr;
		}
		if (left == right) {
			node* retNode = new node;
			retNode->cnt = 1;
			retNode->val = nums[left];
			retNode->leftCur = left;
			retNode->rightCur = right;
			return retNode;
		}
		node* retNode = new node;
		int mid = (left + right) / 2;
		retNode->left = buildTree(left, mid);
		retNode->right = buildTree(mid + 1, right);
		retNode->leftCur = left;
		retNode->rightCur = right;
		//存在单边没有
		if (retNode->left == nullptr) {//右侧获胜，左侧没人
			retNode->val = retNode->right->val;
			retNode->cnt = retNode->right->cnt;
		}
		else if (retNode->right == nullptr) {//左侧获胜，右侧没人
			retNode->val = retNode->left->val;
			retNode->cnt = retNode->left->cnt;
		}
		//两边都有
		else if (retNode->left->val == retNode->right->val) {//两侧胜选者相同
			retNode->val = retNode->left->val;
			retNode->cnt = retNode->left->cnt + retNode->right->cnt;
		}
		else if (retNode->left->cnt > retNode->right->cnt) {//左侧获胜
			retNode->val = retNode->left->val;
			retNode->cnt = retNode->left->cnt - retNode->right->cnt;
		}
		else {//左侧没获胜
			retNode->val = retNode->right->val;
			retNode->cnt = retNode->right->cnt - retNode->left->cnt;
		}
		return retNode;
	}
	bool queryTree(int left, int right, node* root, int& key, int& count) {//查询线段树
		if (root == nullptr || left > right) {
			return false;
		}
		if (root->rightCur < left || root->leftCur > right) {//完全不重合区间
			return false;
		}
		int mid = (root->leftCur + root->rightCur) / 2;
		if (root->leftCur >= left && root->rightCur <= right) {//节点区间是所求区间的子空间
			if (root->val == key) {
				count += root->cnt;
			}
			else if (root->cnt > count) {
				key = root->val;
				count = root->cnt;
			}
			else if (root->cnt <= count) {
				count -= root->cnt;
			}
			return true;//不用将节点区间向下分解了
		}
		if (mid >= left) {//不是子空间的话就掰开节点
			queryTree(left, right, root->left, key, count);
		}
		if (right > mid) {
			queryTree(left, right, root->right, key, count);
		}
		return true;
	}
};


int main(int argc, char* argv[]) {
	Solution mySolution;
	vector<int> nums = { 3, 0, 2, 1, 2 };
	vector<vector<int>> grid = {
		{0, 1},
		{1, 1} };
	vector<vector<int>> matrix = {
		{} };
	vector<string> wordList = { "bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb" };
	vector<string> wdLst2 = { "aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa" };
	mySolution.canReach(nums, 2);
	return 0;
}
#endif

//cookBook-字符串
#if false

class Solution {
public:
	string addBinary(string a, string b) {//二进制求和
		//注意长度
		int aCur = a.size() - 1, bCur = b.size() - 1;
		string res;
		int sign = 0;
		while (aCur > -1 || bCur > -1) {
			int intA = aCur > -1 ? a[aCur] - '0' : 0;
			int intB = bCur > -1 ? b[bCur] - '0' : 0;
			int signCopy = (intA + intB + sign) / 2;
			int remain = (intA + intB + sign) % 2;
			sign = signCopy;
			res.insert(res.begin(), '0' + remain);
			aCur--;
			bCur--;
		}
		if (sign == 1) {
			res.insert(res.begin(), '1');
		}
		return res;
	}
	int numDecodings(string s) {//解码方法
		size_t sLen = s.size();
		if (sLen == 0 || s[0] == '0') {
			return 0;
		}
		int pre = 1, current = 1;
		for (size_t i = 1; i < sLen; i++) {
			int tmp = current;
			if (s[i] == '0') {
				if (s[i - 1] == '1' || s[i - 1] == '2') {
					current = pre;
				}
				else {//以 0 开头的数字不合规则，0 必须是结尾
					return 0;
				}
			}
			else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7' && s[i] > '0')) {
				current += pre;
			}
			pre = tmp;
		}
		return current;
	}
	int longestPalindrome(string s) {//最长回文串
		unordered_map<char, int> chMap;
		for (char& ch : s) {
			chMap[ch]++;
		}
		int res = 0;
		bool odd = false;
		for (auto& it : chMap) {
			res += it.second;
			if (it.second % 2 == 1) {
				res--;
				odd = true;
			}
		}
		if (odd) {
			res++;
		}
		return res;
	}
	vector<string> findWords(vector<string>& words) {//键盘行
		int charMap[] = {
			2, 3, 3, 2, 1, 2, 2,
			2, 1, 2, 2, 2, 3, 3,
			1, 1, 1, 1, 2, 1, 1,
			3, 1, 3, 1, 3
		};
		vector<string> res;
		for (string& word : words) {
			int target = charMap[tolower(word[0]) - 'a'];
			bool add = true;
			for (char& ch : word) {
				if (charMap[tolower(ch) - 'a'] != target) {
					add = false;
					break;
				}
			}
			if (add) {
				res.push_back(word);
			}
		}
		return res;
	}
	string complexNumberMultiply(string a, string b) {//复数乘法
		int re1 = 0, im1 = 0, re2 = 0, im2 = 0;
		imgStr2Int(a, re1, im1);
		imgStr2Int(b, re2, im2);
		return to_string(re1 * re2 - im1 * im2) + '+' + to_string(re1 * im2 + re2 * im1) + 'i';
	}
	inline void imgStr2Int(string& str, int& real, int& imag) {
		bool realSignNeg = false;
		bool imagSignNeg = false;
		size_t cur = 0;
		if (str[cur] == '-') {
			realSignNeg = true;
			cur++;
		}
		while (str[cur] != '+') {
			real *= 10;
			real += str[cur] - '0';
			cur++;
		}
		cur++;
		if (str[cur] == '-') {
			imagSignNeg = true;
			cur++;
		}
		while (str[cur] != 'i') {
			imag *= 10;
			imag += str[cur] - '0';
			cur++;
		}
		if (realSignNeg) {
			real = -real;
		}
		if (imagSignNeg) {
			imag = -imag;
		}
		return;
	}
	string reverseStr(string s, int k) {//反转字符串 II
		//通俗一点说，每隔k个反转k个，末尾不够k个时全部反转
		size_t sLen = s.size();
		size_t processTime = sLen / k;
		for (size_t i = 0; i < processTime; i++) {
			if (i % 2 == 0) {
				int front = k * i;
				int rear = front + k - 1;
				while (front < rear) {
					swap(s[front], s[rear]);
					front++;
					rear--;
				}
			}
		}
		if (processTime % 2 == 0) {
			processTime *= k;
			int front = processTime;
			int rear = sLen - 1;
			while (front < rear) {
				swap(s[front], s[rear]);
				front++;
				rear--;
			}
		}
		return s;
	}
	string shortestCompletingWord(string licensePlate, vector<string>& words) {//最短补全词
		unordered_map<char, int> plateMap;
		for (char& ch : licensePlate) {
			if (isalpha(ch)) {
				plateMap[tolower(ch)]++;
			}
		}
		string res;
		for (string& word : words) {
			if (word.size() < res.size() || res == "") {//剪枝
				unordered_map<char, int> tmp(plateMap);
				for (char& ch : word) {
					char cur = tolower(ch);
					if (tmp.count(cur) > 0) {
						tmp[cur]--;
						if (tmp[cur] == 0) {
							tmp.erase(cur);
						}
					}
				}
				if (tmp.empty()) {
					res = word;
				}
			}
		}
		return res;
	}
	vector<int> smallestRange(vector<vector<int>>& nums) {//最小区间
		//滑动窗口
		unordered_map<int, vector<int>> indicator;
		int minVal = INT_MAX, maxVal = INT_MIN;
		size_t numsCnt = nums.size();
		for (size_t i = 0; i < numsCnt; i++) {
			for (int& num : nums[i]) {
				indicator[num].push_back(i);
			}
			minVal = min(nums[i][0], minVal);
			maxVal = max(nums[i][nums[i].size() - 1], maxVal);
		}
		vector<int> freq(numsCnt);
		int inside = 0;//窗口内！数组！数量
		int left = minVal, right = minVal - 1;
		int bestLeft = minVal, bestRight = maxVal;
		while (right < maxVal) {
			right++;
			if (indicator.count(right) > 0) {//有效数值
				for (int& numSer : indicator[right]) {//增加窗口内！数字！数量
					freq[numSer]++;
					if (freq[numSer] == 1) {
						inside++;
					}
				}
				while (inside == numsCnt) {//窗口包含数组达到要求后缩小宽度，减少数字数量
					if (right - left < bestRight - bestLeft) {
						bestLeft = left;
						bestRight = right;
					}
					if (indicator.count(left)) {
						for (const int& x : indicator[left]) {
							freq[x]--;
							if (freq[x] == 0) {
								inside--;
							}
						}
					}
					left++;
				}
			}
		}
		return { bestLeft, bestRight };
	}
	string mostCommonWord(string paragraph, vector<string>& banned) {//最常见的单词
		size_t sLen = paragraph.size();
		unordered_map<string, int> freq;
		unordered_set<string> bannedList(banned.begin(), banned.end());
		for (string& str : banned) {
			for (char& ch : str) {
				ch = tolower(ch);
			}
		}
		size_t cur = 0;
		size_t last = 0;
		while (cur < sLen) {
			while (cur < sLen && isalpha(paragraph[cur])) {
				cur++;
			}
			string tmp(paragraph.begin() + last, paragraph.begin() + cur);
			for (char& ch : tmp) {
				ch = tolower(ch);
			}
			if (bannedList.count(tmp) < 1) {
				freq[tmp]++;
			}
			while (cur < sLen && !isalpha(paragraph[cur])) {
				cur++;
			}
			last = cur;
		}
		string res;
		int cnt = 0;
		for (auto& it : freq) {
			if (it.second > cnt) {
				res = it.first;
				cnt = it.second;
			}
		}
		return res;
	}
	bool isLongPressedName(string name, string typed) {//长按键入
		size_t typeLen = typed.size();
		size_t nameLen = name.size();
		size_t typeCur = 0, nameCur = 0;
		while (typeCur < typeLen) {
			if (nameCur < nameLen && name[nameCur] == typed[typeCur]) {
				nameCur++;
				typeCur++;
			}
			else if (typeCur > 0 && typed[typeCur] == typed[typeCur - 1]) {
				typeCur++;
			}
			else {
				return false;
			}
		}
		return nameCur == nameLen;
	}
	vector<int> diStringMatch(string S) {//增减字符串匹配
		size_t sLen = S.size();
		int left = 0, right = sLen;
		vector<int> res(sLen + 1);
		for (size_t i = 0; i < sLen; i++) {
			if (S[i] == 'I') {
				res[i] = left++;
			}
			else {
				res[i] = right--;
			}
		}
		res[sLen] = left;
		return res;
	}
	string strWithout3a3b(int a, int b) {//不含 AAA 或 BBB 的字符串
		string res;
		int aCnt = 0, bCnt = 0;
		while (a > 0 || b > 0) {
			if (a > b) {
				if (aCnt < 2) {
					res.push_back('a');
					aCnt++;
					a--;
					bCnt = 0;
				}
				else {
					res.push_back('b');
					bCnt++;
					b--;
					aCnt = 0;
				}
			}
			else {
				if (bCnt < 2) {
					res.push_back('b');
					bCnt++;
					b--;
					aCnt = 0;
				}
				else {
					res.push_back('a');
					aCnt++;
					a--;
					bCnt = 0;
				}
			}
		}
		return res;
	}
	string decodeAtIndex(string S, int K) {//索引处的解码字符串
		string res;
		long size = 0;
		size_t sLen = S.size();
		for (int i = 0; i < sLen; i++) {
			if (isdigit(S[i]))
				size *= S[i] - '0';
			else
				size++;
		}
		for (int i = sLen - 1; i > -1; i--) {
			K %= size;
			if (K == 0 && isalpha(S[i])) {
				res += S[i];
				break;
			}
			if (isdigit(S[i])) {
				size /= S[i] - '0';
			}
			else {
				size--;
			}
		}
		return res;
	}
	int uniqueLetterString(string s) {//统计子串中的唯一字符
		//和之前一道题比较像，统计每一个单独字符的贡献，向两侧拓展
		size_t sLen = s.size();
		vector<int> left(sLen), right(sLen), prev(26, -1);
		for (size_t i = 0; i < sLen; i++) {
			left[i] = prev[s[i] - 'A'];
			prev[s[i] - 'A'] = i;
		}
		prev = vector<int>(26, sLen);
		for (int i = sLen - 1; i > -1; i--) {
			right[i] = prev[s[i] - 'A'];
			prev[s[i] - 'A'] = i;
		}
		int mod = 1000000007;
		long long res = 0;
		for (size_t i = 0; i < sLen; i++) {
			res = (res + (right[i] - i) * (i - left[i])) % mod;
		}
		return res;
	}
	vector<string> findOcurrences(string text, string first, string second) {//Bigram 分词
		vector<string> res, textMap;
		int last = 0, current = 0;
		for (char& ch : text) {
			if (ch == ' ') {
				textMap.push_back(text.substr(last, current - last));
				last = current + 1;//注意单词前空格
			}
			current++;
		}
		textMap.push_back(text.substr(last, current - last));
		int textCnt = textMap.size();
		for (int i = 2; i < textCnt; i++) {
			if (second == textMap[i - 1] && first == textMap[i - 2]) {
				res.push_back(textMap[i]);
			}
		}
		return res;
	}
	string defangIPaddr(string s) {//IP 地址无效化
		string res;
		for (char& ch : s) {
			if (ch == '.') {
				res += "[.]";
			}
			else {
				res += ch;
			}
		}
		return res;
	}
	int maxNumberOfBalloons(string text) {//“气球” 的最大数量 balloon
		vector<int> charCnt(26);
		for (char& ch : text) {
			charCnt[ch - 'a']++;
		}
		return min(min(min(min(charCnt[1], charCnt[0]), charCnt[11] / 2), charCnt[14] / 2), charCnt[13]);
	}
	int balancedStringSplit(string s) {//分割平衡字符串
		int cnt = 0, res = 0;
		for (char& ch : s) {
			if (ch == 'L') {
				cnt++;
			}
			else {
				cnt--;
			}
			if (cnt == 0) {
				res++;
			}
		}
		return res;
	}
	int isPrefixOfWord(string sentence, string searchWord) {//检查单词是否为句中其他单词的前缀
		vector<string> textMap;
		int last = 0, current = 0;
		for (char& ch : sentence) {
			if (ch == ' ') {
				textMap.push_back(sentence.substr(last, current - last));
				last = current + 1;//注意单词前空格
			}
			current++;
		}
		textMap.push_back(sentence.substr(last, current - last));
		int textCnt = textMap.size();
		size_t wordLen = searchWord.size();
		for (int i = 0; i < textCnt; i++) {
			int textCur = 0, wordCur = 0, textLen = textMap[i].size();
			while (textCur < textLen && wordCur < wordLen && searchWord[wordCur] == textMap[i][textCur]) {
				textCur++;
				wordCur++;
			}
			if (wordCur == wordLen) {
				return i + 1;
			}
		}
		return -1;
	}
	int balancedString(string s) {
		int sLen = s.size(), k = sLen / 4, res = sLen;
		unordered_map<char, int> chMap;//窗口外字符计数
		for (char& ch : s) {
			chMap[ch]++;
		}
		int leftCur = 0, rightCur = 0;
		while (rightCur < sLen) {
			chMap[s[rightCur]]--;
			while (leftCur <= rightCur + 1 && chMap['Q'] <= k && chMap['W'] <= k && chMap['E'] <= k && chMap['R'] <= k) {
				//窗口外都小于1/4可以替换当前窗口
				//缺少部分可以用窗口内替换的补偿
				res = min(res, rightCur - leftCur + 1);
				chMap[s[leftCur]]++;
				leftCur++;
			}
			rightCur++;
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "1s3 PSt";
	string b = "1+1i";
	vector<string> inpt = { "hit" };
	vector<vector<int>> nums = {
		{4,10,15,24,26 },
		{ 0,9,12,20 },
		{ 5,18,22,30 }
	};
	mySolution.maxNumberOfBalloons("loonbalxballpoon");
	return 0;
}
#endif

//cookBook-滑动窗口与双指针
#if false

class Solution {
public:
	int characterReplacement(string s, int k) {//替换后的最长重复字符
		int cnt = 0;//最多字母计数
		size_t sLen = s.size();
		vector<int> charCnt(26);//窗口内字母计数
		size_t rightCur = 0, leftCur = 0;
		while (rightCur < sLen) {
			cnt = max(cnt, ++charCnt[s[rightCur] - 'A']);
			if (rightCur - leftCur + 1 - cnt > k) {
				charCnt[s[leftCur] - 'A']--;
				leftCur++;
				//不满足条件的情况下，left和right一起移动,len不变的
			}
			rightCur++;
		}
		return rightCur - leftCur;
	}
	unordered_map<char, int> pMap, tmpMap;
	vector<int> findAnagrams(string s, string p) {//找到字符串中所有字母异位词
		for (char& ch : p) {
			pMap[ch]++;
		}
		size_t sLen = s.size(), pLen = p.size();
		vector<int> res;
		int cur = 0;
		while (cur < pLen) {
			tmpMap[s[cur]]++;
			cur++;
		}
		while (cur < sLen) {
			if (findAnagramsCheck()) {
				res.push_back(cur - pLen);
			}
			--tmpMap[s[cur - pLen]];
			tmpMap[s[cur++]]++;
		}
		if (findAnagramsCheck()) {
			res.push_back(cur - pLen);
		}
		return res;
	}
	bool findAnagramsCheck() {
		for (auto& it : pMap) {
			if (tmpMap.count(it.first) < 1 || tmpMap[it.first] != it.second) {
				return false;
			}
		}
		return true;
	}
	bool checkInclusion(string p, string s) {//字符串的排列
		for (char& ch : p) {
			pMap[ch]++;
		}
		size_t sLen = s.size(), pLen = p.size();
		if (sLen < pLen) {
			return false;
		}
		vector<int> res;
		int cur = 0;
		while (cur < pLen) {
			tmpMap[s[cur]]++;
			cur++;
		}
		while (cur < sLen) {
			if (checkInclusionCheck()) {
				return true;
			}
			--tmpMap[s[cur - pLen]];
			tmpMap[s[cur++]]++;
		}
		if (checkInclusionCheck()) {
			return true;
		}
		return false;
	}
	bool checkInclusionCheck() {
		for (auto& it : pMap) {
			if (tmpMap.count(it.first) < 1 || tmpMap[it.first] != it.second) {
				return false;
			}
		}
		return true;
	}
	vector<int> partitionLabels(string s) {//划分字母区间
		vector<int> endPos(26), res;
		size_t sLen = s.size();
		for (size_t i = 0; i < sLen; i++) {
			endPos[s[i] - 'a'] = i;
		}
		int startCur = 0, endCur = 0;
		for (size_t i = 0; i < sLen; i++) {
			endCur = max(endCur, endPos[s[i] - 'a']);//尽可能把区间向右扩
			if (i == endCur) {
				res.push_back(endCur - startCur + 1);
				startCur = endCur + 1;
			}
		}
		return res;
	}
	vector<double> medianSlidingWindowBAK(vector<int>& nums, int k) {//滑动窗口中位数--暴力法超时
		vector<double> res;
		size_t numsLen = nums.size();
		bool isOdd = k % 2 == 1;
		size_t cur = k / 2;
		for (size_t i = 0; i < numsLen - k + 1; i++) {
			vector<double> tmp(nums.begin() + i, nums.begin() + i + k);
			sort(tmp.begin(), tmp.end());
			if (isOdd) {
				res.push_back(tmp[cur]);
			}
			else {
				res.push_back((tmp[cur] + tmp[cur - 1] + 0.0) / 2);
			}
		}
		return res;
	}
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {//滑动窗口中位数--使用STL multiset
		//multiset默认从小到大排序，红黑树
		size_t numsLen = nums.size();
		vector<double> res(numsLen - k + 1);
		multiset<int> window(nums.begin(), nums.begin() + k);
		auto mid = next(window.begin(), k / 2);//向后移动迭代器，类似prev()
		for (size_t i = k; i < numsLen; i++) {
			res[i - k] = (0.0 + *mid + *next(mid, k % 2 - 1)) * 0.5;
			window.insert(nums[i]);
			// 5 / 2 == 2， 4 / 2 == 2. 故只考虑在前插入和移除的情况
			if (nums[i] < *mid) {//入窗口元素，位置在mid之前
				mid--;
			}
			if (nums[i - k] <= *mid) {//出窗口元素，位置在mid之前
				mid++;
			}
			window.erase(window.lower_bound(nums[i - k]));
		}
		res[numsLen - k] = (0.0 + *mid + *next(mid, k % 2 - 1)) * 0.5;
		return res;
	}
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {//安排工作以达到最大收益
		//哈希映射+动态规划
		size_t diffLen = difficulty.size();
		vector<vector<int>> dp(diffLen + 1, vector<int>(2));
		for (size_t i = 0; i < diffLen; i++) {
			dp[i][0] = difficulty[i];
			dp[i][1] = profit[i];
		}
		dp[diffLen][0] = 0;
		dp[diffLen][1] = 0;
		sort(dp.begin(), dp.end());
		for (size_t i = 1; i <= diffLen; i++) {
			dp[i][1] = max(dp[i][1], dp[i - 1][1]);
		}
		map<int, int> dpMap;
		for (vector<int>& it : dp) {
			dpMap[it[0]] = it[1];
		}
		int res = 0;
		for (int& num : worker) {
			auto it = dpMap.lower_bound(num);
			if (it == dpMap.end() || num != it->first) {
				it--;
			}
			res += it->second;
		}
		return res;
	}
	int longestMountain(vector<int>& arr) {//数组中的最长山脉
		size_t arrLen = arr.size();
		//起始与终点
		vector<int> left(arrLen, 0), right(arrLen, arrLen), climax(arrLen, 0);
		for (size_t i = 1; i < arrLen; i++) {
			if (arr[i] > arr[i - 1]) {
				left[i] = left[i - 1];
			}
			else {
				left[i] = i;
			}
			if (arr[arrLen - i - 1] > arr[arrLen - i]) {
				right[arrLen - i - 1] = right[arrLen - i];
			}
			else {
				right[arrLen - i - 1] = arrLen - i;
			}
		}
		for (size_t i = 2; i < arrLen; i++) {
			if (arr[i - 2] < arr[i - 1] && arr[i - 1] > arr[i]) {
				climax[i - 1] = 1;
			}
		}
		int res = 0;
		for (size_t i = 0; i < arrLen; i++) {
			if (climax[i] == 1) {
				res = max(right[i] - left[i], res);
			}
		}
		return res > 2 ? res : 0;
	}
	string pushDominoes(string s) {//推多米诺
		//受力计算
		size_t sLen = s.size();
		vector<int> left(sLen, 0), right(sLen, 0);
		int force = 0;//最大力
		for (size_t i = 0; i < sLen; i++) {
			if (s[i] == 'R') {
				force = sLen;
			}
			else if (s[i] == 'L') {
				force = 0;
			}
			else {
				force = max(force - 1, 0);
			}
			right[i] += force;
		}
		force = 0;
		for (int i = sLen - 1; i > -1; i--) {
			if (s[i] == 'L') {
				force = sLen;
			}
			else if (s[i] == 'R') {
				force = 0;
			}
			else {
				force = max(0, force - 1);
			}
			left[i] += force;
		}
		for (size_t i = 0; i < sLen; i++) {
			if (left[i] > right[i]) {
				s[i] = 'L';
			}
			else if (left[i] < right[i]) {
				s[i] = 'R';
			}
		}
		return s;
	}
	int numRescueBoats(vector<int>& people, int limit) {//救生艇
		sort(people.begin(), people.end());
		size_t numsLen = people.size();
		int leftCur = 0, rightCur = numsLen - 1;
		int res = 0;
		while (leftCur < numsLen && rightCur > -1 && leftCur < rightCur) {
			if (people[leftCur] + people[rightCur] <= limit) {
				leftCur++;
			}
			rightCur--;
			res++;
		}
		if (leftCur == rightCur) {
			res++;
		}
		return res;
	}
	int totalFruit(vector<int>& tree) {//水果成篮，用map比用set简单
		unordered_map<int, int> fruits;
		int res = 0;
		int left = 0;
		for (int i = 0; i < tree.size(); i++) {
			fruits[tree[i]]++;//入窗口
			while (fruits.size() > 2) {//出窗口
				fruits[tree[left]]--;
				if (fruits[tree[left]] == 0) {
					fruits.erase(tree[left]);
				}
				left++;
			}
			res = max(res, i - left + 1);
		}
		return res;
	}
	int numSubarraysWithSum(vector<int>& nums, int target) {//和相同的二元子数组
		unordered_map<int, int> prefixMap;
		int res = 0, prefix = 0;
		prefixMap[0] = 1;
		for (int& num : nums) {
			prefix += num;
			if (prefixMap.count(prefix - target) > 0) {
				//存在 prefix2 - prefix1 == target 的情况
				res += prefixMap[prefix - target];
			}
			prefixMap[prefix]++;
		}
		return res;
	}
	vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {//区间列表的交集
		size_t flistLen = firstList.size(), slistLen = secondList.size(), fCur = 0, sCur = 0;
		vector<vector<int>> res;
		while (fCur < flistLen && sCur < slistLen) {
			int leftEnd = max(firstList[fCur][0], secondList[sCur][0]);
			int rightEnd = min(firstList[fCur][1], secondList[sCur][1]);
			if (leftEnd <= rightEnd) {//合法区间
				res.push_back({ leftEnd, rightEnd });
			}
			//将靠前的区间向后移
			if (firstList[fCur][1] < secondList[sCur][1]) {
				fCur++;
			}
			else {
				sCur++;
			}
		}
		return res;
	}
	int subarraysWithKDistinct(vector<int>& nums, int cnt) {//K 个不同整数的子数组
		//将“恰好问题”转换为至多相减
		return subarraysWithKDistinctMax(nums, cnt) - subarraysWithKDistinctMax(nums, cnt - 1);
	}
	int subarraysWithKDistinctMax(vector<int>& nums, int cnt) {
		//窗口里至多有k种元素
		int numsLen = nums.size();
		unordered_map<int, int> numsMap;
		int left = 0, res = 0;
		for (int i = 0; i < numsLen; i++) {
			numsMap[nums[i]]++;
			while (numsMap.size() > cnt) {
				numsMap[nums[left]]--;
				if (numsMap[nums[left]] == 0) {
					numsMap.erase(nums[left]);
				}
				left++;
			}
			//以右侧为头向左拓展的子数组数量
			res += i - left + 1;
		}
		return res;
	}
	int minKBitFlipsBAK(vector<int>& nums, int wide) {//K 连续位的最小翻转次数
		//暴力算法超时
		size_t numsLen = nums.size();
		int res = 0;
		for (size_t i = 0; i <= numsLen - wide; i++) {
			if (nums[i] == 0) {
				int lim = i + wide;
				for (int j = i; j < lim; j++) {
					nums[j] = nums[j] == 0 ? 1 : 0;
				}
				res++;
			}
		}
		for (size_t i = numsLen - wide; i < numsLen; i++) {
			if (nums[i] == 0) {
				return -1;
			}
		}
		return res;
	}
	int minKBitFlips(vector<int>& nums, int k) {//K 连续位的最小翻转次数
		size_t numsLen = nums.size();
		int res = 0, flipTime = 0;//窗口内累计翻转次数
		for (size_t i = 0; i < numsLen; i++) {
			if (i >= k && nums[i - k] == 2) {//超出上一个窗口翻转范围
				flipTime--;
			}
			if (flipTime % 2 == nums[i]) {//需要翻转（累积影响）
				if (i + k > numsLen) {
					return -1;
				}
				flipTime++;
				nums[i] = 2;
				res++;
			}
		}
		return res;
	}
	int longestOnes(vector<int>& nums, int K) {//最大连续1的个数 III
		int numsLen = nums.size(), left = 0, res = 0, right = 0;
		while (left < numsLen) {
			if (right < numsLen && ((K > 0 && nums[right] == 0) || nums[right] == 1)) {
				if (nums[right++] == 0) {//先把K分配
					K--;
				}
			}
			else {
				if (K == 0 || (right == numsLen && K > 0)) {//异常判断
					res = max(res, right - left);
				}
				if (nums[left] == 0) {//移动安插位置
					K++;
				}
				left++;
			}
		}
		return res;
	}
	vector<int> numMovesStonesII(vector<int>& stones) {//移动石子直到连续 II
		sort(stones.begin(), stones.end());
		int stoneCnt = stones.size();
		int minStep = INT_MAX, maxStep = 0, s1 = 0, s2 = 0;
		s1 = stones[stoneCnt - 1] - stones[0] + 1 - stoneCnt;//可移动空位
		s2 = min(stones[1] - stones[0] - 1, stones[stoneCnt - 1] - stones[stoneCnt - 2] - 1);//不可利用空位
		maxStep = s1 - s2;
		int right = 0;
		for (int left = 0; left < stoneCnt; left++) {
			while (right + 1 < stoneCnt && stones[right + 1] - stones[left] < stoneCnt) {
				//找到窗口
				right++;
			}
			int cost = stoneCnt - (right - left + 1);//窗口内缺失的石头数量
			if ((right - left + 1 == stoneCnt - 1) && (stones[right] - stones[left] + 1 == stoneCnt - 1)) {
				cost = 2;
			}
			minStep = min(minStep, cost);
		}
		return { minStep, maxStep };
	}
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {//爱生气的书店老板
		size_t numsLen = customers.size();
		int res = 0;
		for (size_t i = 0; i < numsLen; i++) {
			res += grumpy[i] == 0 ? customers[i] : 0;
		}
		int left = 0, right = X;
		for (size_t i = 0; i < right; i++) {
			res += grumpy[i] == 1 ? customers[i] : 0;
		}
		int newRes = res;
		while (right < numsLen) {
			newRes = newRes + (grumpy[right] == 1 ? customers[right] : 0) - (grumpy[left] == 1 ? customers[left] : 0);
			res = max(res, newRes);
			left++;
			right++;
		}
		return res;
	}
	vector<double> sampleStats(vector<int>& count) {//大样本统计
		//最小值、最大值、平均值、中位数和众数
		vector<double> res(5, 0.0);
		int minVal = -1, maxVal = 0;
		int cand = 0, cnt = 0;
		int totalCnt = 0, currentCnt = 0, lastCnt = 0;
		for (int& num : count) {//有效样本数量
			totalCnt += num;
		}
		int lim = totalCnt / 2;
		bool isOdd = totalCnt % 2 == 1;
		for (size_t val = 0; val < 256; val++) {
			int valCnt = count[val];
			if (valCnt == 0) {
				continue;
			}
			//求平均
			res[2] += 1.0 * valCnt * val / totalCnt;
			//最小值
			if (minVal == -1) {
				minVal = val;
			}
			//最大值
			maxVal = val;
			//众数
			if (valCnt > cnt) {
				cand = val;
				cnt = valCnt;
			}
		}
		int lastVal = 0;
		for (size_t val = 0; val < 256; val++) {
			int valCnt = count[val];
			if (valCnt == 0) {
				continue;
			}
			//中位数，三种情况，奇数，偶数非跨区，偶数跨区
			lastCnt = currentCnt;
			currentCnt += valCnt;
			if (isOdd && lastCnt < lim && lim <= currentCnt) {//奇数
				res[3] = val + 0.0;
				break;
			}
			else if (!isOdd && lastCnt < lim && lim + 1 <= currentCnt) {//偶数非跨区
				res[3] = val + 0.0;
				break;
			}
			else if (!isOdd && lastCnt == lim && lim + 1 <= currentCnt) {
				res[3] = (lastVal + val) / 2.0;
				break;
			}
			lastVal = val;
		}
		res[0] = minVal + 0.0;
		res[1] = maxVal + 0.0;
		res[4] = cand + 0.0;
		return res;
	}
	int equalSubstring(string s, string t, int maxCost) {//尽可能使字符串相等
		int res = 0;
		int sLen = s.size(), left = 0;
		for (int i = 0; i < sLen; i++) {
			maxCost -= abs(s[i] - t[i]);
			while (left <= i && maxCost < 0) {
				maxCost += abs(s[left] - t[left]);
				left++;
			}
			res = max(res, i - left + 1);
		}
		return res;
	}
	//int prefix[300][300];
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {//元素和为目标值的子矩阵数量
		size_t rol = matrix.size(), col = matrix[0].size();
		//求累加矩阵
		int** prefix = new int* [rol + 1];
		for (int i = 0; i <= rol; i++) {
			prefix[i] = new int[col + 1];
			for (int j = 0; j <= col; j++) {
				prefix[i][j] = 0;
			}
		}
		for (size_t i = 1; i <= rol; i++) {
			for (size_t j = 1; j <= col; j++) {
				prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
		int res = 0;
		for (size_t r1 = 1; r1 <= rol; r1++) {
			for (size_t c1 = 1; c1 <= col; c1++) {
				for (size_t r2 = r1; r2 <= rol; r2++) {
					for (size_t c2 = c1; c2 <= col; c2++) {
						if (prefix[r2][c2] - prefix[r2][c1 - 1] - prefix[r1 - 1][c2] + prefix[r1 - 1][c1 - 1] == target) {
							res++;
						}
					}
				}
			}
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = ".L.R...LR..L..";
	string b = "abc";
	vector<int> inpt1 = { 1,0,1,2,1,1,7,5 };
	vector<int> inpt2 = { 0,1,0,1,0,1,0,1 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{ 0, 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 1, 0, 0, 1 },
		{ 1, 1, 0, 1, 1, 0 },
		{ 1, 0, 0, 1, 0, 0 },
	};
	mySolution.numSubmatrixSumTarget(nums, 0);
	return 0;
}
#endif

//cookBook-链表
#if false

class Solution {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	ListNode* myBuildList(vector<int>& nums) {
		ListNode* rootNode = new ListNode;
		ListNode* currentNode = rootNode;
		for (int& num : nums) {
			currentNode->next = new ListNode;
			currentNode = currentNode->next;
			currentNode->val = num;
		}
		return rootNode->next;
	}
	ListNode* deleteDuplicatesMKI(ListNode* head) {//删除排序链表中的重复元素
		if (head == nullptr) {
			return head;
		}
		ListNode* currentNode = head, * nextNode = head;
		while (nextNode != nullptr) {
			if (currentNode->val != nextNode->val) {
				currentNode->next = nextNode;
				currentNode = currentNode->next;
			}
			nextNode = nextNode->next;
		}
		currentNode->next = nextNode;
		return head;
	}
	ListNode* deleteDuplicates(ListNode* head) {//删除排序链表中的重复元素 II
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* currentNode, * leftNode, * rightNode;
		ListNode* rootNode = new ListNode;
		rootNode->next = head;
		currentNode = rootNode, leftNode = head, rightNode = head;
		while (rightNode != nullptr) {
			if (leftNode->val == rightNode->val) {
				rightNode = rightNode->next;
			}
			else if (leftNode->next == rightNode) {
				currentNode->next = leftNode;
				currentNode = currentNode->next;
				leftNode = rightNode;
			}
			else {
				leftNode = rightNode;
			}
		}
		currentNode->next = leftNode->next == nullptr ? leftNode : nullptr;
		return rootNode->next;
	}
	ListNode* partition(ListNode* head, int x) {//分隔链表
		ListNode* sortNode = new ListNode;
		ListNode* rminNode = new ListNode;
		ListNode* sortCur = sortNode, * rminCur = rminNode;
		sortNode->next = head, rminNode->next = head;
		while (rminCur != nullptr && rminCur->next != nullptr) {
			if (rminCur->next->val < x) {
				sortCur->next = rminCur->next;
				rminCur->next = rminCur->next->next;
				sortCur = sortCur->next;
			}
			else {
				rminCur = rminCur->next;
			}
		}
		if (rminCur != nullptr) {
			rminCur->next = nullptr;
		}
		sortCur->next = rminNode->next;
		return sortNode->next;
	}
	ListNode* reverseBetween(ListNode* head, int m, int n) {//反转链表 II
		//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
		ListNode* root = new ListNode;
		root->next = head;
		ListNode* last = root;
		stack<ListNode*> stk;
		int cnt = 1;
		while (cnt < m) {
			last = head;
			head = head->next;
			cnt++;
		}
		while (cnt <= n) {
			stk.push(head);
			head = head->next;
			cnt++;
		}
		while (!stk.empty()) {
			last->next = stk.top();
			stk.pop();
			last = last->next;
		}
		last->next = head;
		return root->next;
	}
	ListNode* reverseKGroupBAK(ListNode* head, int k) {//K 个一组翻转链表
		//只使用常数空间
		//栈版本
		ListNode* rootNode = new ListNode;
		rootNode->next = head;
		ListNode* slowCur = rootNode, * fastCur = rootNode;
		stack<ListNode*> stk;
		int cnt = 0;
		while (fastCur->next != nullptr) {
			fastCur = fastCur->next;
			cnt++;
			if (cnt == k) {
				ListNode* front = slowCur, * rear = fastCur->next;
				while (cnt > 0) {
					stk.push(slowCur->next);
					slowCur = slowCur->next;
					cnt--;
				}
				while (!stk.empty()) {
					front->next = stk.top();
					stk.pop();
					front = front->next;
				}
				front->next = rear;
				slowCur = front;
				fastCur = front;
			}
		}
		return rootNode->next;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {//K 个一组翻转链表
		//只使用常数空间
		//不移动头节点固定位置插入就可以实现反序
		ListNode* rootNode = new ListNode;
		rootNode->next = head;
		ListNode* slowCur = rootNode, * fastCur = rootNode;
		int cnt = 0;
		while (fastCur->next != nullptr) {
			fastCur = fastCur->next;
			cnt++;
			if (cnt == k) {
				ListNode* nextNode = slowCur->next;
				while (cnt > 1) {
					ListNode* copy = slowCur->next;
					slowCur->next = copy->next;
					copy->next = fastCur->next;
					fastCur->next = copy;
					cnt--;
				}
				cnt = 0;
				fastCur = nextNode;
				slowCur = nextNode;
			}
		}
		return rootNode->next;
	}
	void reorderList(ListNode* head) {//重排链表
		vector<ListNode*> nodeVtr;
		ListNode* current = head;
		while (current != nullptr) {
			nodeVtr.push_back(current);
			current = current->next;
		}
		int leftCur = 0, rightCur = nodeVtr.size() - 1;
		head = new ListNode;
		current = head;
		while (leftCur < rightCur) {
			current->next = nodeVtr[leftCur++];
			current = current->next;
			current->next = nodeVtr[rightCur--];
			current = current->next;
		}
		if (leftCur == rightCur) {
			current->next = nodeVtr[leftCur];
			current = current->next;
		}
		current->next = nullptr;
		head = head->next;
		return;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {//两数相加 II
		stack<ListNode*> stk1, stk2;
		while (l1 != nullptr) {
			stk1.push(l1);
			l1 = l1->next;
		}
		while (l2 != nullptr) {
			stk2.push(l2);
			l2 = l2->next;
		}
		int aux = 0;
		ListNode* root = new ListNode;
		while (!stk1.empty() || !stk2.empty() || aux == 1) {
			int cand1 = 0, cand2 = 0;
			if (!stk1.empty()) {
				cand1 = stk1.top()->val;
				stk1.pop();
			}
			if (!stk2.empty()) {
				cand2 = stk2.top()->val;
				stk2.pop();
			}
			ListNode* tmp = new ListNode;
			tmp->val = (cand1 + cand2 + aux) % 10;
			tmp->next = root->next;
			root->next = tmp;
			aux = (cand1 + cand2 + aux) / 10;
		}
		return root->next;
	}
	vector<ListNode*> splitListToParts(ListNode* root, int k) {//分隔链表
		ListNode* current = root;
		int cnt = 0;
		while (current != nullptr) {
			current = current->next;
			cnt++;
		}
		int lim = cnt / k;
		int gap = cnt % k;
		vector<ListNode*> res(k);
		current = root;
		ListNode* tmp = new ListNode;
		for (int i = 0; i < k; i++) {
			int currentCnt = 0;
			int currentLim = lim;
			if (i < gap) {
				currentLim++;
			}
			res[i] = current;
			ListNode* cur = tmp;
			cur->next = current;
			while (current != nullptr && currentCnt++ < currentLim) {
				current = current->next;
				cur = cur->next;
			}
			if (cur != nullptr) {
				cur->next = nullptr;
			}
		}
		return res;
	}
	ListNode* middleNode(ListNode* head) {//链表的中间结点
		ListNode* root = new ListNode;
		root->next = head;
		ListNode* slowCur = root, * fastCur = root;
		int cnt = 0;
		while (fastCur != nullptr && fastCur->next != nullptr) {
			slowCur = slowCur->next;
			fastCur = fastCur->next->next;
			cnt += 2;
		}
		if (fastCur == nullptr) {
			cnt++;
		}
		if (cnt % 2 == 0) {
			slowCur = slowCur->next;
		}
		return slowCur;
	}
	int getDecimalValue(ListNode* head) {//二进制链表转整数
		int res = 0;
		while (head != nullptr) {
			res *= 2;
			res += head->val;
			head = head->next;
		}
		return res;
	}
	ListNode* removeZeroSumSublists(ListNode* head) {//从链表中删去总和值为零的连续节点
		unordered_map<int, ListNode*> prefixMap;
		int sum = 0;
		ListNode* root = new ListNode;
		root->next = head, root->val = 0;
		ListNode* cur = root;
		while (cur != nullptr) {
			sum += cur->val;
			prefixMap[sum] = cur;
			cur = cur->next;
		}
		cur = root, sum = 0;
		while (cur != nullptr) {
			sum += cur->val;
			cur->next = prefixMap[sum]->next;
			cur = cur->next;
		}
		return root->next;
	}
	vector<int> nextLargerNodes(ListNode* head) {//链表中的下一个更大节点
		vector<int> nums;
		for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
			nums.push_back(cur->val);
		}
		vector<int> res(nums);
		stack<int> stk;
		for (int i = nums.size() - 1; i > -1; i--) {
			while (!stk.empty() && stk.top() <= nums[i]) {
				stk.pop();
			}
			res[i] = stk.empty() ? 0 : stk.top();
			stk.push(nums[i]);
		}
		return res;
	}
	int numComponents(ListNode* head, vector<int>& G) {//链表组件
		unordered_set<int> gSet;
		for (int& num : G) {
			gSet.emplace(num);
		}
		for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
			cur->val = gSet.count(cur->val) > 0 ? 1 : 0;
		}
		int res = 0;
		ListNode* cur = head;
		while (cur != nullptr) {
			if (cur->val == 1) {
				res++;
				while (cur != nullptr && cur->val == 1) {
					cur = cur->next;
				}
			}
			else {
				cur = cur->next;
			}
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = ".L.R...LR..L..";
	string b = "abc";
	vector<int> inpt1 = { 1, 2, 3, 4, 5, 6 };
	vector<int> inpt2 = { 0,1,0,1,0,1,0,1 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{ 0, 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 1, 0, 0, 1 },
		{ 1, 1, 0, 1, 1, 0 },
		{ 1, 0, 0, 1, 0, 0 },
	};
	mySolution.middleNode(mySolution.myBuildList(inpt1));
	return 0;
}
#endif

//cookBook-栈和队列
#if false

class FreqStack {//最大频率栈
public:
	FreqStack() {

	}

	void push(int x) {
		freq[x]++;
		maxFreq = max(maxFreq, freq[x]);
		stkVtr[freq[x]].push(x);
		return;
	}

	int pop() {
		int res = stkVtr[maxFreq].top();
		stkVtr[maxFreq].pop();
		freq[res]--;
		if (stkVtr[maxFreq].size() == 0) {
			maxFreq--;
		}
		return res;
	}
private:
	unordered_map<int, int> freq;
	unordered_map<int, stack<int>> stkVtr;
	int maxFreq = 0;
};

class StockSpanner {//股票价格跨度
public:
	StockSpanner() {
		return;
	}

	int next(int price) {
		int tmp = 1;
		while (!pri.empty() && pri.top() <= price) {
			tmp += day.top();
			day.pop();
			pri.pop();
		}
		pri.push(price);
		day.push(tmp);
		return day.top();
	}
private:
	stack<int> day, pri;
};

class NestedInteger {
public:
	// Constructor initializes an empty nested list.
	NestedInteger();

	// Constructor initializes a single integer.
	NestedInteger(int value);

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Set this NestedInteger to hold a single integer.
	void setInteger(int value);

	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger& ni);

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger>& getList() const;

};

class Solution {
public:
	string simplifyPath(string path) {//简化路径
		path.push_back('/');
		stack<string> pathStack;
		string current;
		for (char& ch : path) {
			if (ch == '/') {
				if (current == ".") {
					current.clear();
				}
				else if (current == "..") {
					if (!pathStack.empty()) {
						pathStack.pop();
					}
				}
				else if (current.size() > 0) {
					pathStack.push(current);
				}
				current.clear();
			}
			else {
				current.push_back(ch);
			}
		}
		string res = "/";
		while (!pathStack.empty()) {
			res = '/' + pathStack.top() + res;
			pathStack.pop();
		}
		if (res.size() != 1) {
			res.pop_back();
		}
		return res;
	}
	int calculate(string s) {//基本计算器
		int res = 0, sym = 1, tmp = 0;
		stack<int> numStack;
		//假设只有两个操作数，A - (B - C) = A + （-1）* (B - C)
		for (char& ch : s) {
			if (ch == ' ') {
				continue;
			}
			else if (ch >= '0' && ch <= '9') {
				tmp *= 10;
				tmp += ch - '0';
			}
			else if (ch == '+') {
				res += tmp * sym;
				tmp = 0;
				sym = 1;
			}
			else if (ch == '-') {
				res += tmp * sym;
				tmp = 0;
				sym = -1;
			}
			else if (ch == '(') {
				numStack.push(res);
				numStack.push(sym);
				sym = 1;
				res = 0;
			}
			else if (ch == ')') {
				res += tmp * sym;
				res *= numStack.top();
				numStack.pop();
				res += numStack.top();
				numStack.pop();
				tmp = 0;
			}
		}
		return res + tmp * sym;
	}
	bool isValidSerialization(string preorder) {//验证二叉树的前序序列化
		int cur = 0, sLen = preorder.size();
		bool isLeave = false;
		while (cur < sLen) {//先转换为节点标记
			if (preorder[cur] <= '9' && preorder[cur] >= '0') {
				if (isLeave == false) {
					isLeave = true;
				}
				else {
					preorder[cur] = ',';
				}
			}
			else {
				isLeave = false;
			}
			cur++;
		}
		int diff = 1;//出度 - 入度
		for (char& ch : preorder) {
			if (ch == ',') {
				continue;
			}
			diff--;
			if (diff < 0) {
				return false;
			}
			if (ch != '#') {
				diff += 2;
			}
		}
		return diff == 0;
	}
	NestedInteger deserialize(string s) {//迷你语法分析器
		//整数也需要创建容器
		int n = s.size();
		if (n == 0)return NestedInteger();
		if (s[0] != '[')return NestedInteger(stoi(s));
		string num;
		stack<NestedInteger> st;
		for (int i = 0; i < n; i++) {
			//cout << i << " " << st.size() << "\n";
			if (s[i] == '[') {
				st.push(NestedInteger());
			}
			else if (s[i] == ',') {
				if (!num.empty())st.top().add(NestedInteger(stoi(num)));
				num.clear();
			}
			else if (s[i] == ']') {
				if (!num.empty()) {
					st.top().add(NestedInteger(stoi(num)));
					num.clear();
				}
				if (st.size() > 1) {
					auto now = st.top();
					st.pop();
					st.top().add(now);
				}
			}
			else num += s[i];
		}
		return st.top();
	}
	string removeKdigits(string num, int k) {//移掉K位数字
		stack<char> stk;
		for (char& ch : num) {//单调不减栈
			while (stk.size() > 0 && stk.top() > ch && k > 0) {
				stk.pop();
				--k;
			}
			stk.push(ch);
		}
		while (k-- > 0) {//尾部弹出
			stk.pop();
		}
		string res = "";
		while (!stk.empty()) {//倒叙生成
			res = stk.top() + res;
			stk.pop();
		}
		size_t resLen = res.size(), cur = 0;
		while (cur < resLen) {//去零
			if (res[cur] != '0') {
				break;
			}
			cur++;
		}
		res = res.substr(cur, resLen - cur);
		return res == "" ? "0" : res;
	}
	bool find132pattern(vector<int>& nums) {//132模式
		//贪心+递减栈
		size_t numsLen = nums.size();
		if (numsLen < 3) {
			return false;
		}
		vector<int> left(nums);
		for (size_t i = 1; i < numsLen; i++) {
			left[i] = min(left[i], left[i - 1]);
		}
		stack<int> stk;
		for (int i = numsLen - 1; i > -1; i--) {
			if (left[i] < nums[i]) {
				while (!stk.empty() && stk.top() <= left[i]) {//递减栈，从1向上找
					stk.pop();
				}
				if (!stk.empty() && stk.top() < nums[i]) {//找到满足<3的就行
					return true;
				}
				stk.push(nums[i]);
			}
		}
		return false;
	}
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {//下一个更大元素 I
		stack<int> stk;
		vector<int> res;
		unordered_map<int, int> resMap;
		for (int& num : nums2) {
			while (!stk.empty() && stk.top() < num) {//带入栈元素大于栈顶元素，证明找到了右侧更大的
				resMap[stk.top()] = num;
				stk.pop();
			}
			stk.push(num);
		}
		while (!stk.empty()) {
			resMap[stk.top()] = -1;
			stk.pop();
		}
		for (int& num : nums1) {
			res.push_back(resMap[num]);
		}
		return res;
	}
	vector<int> nextGreaterElements(vector<int>& nums) {//下一个更大元素 II
		int numnsLen = nums.size();
		vector<int> res(numnsLen, -1);
		for (int i = 0; i < numnsLen; i++) {
			nums.push_back(nums[i]);
		}
		stack<int> stk;
		for (int i = 0; i < 2 * numnsLen; i++) {
			while (!stk.empty() && nums[i] > nums[stk.top()]) {
				int id = stk.top();
				stk.pop();
				if (id < numnsLen) {
					res[id] = nums[i];
				}
			}
			stk.push(i);
		}
		return res;
	}
	vector<int> exclusiveTime(int n, vector<string>& logs) {//函数的独占时间
		//关键点：栈顶元素抢占cpu
		vector<int> res(n, 0);
		stack<int> stk;//记录id
		int prev = 0;//上次刷新时间戳
		for (string& str : logs) {
			int cur = 0;
			int sLen = str.size();
			int id = 0, time = 0;
			string flag;
			while (cur < sLen) {//获取ID
				if (str[cur] == ':') {
					break;
				}
				id *= 10;
				id += str[cur] - '0';
				cur++;
			}
			cur++;
			while (cur < sLen) {//获取状态
				if (str[cur] == ':') {
					break;
				}
				flag.push_back(str[cur]);
				cur++;
			}
			cur++;
			while (cur < sLen) {//获取时间
				time *= 10;
				time += str[cur] - '0';
				cur++;
			}
			if (stk.empty()) {
				stk.push(id);
				prev = time;
				continue;
			}
			if (flag == "start") {
				res[stk.top()] += time - prev;
				stk.push(id);
				prev = time;
			}
			else {
				res[id] += time - prev + 1;
				stk.pop();
				prev = time + 1;
			}
		}
		return res;
	}
	int calPoints(vector<string>& ops) {//棒球比赛
		stack<int> stk;
		for (string& op : ops) {
			if (op == "+") {
				int tmp = stk.top();
				stk.pop();
				int current = tmp + stk.top();
				stk.push(tmp);
				stk.push(current);
			}
			else if (op == "D") {
				stk.push(2 * stk.top());
			}
			else if (op == "C") {
				stk.pop();
			}
			else {
				stk.push(stoi(op));
			}
		}
		int res = 0;
		while (!stk.empty()) {
			res += stk.top();
			stk.pop();
		}
		return res;
	}
	bool backspaceCompare(string S, string T) {//比较含退格的字符串
		stack<char> stkS, stkT;
		for (char& ch : S) {
			if (ch == '#') {
				if (!stkS.empty()) {
					stkS.pop();
				}
			}
			else {
				stkS.push(ch);
			}
		}
		for (char& ch : T) {
			if (ch == '#') {
				if (!stkT.empty()) {
					stkT.pop();
				}
			}
			else {
				stkT.push(ch);
			}
		}
		if (stkS.size() != stkT.size()) {
			return false;
		}
		while (!stkS.empty()) {
			if (stkS.top() != stkT.top()) {
				return false;
			}
			stkS.pop();
			stkT.pop();
		}
		return true;
	}
	vector<int> asteroidCollision(vector<int>& asteroids) {//行星碰撞
		stack<int> stk;
		int asteroidsCnt = asteroids.size();
		int cur = 0;
		while (cur < asteroidsCnt) {
			int num = asteroids[cur];
			if (stk.empty() || (!stk.empty() && stk.top() * num > 0) || (!stk.empty() && stk.top() < 0 && num > 0)) {//新行星入栈
				stk.push(num);
			}
			else if (abs(stk.top()) == abs(num)) {//新行星和栈顶行星湮灭
				stk.pop();
			}
			else if (abs(stk.top()) < abs(num)) {//栈顶行星消灭
				stk.pop();
				continue;
			}
			cur++;
		}
		vector<int> res;
		while (!stk.empty()) {
			res.insert(res.begin(), stk.top());
			stk.pop();
		}
		return res;
	}
	bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }
	bool isLower(char c) { return c >= 'a' && c <= 'z'; }
	bool isDigit(char c) { return c >= '0' && c <= '9'; }
	map<string, int> atomSplit(const string  str, int leftCur, int rightCur) {
		map<string, int> atomMap;
		string atomName;
		int cnt = 0, cur = leftCur;
		while (cur <= rightCur) {
			char ch = str[cur];
			if (isUpper(ch)) {
				if (!atomName.empty()) {//正常元素
					atomMap[atomName] += max(cnt, 1);
					atomName.clear();
					cnt = 0;
				}
				atomName += ch;
			}
			else if (isLower(ch)) {
				atomName += ch;
			}
			else if (isDigit(ch)) {
				cnt *= 10;
				cnt += ch - '0';
			}
			else if (ch == '(') {
				if (!atomName.empty()) {//括号前元素
					atomMap[atomName] += max(cnt, 1);
					atomName.clear();
					cnt = 0;
				}
				int newCur = ++cur;//括号内第一个元素头
				int bracket = 1;
				while (cur <= rightCur) {
					if (str[cur] == '(') {
						bracket++;
					}
					else if (str[cur] == ')') {
						bracket--;
					}
					if (bracket == 0) {
						break;
					}
					cur++;
				}
				map<string, int> newAtomMap = atomSplit(str, newCur, cur - 1);//处理括号内
				cnt = 0;
				while (cur + 1 <= rightCur && isDigit(str[cur + 1])) {
					cnt *= 10;
					cnt += str[cur + 1] - '0';
					cur++;
				}
				cnt = max(1, cnt);
				for (auto& it : newAtomMap) {
					atomMap[it.first] += it.second * cnt;
				}
				cnt = 0;
			}
			cur++;
		}
		if (!atomName.empty()) {
			atomMap[atomName] += max(cnt, 1);
		}
		return atomMap;
	}
	string countOfAtoms(string formula) {//原子的数量
		map<string, int> atomMap = atomSplit(formula, 0, formula.size() - 1);
		//后处理
		string res;
		for (auto& it : atomMap) {
			res += it.first;
			if (it.second > 1) {
				res += to_string(it.second);
			}
		}
		return res;
	}
	int scoreOfParentheses(string S) {//括号的分数
		stack<int> stk;
		for (char& ch : S) {
			if (ch == '(') {
				stk.push(0);
			}
			else {
				if (stk.top() == 0) {
					stk.pop();
					stk.push(1);
				}
				else {
					int tmp = 0;
					while (!stk.empty() && stk.top() != 0) {
						tmp += stk.top();
						stk.pop();
					}
					stk.pop();
					stk.push(2 * tmp);
				}
			}
		}
		int res = 0;
		while (!stk.empty()) {
			res += stk.top();
			stk.pop();
		}
		return res;
	}
	int shortestSubarray(vector<int>& nums, int K) {//和至少为 K 的最短子数组
		size_t numsLen = nums.size();
		vector<int> prefix(numsLen + 1);
		for (size_t i = 0; i < numsLen; i++) {
			prefix[i + 1] = prefix[i] + nums[i];
		}
		deque<int> dq;
		int res = INT_MAX;
		for (int i = 0; i <= numsLen; i++) {
			while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
				dq.pop_back();
			}
			while (!dq.empty() && prefix[i] >= prefix[dq.front()] + K) {
				res = min(res, i - dq.front());
				dq.pop_front();
			}
			dq.push_back(i);
		}
		return res == INT_MAX ? -1 : res;
	}
	string removeOuterParentheses(string S) {//删除最外层的括号
		stack<int> stk;
		int sLen = S.size();
		int cur = 0;
		int bracket = 0;
		while (cur < sLen) {
			if (bracket == 0) {
				stk.push(cur - 1);
				stk.push(cur);
			}
			if (S[cur] == '(') {
				bracket++;
			}
			else {
				bracket--;
			}
			cur++;
		}
		stk.push(sLen - 1);
		string res;
		for (int i = sLen - 1; i > -1; i--) {
			if (!stk.empty() && i == stk.top()) {
				stk.pop();
				continue;
			}
			res = S[i] + res;
		}
		return res;
	}
	string removeDuplicates(string S) {//删除字符串中的所有相邻重复项
		string res;
		for (char& ch : S) {
			if (!res.empty() && ch == res.back()) {
				while (!res.empty() && ch == res.back()) {
					res.pop_back();
				}
				continue;
			}
			res.push_back(ch);
		}
		return res;
	}
	bool isValid(string s) {//检查替换后的词是否有效
		stack<char> stk;
		for (char& ch : s) {
			if (ch == 'c') {
				if (stk.empty() || stk.top() != 'b') {
					return false;
				}
				stk.pop();
				if (stk.empty() || stk.top() != 'a') {
					return false;
				}
				stk.pop();
				continue;
			}
			stk.push(ch);
		}
		return stk.empty();
	}
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {//验证栈序列
		int totalCnt = pushed.size();
		int pushCur = 0, popCur = 0;
		stack<int> stk;
		while (pushCur < totalCnt) {
			if (stk.empty() || stk.top() != popped[popCur]) {
				stk.push(pushed[pushCur++]);
			}
			else if (stk.top() == popped[popCur]) {
				stk.pop();
				popCur++;
			}
		}
		while (!stk.empty()) {
			if (stk.top() != popped[popCur]) {
				return false;
			}
			stk.pop();
			popCur++;
		}
		return popCur == totalCnt;
	}
	int minAddToMakeValid(string S) {//使括号有效的最少添加
		stack<char> stk;
		for (char& ch : S) {
			if (!stk.empty() && ch == ')' && stk.top() == '(') {
				stk.pop();
			}
			else {
				stk.push(ch);
			}
		}
		return stk.size();
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = ".L.R...LR..L..";
	string b = "(()())(())";
	vector<int> inpt1 = { 1 };
	vector<int> inpt2 = { 1, 3, 4, 2 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{ 0, 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 1, 0, 0, 1 },
		{ 1, 1, 0, 1, 1, 0 },
		{ 1, 0, 0, 1, 0, 0 },
	};
	mySolution.removeOuterParentheses(b);
	return 0;
}
#endif

//cookBook-树
#if false

class Solution {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
	int numTrees(int n) {//不同的二叉搜索树
		vector<int> dp(n + 1, 0);
		dp[0] = 1, dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}
		return dp[n];
	}
	bool isSameTree(TreeNode* p, TreeNode* q) {//相同的树
		if (p == nullptr && q == nullptr) {
			return true;
		}
		if ((p == nullptr) ^ (q == nullptr)) {
			return false;
		}
		if (p->val == q->val) {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		return false;
	}
	void recoverTree(TreeNode* root) {//恢复二叉搜索树
		vector<int> nums;
		recoverTreeSubFunc(root, nums);
		size_t numsLen = nums.size();
		int x = -1, y = -1;
		for (size_t i = 1; i < numsLen; i++) {
			if (nums[i] < nums[i - 1]) {
				y = nums[i];
				if (x == -1) {
					x = nums[i - 1];
				}
				else {
					break;
				}
			}
		}
		recoverTreeSubFuncRec(root, x, y, 2);
		return;
	}
	void recoverTreeSubFunc(TreeNode* root, vector<int>& nums) {//中序遍历获取
		if (root == nullptr) {
			return;
		}
		recoverTreeSubFunc(root->left, nums);
		nums.push_back(root->val);
		recoverTreeSubFunc(root->right, nums);
		return;
	}
	void recoverTreeSubFuncRec(TreeNode* root, int x, int y, int cnt) {//中序遍历恢复
		if (root == nullptr) {
			return;
		}
		if (root->val == x || root->val == y) {
			root->val = root->val == x ? y : x;
			cnt--;
			if (cnt == 0) {
				return;
			}
		}
		recoverTreeSubFuncRec(root->left, x, y, cnt);
		recoverTreeSubFuncRec(root->right, x, y, cnt);
		return;
	}
	bool isSymmetric(TreeNode* root) {//对称二叉树
		return isSymmetricCheck(root, root);
	}
	bool isSymmetricCheck(TreeNode* leftCur, TreeNode* rightCur) {
		if (leftCur == nullptr && rightCur == nullptr) {
			return true;
		}
		if ((leftCur == nullptr) ^ (rightCur == nullptr)) {
			return false;
		}
		return leftCur->val == rightCur->val && isSymmetricCheck(leftCur->left, rightCur->right) && isSymmetricCheck(leftCur->right, rightCur->left);
	}
	int maxDepth(TreeNode* root) {//二叉树的最大深度
		if (root == nullptr) {
			return 0;
		}
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {//二叉树的层序遍历 II
		vector<vector<int>> res;
		if (root == nullptr) {
			return res;
		}
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			size_t queLen = que.size();
			vector<int> tmp;
			while (queLen != 0) {
				TreeNode* cur = que.front();
				que.pop();
				queLen--;
				tmp.push_back(cur->val);
				if (cur->left != nullptr) {
					que.push(cur->left);
				}
				if (cur->right != nullptr) {
					que.push(cur->right);
				}
			}
			res.insert(res.begin(), tmp);
		}
		return res;
	}
	TreeNode* sortedListToBST(ListNode* head) {//有序链表转换二叉搜索树
		vector<int> nums;
		while (head != nullptr) {
			nums.push_back(head->val);
			head = head->next;
		}
		int numsLen = nums.size();
		return sortedListToBSTSub(nums, 0, numsLen);
	}
	TreeNode* sortedListToBSTSub(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return nullptr;
		}
		int mid = left + (right - left) / 2;
		TreeNode* current = new TreeNode;
		current->val = nums[mid];
		current->left = sortedListToBSTSub(nums, left, mid);
		current->right = sortedListToBSTSub(nums, mid + 1, right);
		return current;
	}
	int minDepth(TreeNode* root) {//二叉树的最小深度
		if (root == nullptr) {
			return 0;
		}
		if (root->left == nullptr && root->right == nullptr) {
			return 1;
		}
		int left = INT_MAX, right = INT_MAX;
		if (root->left != nullptr) {
			left = minDepth(root->left);
		}
		if (root->right != nullptr) {
			right = minDepth(root->right);
		}
		return min(left, right) + 1;
	}
	vector<vector<int>> pathSumBAK(TreeNode* root, int targetSum) {//路径总和 II
		vector<vector<int>> res;
		vector<int> tmp;
		pathSumSubBAK(root, targetSum, res, tmp);
		return res;
	}
	void pathSumSubBAK(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& tmp) {
		if (root == nullptr) {
			return;
		}
		targetSum -= root->val;
		tmp.push_back(root->val);
		if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
			res.push_back(tmp);
		}
		pathSumSubBAK(root->left, targetSum, res, tmp);
		pathSumSubBAK(root->right, targetSum, res, tmp);
		tmp.pop_back();
		return;
	}
	void flatten(TreeNode* root) {//二叉树展开为链表
		if (root == nullptr) {
			return;
		}
		//从后到前的先序遍历
		flatten(root->right);
		if (root->left == nullptr) {
			return;
		}
		flatten(root->left);
		TreeNode* cur = root->left;
		while (cur->right != nullptr) {
			cur = cur->right;
		}
		cur->right = root->right;
		root->right = root->left;
		root->left = nullptr;
		return;
	}
	vector<int> rightSideView(TreeNode* root) {//二叉树的右视图
		vector<int> res;
		if (root == nullptr) {
			return res;
		}
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			size_t queLen = que.size();
			TreeNode* cur = que.back();
			res.push_back(cur->val);
			while (queLen != 0) {
				cur = que.front();
				que.pop();
				queLen--;
				if (cur->left != nullptr) {
					que.push(cur->left);
				}
				if (cur->right != nullptr) {
					que.push(cur->right);
				}
			}
		}
		return res;
	}
	int sumNumbers(TreeNode* root) {//求根到叶子节点数字之和
		int res = 0, tmp = 0;
		sumNumbersSub(root, tmp, res);
		return res;
	}
	void sumNumbersSub(TreeNode* root, int& tmp, int& res) {
		if (root == nullptr) {
			return;
		}
		tmp *= 10;
		tmp += root->val;
		if (root->left == nullptr && root->right == nullptr) {
			res += tmp;
		}
		sumNumbersSub(root->left, tmp, res);
		sumNumbersSub(root->right, tmp, res);
		tmp /= 10;
		return;
	}
	class BSTIterator {//二叉搜索树迭代器
	public:
		BSTIterator(TreeNode* root) {
			serialize(root);
			numsLen = nums.size();
		}

		int next() {
			if (hasNext()) {
				return nums[cur++];
			}
			return -1;
		}

		bool hasNext() {
			return cur < numsLen;
		}
	private:
		size_t numsLen = 0, cur = 0;
		vector<int> nums;
		void serialize(TreeNode* root) {
			if (root == nullptr) {
				return;
			}
			serialize(root->left);
			nums.push_back(root->val);
			serialize(root->right);
			return;
		}
	};
	TreeNode* invertTree(TreeNode* root) {//翻转二叉树
		if (root == nullptr) {
			return nullptr;
		}
		root->left = invertTree(root->left);
		root->right = invertTree(root->right);
		swap(root->left, root->right);
		return root;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {//二叉搜索树的最近公共祖先
		TreeNode* res = root;
		while (res != nullptr) {
			if ((p->val < res->val) && (q->val < res->val)) {
				res = res->left;
			}
			else if ((p->val > res->val) && (q->val > res->val)) {
				res = res->right;
			}
			else {
				break;
			}
		}
		return res;
	}
	vector<string> binaryTreePaths(TreeNode* root) {//二叉树的所有路径
		vector<string> res;
		string tmp;
		binaryTreePathsSub(root, res, tmp);
		return res;
	}
	void binaryTreePathsSub(TreeNode* root, vector<string>& res, string& tmp) {
		if (root == nullptr) {
			return;
		}
		string tmpCopy = tmp;
		tmp += "->" + to_string(root->val);
		if (root->left == nullptr && root->right == nullptr) {
			res.push_back(tmp.substr(2, tmp.size() - 2));
		}
		binaryTreePathsSub(root->left, res, tmp);
		binaryTreePathsSub(root->right, res, tmp);
		tmp = tmpCopy;
		return;
	}
	int rob(TreeNode* root) {//打家劫舍 III
		unordered_map<TreeNode*, int> nodeMapY, nodeMapN;
		nodeMapY[nullptr] = 0, nodeMapN[nullptr] = 0;
		robSub(root, nodeMapY, nodeMapN);
		return max(nodeMapY[root], nodeMapN[root]);
	}
	void robSub(TreeNode* root, unordered_map<TreeNode*, int>& nodeMapY, unordered_map<TreeNode*, int>& nodeMapN) {
		if (root == nullptr) {
			return;
		}
		robSub(root->left, nodeMapY, nodeMapN);
		robSub(root->right, nodeMapY, nodeMapN);
		nodeMapY[root] = nodeMapN[root->left] + nodeMapN[root->right] + root->val;
		nodeMapN[root] = max(nodeMapN[root->left], nodeMapY[root->left]) + max(nodeMapN[root->right], nodeMapY[root->right]);
		return;
	}
	int sumOfLeftLeaves(TreeNode* root) {//左叶子之和
		if (root == nullptr) {
			return 0;
		}
		queue<TreeNode*> que;
		que.push(root);
		int res = 0;
		while (!que.empty()) {
			TreeNode* cur = que.front();
			que.pop();
			if (cur->left != nullptr) {
				if (cur->left->left == nullptr && cur->left->right == nullptr) {
					res += cur->left->val;
				}
				else {
					que.push(cur->left);
				}
			}
			if (cur->right != nullptr) {
				if (cur->right->left != nullptr || cur->right->right != nullptr) {
					que.push(cur->right);
				}
			}
		}
		return res;
	}
	int pathSum(TreeNode* root, int sum) {//路径总和 III
		int res = 0;
		unordered_map<int, int> prefix;
		prefix[0] = 1;
		pathSumSub(root, sum, res, prefix, 0);
		return res;
	}
	void pathSumSub(TreeNode* root, int sum, int& res, unordered_map<int, int>& prefix, int last) {
		if (root == nullptr) {
			return;
		}
		int current = last + root->val;
		if (prefix.count(current - sum) > 0) {
			res += prefix[current - sum];
		}
		prefix[current]++;
		pathSumSub(root->left, sum, res, prefix, current);
		pathSumSub(root->right, sum, res, prefix, current);
		prefix[current]--;
		return;
	}
	vector<int> findFrequentTreeSum(TreeNode* root) {//出现次数最多的子树元素和
		unordered_map<int, int> sumMap;
		findFrequentTreeSumSub(root, sumMap);
		int maxCnt = 0;
		vector<int> res;
		for (auto& it : sumMap) {
			if (it.second > maxCnt) {
				res.clear();
				res.push_back(it.first);
				maxCnt = it.second;
			}
			else if (it.second == maxCnt) {
				res.push_back(it.first);
			}
		}
		return res;
	}
	int findFrequentTreeSumSub(TreeNode* root, unordered_map<int, int>& sumMap) {
		if (root == nullptr) {
			return 0;
		}
		int left = findFrequentTreeSumSub(root->left, sumMap);
		int right = findFrequentTreeSumSub(root->right, sumMap);
		int res = left + right + root->val;
		sumMap[res]++;
		return res;
	}
	int findBottomLeftValue(TreeNode* root) {//找树左下角的值
		if (root == nullptr) {
			return 0;
		}
		queue<TreeNode*> que;
		int res = 0;
		que.push(root);
		while (!que.empty()) {
			int qLen = que.size();
			res = que.front()->val;
			while (qLen > 0) {
				TreeNode* cur = que.front();
				que.pop();
				qLen--;
				if (cur->left != nullptr) {
					que.push(cur->left);
				}
				if (cur->right != nullptr) {
					que.push(cur->right);
				}
			}
		}
		return res;
	}
	vector<int> largestValues(TreeNode* root) {//在每个树行中找最大值
		vector<int> res;
		if (root == nullptr) {
			return res;
		}
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int qLen = que.size();
			int tmp = que.front()->val;
			while (qLen > 0) {
				TreeNode* cur = que.front();
				que.pop();
				qLen--;
				tmp = max(tmp, cur->val);
				if (cur->left != nullptr) {
					que.push(cur->left);
				}
				if (cur->right != nullptr) {
					que.push(cur->right);
				}
			}
			res.push_back(tmp);
		}
		return res;
	}
	int findTilt(TreeNode* root) {//二叉树的坡度
		int res = 0;
		findTiltSub(root, res);
		return res;
	}
	int findTiltSub(TreeNode* root, int& res) {
		if (root == nullptr) {
			return 0;
		}
		int left = findTiltSub(root->left, res);
		int right = findTiltSub(root->right, res);
		res += abs(left - right);
		int sum = root->val + left + right;
		return sum;
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {//另一个树的子树
		if (s == nullptr) {
			return false;
		}
		if (isSameTree(s, t)) {
			return true;
		}
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
	vector<double> averageOfLevels(TreeNode* root) {//二叉树的层平均值
		vector<double> res;
		if (root == nullptr) {
			return res;
		}
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int qLen = que.size(), qLenBak = qLen;
			double tmp = 0;
			while (qLen > 0) {
				TreeNode* cur = que.front();
				que.pop();
				qLen--;
				tmp += cur->val;
				if (cur->left != nullptr) {
					que.push(cur->left);
				}
				if (cur->right != nullptr) {
					que.push(cur->right);
				}
			}
			res.push_back(1.0 * tmp / qLenBak);
		}
		return res;
	}
	int widthOfBinaryTree(TreeNode* root) {//二叉树最大宽度
		if (root == nullptr) {
			return 0;
		}
		queue<pair<TreeNode*, unsigned long long>> que;
		unsigned long long res = 0;
		que.push(make_pair(root, 1));
		while (!que.empty()) {
			int qLen = que.size();
			unsigned long long frontPos = que.front().second, pos = 0;
			while (qLen > 0) {
				TreeNode* cur = que.front().first;
				pos = que.front().second;
				que.pop();
				qLen--;
				//二叉树子节点编号
				if (cur->left) {
					que.push(make_pair(cur->left, pos * 2));
				}
				if (cur->right) {
					que.push(make_pair(cur->right, pos * 2 + 1));
				}
			}
			res = max(pos - frontPos + 1, res);
		}
		return (int)res;
	}
	bool findTarget(TreeNode* root, int k) {//两数之和 IV - 输入 BST
		bool res = false;
		unordered_set<int> valSet;
		findTargetSub(root, k, valSet, res);
		return res;
	}
	void findTargetSub(TreeNode* root, int k, unordered_set<int>& valSet, bool& res) {
		if (root == nullptr || res) {
			return;
		}
		if (valSet.count(k - root->val) > 0) {
			res = true;
		}
		valSet.insert(root->val);
		findTargetSub(root->left, k, valSet, res);
		findTargetSub(root->right, k, valSet, res);
		return;
	}
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {//叶子相似的树
		vector<int> nums1, nums2;
		leafSimilarSub(root1, nums1);
		leafSimilarSub(root2, nums2);
		return nums1 == nums2;
	}
	void leafSimilarSub(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		leafSimilarSub(root->left, res);
		leafSimilarSub(root->right, res);
		if (root->left == nullptr && root->right == nullptr) {
			res.push_back(root->val);
		}
		return;
	}
	TreeNode* increasingBST(TreeNode* root) {//递增顺序查找树
		stack<TreeNode*> stk;
		increasingBSTSub(root, stk);
		TreeNode* res = nullptr;
		while (!stk.empty()) {
			stk.top()->right = res;
			stk.top()->left = nullptr;
			res = stk.top();
			stk.pop();
		}
		return res;
	}
	void increasingBSTSub(TreeNode* root, stack<TreeNode*>& stk) {
		if (root == nullptr) {
			return;
		}
		increasingBSTSub(root->left, stk);
		stk.push(root);
		increasingBSTSub(root->right, stk);
		return;
	}
	bool isCousins(TreeNode* root, int x, int y) {//二叉树的堂兄弟节点
		queue<TreeNode*> que;
		que.push(root);
		int level = 0, xLev = -1, yLev = -1;
		TreeNode* fx = nullptr, * fy = nullptr;
		while (!que.empty() && (xLev == -1 || yLev == -1)) {
			int qLen = que.size();
			while (qLen > 0 && (xLev == -1 || yLev == -1)) {
				TreeNode* cur = que.front();
				que.pop();
				qLen--;
				if (cur->val == x) {
					xLev = level;
				}
				else if (cur->val == y) {
					yLev = level;
				}
				if (cur->left != nullptr) {
					que.push(cur->left);
					if (cur->left->val == x) {
						fx = cur;
					}
					if (cur->left->val == y) {
						fy = cur;
					}
				}
				if (cur->right != nullptr) {
					que.push(cur->right);
					if (cur->right->val == x) {
						fx = cur;
					}
					if (cur->right->val == y) {
						fy = cur;
					}
				}
			}
			level++;
		}
		return xLev == yLev && fx != fy;
	}
	int distributeCoins(TreeNode* root) {//在二叉树中分配硬币
		int res = 0;
		distributeCoinsSub(root, res);
		return res;
	}
	int distributeCoinsSub(TreeNode* root, int& res) {
		if (root == nullptr) {
			return 0;
		}
		//两侧需要移动步数
		int left = distributeCoinsSub(root->left, res);
		int right = distributeCoinsSub(root->right, res);
		res += abs(left) + abs(right);
		return left + right + root->val - 1;
	}
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {//二叉树中所有距离为 K 的结点
		unordered_map<TreeNode*, TreeNode*> parent;
		distanceKSub(root, nullptr, parent);
		queue<TreeNode*> que;
		unordered_set<TreeNode*> vist;
		vector<int> res;
		int dist = 0;
		que.push(target);
		while (!que.empty() && dist <= k) {
			int qLen = que.size();
			while (qLen--) {
				TreeNode* cur = que.front();
				que.pop();
				if (vist.count(cur) > 0) {
					continue;
				}
				vist.insert(cur);
				if (dist == k) {
					res.push_back(cur->val);
				}
				if (cur->left != nullptr) {
					que.push(cur->left);
				}
				if (cur->right != nullptr) {
					que.push(cur->right);
				}
				if (parent[cur] != nullptr) {
					que.push(parent[cur]);
				}
			}
			dist++;
		}
		return res;
	}
	void distanceKSub(TreeNode* root, TreeNode* par, unordered_map<TreeNode*, TreeNode*>& parent) {
		//转换为图计算
		if (root == nullptr) {
			return;
		}
		parent[root] = par;
		distanceKSub(root->left, root, parent);
		distanceKSub(root->right, root, parent);
		return;
	}
	int deepestLeavesSum(TreeNode* root) {//层数最深叶子节点的和
		int res = 0, maxDepth = 0, currentDepth = 0;
		deepestLeavesSumSub(root, maxDepth, currentDepth, res);
		return res;
	}
	void deepestLeavesSumSub(TreeNode* root, int& maxDepth, int& currentDepth, int& res) {
		if (root == nullptr) {
			return;
		}
		currentDepth++;
		if (currentDepth > maxDepth) {
			maxDepth = currentDepth;
			res = 0;
		}
		if (currentDepth == maxDepth && root->left == nullptr && root->right == nullptr) {
			res += root->val;
		}
		deepestLeavesSumSub(root->left, maxDepth, currentDepth, res);
		deepestLeavesSumSub(root->right, maxDepth, currentDepth, res);
		currentDepth--;
		return;
	}
	TreeNode* lcaDeepestLeaves(TreeNode* root) {//最深叶节点的最近公共祖先
		int maxDepth = 0;
		return lcaDeepestLeavesSub(root, maxDepth);
	}
	TreeNode* lcaDeepestLeavesSub(TreeNode* root, int& maxDepth) {
		if (root == nullptr) {
			maxDepth = 0;
			return nullptr;
		}
		int leftHt = 0, rightHt = 0;
		TreeNode* leftNode = lcaDeepestLeavesSub(root->left, leftHt);
		TreeNode* rightNode = lcaDeepestLeavesSub(root->right, rightHt);
		maxDepth = max(leftHt, rightHt) + 1;
		if (leftHt == rightHt) {
			return root;
		}
		if (leftHt > rightHt) {
			return leftNode;
		}
		return rightNode;
	}
	int maxAncestorDiff(TreeNode* root) {//节点与其祖先之间的最大差值
		int res = 0;
		maxAncestorDiffSub(root, root->val, root->val, res);
		return res;
	}
	void maxAncestorDiffSub(TreeNode* root, int hi, int lo, int& res) {
		if (root == nullptr) {
			return;
		}
		res = max(max(abs(hi - root->val), abs(lo - root->val)), res);
		hi = max(hi, root->val);
		lo = min(lo, root->val);
		maxAncestorDiffSub(root->left, hi, lo, res);
		maxAncestorDiffSub(root->right, hi, lo, res);
		return;
	}
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {//删点成林
		vector<TreeNode*> res;
		unordered_set<int> delSet(to_delete.begin(), to_delete.end());
		if (delNodesSub(root, delSet, res) != nullptr) {
			res.push_back(root);
		}
		return res;
	}
	TreeNode* delNodesSub(TreeNode* root, unordered_set<int>& delSet, vector<TreeNode*>& res) {
		if (root == nullptr) {
			return nullptr;
		}
		root->left = delNodesSub(root->left, delSet, res);
		root->right = delNodesSub(root->right, delSet, res);
		if (delSet.count(root->val) > 0) {
			if (root->left != nullptr) {
				res.push_back(root->left);
			}
			if (root->right != nullptr) {
				res.push_back(root->right);
			}
			return nullptr;
		}
		return root;
	}
	bool btreeGameWinningMove(TreeNode* root, int n, int x) {//二叉树着色游戏
		int leftCon = 0, rightCon = 0;
		btreeGameWinningMoveSub(root, x, leftCon, rightCon);
		int parent = n - leftCon - rightCon - 1;
		n /= 2;
		return parent > n || leftCon > n || rightCon > n;
	}
	int btreeGameWinningMoveSub(TreeNode* root, int val, int& leftCon, int& rightCon) {
		if (root == nullptr) {
			return 0;
		}
		int leftCnt = btreeGameWinningMoveSub(root->left, val, leftCon, rightCon);
		int rightCnt = btreeGameWinningMoveSub(root->right, val, leftCon, rightCon);
		if (root->val == val) {
			leftCon = leftCnt;
			rightCon = rightCnt;
		}
		return leftCnt + rightCnt + 1;
	}
	TreeNode* recoverFromPreorder(string s) {//从先序遍历还原二叉树
		stack<pair<TreeNode*, int>> stk;
		TreeNode* tmp = new TreeNode;
		stk.push(make_pair(tmp, -1));
		size_t sLen = s.size();
		size_t cur = 0;
		while (cur < sLen) {
			int level = 0;
			int nodeVal = 0;
			while (s[cur] == '-') {
				level++;
				cur++;
			}
			while (s[cur] <= '9' && s[cur] >= '0') {
				nodeVal *= 10;
				nodeVal += s[cur] - '0';
				cur++;
			}
			tmp = new TreeNode(nodeVal);
			while (stk.top().second >= level) {
				stk.pop();
			}
			if (stk.top().first->left == nullptr) {
				stk.top().first->left = tmp;
			}
			else {
				stk.top().first->right = tmp;
			}
			stk.push(make_pair(tmp, level));
		}
		while (!stk.empty()) {
			tmp = stk.top().first;
			stk.pop();
		}
		return tmp->left;
	}
	int minCameraCover(TreeNode* root) {//监控二叉树
		int res = 0;
		if (minCameraCoverSub(root, res) == 0) {
			res++;
		}
		return res;
	}
	int minCameraCoverSub(TreeNode* root, int& res) {
		//0: 无覆盖, 1: 有摄像头, 2: 覆盖
		if (root == nullptr) {
			return 2;
		}
		int leftStat = minCameraCoverSub(root->left, res);
		int rightStat = minCameraCoverSub(root->right, res);
		if (leftStat == 2 && rightStat == 2) {
			return 0;
		}
		if (leftStat == 0 || rightStat == 0) {
			res++;
			return 1;
		}
		if (leftStat == 1 || rightStat == 1) {
			return 2;
		}
		return -1;
	}
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {//树中距离之和
		if (N == 0 || edges.empty()) {
			return { 0 };
		}
		vector<int> cnt(N, 1);
		vector<int> res(N);
		vector<vector<int>> graph(N);
		for (vector<int>& edge : edges) {
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		sumOfDistancesInTreeSub1(0, -1, graph, cnt, res);
		sumOfDistancesInTreeSub2(0, -1, graph, cnt, res);
		return res;
	}
	void sumOfDistancesInTreeSub1(int child, int parent, vector<vector<int>>& graph, vector<int>& cnt, vector<int>& res) {
		for (int i = 0; i < graph[child].size(); i++) {
			if (graph[child][i] != parent) {
				sumOfDistancesInTreeSub1(graph[child][i], child, graph, cnt, res);
				cnt[child] += cnt[graph[child][i]];
				res[child] += res[graph[child][i]] + cnt[graph[child][i]];
			}
		}
		return;
	}
	void sumOfDistancesInTreeSub2(int child, int parent, vector<vector<int>>& graph, vector<int>& cnt, vector<int>& res) {
		for (int i = 0; i < graph[child].size(); i++) {
			if (parent != graph[child][i]) {
				res[graph[child][i]] = res[child] - cnt[graph[child][i]] + res.size() - cnt[graph[child][i]];//先计算出根节点的子节点，然后再递归去算子节点的子节点
				sumOfDistancesInTreeSub2(graph[child][i], child, graph, cnt, res);
			}
		}
		return;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "1-2--3--4-5--6--7";
	string b = "(()())(())";
	vector<int> inpt1 = { 1 };
	vector<int> inpt2 = { 1, 3, 4, 2 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{ 0, 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 1, 0, 0, 1 },
		{ 1, 1, 0, 1, 1, 0 },
		{ 1, 0, 0, 1, 0, 0 },
	};
	mySolution.recoverFromPreorder(a);
	return 0;
}
#endif

//cookBook-动态规划
#if false

class Solution {
public:
	int integerBreak(int n) {//整数拆分
		vector<int> dp(n + 1, 0);
		for (int i = 2; i <= n; i++) {
			int tmp = 0;
			for (int j = 1; j < i; j++) {
				tmp = max(tmp, max(j * (i - j), j * dp[i - j]));
			}
			dp[i] = tmp;
		}
		return dp[n];
	}
	bool canPartition(vector<int>& nums) {//分割等和子集
		size_t numsLen = nums.size();
		if (numsLen < 2) {
			return false;
		}
		int target = 0, maxVal = 0;
		for (int& num : nums) {
			target += num;
			maxVal = max(maxVal, num);
		}
		if (target % 2 == 1 || maxVal > target / 2) {
			return false;
		}
		target /= 2;
		vector<vector<bool>> dp(numsLen, vector<bool>(target + 1, false));
		//dp[i][j]: 截止到下标i，是否有恰好等于j的和
		for (int i = 0; i < numsLen; i++) {
			dp[i][0] = true;
		}
		dp[0][nums[0]] = true;
		for (int i = 1; i < numsLen; i++) {
			int cur = nums[i];
			for (int j = 0; j < cur; j++) {
				dp[i][j] = dp[i - 1][j];
			}
			for (int j = cur; j <= target; j++) {
				dp[i][j] = dp[i - 1][j] | dp[i - 1][j - cur];
			}
		}
		return dp[numsLen - 1][target];
	}
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {//无重叠区间
		size_t intvCnt = intervals.size();
		if (intvCnt < 2) {
			return 0;
		}
		sort(intervals.begin(), intervals.end());
		vector<int> dp(intvCnt, 1);
		for (int i = 1; i < intvCnt; i++) {
			for (int j = 0; j < i; j++) {
				if (intervals[j][1] <= intervals[i][0]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		return intvCnt - *max_element(dp.begin(), dp.end());
	}
	int findMaxForm(vector<string>& strs, int m, int n) {//一和零
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (string& str : strs) {
			pair<int, int> cnt = findMaxFormSub(str);
			int zeros = cnt.first, ones = cnt.second;
			for (int i = m; i >= zeros; i--) {
				for (int j = n; j >= ones; j--) {
					dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
				}
			}
		}
		return dp[m][n];
	}
	pair<int, int> findMaxFormSub(string& str) {
		int zero = 0, one = 0;
		for (char& ch : str) {
			if (ch == '0') {
				zero++;
			}
			else {
				one++;
			}
		}
		return { zero, one };
	}
	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {//填充书架
		int bookCnt = books.size();
		vector<int> dp(bookCnt + 1, INT_MAX);
		dp[books.size()] = 0;
		for (int i = bookCnt - 1; i > -1; i--) {
			int maxHeight = 0;
			int leftWt = shelf_width;
			for (int j = i; j < bookCnt && leftWt >= books[j][0]; j++) {
				maxHeight = max(maxHeight, books[j][1]);
				dp[i] = min(dp[i], dp[j + 1] + maxHeight);
				leftWt -= books[j][0];
			}
		}
		return dp[0];
	}
	int lastStoneWeightII(vector<int>& stones) {//最后一块石头的重量 II
		int stoneCnt = stones.size();
		int target = 0, sum = 0;
		for (int& stone : stones) {
			sum += stone;
		}
		target = sum / 2;
		vector<int> dp(target + 1);
		for (int& stone : stones) {
			for (int j = target; j >= stone; j--) {
				dp[j] = max(dp[j], dp[j - stone] + stone);
			}
		}
		return sum - dp[target] * 2;
	}
	int numMusicPlaylists(int N, int L, int K) {//播放列表的数量
		const int divider = 1000000007;
		//令 dp[i][j] 为播放列表长度为 i 包含恰好 j 首不同歌曲的数量
		vector<vector<long long>> dp(L + 1, vector<long long>(N + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= N; j++) {
				dp[i][j] += dp[i - 1][j - 1] * (N - j + 1);
				dp[i][j] += max(0, j - K) * dp[i - 1][j];
				dp[i][j] %= divider;
			}
		}
		return (int)dp[L][N];
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "1-2--3--4-5--6--7";
	string b = "(()())(())";
	vector<int> inpt1 = { 1 };
	vector<int> inpt2 = { 1, 3, 4, 2 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{ 0, 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 1, 0, 0, 1 },
		{ 1, 1, 0, 1, 1, 0 },
		{ 1, 0, 0, 1, 0, 0 },
	};
	mySolution;
	return 0;
}
#endif

//cookBook-DFS, BFS
#if false

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {//复原 IP 地址
		int sLen = s.size();
		vector<string> res;
		if (sLen < 4) {
			return res;
		}
		vector<int> ipAddr;
		restoreIpAddressesSub(res, ipAddr, s, 0, sLen);
		return res;
	}
	void restoreIpAddressesSub(vector<string>& res, vector<int>& ipAddr, string& s, int cur, int sLen) {
		if (ipAddr.size() == 4) {
			if (cur == sLen) {
				res.push_back(restoreIpAddressesSub2(ipAddr));
			}
			return;
		}
		if (cur == sLen) {
			return;
		}
		int tmp = 0;
		if (s[cur] == '0') {
			ipAddr.push_back(0);
			restoreIpAddressesSub(res, ipAddr, s, cur + 1, sLen);
			ipAddr.pop_back();
			return;
		}
		while (cur < sLen) {
			tmp *= 10;
			tmp += s[cur] - '0';
			if (tmp < 256) {
				ipAddr.push_back(tmp);
				restoreIpAddressesSub(res, ipAddr, s, cur + 1, sLen);
				ipAddr.pop_back();
			}
			else {
				break;
			}
			cur++;
		}
		return;
	}
	string restoreIpAddressesSub2(vector<int>& ipAddr) {
		string res;
		for (int& num : ipAddr) {
			res += to_string(num) + '.';
		}
		res.pop_back();
		return res;
	}
	vector<vector<int>> combine(int n, int k) {//组合
		vector<vector<int>> res;
		vector<int> tmp;
		combineSub(res, tmp, k, 1, n);
		return res;
	}
	void combineSub(vector<vector<int>>& res, vector<int>& tmp, int k, int cur, int n) {
		if (tmp.size() + (n - cur + 1) < k) {
			return;
		}
		if (tmp.size() == k) {
			res.push_back(tmp);
			return;
		}
		if (cur == n + 1) {
			return;
		}
		tmp.push_back(cur);
		combineSub(res, tmp, k, cur + 1, n);
		tmp.pop_back();
		combineSub(res, tmp, k, cur + 1, n);
		return;
	}
	vector<int> grayCode(int n) {//格雷编码
		vector<int> res(1, 0);
		int cnt = pow(2, n);
		for (int i = 1; i < cnt; i++) {
			res.push_back(i ^ (i >> 1));
		}
		return res;
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {//全排列 II
		vector<vector<int>> res;
		vector<int> tmp;
		vector<bool> vist(nums.size(), false);
		sort(nums.begin(), nums.end());
		permuteUniqueSub(res, nums, tmp, 0, nums.size(), vist);
		return res;
	}
	void permuteUniqueSub(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, int cur, int numCnt, vector<bool>& vist) {
		if (cur == numCnt) {
			res.push_back(tmp);
			return;
		}
		for (int i = 0; i < numCnt; i++) {
			if (vist[i] || (i > 0 && nums[i] == nums[i - 1] && !vist[i - 1])) {//最后一个是剪枝
				continue;
			}
			vist[i] = true;
			tmp.push_back(nums[i]);
			permuteUniqueSub(res, nums, tmp, cur + 1, nums.size(), vist);
			vist[i] = false;
			tmp.pop_back();
		}
		return;
	}
	void solveSudoku(vector<vector<char>>& board) {//解数独
		//记录某个数字是否存在
		vector<vector<bool>> rolExist(9, vector<bool>(9, false));
		vector<vector<bool>> colExist(9, vector<bool>(9, false));
		vector<vector<vector<bool>>> blockExist(3, vector<vector<bool>>(3, vector<bool>(9, false)));
		vector<pair<int, int>> pos;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					pos.push_back(make_pair(i, j));
				}
				else {
					int tmp = board[i][j] - '0' - 1;//范围：1-9
					rolExist[i][tmp] = true;
					colExist[j][tmp] = true;
					blockExist[i / 3][j / 3][tmp] = true;
				}
			}
		}
		bool valid = false;
		solveSudokuSub(board, rolExist, colExist, blockExist, pos, 0, valid);
	}
	void solveSudokuSub(vector<vector<char>>& board, vector<vector<bool>>& rolExist, vector<vector<bool>>& colExist, vector<vector<vector<bool>>>& blockExist, vector<pair<int, int>>& pos, int cur, bool& valid) {
		if (cur == pos.size()) {
			valid = true;
			return;
		}
		int rol = pos[cur].first, col = pos[cur].second;
		for (int i = 0; i < 9 && !valid; i++) {
			if (!rolExist[rol][i] && !colExist[col][i] && !blockExist[rol / 3][col / 3][i]) {
				rolExist[rol][i] = true;
				colExist[col][i] = true;
				blockExist[rol / 3][col / 3][i] = true;
				board[rol][col] = i + 1 + '0';//直接改棋盘，不用回溯，因为已经保存在三个bool数组中
				solveSudokuSub(board, rolExist, colExist, blockExist, pos, cur + 1, valid);
				rolExist[rol][i] = false;
				colExist[col][i] = false;
				blockExist[rol / 3][col / 3][i] = false;
			}
		}
		return;
	}
	vector<vector<string>> solveNQueens(int n) {//N 皇后
		vector<string> tmp(n, string(n, '.'));
		vector<vector<string>> res;
		vector<bool> colExist(n, false), LLExist(2 * n - 1, false), LRExist(2 * n - 1, false);
		solveNQueensSub(res, tmp, colExist, LLExist, LRExist, n, 0);
		return res;
	}
	void solveNQueensSub(vector<vector<string>>& res, vector<string>& tmp, vector<bool>& colExist, vector<bool>& LLExist, vector<bool>& LRExist, int n, int pos) {
		if (pos == n) {//在第i行安置皇后，试探皇后在j列
			res.push_back(tmp);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!colExist[i] && !LRExist[i + pos] && !LLExist[n - 1 - i + pos]) {
				colExist[i] = true;
				LRExist[i + pos] = true;
				LLExist[n - 1 - i + pos] = true;
				tmp[i][pos] = 'Q';
				solveNQueensSub(res, tmp, colExist, LLExist, LRExist, n, pos + 1);
				tmp[i][pos] = '.';
				colExist[i] = false;
				LRExist[i + pos] = false;
				LLExist[n - 1 - i + pos] = false;
			}
		}
		return;
	}
	int totalNQueens(int n) {//N皇后 II
		int res = 0;
		vector<bool> colExist(n, false), LLExist(2 * n - 1, false), LRExist(2 * n - 1, false);
		totalNQueensSub(res, colExist, LLExist, LRExist, n, 0);
		return res;
	}
	void totalNQueensSub(int& res, vector<bool>& colExist, vector<bool>& LLExist, vector<bool>& LRExist, int n, int pos) {
		if (pos == n) {
			res++;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!colExist[i] && !LRExist[pos + i] && !LLExist[n - 1 - i + pos]) {
				colExist[i] = true;
				LRExist[pos + i] = true;
				LLExist[n - 1 - i + pos] = true;
				totalNQueensSub(res, colExist, LLExist, LRExist, n, pos + 1);
				colExist[i] = false;
				LRExist[pos + i] = false;
				LLExist[n - 1 - i + pos] = false;
			}
		}
	}
	//string getPermutation(int n, int k) {//排列序列
	//	//DFS暴力超时
	//	vector<bool> vist(n, false);
	//	vector<string> strSet;
	//	string tmp;
	//	getPermutationSub(strSet, tmp, vist, 0, n);
	//	return strSet[k - 1];
	//}
	//void getPermutationSub(vector<string>& strSet, string& tmp, vector<bool>& vist, int pos, int n) {
	//	if (pos == n) {
	//		strSet.push_back(tmp);
	//	}
	//	for (int i = 0; i < n; i++) {
	//		if (!vist[i]) {
	//			tmp.push_back(i + 1 + '0');
	//			vist[i] = true;
	//			getPermutationSub(strSet, tmp, vist, pos + 1, n);
	//			vist[i] = false;
	//			tmp.pop_back();
	//		}
	//	}
	//	return;
	//}
	string getPermutation(int n, int k) {//排列序列
		vector<int> frac(n);
		frac[0] = 1;
		for (int i = 1; i < n; i++) {
			frac[i] = i * frac[i - 1];
		}
		k--;
		vector<int> valid(n + 1, 1);
		string res;
		for (int i = 1; i <= n; i++) {
			int order = k / frac[n - i] + 1;
			for (int j = 1; j <= n; j++) {
				order -= valid[j];
				if (!order) {
					res += '0' + j;
					valid[j] = 0;
					break;
				}
			}
			k %= frac[n - i];
		}
		return res;
	}
	bool isAdditiveNumber(string str) {//累加数
		//依次取一个数
		vector<long double> tmp;
		return isAdditiveNumberSub(str, tmp);
	}
	bool isAdditiveNumberSub(string str, vector<long double>& tmp) {
		int cnt = tmp.size();
		if (cnt >= 3 && tmp[cnt - 1] != tmp[cnt - 2] + tmp[cnt - 3]) {
			return false;
		}
		int strLen = str.size();
		if (strLen == 0 && cnt >= 3) {
			return true;
		}
		for (int i = 0; i < strLen; i++) {
			string cur = str.substr(0, i + 1);
			if (cur[0] == '0' && cur.size() != 1) {
				break;
			}
			tmp.push_back(stold(cur));
			if (isAdditiveNumberSub(str.substr(i + 1), tmp)) {
				return true;
			}
			tmp.pop_back();
		}
		return false;
	}
	int countNumbersWithUniqueDigits(int n) {//计算各个位数不同的数字个数
		if (n == 0) {
			return 1;
		}
		int res = 10, uniq = 9, avail = 9;
		while (n > 1 && avail > 0) {
			uniq *= avail;
			res += uniq;
			avail--;
			n--;
		}
		return res;
	}
	vector<int> lexicalOrder(int n) {//字典序排数
		vector<int> res;
		for (int i = 1; i <= 9; i++) {
			lexicalOrderSub(res, i, n);
		}
		return res;
	}
	void lexicalOrderSub(vector<int>& res, int current, int n) {
		if (current > n) {
			return;
		}
		res.push_back(current);
		for (int i = 0; i <= 9; i++) {
			lexicalOrderSub(res, current * 10 + i, n);
		}
		return;
	}
	int findTargetSumWays(vector<int>& nums, int target) {//目标和--暴力DFS
		int res = 0;
		int numsLen = nums.size();
		findTargetSumWaysSub(nums, target, 0, numsLen, 0, res);
		return res;
	}
	void findTargetSumWaysSub(vector<int>& nums, int& target, int cur, int& numsLen, int acc, int& res) {
		if (cur == numsLen) {
			if (acc == target) {
				res++;
			}
			return;
		}
		findTargetSumWaysSub(nums, target, cur + 1, numsLen, acc + nums[cur], res);
		findTargetSumWaysSub(nums, target, cur + 1, numsLen, acc - nums[cur], res);
		return;
	}
	int minMutation(string start, string end, vector<string>& bank) {//最小基因变化
		unordered_map<string, bool> vist;
		string current = start;
		for (string& str : bank) {
			vist[str] = false;
		}
		vist[current] = true;
		int res = INT_MAX;
		minMutationSub(bank, vist, current, end, res, 0);
		return res == INT_MAX ? -1 : res;
	}
	void minMutationSub(vector<string>& bank, unordered_map<string, bool>& vist, string current, string& end, int& res, int tmp) {
		if (current == end) {
			res = min(res, tmp);
			return;
		}
		for (string& str : bank) {
			if (!vist[str]) {
				if (minMutationCheck(current, str) == 1) {
					vist[str] = true;
					minMutationSub(bank, vist, str, end, res, tmp + 1);
					vist[str] = false;
				}
			}
		}
		return;
	}
	int minMutationCheck(string& str1, string& str2) {
		int res = 0;
		int sLen = str1.size();
		for (int i = 0; i < sLen; i++) {
			if (str1[i] != str2[i]) {
				res++;
			}
		}
		return res;
	}
	vector<vector<int>> findSubsequences(vector<int>& nums) {//递增子序列
		vector<vector<int>> res;
		vector<int> tmp;
		findSubsequencesSub(res, tmp, nums, 0, INT_MIN);
		return res;
	}
	void findSubsequencesSub(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int cur, int last) {
		if (cur == nums.size()) {
			if (tmp.size() > 1) {
				res.push_back(tmp);
			}
			return;
		}
		if (nums[cur] >= last) {
			tmp.push_back(nums[cur]);
			findSubsequencesSub(res, tmp, nums, cur + 1, nums[cur]);
			tmp.pop_back();
		}
		if (nums[cur] != last) {
			findSubsequencesSub(res, tmp, nums, cur + 1, last);
		}
		return;
	}
	int countArrangement(int n) {//优美的排列
		vector<bool> vist(n + 1, false);
		int res = 0;
		countArrangementSub(vist, res, 1, n);
		return res;
	}
	void countArrangementSub(vector<bool>& vist, int& res, int cur, int n) {
		if (cur > n) {
			res++;
			return;
		}
		for (int i = 1; i <= n; i++) {
			if (!vist[i] && (cur % i == 0 || i % cur == 0)) {
				vist[i] = true;
				countArrangementSub(vist, res, cur + 1, n);
				vist[i] = false;
			}
		}
		return;
	}
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {//扫雷游戏
		size_t rol = board.size(), col = board[0].size();
		vector<vector<bool>> vist(rol, vector<bool>(col, false));
		queue<pair<int, int>> que;
		vector<vector<int>> dir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
		que.push(make_pair(click[0], click[1]));
		while (!que.empty()) {
			int rolCur = que.front().first, colCur = que.front().second;
			que.pop();
			if (vist[rolCur][colCur]) {
				continue;
			}
			vist[rolCur][colCur] = true;
			if (board[rolCur][colCur] == 'M') {
				board[rolCur][colCur] = 'X';
				return board;
			}
			int mineCnt = 0;
			for (int i = 0; i < 8; i++) {//确定地雷数目
				int tmpRol = rolCur + dir[i][0];
				int tmpCol = colCur + dir[i][1];
				if (tmpRol < 0 || tmpRol >= rol || tmpCol < 0 || tmpCol >= col) {
					continue;
				}
				if (board[tmpRol][tmpCol] == 'M') {
					mineCnt++;
					continue;
				}
			}
			board[rolCur][colCur] = mineCnt == 0 ? 'B' : mineCnt + '0';
			if (board[rolCur][colCur] != 'B') {
				//只有周边没有地雷的情况下，周围的方块才会被添加
				continue;
			}
			for (int i = 0; i < 8; i++) {//添加周围方块
				int tmpRol = rolCur + dir[i][0];
				int tmpCol = colCur + dir[i][1];
				if (tmpRol < 0 || tmpRol >= rol || tmpCol < 0 || tmpCol >= col) {
					continue;
				}
				que.push(make_pair(tmpRol, tmpCol));
			}
		}
		return board;
	}
	bool pyramidTransition(string bottom, vector<string>& allowed) {//金字塔转换矩阵
		int heit = bottom.size();
		//构建金字塔
		string str;
		vector<string> tower;
		for (int i = 1; i < heit; i++) {
			str.push_back('.');
			tower.push_back(str);
		}
		tower.push_back(bottom);
		int total = (heit - 1) * heit / 2;
		bool res = false;
		//构建坐标哈希表
		unordered_map<int, pair<int, int>> curMap;
		heit--;
		int cur = 0;
		while (heit > -1) {
			for (int i = 0; i < heit; i++) {
				curMap[cur] = make_pair(heit - 1, i);
				cur++;
			}
			heit--;
		}
		pyramidTransitionSub(allowed, tower, res, 0, total, curMap, allowed.size());
		return res;
	}
	void pyramidTransitionSub(vector<string>& allowed, vector<string>& tower, bool& res, int cur, int total, unordered_map<int, pair<int, int>>& curMap, int listCnt) {
		if (cur == total) {
			res = true;
			return;
		}
		int rolCur = curMap[cur].first, colCur = curMap[cur].second;
		char targetL = tower[rolCur + 1][colCur], targetR = tower[rolCur + 1][colCur + 1];
		for (int i = 0; i < listCnt && !res; i++) {//剪枝，找到答案就返回
			if (allowed[i][0] == targetL && allowed[i][1] == targetR) {
				tower[rolCur][colCur] = allowed[i][2];
				pyramidTransitionSub(allowed, tower, res, cur + 1, total, curMap, listCnt);
				tower[rolCur][colCur] = '.';
			}
		}
		return;
	}
	vector<string> letterCasePermutation(string s) {//字母大小写全排列
		int cur = s.size() - 1;
		vector<string> res;
		res.push_back("");
		string tmp;
		while (cur >= 0) {
			if (isalpha(s[cur])) {
				vector<string> resCopy = res;
				res.clear();
				for (string& str : resCopy) {
					res.push_back((char)toupper(s[cur]) + tmp + str);
					res.push_back((char)tolower(s[cur]) + tmp + str);
				}
				tmp.clear();
			}
			else {
				tmp = s[cur] + tmp;
			}
			cur--;
		}
		for (string& str : res) {
			str = tmp + str;
		}
		return res;
	}
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {//大礼包
		int res = INT_MAX;
		int initCost = 0;
		for (int i = 0; i < price.size(); i++) {
			initCost += price[i] * needs[i];
		}
		shoppingOffersSub(price, special, needs, res, initCost, 0);
		return res;
	}
	void shoppingOffersSub(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int& res, int cost, int cur) {
		if (cur == special.size()) {
			res = min(res, cost);
			return;
		}
		//选择当前的
		vector<int> needsCopy(needs);
		bool chose = true;
		int currentCost = cost;
		for (int i = 0; i < needs.size(); i++) {
			if (needs[i] < special[cur][i]) {
				chose = false;
				break;
			}
			needsCopy[i] -= special[cur][i];
			currentCost -= special[cur][i] * price[i];
		}
		currentCost += special[cur][needs.size()];
		if (chose) {
			shoppingOffersSub(price, special, needsCopy, res, currentCost, cur);
		}
		//不选择当前的
		shoppingOffersSub(price, special, needs, res, cost, cur + 1);
		return;
	}
	string crackSafe(int n, int k) {
		int kn = pow(k, n), kn_1 = pow(k, n - 1);//将所有n-1位数作为节点的节点个数
		vector<int> num(kn_1, k - 1);//表示k^(n-1)个节点的下一位可以从k-1选到0，当前索引处对应的元素值表示该节点已经把比元素值大的值都作为下一数字添加过了
		string s(kn + (n - 1), '0');//字符串初始化，（结果一定是kn+n-1位）
		for (int i = n - 1, node = 0; i < s.size(); ++i) {//i从n-1开始递增 （第一个密码是n-1个0（00...为起始点））
			s[i] = num[node]-- + '0';//更新字符串。先运算 再--，表示下一次该节点要选的下一数字
			node = node * k - (s[i - (n - 1)] - '0') * kn_1 + num[node] + 1;//更新当前节点。
			//左移操作：1.*k,2.减去左侧超出的一位代表的数字（这位数字已经到了k^(n-1)上，所以后面×一个k(n-1)）,3.加上右边进来的新数字(刚才-1用于下次的选路径，但这次的节点还没更新呢，要把这个1加回来)
		}
		return s;
	}
	vector<int> splitIntoFibonacci(string s) {//将数组拆分成斐波那契序列
		vector<int> res;
		bool done = false;
		splitIntoFibonacciSub(res, s, 0, s.size(), done);
		return res;
	}
	void splitIntoFibonacciSub(vector<int>& res, string& s, int cur, int sLen, bool& done) {
		if (cur == sLen && res.size() > 2) {
			done = true;
		}
		int tmp = 0;
		for (int i = cur; i < sLen && !done; i++) {
			tmp *= 10;
			tmp += s[i] - '0';
			if (res.size() < 2 || (long(res[res.size() - 2]) + long(res[res.size() - 1]) < INT_MAX && res[res.size() - 2] + res[res.size() - 1] == tmp)) {
				res.push_back(tmp);
				splitIntoFibonacciSub(res, s, i + 1, sLen, done);
				if (done) {
					break;
				}
				res.pop_back();
			}
			if (tmp == 0 || tmp > INT_MAX / 10) {
				break;
			}
		}
	}
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {//找到最终的安全状态
		vector<int> res;
		int nodeCnt = graph.size();
		vector<int> memo(nodeCnt, 0);//记忆节点状态0 : 未知, 1 : 有环, 2 : 无环
		for (int i = 0; i < nodeCnt; i++) {
			vector<bool> vist(nodeCnt, false);
			vist[i] = true;
			if (!eventualSafeNodesSub(graph, vist, memo, i)) {//是否有环
				res.push_back(i);
			}
		}
		return res;
	}
	bool eventualSafeNodesSub(vector<vector<int>>& graph, vector<bool>& vist, vector<int>& memo, int cur) {
		if (graph[cur].size() == 0) {
			memo[cur] = 2;
			return false;
		}
		for (int& i : graph[cur]) {
			if (vist[i]) {//访问过，有环
				memo[i] = 1;
				return true;
			}
			if (memo[i] == 2) {//待访问节点确定无环
				continue;
			}
			vist[i] = true;
			if (memo[i] == 1 || eventualSafeNodesSub(graph, vist, memo, i)) {
				memo[i] = 1;
				return true;
			}
			vist[i] = false;
		}
		memo[cur] = 2;
		return false;
	}
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {//喧闹和富有
		int peopleCnt = quiet.size();
		vector<int> res(peopleCnt, -1), inDegree(peopleCnt, 0);
		vector<vector<int>> inferiorGraph(peopleCnt);
		for (vector<int>& rich : richer) {//比较穷的邻居
			inferiorGraph[rich[0]].push_back(rich[1]);
			inDegree[rich[1]]++;//比这个邻居更富的人数
		}
		queue<int> que;
		for (int i = 0; i < peopleCnt; i++) {
			if (inDegree[i] == 0) {//最富的
				que.push(i);
			}
			res[i] = i;
		}
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			for (int& neigh : inferiorGraph[cur]) {
				if (quiet[res[cur]] < quiet[res[neigh]]) {//更新更安静的
					res[neigh] = res[cur];
				}
				inDegree[neigh]--;
				if (inDegree[neigh] == 0) {
					que.push(neigh);
				}
			}
		}
		return res;
	}
	int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {//公交路线
		if (source == target) {
			return 0;
		}
		int busCnt = routes.size();
		unordered_map<int, unordered_set<int>> graph;
		for (int i = routes.size() - 1; i > -1; i--) {//站为节点
			for (int& j : routes[i]) {
				graph[j].insert(i);
			}
		}
		queue<int> que;
		int level = 0;
		vector<bool> vist(busCnt, false);
		que.push(source);
		while (!que.empty()) {
			level++;
			for (int i = que.size(); i > 0; i--) {
				int cur = que.front();
				que.pop();
				for (const int& bus : graph[cur]) {
					if (vist[bus]) {
						continue;
					}
					vist[bus] = true;
					for (int& stop : routes[bus]) {
						if (stop == target) {
							return level;
						}
						que.push(stop);
					}
				}
			}
		}
		return -1;
	}
	int numEnclaves(vector<vector<int>>& grid) {//飞地的数量
		int rolSize = grid.size(), colSize = grid[0].size();
		if (rolSize == 1 || colSize == 1) {
			return 0;
		}
		int res = 0;
		vector<vector<bool>> vist(rolSize, vector<bool>(colSize, false));
		vector<vector<int>> dir = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		queue<pair<int, int>> que;
		for (int i = 0; i < rolSize; i++) {
			if (grid[i][0] == 1) {
				que.push(make_pair(i, 0));
			}
			if (grid[i][colSize - 1] == 1) {
				que.push(make_pair(i, colSize - 1));
			}
		}
		for (int i = 0; i < colSize; i++) {
			if (grid[0][i] == 1) {
				que.push(make_pair(0, i));
			}
			if (grid[rolSize - 1][i] == 1) {
				que.push(make_pair(rolSize - 1, i));
			}
		}
		while (!que.empty()) {
			int rolCur = que.front().first, colCur = que.front().second;
			que.pop();
			if (vist[rolCur][colCur]) {
				continue;
			}
			vist[rolCur][colCur] = true;
			grid[rolCur][colCur] = 0;
			for (int i = 0; i < 4; i++) {
				int tmpRol = rolCur + dir[i][0], tmpCol = colCur + dir[i][1];
				if (tmpRol < 0 || tmpRol == rolSize || tmpCol < 0 || tmpCol == colSize) {
					continue;
				}
				if (grid[tmpRol][tmpCol] == 1) {
					que.push(make_pair(tmpRol, tmpCol));
				}
			}
		}
		for (int i = 0; i < rolSize; i++) {
			for (int j = 0; j < colSize; j++) {
				res += grid[i][j];
			}
		}
		return res;
	}
	int closedIsland(vector<vector<int>>& grid) {//统计封闭岛屿的数目
		int rolSize = grid.size(), colSize = grid[0].size();
		if (rolSize == 1 || colSize == 1) {
			return 0;
		}
		int res = 0;
		vector<vector<bool>> vist(rolSize, vector<bool>(colSize, false));
		vector<vector<int>> dir = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		queue<pair<int, int>> que;
		//消除地图周围的陆地
		for (int i = 0; i < rolSize; i++) {
			if (grid[i][0] == 0) {
				closedIslandSub(grid, vist, i, 0, rolSize, colSize);
			}
			if (grid[i][colSize - 1] == 0) {
				closedIslandSub(grid, vist, i, colSize - 1, rolSize, colSize);
			}
		}
		for (int i = 0; i < colSize; i++) {
			if (grid[0][i] == 0) {
				closedIslandSub(grid, vist, 0, i, rolSize, colSize);
			}
			if (grid[rolSize - 1][i] == 0) {
				closedIslandSub(grid, vist, rolSize - 1, i, rolSize, colSize);
			}
		}
		//统计陆地数量
		for (int i = 0; i < rolSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (grid[i][j] == 0) {
					res++;
					closedIslandSub(grid, vist, i, j, rolSize, colSize);
				}
			}
		}
		return res;
	}
	inline void closedIslandSub(vector<vector<int>>& grid, vector<vector<bool>>& vist, int rolCur, int colCur, int rolSize, int colSize) {
		vector<vector<int>> dir = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		queue<pair<int, int>> que;
		que.push(make_pair(rolCur, colCur));
		while (!que.empty()) {
			int rolCur = que.front().first, colCur = que.front().second;
			que.pop();
			if (vist[rolCur][colCur]) {
				continue;
			}
			vist[rolCur][colCur] = true;
			grid[rolCur][colCur] = 1;
			for (int i = 0; i < 4; i++) {
				int tmpRol = rolCur + dir[i][0], tmpCol = colCur + dir[i][1];
				if (tmpRol < 0 || tmpRol == rolSize || tmpCol < 0 || tmpCol == colSize) {
					continue;
				}
				if (grid[tmpRol][tmpCol] == 0) {
					que.push(make_pair(tmpRol, tmpCol));
				}
			}
		}
		return;
	}
	int numTilePossibilities(string str) {//活字印刷
		int sLen = str.size();
		vector<bool> vist(sLen, false);
		sort(str.begin(), str.end());
		int res = 0;
		numTilePossibilitiesSub(str, vist, res, sLen);
		return res;
	}
	void numTilePossibilitiesSub(string& str, vector<bool>& vist, int& res, int& sLen) {
		for (int i = 0; i < sLen; i++) {
			if (i > 0 && str[i - 1] == str[i] && !vist[i - 1]) {//排序后剪枝
				continue;
			}
			if (!vist[i]) {
				vist[i] = true;
				res++;
				numTilePossibilitiesSub(str, vist, res, sLen);
				vist[i] = false;
			}
		}
		return;
	}
	int uniquePathsIII(vector<vector<int>>& grid) {//不同路径 III
		int rolSize = grid.size(), colSize = grid[0].size();
		vector<vector<int>> dir = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		pair<int, int> startPoint, endPoint;
		int blankCnt = 0;
		for (int i = 0; i < rolSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (grid[i][j] == 1) {
					startPoint = make_pair(i, j);
				}
				if (grid[i][j] == 2) {
					endPoint = make_pair(i, j);
				}
				if (grid[i][j] == 0) {
					blankCnt++;
				}
			}
		}
		int res = 0;
		vector<vector<bool>> vist(rolSize, vector<bool>(colSize, false));
		uniquePathsIIISub(grid, vist, dir, res, rolSize, colSize, endPoint, startPoint, blankCnt);
		return res;
	}
	void uniquePathsIIISub(vector<vector<int>>& grid, vector<vector<bool>>& vist, vector<vector<int>>& dir, int& res, int& rolSize, int& colSize, pair<int, int>& endPoint, pair<int, int> startPoint, int blankCnt) {
		if (startPoint.first == endPoint.first && startPoint.second == endPoint.second) {
			if (blankCnt == -1) {
				res++;
			}
			return;
		}
		for (int i = 0; i < 4; i++) {
			int tmpRol = startPoint.first + dir[i][0], tmpCol = startPoint.second + dir[i][1];
			if (tmpRol < 0 || tmpRol == rolSize || tmpCol < 0 || tmpCol == colSize) {
				continue;
			}
			if (vist[tmpRol][tmpCol]) {
				continue;
			}
			vist[tmpRol][tmpCol] = true;
			if (grid[tmpRol][tmpCol] == 0 || grid[tmpRol][tmpCol] == 2) {
				uniquePathsIIISub(grid, vist, dir, res, rolSize, colSize, endPoint, make_pair(tmpRol, tmpCol), blankCnt - 1);
			}
			vist[tmpRol][tmpCol] = false;
		}
		return;
	}
	int numSquarefulPerms(vector<int>& nums) {//正方形数组的数目
		vector<bool> vist(nums.size(), false);
		int res = 0;
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		numSquarefulPermsSub(nums, tmp, res, vist);
		return res;
	}
	void numSquarefulPermsSub(vector<int>& nums, vector<int>& tmp, int& res, vector<bool>& vist) {
		if (tmp.size() == nums.size()) {
			res++;
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (vist[i] || i > 0 && nums[i] == nums[i - 1] && !vist[i - 1]) {
				continue;
			}
			vist[i] = true;
			if (tmp.size() < 1 || (tmp[tmp.size() - 1] + nums[i] == (int)sqrt(tmp[tmp.size() - 1] + nums[i]) * (int)sqrt(tmp[tmp.size() - 1] + nums[i]))) {
				tmp.push_back(nums[i]);
				numSquarefulPermsSub(nums, tmp, res, vist);
				tmp.pop_back();
			}
			vist[i] = false;
		}
		return;
	}
	int shortestPathAllKeys(vector<string>& grid) {//获取所有钥匙的最短路径
		int rolSize = grid.size(), colSize = grid[0].size();
		vector<vector<int>> dir = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		int keyCnt = 0;
		queue<vector<int>> que;
		for (int i = 0; i < rolSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
					keyCnt++;
				}
				else if (grid[i][j] == '@') {
					que.push({ i, j, 0 });
				}
			}
		}
		int target = (1 << keyCnt) - 1;
		vector<vector<vector<int>>> distance(rolSize, vector<vector<int>>(colSize, vector<int>(target, -1)));
		distance[que.front()[0]][que.front()[1]][0] = 0;
		while (!que.empty()) {
			vector<int> cur = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int tmpRol = cur[0] + dir[i][0], tmpCol = cur[1] + dir[i][1];
				if (tmpRol < 0 || tmpRol == rolSize || tmpCol < 0 || tmpCol == colSize || grid[tmpRol][tmpCol] == '#') {
					//越界或者是墙
					continue;
				}
				if (grid[tmpRol][tmpCol] >= 'A' && grid[tmpRol][tmpCol] <= 'Z' && !(cur[2] & (1 << (grid[tmpRol][tmpCol] - 'A')))) {
					//有锁没钥匙
					continue;
				}
				int keyStat = cur[2];
				if (grid[tmpRol][tmpCol] >= 'a' && grid[tmpRol][tmpCol] <= 'z') {
					//当前是钥匙就新增钥匙状态
					keyStat |= 1 << (grid[tmpRol][tmpCol] - 'a');
					if (keyStat == target) {
						return distance[cur[0]][cur[1]][cur[2]] + 1;
					}
				}
				if (distance[tmpRol][tmpCol][keyStat] == -1) {
					distance[tmpRol][tmpCol][keyStat] = distance[cur[0]][cur[1]][cur[2]] + 1;
					que.push({ tmpRol, tmpCol, keyStat });
				}
			}
		}
		return -1;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "1-2--3--4-5--6--7";
	string b = "(()())(())";
	vector<int> inpt1 = { 64, 44, 5, 11 };
	vector<int> inpt2 = { 3, 2 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{1, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 2, -1}
	};
	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	};
	unordered_set<int> r1Set(inpt1.begin(), inpt1.end());
	vector<string> tmp = { "ACC","ACB","ABD","DAA","BDC","BDB","DBC","BBD","BBC","DBD","BCC","CDD","ABA","BAB","DDC","CCD","DDA","CCA","DDD" };
	mySolution.numSquarefulPerms(inpt1);
	return 0;
}
#endif

//cookBook-二分搜索
#if false

class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
	int countNodes(TreeNode* root) {//完全二叉树的节点个数
		if (root == nullptr) {
			return 0;
		}
		int depth = -1;
		TreeNode* cur = root;
		while (cur != nullptr) {
			depth++;
			cur = cur->left;
		}
		int low = 1 << depth, high = (1 << (depth + 1)) - 1;
		while (low < high) {
			int mid = low + (high - low + 1) / 2;
			if (countNodesSub(root, depth, mid)) {
				low = mid;
			}
			else {
				high = mid - 1;
			}
		}
		return low;
	}
	bool countNodesSub(TreeNode* root, int level, int k) {
		int bit = 1 << (level - 1);
		while (root != nullptr && bit > 0) {
			if (!(bit & k)) {
				root = root->left;
			}
			else {
				root = root->right;
			}
			bit >>= 1;
		}
		return root != nullptr;
	}
	bool isSubsequence(string s, string t) {//判断子序列
		size_t sLen = s.size(), tLen = t.size(), sCur = 0, tCur = 0;
		while (sCur < sLen && tCur < tLen) {
			if (s[sCur] == t[tCur]) {
				sCur++;
			}
			tCur++;
		}
		return sCur == sLen;
	}
	int hIndex(vector<int>& nums) {//H 指数 II
		int numsLen = nums.size();
		int left = 0, right = numsLen;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < numsLen - mid) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return numsLen - left;
	}
	int calculateMinimumHP(vector<vector<int>>& grid) {//地下城游戏
		int rolSize = grid.size(), colSize = grid[0].size();
		vector<vector<int>> dp(rolSize + 1, vector<int>(colSize + 1, INT_MAX));
		dp[rolSize][colSize - 1] = 1, dp[rolSize - 1][colSize] = 1;
		for (int i = rolSize - 1; i > -1; i--) {
			for (int j = colSize - 1; j > -1; j--) {
				int tmp = min(dp[i + 1][j], dp[i][j + 1]);
				dp[i][j] = max(tmp - grid[i][j], 1);
			}
		}
		return dp[0][0];
	}
	int maxEnvelopes(vector<vector<int>>& envelopes) {//俄罗斯套娃信封问题
		sort(envelopes.begin(), envelopes.end(), [](vector<int>& v1, vector<int>& v2) {
			return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
			});
		int enveCnt = envelopes.size();
		vector<int> dp(enveCnt, 1);
		for (int i = 1; i < enveCnt; i++) {
			for (int j = 0; j < i; j++) {
				if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
	int arrangeCoins(int n) {//排列硬币
		if (n <= 0) {
			return 0;
		}
		int res = 1;
		while (n >= res) {
			n -= res;
			res++;
		}
		return res - 1;
	}
	int findRadius(vector<int>& houses, vector<int>& heaters) {//供暖器
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int left = 0;
		int right = max(abs(heaters[heaters.size() - 1] - houses[0]), abs(heaters[0] - houses[houses.size() - 1]));
		while (left < right) {
			int  mid = left + (right - left) / 2;
			if (findRadiusSub(houses, heaters, mid)) {
				//能覆盖
				right = mid;
			}
			else {
				//mid确定不能覆盖，所以+1
				left = mid + 1;
			}
		}
		return left;
	}
	bool findRadiusSub(vector<int>& houses, vector<int>& heaters, int radius) {
		int houseCnt = houses.size(), heaterCnt = heaters.size(), houseCur = 0, heaterCur = 0;
		while (houseCur < houseCnt && heaterCur < heaterCnt) {
			int house = houses[houseCur], heater = heaters[heaterCur];
			if (abs(heater - house) <= radius) {
				houseCur++;
			}
			else {
				heaterCur++;
			}
		}
		return houseCur == houseCnt;
	}
	vector<int> findRightInterval(vector<vector<int>>& intervals) {//寻找右区间
		vector<pair<int, int>> curMap;
		int intervalCnt = intervals.size();
		for (int i = 0; i < intervalCnt; i++) {
			curMap.push_back(make_pair(intervals[i][0], i));
		}
		sort(curMap.begin(), curMap.end());
		vector<int> res;
		for (int i = 0; i < intervalCnt; i++) {
			res.push_back(findRightIntervalSub(curMap, intervals[i][1]));
		}
		return res;
	}
	int findRightIntervalSub(vector<pair<int, int>>& curMap, int num) {
		int left = 0, right = curMap.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (curMap[mid].first < num) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return left == curMap.size() ? -1 : curMap[left].second;
	}
	string smallestGoodBase(string n) {//最小好进制
		long long num = stol(n);
		long long res = num - 1;//默认答案
		for (int base = 59; base > 1; base--) {
			int k = pow(num, 1.0 / base);
			if (k > 1) {
				long long sum = 1, mul = 1;
				for (int i = 1; i <= base; i++) {
					mul *= k;
					sum += mul;
					if (sum == num) {
						res = k;
						break;
					}
				}
			}
		}
		return to_string(res);
	}
	bool judgeSquareSum(int c) {//平方数之和
		int left = 0, right = sqrt(c);
		while (left <= right) {
			long long tmp = (long long)left * left + right * right;
			if (tmp == c) {
				return true;
			}
			else if (tmp > c) {
				right--;
			}
			else {
				left++;
			}
		}
		return false;
	}
	int findKthNumber(int m, int n, int k) {//乘法表中第k小的数
		int lo = 1, hi = m * n;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (!findKthNumberSub(m, n, mid, k)) {
				lo = mid + 1;
			}
			else {
				;
				hi = mid;
			}
		}
		return lo;
	}
	bool findKthNumberSub(int m, int n, int mid, int k) {
		int cnt = 0;
		for (int i = 1; i <= m; i++) {
			cnt += min(n, mid / i);
		}
		return cnt >= k;
	}
	vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {//第 K 个最小的素数分数
		double lo = 0.0, hi = 1.0;
		int numsLen = nums.size();
		while (lo < hi) {
			double mid = (lo + hi) / 2;
			int cnt = 0;
			vector<int> res = { 0, 1 };
			int j = 0;
			for (int i = 0; i < numsLen; i++) {
				while (j < numsLen && nums[i] >= mid * nums[j]) {
					j++;
				}
				cnt += numsLen - j;
				if (j < numsLen && res[0] * nums[j] < res[1] * nums[i]) {
					res = { nums[i], nums[j] };
				}
			}
			if (cnt == k) {
				return res;
			}
			else if (cnt < k) {
				lo = mid;
			}
			else {
				hi = mid;
			}
		}
		return {};
	}
	int peakIndexInMountainArray(vector<int>& arr) {//山脉数组的峰顶索引
		int left = 1, right = arr.size() - 2;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
				return mid;
			}
			else if (arr[mid] < arr[mid + 1]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return 0;
	}
	class RecentCounter {//最近的请求次数
	public:
		RecentCounter() {
			return;
		}

		int ping(int t) {
			time[0] = t - 3000;
			time[1] = t;
			int cnt = 0;
			log.push_back(t);
			cnt = log.end() - lower_bound(log.begin(), log.end(), time[0]);
			return cnt;
		}
	private:
		vector<int> time = { -3000, 0 };
		vector<int> log;
	};
	int minEatingSpeed(vector<int>& nums, int h) {//爱吃香蕉的珂珂
		sort(nums.begin(), nums.end());
		int left = 1, right = nums[nums.size() - 1];
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (!minEatingSpeedSub(nums, h, mid)) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return left;
	}
	bool minEatingSpeedSub(vector<int>& nums, int h, int spd) {
		//能不能在规定时间吃完
		int cnt = 0;
		for (int& num : nums) {
			cnt += num / spd;
			if (num % spd != 0) {
				cnt++;
			}
		}
		return cnt <= h;
	}
	class TimeMap {//基于时间的键值存储
	public:
		/** Initialize your data structure here. */
		TimeMap() {

		}

		void set(string key, string value, int timestamp) {
			keyMap[key][timestamp] = value;
			return;
		}

		string get(string key, int timestamp) {
			if (keyMap.count(key) < 1) {
				return "";
			}
			auto it = keyMap[key].upper_bound(timestamp);
			if (it == keyMap[key].begin()) {
				return "";
			}
			return (--it)->second;
		}
	private:
		unordered_map<string, map<int, string>> keyMap;
	};

	class TopVotedCandidate {////在线选举
	public:
		TopVotedCandidate(vector<int>& persons, vector<int>& times) {
			int N = persons.size();
			int lead = 0;
			vector<int> count(N, 0);
			for (int i = 0; i < N; i++) {
				count[persons[i]]++;
				// Note: use >= to include case tie case, choose the latest voted candidate
				if (count[persons[i]] >= count[lead]) {
					lead = persons[i];
				}
				mp[times[i]] = lead;
			}
		}

		int q(int t) {
			auto iter = mp.upper_bound(t);
			auto last = prev(iter); // floor key
			return last->second;
		}

	private:
		map<int, int> mp; // time stamp to lead
	};
	int preimageSizeFZF(int K) {//阶乘函数后 K 个零
		long long left = 0, right = 5l * K;
		while (left <= right) {
			long long mid = left + (right - left) / 2;
			int zeroCnt = preimageSizeFZFSub(mid);
			if (zeroCnt == K) {
				return 5;
			}
			else if (zeroCnt > K) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return 0;
	}
	int preimageSizeFZFSub(long long num) {
		int res = 0;
		while (num != 0) {
			res += num / 5;
			num /= 5;
		}
		return res;
	}
	int nthMagicalNumber(int n, int a, int b) {//第 N 个神奇数字
		const int mod = 1000000007;
		int L = a * b / gcd(a, b);//最小公倍数
		long long left = min(a, b), right = 1e15;
		while (left < right) {
			long long mid = left + (right - left) / 2;
			if (mid / a + mid / b - mid / L < n) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return (int)(left % mod);
	}
	int gcd(int x, int y) {
		if (x == 0) return y;
		return gcd(y % x, x);
	}
	vector<int> maxDepthAfterSplit(string seq) {//有效括号的嵌套深度
		vector<int> res;
		int cnt = 0;
		for (char& ch : seq) {
			if (ch == '(') {
				cnt++;
				res.push_back(cnt % 2);
			}
			else {
				res.push_back(cnt % 2);
				cnt--;
			}
		}
		return res;
	}
	int nthUglyNumber(int n, int a, int b, int c) {//丑数 III
		long long ab = 1l * a * b / gcd(a, b), ac = 1l * a * c / gcd(a, c), bc = 1l * b * c / gcd(b, c);
		long long abc = 1l * a * bc / gcd(a, bc);
		long long left = min(min(a, b), c), right = n * left;
		while (left < right) {
			long long mid = left + (right - left) / 2;
			if (mid / a + mid / b + mid / c + mid / abc - mid / ab - mid / ac - mid / bc < n) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return (int)left;
	}
	int smallestDivisor(vector<int>& nums, int threshold) {//使结果不超过阈值的最小除数
		int left = 1, right = *max_element(nums.begin(), nums.end());
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (smallestDivisorSub(nums, mid) > threshold) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return left;
	}
	int smallestDivisorSub(vector<int>& nums, int mid) {
		int res = 0;
		for (int& num : nums) {
			res += num / mid;
			if (num % mid != 0) {
				res++;
			}
		}
		return res;
	}
	vector<int> threeEqualParts(vector<int>& arr) {//三等分
		vector<int> bits;
		int arrLen = arr.size();
		for (int i = 0; i < arrLen; i++) {
			if (arr[i] == 1) {
				bits.push_back(i);
			}
		}
		if (bits.size() % 3 != 0) {
			return { -1, -1 };
		}
		if (bits.empty()) {
			return { 0, 2 };
		}
		int oneCnt = bits.size() / 3;
		int backZero = arrLen - 1 - bits.back();
		if (backZero > bits[2 * oneCnt] - bits[2 * oneCnt - 1] - 1 || backZero > bits[oneCnt] - bits[oneCnt - 1] - 1) {
			return { -1, -1 };
		}
		vector<int> fst(bits.begin(), bits.begin() + oneCnt);
		vector<int> sec(bits.begin() + oneCnt, bits.begin() + 2 * oneCnt);
		vector<int> trd(bits.begin() + 2 * oneCnt, bits.end());
		for (int i = oneCnt - 1; i > 0; i--) {
			;
			if (fst[i] - fst[i - 1] != sec[i] - sec[i - 1] || fst[i] - fst[i - 1] != trd[i] - trd[i - 1]) {
				return { -1, -1 };
			}
		}
		int i = bits[oneCnt - 1] + backZero;
		int j = bits[2 * oneCnt - 1] + backZero + 1;
		return { i, j };
	}
};

//class Solution {
//public:
//	Solution(vector<int>& w) {//按权重随机选择
//		nums = w;
//		int numsLen = nums.size();
//		for (int i = 1; i < numsLen; i++) {
//			nums[i] += nums[i - 1];
//		}
//		lo = 0, hi = nums[numsLen - 1];
//		return;
//	}
//
//	int pickIndex() {
//		int r = rand() % (hi - lo) + 1;
//		return lower_bound(nums.begin(), nums.end(), r) - nums.begin();
//	}
//private:
//	vector<int> nums;
//	int lo, hi;
//};

//class Solution {//非重叠矩形中的随机点
//public:
//	Solution(vector<vector<int>>& rects) {
//		int rectCnt = rects.size();
//		rectBackup = rects;
//		int last = 0;
//		for (vector<int>& rect : rects) {
//			last += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
//			cur.push_back(last);
//		}
//		hi = cur[rectCnt - 1];
//		return;
//	}
//
//	vector<int> pick() {
//		int r = rand() % hi + 1;
//		int rect = lower_bound(cur.begin(), cur.end(), r) - cur.begin();
//		int x = rand() % (rectBackup[rect][2] - rectBackup[rect][0] + 1) + rectBackup[rect][0];
//		int y = rand() % (rectBackup[rect][3] - rectBackup[rect][1] + 1) + rectBackup[rect][1];
//		return { x, y };
//	}
//private:
//	vector<int> cur;
//	vector<vector<int>> rectBackup;
//	int hi;
//};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "1-2--3--4-5--6--7";
	string b = "(()())(())";
	vector<int> inpt1 = { 1, 2, 3 };
	vector<int> inpt2 = { 2 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{82918473, -57180867, 82918476, -57180863},
		{83793579, 18088559, 83793580, 18088560},
		{66574245, 26243152, 66574246, 26243153},
		{72983930, 11921716, 72983934, 11921720}
	};
	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	};
	unordered_set<int> r1Set(inpt1.begin(), inpt1.end());
	vector<string> tmp = { "ACC","ACB","ABD","DAA","BDC","BDB","DBC","BBD","BBC","DBD","BCC","CDD","ABA","BAB","DDC","CCD","DDA","CCA","DDD" };
	mySolution.preimageSizeFZF(3);
	return 0;
}
#endif

//cookBook-数学
#if false

class Solution {
public:
	bool isPalindrome(int x) {//回文数
		if (x == 0) {
			return true;
		}
		if (x < 0 || x % 10 == 0) {
			return false;
		}
		long long xCopy = x, tmp = 0;
		while (x != 0) {
			tmp *= 10;
			tmp += x % 10;
			x /= 10;
		}
		return tmp == xCopy;
	}
	string convertToTitle(int columnNumber) {//Excel表列名称
		string res;
		while (columnNumber != 0) {
			res.insert(res.begin(), (columnNumber - 1) % 26 + 'A');
			columnNumber = (columnNumber - 1) / 26;
		}
		return res;
	}
	int titleToNumber(string columnTitle) {//Excel表列序号
		int res = 0;
		for (char& ch : columnTitle) {
			res *= 26;
			res += ch - 'A' + 1;
		}
		return res;
	}
	int trailingZeroes(int n) {//阶乘后的零
		int res = 0;
		while (n != 0) {
			res += n / 5;
			n /= 5;
		}
		return res;
	}
	int addDigits(int num) {//各位相加
		return (num - 1) % 9 + 1;
	}
	bool isUgly(int n) {//丑数
		if (n == 0) {
			return false;
		}
		while (n % 2 == 0) {
			n /= 2;
		}
		while (n % 3 == 0) {
			n /= 3;
		}
		while (n % 5 == 0) {
			n /= 5;
		}
		return n == 1;
	}
	bool isPowerOfThree(int n) {//3的幂
		if (n == 0) {
			return false;
		}
		while (n % 3 == 0) {
			n /= 3;
		}
		return n == 1;
	}
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {//矩形面积
		int x = max(A, E), y = max(B, F);
		int z = min(C, G), w = min(D, H);
		return (int)(computeAreaSub(A, B, C, D) + computeAreaSub(E, F, G, H) - computeAreaSub(x, y, z, w));
	}
	long long computeAreaSub(int x, int y, int z, int w) {
		long long l = 0l + z - x, h = 0l + w - y;
		if (l <= 0 || h <= 0) {
			return 0;
		}
		return h * l;
	}
	int superPow(int a, vector<int>& b) {//超级次方
		if (a < 2) {
			return a;
		}
		vector<long long> baseList(10, 1);
		int moder = 1337;
		for (int i = 1; i < 10; i++) {
			baseList[i] = baseList[i - 1] * a % moder;
		}
		long long res = 1l;
		for (int& num : b) {
			long long tmp = res;
			for (int i = 1; i < 10; i++) {
				res = res * tmp % moder;
			}
			res = res * baseList[num] % moder;
		}
		return res % moder;
	}
	int maxCount(int m, int n, vector<vector<int>>& ops) {//范围求和 II
		for (vector<int>& lim : ops) {
			m = min(lim[0], m);
			n = min(lim[1], n);
		}
		return m * n;
	}
	bool checkPerfectNumber(int num) {//完美数
		if (num < 2) {
			return false;
		}
		int res = 1;
		int ub = sqrt(num) + 1;
		for (int i = 2; i < ub; i++) {
			if (num % i == 0) {
				res += i;
				res += num / i;
			}
		}
		return res == num;
	}
	int minMoves(vector<int>& nums) {//最小操作次数使数组元素相等
		int sum = 0, minVal = INT_MAX;
		for (int& num : nums) {
			minVal = min(minVal, num);
			sum += num;
		}
		return sum - minVal * nums.size();
	}
	vector<int> findErrorNums(vector<int>& nums) {//错误的集合
		unordered_set<int> numSet;
		vector<int> res(2, 0);
		int sum = (nums.size() + 1) * nums.size() / 2;
		for (int& num : nums) {
			if (numSet.count(num) > 0) {
				res[0] = num;
			}
			numSet.insert(num);
			sum -= num;
		}
		res[1] = res[0] + sum;
		return res;
	}
	int numRabbits(vector<int>& answers) {//森林中的兔子
		unordered_map<int, int> rabbits;
		int res = 0;
		for (int& num : answers) {
			rabbits[num]++;
			if (rabbits[num] == num + 1) {
				res += rabbits[num];
				rabbits[num] = 0;
			}
		}
		for (auto& it : rabbits) {
			if (it.second != 0) {
				res += it.first + 1;
			}
		}
		return res;
	}
	double largestTriangleArea(vector<vector<int>>& points) {//最大三角形面积
		double res = 0.0;
		int pointCnt = points.size();
		for (int i = 0; i < pointCnt; i++) {
			for (int j = i + 1; j < pointCnt; j++) {
				for (int k = j + 1; k < pointCnt; k++) {
					res = max(res, largestTriangleAreaSub(points[i], points[j], points[k]));
				}
			}
		}
		return res;
	}
	double largestTriangleAreaSub(vector<int>& p, vector<int>& q, vector<int>& r) {
		return 0.5 * abs(p[0] * q[1] + q[0] * r[1] + r[0] * p[1] - p[1] * q[0] - q[1] * r[0] - r[1] * p[0]);
	}
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {//矩形重叠
		int x = max(rec1[0], rec2[0]), y = max(rec1[1], rec2[1]);
		int z = min(rec1[2], rec2[2]), w = min(rec1[3], rec2[3]);
		if (z - x <= 0 || w - y <= 0) {
			return false;
		}
		return true;
	}
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {//螺旋矩阵 III
		vector<vector<int>> copy;
		copy.push_back({ r0, c0 });
		int last = 2;
		int radius = 1;
		while (last <= R * C) {
			last = spiralMatrixIIISub(R, C, r0, c0, radius, last, copy);
			radius++;
		}
		return copy;
	}
	int spiralMatrixIIISub(int rolSize, int colSize, int r0, int c0, int radius, int start, vector<vector<int>>& copy) {
		for (int i = r0 - radius + 1; i <= r0 + radius; i++) {
			if (i < 0 || i >= rolSize || c0 + radius >= colSize) {//右
				continue;
			}
			start++;
			copy.push_back({ i, c0 + radius });
		}
		for (int i = c0 + radius - 1; i >= c0 - radius; i--) {
			if (i < 0 || i >= colSize || r0 + radius >= rolSize) {//下
				continue;
			}
			start++;
			copy.push_back({ r0 + radius, i });
		}
		for (int i = r0 + radius - 1; i >= r0 - radius; i--) {
			if (i < 0 || i >= rolSize || c0 - radius < 0) {//左
				continue;
			}
			start++;
			copy.push_back({ i, c0 - radius });
		}
		for (int i = c0 - radius + 1; i <= c0 + radius; i++) {
			if (r0 - radius < 0 || i < 0 || i >= colSize) {//上
				continue;
			}
			start++;
			copy.push_back({ r0 - radius, i });
		}
		return start;
	}
	int surfaceArea(vector<vector<int>>& grid) {//三维形体的表面积
		int gridLen = grid.size();
		vector<vector<int>> dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
		int res = 0;
		for (int i = 0; i < gridLen; i++) {
			for (int j = 0; j < gridLen; j++) {
				if (grid[i][j] > 0) {
					res += grid[i][j] * 4 + 2;
					for (int k = 0; k < 4; k++) {
						int tmpRol = i + dir[k][0], tmpCol = j + dir[k][1];
						if (tmpRol < 0 || tmpRol >= gridLen || tmpCol < 0 || tmpCol >= gridLen) {
							continue;
						}
						res -= min(grid[i][j], grid[tmpRol][tmpCol]);
					}
				}
			}
		}
		return res;
	}
	string largestTimeFromDigits(vector<int>& arr) {//给定数字能组成的最大时间--回溯
		vector<bool> vist(4, false);
		int hourTmp = 0, minTmp = 0;
		int res = -1;
		for (int i = 0; i < 4; i++) {
			if (arr[i] > 2) {
				continue;
			}
			vist[i] = true;
			for (int j = 0; j < 4; j++) {
				if (vist[j]) {
					continue;
				}
				if (arr[i] * 10 + arr[j] > 23) {
					continue;
				}
				hourTmp = arr[i] * 10 + arr[j];
				vist[j] = true;
				for (int k = 0; k < 4; k++) {
					if (vist[k] || arr[k] > 5) {
						continue;
					}
					vist[k] = true;
					for (int w = 0; w < 4; w++) {
						if (vist[w]) {
							continue;
						}
						minTmp = arr[k] * 10 + arr[w];
						res = max(res, hourTmp * 100 + minTmp);
					}
					vist[k] = false;
				}
				vist[j] = false;
			}
			vist[i] = false;
		}
		if (res == -1) {
			return "";
		}
		string str1 = to_string(res / 100), str2 = to_string(res % 100);
		if (str1.size() == 1) {
			str1.insert(str1.begin(), '0');
		}
		if (str2.size() == 1) {
			str2.insert(str2.begin(), '0');
		}
		return str1 + ':' + str2;
	}
	vector<int> powerfulIntegers(int x, int y, int bound) {//强整数
		unordered_set<int> resSet;
		int tmpX = 1;
		while (tmpX < bound) {
			int tmpY = 1;
			while (tmpX + tmpY <= bound) {
				resSet.insert(tmpX + tmpY);
				if (y == 1) {
					break;
				}
				tmpY *= y;
			}
			if (x == 1) {
				break;
			}
			tmpX *= x;
		}
		vector<int> res;
		for (auto& it : resSet) {
			res.push_back(it);
		}
		return res;
	}
	int tribonacci(int n) {//第 N 个泰波那契数
		if (n == 0) {
			return 0;
		}
		else if (n < 3) {
			return 1;
		}
		int n_3 = 0, n_2 = 1, n_1 = 1;
		int res = 0;
		while (n > 2) {
			res = n_3 + n_2 + n_1;
			n_3 = n_2;
			n_2 = n_1;
			n_1 = res;
			n--;
		}
		return res;
	}
	int dayOfYear(string date) {//一年中的第几天
		int year = stoi(date.substr(0, 4)), month = stoi(date.substr(5, 2)), day = stoi(date.substr(8, 2));
		int res = 0;
		vector<int> prefix = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
		res = prefix[month - 1] + day;
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
			if (month > 2) {
				res++;
			}
		}
		return res;
	}
	int numPrimeArrangements(int n) {//质数排列
		if (n < 2) {
			return n;
		}
		vector<bool> dp(n + 1, true);
		dp[0] = false;
		dp[1] = false;
		int cnt = 0;
		for (int i = 2; i <= n; i++) {
			if (dp[i]) {
				cnt++;
				int j = i + i;
				while (j <= n) {
					dp[j] = false;
					j += i;
				}
			}
		}
		long long res = 1l;
		int moder = 1000000007;
		n -= cnt;
		while (cnt > 0) {
			res *= cnt--;
			res %= moder;
		}
		while (n > 0) {
			res *= n--;
			res %= moder;
		}
		return (int)res;
	}
	int subtractProductAndSum(int n) {//整数的各位积和之差
		int tmp1 = 1, tmp2 = 0;
		while (n != 0) {
			tmp1 *= n % 10;
			tmp2 += n % 10;
			n /= 10;
		}
		return tmp1 - tmp2;
	}
	bool divisorGame(int N) {//除数博弈
		return N % 2 == 0;
	}
	bool isBoomerang(vector<vector<int>>& points) {//有效的回旋镖
		return(points[0][0] * points[1][1] + points[2][0] * points[0][1] + points[1][0] * points[2][1] != points[1][0] * points[0][1] + points[2][0] * points[1][1] + points[0][0] * points[2][1]);
	}
	string baseNeg2(int N) {//负二进制转换
		if (N == 0) {
			return "0";
		}
		string res;
		while (N != 0) {
			int tmp = N % -2;
			N /= -2;
			if (tmp < 0) {
				tmp += 2;
				N++;
			}
			res = to_string(tmp) + res;
		}
		return res;
	}
	vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {//负二进制数相加
		reverse(arr1.begin(), arr1.end());
		reverse(arr2.begin(), arr2.end());
		int arr1Len = arr1.size(), arr2Len = arr2.size();
		if (arr1Len < arr2Len) {
			for (int i = 0; i < arr2Len - arr1Len; i++) {
				arr1.push_back(0);
			}
		}
		else if (arr2Len < arr1Len) {
			for (int i = 0; i < arr1Len - arr2Len; i++) {
				arr2.push_back(0);
			}
		}
		vector<int> res;
		int arrLen = max(arr1Len, arr2Len);
		int carry = 0;
		for (int i = 0; i < arrLen; i++) {
			int tmp = arr1[i] + arr2[i] + carry;
			if (tmp == 0 || tmp == 1) {
				res.push_back(tmp);
				carry = 0;
			}
			else if (tmp == -1) {
				res.push_back(1);
				carry = 1;
			}
			else if (tmp == 2) {
				res.push_back(0);
				carry = -1;
			}
			else if (tmp == 3) {
				res.push_back(1);
				carry = -1;
			}
		}
		if (carry == 1) {
			res.push_back(1);
		}
		else if (carry == -1) {
			res.push_back(1);
			res.push_back(1);
		}
		while (res.size() > 1 && res.back() == 0) {
			res.pop_back();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "1-2--3--4-5--6--7";
	string b = "(()())(())";
	vector<int> inpt1 = { 1, 1 };
	vector<int> inpt2 = { 0 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{1, 0},
		{0, 2}
	};
	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	};
	unordered_set<int> r1Set(inpt1.begin(), inpt1.end());
	vector<string> tmp = { "ACC","ACB","ABD","DAA","BDC","BDB","DBC","BBD","BBC","DBD","BCC","CDD","ABA","BAB","DDC","CCD","DDA","CCA","DDD" };
	mySolution.addNegabinary(inpt1, inpt2);
	return 0;
}
#endif

//cookBook-哈希表
#if false

class Solution {
public:
	int repeatedNTimes(vector<int>& nums) {//重复 N 次的元素
		int target = nums.size() / 2;
		unordered_map<int, int> numMap;
		for (int& num : nums) {
			if (++numMap[num] == target) {
				return num;
			}
		}
		return -1;
	}
	bool uniqueOccurrences(vector<int>& arr) {//独一无二的出现次数
		unordered_map<int, int> arrMap;
		for (int& num : arr) {
			++arrMap[num];
		}
		unordered_set<int> freqSet;
		for (auto& it : arrMap) {
			if (freqSet.count(it.second) > 0) {
				return false;
			}
			freqSet.insert(it.second);
		}
		return true;
	}
	bool wordPattern(string pattern, string s) {//单词规律
		unordered_map<char, string> chMap;
		unordered_map<string, char> strMap;
		int cur = 0, sLen = s.size();
		for (char& ch : pattern) {
			int curLast = cur;
			if (cur >= sLen) {
				return false;
			}
			while (cur < sLen && s[cur] != ' ') {
				cur++;
			}
			string tmp = s.substr(curLast, cur - curLast);
			cur++;
			if (chMap.count(ch) < 1 && strMap.count(tmp) < 1) {
				chMap[ch] = tmp;
				strMap[tmp] = ch;
			}
			else if (chMap.count(ch) < 1 || strMap.count(tmp) < 1 || chMap[ch] != tmp || strMap[tmp] != ch) {
				return false;
			}
		}
		return cur == sLen + 1;
	}
	int distributeCandies(vector<int>& candyType) {//分糖果
		unordered_map<int, int> candyMap;
		for (int& candy : candyType) {
			candyMap[candy]++;
		}
		return min(candyMap.size(), candyType.size() / 2);
	}
	int findLHS(vector<int>& nums) {//最长和谐子序列
		unordered_map<int, int> numMap;
		int res = 0;
		for (int& num : nums) {
			numMap[num]++;
		}
		for (auto& it : numMap) {
			if (numMap.count(it.first + 1)) {
				res = max(res, it.second + numMap[it.first + 1]);
			}
			if (numMap.count(it.first - 1)) {
				res = max(res, it.second + numMap[it.first - 1]);
			}
		}
		return res;
	}
	vector<string> uncommonFromSentences(string A, string B) {//两句话中的不常见单词
		unordered_map<string, int> strMap;
		A = A + ' ' + B + ' ';
		int sLen = A.size(), cur = 0, last = 0;
		while (cur < sLen) {
			if (A[cur] != ' ') {
				cur++;
				continue;
			}
			strMap[A.substr(last, cur - last)]++;
			last = cur + 1;
			cur++;
		}
		vector<string> res;
		for (auto& it : strMap) {
			if (it.second == 1) {
				res.push_back(it.first);
			}
		}
		return res;
	}
	vector<string> subdomainVisits(vector<string>& cpdomains) {//子域名访问计数
		unordered_map<string, int> urlCnt;
		for (string& s : cpdomains) {
			int sLen = s.size(), cur = 0, cnt = 0;
			while (s[cur] != ' ') {
				cur++;
			}
			cnt = stoi(s.substr(0, cur));
			s = '.' + s.substr(cur + 1, sLen - cur);
			sLen = s.size(), cur = 0;
			while (cur < sLen) {
				if (s[cur] != '.') {
					cur++;
					continue;
				}
				string tmp = s.substr(cur + 1, sLen - cur);
				cur++;
				urlCnt[tmp] += cnt;
			}
		}
		vector<string> res;
		for (auto& it : urlCnt) {
			res.push_back(to_string(it.second) + ' ' + it.first);
		}
		return res;
	}
	class MagicDictionary {//实现一个魔法字典
	public:
		/** Initialize your data structure here. */
		MagicDictionary() {
			return;
		}

		void buildDict(vector<string> dictionary) {
			for (string& s : dictionary) {
				int sLen = s.size();
				for (int i = 0; i < sLen; i++) {
					string sCopy = s;
					sCopy[i] = '*';
					wordDict[sCopy].insert(s);
				}
			}
			return;
		}

		bool search(string s) {
			if (wordDict.count(s) > 0) {
				return false;
			}
			int sLen = s.size();
			for (int i = 0; i < sLen; i++) {
				string sCopy = s;
				sCopy[i] = '*';
				if (wordDict.count(sCopy) > 0) {
					if (wordDict[sCopy].size() > 1 || wordDict[sCopy].count(s) < 1) {
						return true;
					}
				}
			}
			return false;
		}
	private:
		unordered_map<string, unordered_set<string>> wordDict;
	};
	vector<int> findSubstring(string s, vector<string>& words) {//串联所有单词的子串
		vector<int> res;
		int sLen = s.size();
		if (sLen == 0 || words.empty()) {
			return res;
		}
		int wordCnt = words.size(), wordLen = words[0].size();
		if (wordCnt * wordLen > sLen) {
			return res;
		}
		unordered_map<string, int> wordMap;
		for (string& word : words) {
			++wordMap[word];
		}
		for (int i = 0; i < wordLen; i++) {
			int left = i, right = i, cnt = 0;
			unordered_map<string, int> currMap;
			while (right + wordLen <= sLen) {
				string tmp = s.substr(right, wordLen);
				right += wordLen;
				if (wordMap.count(tmp) > 0) {
					++currMap[tmp];
					++cnt;
					while (currMap[tmp] > wordMap[tmp]) {
						string ts = s.substr(left, wordLen);
						left += wordLen;
						--cnt;
						--currMap[ts];
					}
					if (cnt == wordCnt) {
						res.push_back(left);
					}
				}
				else {
					left = right;
					currMap.clear();
					cnt = 0;
				}
			}
		}
		return res;
	}
	class WordFilter {//前缀和后缀搜索
	public:
		WordFilter(vector<string>& words) {
			int wordCnt = words.size();
			for (int i = 0; i < wordCnt; i++) {
				vector<string> prefix, suffix;
				string prefixTmp = "**********", suffixTmp = "**********";
				int wordLen = words[i].size();
				for (int j = 0; j < wordLen; j++) {
					prefixTmp[j] = words[i][j];
					suffixTmp[9 - j] = words[i][wordLen - 1 - j];
					prefix.push_back(prefixTmp);
					suffix.push_back(suffixTmp);
				}
				for (int j = 0; j < wordLen; j++) {
					for (int k = 0; k < wordLen; k++) {
						wordWt[prefix[j]][suffix[k]] = i;
					}
				}
			}
			return;
		}

		int f(string prefix, string suffix) {
			while (prefix.size() < 10) {
				prefix.push_back('*');
			}
			while (suffix.size() < 10) {
				suffix = '*' + suffix;
			}
			if (wordWt.count(prefix) < 1 || wordWt[prefix].count(suffix) < 1) {
				return -1;
			}
			return wordWt[prefix][suffix];
		}
	private:
		unordered_map<string, unordered_map<string, int>> wordWt;
	};
};


int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "this apple is sweet";
	string b = "this apple is sour";
	vector<int> inpt1 = { 1, 1 };
	vector<int> inpt2 = { 0 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{1, 0},
		{0, 2}
	};
	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	};
	unordered_set<int> r1Set(inpt1.begin(), inpt1.end());
	vector<string> tmp = { "apple" };
	mySolution.findSubstring("wordgoodgoodgoodbestword", tmp);
	return 0;
}
#endif

//cookBook-排序
#if false

class Solution {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
		
	};
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {//插入区间
		int intervalCnt = intervals.size();
		int cur = 0;
		vector<vector<int>> res;
		bool placed = false;
		for (vector<int>& intv : intervals) {
			if (intv[1] < newInterval[0]) {
				res.push_back(intv);
			}
			else if (intv[0] > newInterval[1]) {
				if (!placed) {
					res.push_back(newInterval);
					placed = true;
				}
				res.push_back(intv);
			}
			else {
				newInterval[0] = min(newInterval[0], intv[0]);
				newInterval[1] = max(newInterval[1], intv[1]);
			}
		}
		if (!placed) {
			res.push_back(newInterval);
		}
		return res;
	}
	void sortColors(vector<int>& nums) {//颜色分类
		sortColorsSub(nums, 0, nums.size() - 1);
		return;
	}
	void sortColorsSub(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}
		int pivot = nums[left];
		int i = left, j = right;
		while (i < j) {
			while (i < j && nums[j] >= pivot) {
				j--;
			}
			if (i < j) {
				nums[i++] = nums[j];
			}
			while (i < j && nums[i] <= pivot) {
				i++;
			}
			if (i < j) {
				nums[j--] = nums[i];
			}
		}
		nums[i] = pivot;
		sortColorsSub(nums, left, i - 1);
		sortColorsSub(nums, i + 1, right);
		return;
	}
	ListNode* myBuildList(vector<int>& nums) {
		ListNode* rootNode = new ListNode;
		ListNode* currentNode = rootNode;
		for (int& num : nums) {
			currentNode->next = new ListNode;
			currentNode = currentNode->next;
			currentNode->val = num;
		}
		return rootNode->next;
	}
	ListNode* insertionSortList(ListNode* head) {//对链表进行插入排序
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* root = new ListNode;
		root->next = head;
		ListNode* cur = head->next, * prev = head;
		while (cur != nullptr) {
			if (cur->val >= prev->val) {
				cur = cur->next;
				prev = prev->next;
			}
			else {
				ListNode* tmp = root;
				while (tmp->next->val <= cur->val) {
					tmp = tmp->next;
				}
				prev->next = cur->next;
				cur->next = tmp->next;
				tmp->next = cur;
				cur = prev->next;
			}
		}
		return root->next;
	}
	int findKthLargest(vector<int>& nums, int k) {//数组中的第K个最大元素
		findKthLargestSub(nums, 0, nums.size() - 1);
		return nums[nums.size() - k];
	}
	void findKthLargestSub(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}
		int i = left, j = right, pivot = nums[left];
		while (i < j) {
			while (i < j && nums[j] >= pivot) {
				j--;
			}
			if (i < j) {
				nums[i++] = nums[j];
			}
			while (i < j && nums[i] < pivot) {
				i++;
			}
			if (i < j) {
				nums[j--] = nums[i];
			}
		}
		nums[i] = pivot;
		findKthLargestSub(nums, left, i - 1);
		findKthLargestSub(nums, i + 1, right);
		return;
	}
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {//存在重复元素 III
		if (t < 0) {
			return false;
		}
		long long wt = 1ll + t;
		unordered_map<long long, long long> numMap;
		int numsLen = nums.size();
		for (int i = 0; i < numsLen; i++) {
			long long tmp = containsNearbyAlmostDuplicateID(nums[i], wt);
			if (numMap.count(tmp) > 0) {
				return true;
			}
			if (numMap.count(tmp - 1) > 0 && abs(nums[i] - numMap[tmp - 1]) < wt) {
				return true;
			}
			if (numMap.count(tmp + 1) > 0 && abs(nums[i] - numMap[tmp + 1]) < wt) {
				return true;
			}
			numMap[tmp] = (long long)nums[i];
			if (i >= k) {
				numMap.erase(containsNearbyAlmostDuplicateID(nums[i - k], wt));
			}
		}
		return false;
	}
	long long containsNearbyAlmostDuplicateID(long long x, long long wt) {
		return x < 0 ? (x + 1) / wt - 1 : x / wt;
	}
	int hIndex(vector<int>& citations) {//H 指数
		int citationsCnt = citations.size();
		hIndexSub(citations, 0, citationsCnt - 1);
		int left = 0, right = citationsCnt;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (citations[mid] < citationsCnt - mid) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return citationsCnt - left;
	}
	void hIndexSub(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}
		int i = left, j = right, pivot = nums[left];
		while (i < j) {
			while (i < j && nums[j] >= pivot) {
				j--;
			}
			if (i < j) {
				nums[i++] = nums[j];
			}
			while (i < j && nums[i] < pivot) {
				i++;
			}
			if (i < j) {
				nums[j--] = nums[i];
			}
		}
		nums[i] = pivot;
		hIndexSub(nums, left, i - 1);
		hIndexSub(nums, i + 1, right);
		return;
	}
	//int maximumGap(vector<int>& nums) {//最大间距
	//	int numsLen = nums.size();
	//	if (numsLen < 2) {
	//		return 0;
	//	}
	//	int res = 0;
	//	maximumGapSub(nums, 0, numsLen - 1);
	//	for (int i = 1; i < numsLen; i++) {
	//		res = max(res, nums[i] - nums[i - 1]);
	//	}
	//	return res;
	//}
	//void maximumGapSub(vector<int>& nums, int left, int right) {
	//	if (left >= right) {
	//		return;
	//	}
	//	int i = left, j = right, pivot = nums[left];
	//	while (i < j) {
	//		while(i < j && nums[j] >= pivot) {
	//			j-- ;
	//		}
	//		if (i < j) {
	//			nums[i++] = nums[j];
	//		}
	//		while (i < j && nums[i] < pivot) {
	//			i++;
	//		}
	//		if (i < j) {
	//			nums[j--] = nums[i];
	//		}
	//	}
	//	nums[i] = pivot;
	//	maximumGapSub(nums, left, i - 1);
	//	maximumGapSub(nums, i + 1, right);
	//	return;
	//}
	int maximumGap(vector<int>& nums) {//最大间距
		//采用基数排序法
		int numsLen = nums.size();
		if (numsLen < 2) {
			return 0;
		}
		int exp = 1, maxElem = *max_element(nums.begin(), nums.end());
		vector<int> buffer(numsLen);
		while (exp <= maxElem) {
			vector<int> digitCnt(10, 0);
			for (int i = 0; i < numsLen; i++) {//求同一数位上相同数值元素数量
				digitCnt[(nums[i] / exp) % 10]++;
			}
			for (int i = 1; i < 10; i++) {
				digitCnt[i] += digitCnt[i - 1];
			}
			for (int i = numsLen - 1; i > -1; i--) {
				//怎么这么神奇？
				int digit = (nums[i] / exp) % 10;
				buffer[--digitCnt[digit]] = nums[i];
			}
			copy(buffer.begin(), buffer.end(), nums.begin());
			exp *= 10;
		}
		int res = 0;
		for (int i = 1; i < numsLen; i++) {
			res = max(res, nums[i] - nums[i - 1]);
		}
		return res;
	}
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {//查找和最小的K对数字
		vector<vector<int>> res;
		int nums1Len = nums1.size(), nums2Len = nums2.size();
		int cnt = nums1Len * nums2Len;
		vector<pair<int, int>> tmp;
		for (int i = 0; i < nums1Len; i++) {
			for (int j = 0; j < nums2Len; j++) {
				tmp.push_back(make_pair(nums1[i], nums2[j]));
			}
		}
		sort(tmp.begin(), tmp.end(), [](pair<int, int> pr1, pair<int, int> pr2) {
			return pr1.first + pr1.second < pr2.first + pr2.second; });
		int cur = 0;
		k = min(k, cnt);
		while (cur < k) {
			res.push_back({ tmp[cur].first, tmp[cur].second });
			cur++;
		}
		return res;
	}
	int findContentChildren(vector<int>& nums1, vector<int>& nums2) {//分发饼干
		int res = 0, nums1Len = nums1.size(), nums2Len = nums2.size(), cur1 = 0, cur2 = 0;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		while (cur1 < nums1Len && cur2 < nums2Len) {
			if (nums1[cur1] <= nums2[cur2]) {
				cur1++;
				cur2++;
				res++;
			}
			else {
				cur2++;
			}
		}
		return res;
	}
	string findLongestWord(string s, vector<string>& dictionary) {//通过删除字母匹配到字典里最长单词
		string res;
		sort(dictionary.begin(), dictionary.end());
		for (string& str : dictionary) {
			if (findLongestWordSub(s, str) && str.size() > res.size()) {
				res = str;
			}
		}
		return res;
	}
	bool findLongestWordSub(string& str1, string& str2) {
		int str1Len = str1.size(), str2Len = str2.size();
		int cur1 = 0, cur2 = 0;
		while (cur1 < str1Len && cur2 < str2Len) {
			if (str1[cur1] == str2[cur2]) {
				cur2++;
			}
			cur1++;
		}
		return cur2 == str2Len;
	}
	string reorganizeString(string S) {//重构字符串
		if (S.length() < 2) {
			return S;
		}
		vector<int> counts(26, 0);
		int maxCount = 0;
		int length = S.length();
		for (int i = 0; i < length; i++) {
			char c = S[i];
			counts[c - 'a']++;
			maxCount = max(maxCount, counts[c - 'a']);
		}
		if (maxCount > (length + 1) / 2) {
			return "";
		}
		string reorganizeArray(length, ' ');
		int evenIndex = 0, oddIndex = 1;
		int halfLength = length / 2;
		for (int i = 0; i < 26; i++) {
			char c = 'a' + i;
			while (counts[i] > 0 && counts[i] <= halfLength && oddIndex < length) {
				reorganizeArray[oddIndex] = c;
				counts[i]--;
				oddIndex += 2;
			}
			while (counts[i] > 0) {
				reorganizeArray[evenIndex] = c;
				counts[i]--;
				evenIndex += 2;
			}
		}
		return reorganizeArray;
	}
	bool isAlienSorted(vector<string>& words, string order) {//验证外星语词典
		if (words.size() < 2) {
			return true;
		}
		int charCnt = order.size();
		unordered_map<char, int> newOrder;
		for (int i = 0; i < charCnt; i++) {
			newOrder[order[i]] = i;
		}
		string last = words[0];
		for (string& str : words) {
			if (!isAlienSortedSub(last, str, newOrder)) {
				return false;
			}
			last = str;
		}
		return true;
	}
	bool isAlienSortedSub(string& str1, string& str2, unordered_map<char, int>& newOrder) {
		int cur1 = 0, cur2 = 0, str1Len = str1.size(), str2Len = str2.size();
		while (cur1 < str1Len && cur2 < str2Len) {
			if (newOrder[str1[cur1]] < newOrder[str2[cur2]]) {
				return true;
			}
			else if (newOrder[str1[cur1]] == newOrder[str2[cur2]]) {
				cur1++;
				cur2++;
			}
			else {
				return false;
			}
		}
		return cur1 == str1Len;
	}
	int largestPerimeter(vector<int>& nums) {//三角形的最大周长
		int numsLen = nums.size();
		if (numsLen < 3) {
			return 0;
		}
		sort(nums.begin(), nums.end());
		for (int i = numsLen - 1; i > 1; i--) {
			int a = nums[i], b = nums[i - 1], c = nums[i - 2];
			if (a + b > c && a + c > b && b + c > a) {
				return a + b + c;
			}
		}
		return 0;
	}
	int largestSumAfterKNegations(vector<int>& nums, int k) {//K 次取反后最大化的数组和
		sort(nums.begin(), nums.end());
		int cur = 0, numsLen = nums.size();
		while (cur < numsLen && nums[cur] < 0 && k > 0) {
			nums[cur] = -nums[cur];
			cur++;
			k--;
		}
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int& num : nums) {
			res += num;
		}
		if (k % 2 == 1) {
			return res - 2 * nums[0];
		}
		return res;
	}
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {//距离顺序排列矩阵单元格
		vector<vector<int>> tmp;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				tmp.push_back({ i, j , r0, c0});
			}
		}
		sort(tmp.begin(), tmp.end(), [](vector<int>& vtr1, vector<int>& vtr2) {
			int r0 = vtr1[2], c0 = vtr1[3];
			return abs(vtr1[0] - r0) + abs(vtr1[1] - c0) < abs(vtr2[0] - r0) + abs(vtr2[1] - c0);
		});
		vector<vector<int>> res;
		for (vector<int>& vtr : tmp) {
			res.push_back({ vtr[0], vtr[1] });
		}
		return res;
	}
	vector<int> rearrangeBarcodes(vector<int>& nums) {//距离相等的条形码
		int numsLen = nums.size();
		if (numsLen < 3) {
			return nums;
		}
		vector<int> res(numsLen);
		vector<int> numMap(*max_element(nums.begin(), nums.end()) + 1);
		for (int& num : nums) {
			numMap[num]++;
		}
		//sort(numMap.begin(), numMap.end());
		int oddCur = 1, evenCur = 0;
		for (int i = 0; i < numMap.size(); i++) {
			//先填入奇数，后填入偶数
			while (numMap[i] > 0 && numMap[i] <= numsLen / 2 && oddCur < numsLen) {
				res[oddCur] = i;
				numMap[i]--;
				oddCur += 2;
			}
			while (numMap[i] > 0) {
				res[evenCur] = i;
				numMap[i]--;
				evenCur += 2;
			}
		}
		return res;
	}
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {//最接近原点的 K 个点
		sort(points.begin(), points.end(), [](vector<int>& vtr1, vector<int>& vtr2) {
			double d1 = 0.0 + sqrt(vtr1[0] * vtr1[0] + vtr1[1] * vtr1[1]);
			double d2 = 0.0 + sqrt(vtr2[0] * vtr2[0] + vtr2[1] * vtr2[1]);
			return d1 < d2;
		});
		vector<vector<int>> res(points.begin(), points.begin() + k);
		return res;
	}
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {//两棵二叉搜索树中的所有元素
		vector<int> res;
		stack<TreeNode*> stk1, stk2;
		while ((root1 != nullptr || !stk1.empty()) && (root2 != nullptr || !stk2.empty())) {
			if (root1 != nullptr || root2 != nullptr) {
				if (root1 != nullptr) {
					stk1.push(root1);
					root1 = root1->left;
				}
				if (root2 != nullptr) {
					stk2.push(root2);
					root2 = root2->left;
				}
			}
			else {
				TreeNode* tmp1 = stk1.top();
				TreeNode* tmp2 = stk2.top();
				if (tmp1->val < tmp2->val) {
					res.push_back(tmp1->val);
					stk1.pop();
					root1 = tmp1->right;
				}
				else {
					res.push_back(tmp2->val);
					stk2.pop();
					root2 = tmp2->right;
				}
			}
		}
		while ((root1 != nullptr || !stk1.empty())) {
			if (root1 != nullptr) {
				stk1.push(root1);
				root1 = root1->left;
			}
			else {
				TreeNode* tmp1 = stk1.top();
				res.push_back(tmp1->val);
				stk1.pop();
				root1 = tmp1->right;
			}
		}
		while ((root2 != nullptr || !stk2.empty())) {
			if (root2 != nullptr) {
				stk2.push(root2);
				root2 = root2->left;
			}
			else {
				TreeNode* tmp2 = stk2.top();
				res.push_back(tmp2->val);
				stk2.pop();
				root2 = tmp2->right;
			}
		}
		return res;
	}
	int carFleet(int target, vector<int>& position, vector<int>& speed) {//车队
		int res = 0;
		if (position.empty() || speed.empty()) {
			return res;
		}
		int carCnt = speed.size();
		map<int, double> reachTime;
		for (int i = 0; i < carCnt; i++) {
			reachTime[-position[i]] = (0.0 + target - position[i]) / speed[i];//最先到的排前面
		}
		double time = 0.0;
		for (auto& it : reachTime) {
			if (it.second <= time) {
				continue;
			}
			time = it.second;
			res++;
		}
		return res;
	}
	vector<int> pancakeSort(vector<int>& nums) {//煎饼排序
		vector<int> res;
		int numsLen = nums.size();
		for (int i = numsLen; i > 0; i--) {
			if (nums[i - 1] != i) {
				int cur = 0;
				while (nums[cur] != i) {
					cur++;
				}
				res.push_back(cur + 1);
				pancakeSortSub(nums, 0, cur);
				res.push_back(i);
				pancakeSortSub(nums, 0, i - 1);
			}
		}
		return res;
	}
	void pancakeSortSub(vector<int>& nums, int left, int right) {
		while (left < right) {
			swap(nums[left++], nums[right--]);
		}
		return;
	}
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {//规划兼职工作
		int jobCnt = startTime.size();
		vector<int> job(jobCnt + 1);
		iota(job.begin(), job.end(), 0);
		sort(job.begin() + 1, job.end(), [&](int& a, int& b) {
			return endTime[a - 1] < endTime[b - 1];
		});
		vector<int> prev(jobCnt + 1);
		for (int i = 1; i <= jobCnt; i++) {
			for (int j = i - 1; j > 0; j--) {
				if (endTime[job[j] - 1] <= startTime[job[i] - 1]) {
					prev[i] = j;
					break;
				}
			}
		}
		vector<int> dp(jobCnt + 1);
		dp[1] = profit[job[1] - 1];
		for (int i = 1; i <= jobCnt; i++) {
			dp[i] = max(dp[i - 1], profit[job[i] - 1] + dp[prev[i]]);
		}
		return dp[jobCnt];
	}
};
class Solution1 {//黑名单中的随机数
public:

	unordered_map<int, int> m;
	int wlen;

	Solution1(int n, vector<int> b) {
		wlen = n - b.size();
		unordered_set<int> w;
		for (int i = wlen; i < n; i++) w.insert(i);
		for (int x : b) w.erase(x);
		auto wi = w.begin();
		for (int x : b)
			if (x < wlen)
				m[x] = *wi++;
	}

	int pick() {
		int k = rand() % wlen;
		return m.count(k) ? m[k] : k;
	}
};


int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "hlabcdefgijkmnopqrstuvwxyz";
	string b = "this apple is sour";
	vector<int> inpt1 = { 3, 2, 4, 1 };
	vector<int> inpt2 = { 2,4,1,1,3 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{1, 0},
		{0, 2}
	};
	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	};
	unordered_set<int> r1Set(inpt1.begin(), inpt1.end());
	vector<string> tmp = { "hello","leetcode" };
	mySolution.pancakeSort(inpt1);
	return 0;
}
#endif

//cookBook-位运算
#if false

class Solution {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}

	};
	int singleNumberII(vector<int>& nums) {//只出现一次的数字 II
		int lowBit = 0, highBit = 0;
		for (int& num : nums) {
			lowBit = lowBit ^ num & ~highBit;
			highBit = highBit ^ num & ~lowBit;
		}
		return lowBit;
	}
	int rangeBitwiseAnd(int left, int right) {//数字范围按位与
		if (left == 0) {
			return 0;
		}
		int res = 0;
		while (left != right) {
			left >>= 1;
			right >>= 1;
			res++;
		}
		res = left << res;
		return res;
	}
	bool isPowerOfTwo(int n) {//2的幂
		return n > 0 && ((n & (n - 1)) == 0);
	}
	bool isPowerOfFour(int n) {//4的幂
		if (n < 1) {
			return false;
		}
		while (n > 0 && (n & 1) == 0) {
			n >>= 1;
			if ((n & 1) == 1) {
				return false;
			}
			n >>= 1;
		}
		return n == 1;
	}
	int getSum(int a, int b) {//两整数之和
		while (b != 0) {
			int tmp = a ^ b;
			b = ((unsigned int)(a & b)) << 1;
			a = tmp;
		}
		return a;
	}
	char findTheDifference(string s, string t) {//找不同
		char res = 0;
		for (char& ch : s) {
			res ^= ch;
		}
		for (char& ch : t) {
			res ^= ch;
		}
		return res;
	}
	int integerReplacement(int n) {//整数替换
		int res = 0;
		unsigned long long tmp = n;
		while (tmp > 1) {
			if ((tmp & 1) == 0) {
				tmp >>= 1;
			}
			else if ((tmp + 1) % 4 == 0 && tmp != 3) {
			tmp++;
			}
			else {
			tmp--;
			}
			res++;
		}
		return res;
	}
	vector<int> countBits(int num) {//比特位计数
		vector<int> res(num + 1, 0);
		int highBit = 0;
		for (int i = 1; i <= num; i++) {
			if ((i & (i - 1)) == 0) {
				highBit = i;
			}
			res[i] = res[i - highBit] + 1;
		}
		return res;
	}
	vector<string> findRepeatedDnaSequences(string s) {//重复的DNA序列
		unordered_map<long long, int> dnaMap;
		unordered_map<char, int> base = { {'A', 1 }, {'C', 2 }, {'G', 3 }, {'T', 4 } };
		unordered_map<int, char> baseInv = { {1, 'A' }, {2, 'C'}, {3, 'G'}, {4, 'T'} };
		long long tmp = 0;
		for (char& ch : s) {
			if (tmp > 999999999) {
				dnaMap[tmp]++;
				tmp %= 1000000000;
			}
			tmp *= 10;
			tmp += base[ch];
		}
		dnaMap[tmp]++;
		vector<string> res;
		for (auto& it : dnaMap) {
			if (it.second < 2) {
				continue;
			}
			tmp = it.first;
			string curr;
			while (tmp > 0) {
				curr = baseInv[(int)(tmp % 10)] + curr;
				tmp /= 10;
			}
			res.push_back(curr);
		}
		return res;
	}
	vector<int> singleNumber(vector<int>& nums) {//只出现一次的数字 III
		int res = 0;
		for (int& num : nums) {
			res ^= num;
		}
		int div = 1;
		while ((div & res) == 0) {
			div <<= 1;
		}
		int a = 0, b = 0;
		for (int& num : nums) {
			if (div & num) {
				a ^= num;
			}
			else {
				b ^= num;
			}
		}
		return { a, b };
	}
	int maxProduct(vector<string>& words) {//最大单词长度乘积
		int res = 0;
		int wordCnt = words.size();
		vector<int> tmp(wordCnt);
		for (int i = 0; i < wordCnt; i++) {
			string& str = words[i];
			int strVal = 0;
			for (char& ch : str) {
				strVal |= (1 << (ch - 'a'));
			}
			tmp[i] = strVal;
		}
		for (int i = 0; i < wordCnt; i++) {
			for (int j = i + 1; j < wordCnt; j++) {
				if ((tmp[i] & tmp[j]) == 0) {
					int tmpVal = words[i].size() * words[j].size();
					res = max(res, tmpVal);
				}
			}
		}
		return res;
	}
	bool validUtf8(vector<int>& data) {//UTF-8 编码验证
		int availCnt = 0;
		for (int& num : data) {
			if (availCnt == 0) {//没有待处理的字节
				if (num < 128) {//当前字节为单字节
					continue;
				}
				if (num < 192) {//多余字节
					return false;
				}
				int cur = 255;
				availCnt = 7;
				while ((cur & num) != cur) {
					cur = (cur << 1) & 255;
					availCnt--;
				}
				if (availCnt > 3) {//过长字节
					return false;
				}
			}
			else if ((num & 192) == 128) {
				availCnt--;
			}
			else {
				return false;
			}
		}
		return availCnt == 0;
	}
	vector<string> readBinaryWatch(int num) {//二进制手表
		vector<string> res;
		for (int i = 0; i < 1024; i++) {
			if (readBinaryWatchSub(i, num)) {
				int hour = (i & 960) >> 6;
				int mint = i & 63;
				if (hour < 12 && mint < 10) {
					res.push_back(to_string(hour) + ':' + '0' + to_string(mint));
				}
				else if (hour < 12 && mint < 60) {
					res.push_back(to_string(hour) + ':' + to_string(mint));
				}
			}
		}
		return res;
	}
	inline bool readBinaryWatchSub(int num, int target) {
		int cur = 1, cnt = 0;
		for (int i = 0; i < 10; i++) {
			if (num & cur) {
				cnt++;
			}
			cur <<= 1;
		}
		return target == cnt;
	}
	string toHex(int num) {//数字转换为十六进制数
		if (num == 0) {
			return "0";
		}
		unsigned int curr = (unsigned int)num;
		string res;
		while (curr != 0) {
			int tmp = curr & 15;
			if (tmp < 10) {
				res = (char)(tmp + '0') + res;
			}
			else {
				res = (char)(tmp + 'a' - 10) + res;
			}
			curr >>= 4;
		}
		return res;
	}
	int findComplement(int num) {//数字的补数
		unsigned int cur = 1;
		unsigned int curr = (unsigned int)num;
		while (cur <= curr) {
			cur <<= 1;
		}
		cur -= curr + 1;
		return cur;
	}
	int totalHammingDistance(vector<int>& nums) {//汉明距离总和
		int numsLen = nums.size(), res = 0;
		if (numsLen == 0) {
			return 0;
		}
		vector<int> cnt(32);
		for (int& num : nums) {
			int i = 0;
			while (num != 0) {
				cnt[i] += num & 1;
				num >>= 1;
				i++;
			}
		}
		for (int& val : cnt) {
			res += val * (numsLen - val);
		}
		return res;
	}
	bool hasAlternatingBits(int n) {//交替位二进制数
		bool status = (n & 1) != 0;
		n >>= 1;
		while (n != 0) {
			if (((n & 1) != 0) == status) {
				return false;
			}
			status = !status;
			n >>= 1;
		}
		return true;
	}
	int countPrimeSetBits(int L, int R) {//二进制表示中质数个计算置位
		unordered_set<int> uniq = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
		int res = 0;
		for (int i = L; i <= R; i++) {
			int cur = 1;
			int cnt = 0;
			while (cur <= i) {
				if (cur & i) {
					cnt++;
				}
				cur <<= 1;
			}
			if (uniq.count(cnt) > 0) {
				res++;
			}
		}
		return res;
	}
	int subarrayBitwiseORs(vector<int>& nums) {//子数组按位或操作
		int numsLen = nums.size();
		unordered_set<int> res;
		vector<int> dp(nums);
		for (int r = 0; r < numsLen; r++) {
			res.insert(dp[r]);
			for (int l = r - 1; l > -1; l--) {
				if ((dp[l] | dp[r]) == dp[l]) {
					break;
				}
				dp[l] |= dp[r];
				res.insert(dp[l]);
			}
		}
		return res.size();
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "AAGATCCGTCCCCCCAAGATCCGTC";
	string b = "this apple is sour";
	vector<int> inpt1 = { 250,145,145,145,145 };
	vector<int> inpt2 = { 2,4,1,1,3 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{1, 0},
		{0, 2}
	};
	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	};
	unordered_set<int> r1Set(inpt1.begin(), inpt1.end());
	vector<string> tmp = { "abcw","baz","foo","bar","xtfn","abcdef" };
	mySolution.toHex(-1);
	return 0;
}
#endif

//cookBook-并查集
#if false

class Solution {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	int longestConsecutive(vector<int>& nums) {//最长连续序列
		unordered_set<int> numSet;
		for (int& num : nums) {
			numSet.insert(num);
		}
		int current = 0, res = 0;
		for (int& num : nums) {
			if (numSet.count(num - 1) > 0) {
				continue;
			}
			current = 1;
			while (numSet.count(num + current) > 0) {
				current++;
			}
			res = max(res, current);
		}
		return res;
	}
	class UnionFind {
	public:
		//自己的父节点是自己
		UnionFind(int num) {
			for (int i = 0; i < num; i++) {
				parent.push_back(i);
				weight.push_back(1.0);
			}
			return;
		}
		int find(int x) {
			if (x != parent[x]) {
				int ori = parent[x];
				parent[x] = find(ori);
				weight[x] *= weight[ori];
			}
			return parent[x];
		}
		double isConnected(int x, int y) {
			int rootX = find(x), rootY = find(y);
			if (rootX == rootY) {
				return weight[x] / weight[y];
			}
			return -1.0;
		}
		void nyUnion(int x, int y, double val) {
			int rootX = find(x), rootY = find(y);
			if (rootX == rootY) {
				return;
			}
			parent[rootX] = rootY;
			weight[rootX] = weight[y] * val / weight[x];
			return;
		}
	private:
		vector<int> parent;
		vector<double> weight;
	};
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {//除法求值
		int eqCnt = equations.size();
		UnionFind myUnion(2 * eqCnt);
		//获取节点--id对应
		unordered_map<string, int> curMap;
		int id = 0;
		for (int i = 0; i < eqCnt; i++) {
			string& str1 = equations[i][0];
			string& str2 = equations[i][1];
			if (curMap.count(str1) < 1) {
				curMap[str1] = id++;
			}
			if (curMap.count(str2) < 1) {
				curMap[str2] = id++;
			}
			//连接有向图
			myUnion.nyUnion(curMap[str1], curMap[str2], values[i]);
		}
		//查询
		int irqCnt = queries.size();
		vector<double> res(irqCnt, -1);
		for (int i = 0; i < irqCnt; i++) {
			string& str1 = queries[i][0];
			string& str2 = queries[i][1];
			if (curMap.count(str1) > 0 && curMap.count(str2) > 0) {
				int id1 = curMap[str1], id2 = curMap[str2];
				res[i] = myUnion.isConnected(id1, id2);
			}
		}
		return res;
	}
	class findRedundantConnectionSub {
	public:
		findRedundantConnectionSub(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int findParent(int x) {
			if (x != parent[x]) {
				parent[x] = findParent(parent[x]);
			}
			return parent[x];
		}
		void addToTree(int x, int y) {
			parent[findParent(x)] = findParent(y);
			return;
		}
		bool check(int x, int y) {//是否具有相同连接分量
			int rootX = findParent(x), rootY = findParent(y);
			if (rootX == rootY) {
				return true;
			}
			return false;
		}
	private:
		vector<int> parent;
	};
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {//冗余连接
		unordered_map<int, int> curMap;
		int id = 0;
		for (vector<int>& edge : edges) {
			if (curMap.count(edge[0]) < 1) {
				curMap[edge[0]] = id++;
			}
			if (curMap.count(edge[1]) < 1) {
				curMap[edge[1]] = id++;
			}
		}
		int edgeCnt = edges.size();
		findRedundantConnectionSub mySub(2 * edgeCnt);
		for (vector<int>& edge : edges) {
			int x = curMap[edge[0]], y = curMap[edge[1]];
			if (mySub.check(x, y)) {
				return edge;
			}
			mySub.addToTree(x, y);
		}
		return{};
	}
	class findRedundantDirectedConnectionSub {
	public:
		findRedundantDirectedConnectionSub(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
		}
		int findPatent(int x) {
			if (x != parent[x]) {
				parent[x] = findPatent(parent[x]);
			}
			return parent[x];
		}
		bool checkPatent(int x, int y) {
			if (findPatent(x) == findPatent(y)) {
				return true;
			}
			return false;
		}
		void addToTree(int x, int y) {
			parent[findPatent(x)] = findPatent(y);
			return;
		}
	private:
		vector<int> parent;
	};
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {//冗余连接 II
		int edgeCnt = edges.size();
		findRedundantDirectedConnectionSub mySub(edgeCnt + 1);
		vector<int> parent(edgeCnt + 1);//最后一次刷新的父节点
		for (int i = 0; i <= edgeCnt; i++) {
			parent[i] = i;
		}
		int conflict = -1, cycle = -1;
		for (int i = 0; i < edgeCnt; i++) {
			vector<int>& edge = edges[i];
			int node1 = edge[0], node2 = edge[1];
			if (parent[node2] != node2) {//再次连接已连接节点(不一定有环)
				conflict = i;
			}
			else {
				parent[node2] = node1;
				if (mySub.checkPatent(node1, node2)) {//连接出现环
					cycle = i;
				}
				else {
					mySub.addToTree(node1, node2);
				}
			}
		}
		if (conflict < 0) {//环连接到根节点
			return edges[cycle];
		}
		else if (cycle >= 0) {//有环出现,删除环节点的父节点和环节点
			return{parent[edges[conflict][1]], edges[conflict][1] };
		}
		return edges[conflict];//无环出现
	}
	class findCircleNumSub {
	public:
		findCircleNumSub(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int findParent(int x) {
			if (x != parent[x]) {
				parent[x] = findParent(parent[x]);
			}
			return parent[x];
		}
		void addToTree(int x, int y) {//把x添加到y
			parent[findParent(x)] = findParent(y);
			return;
		}
		int getRes(void) {
			unordered_set<int> capCnt;
			for (int i = 0; i < parent.size(); i++) {
				int tmp = findParent(i);
				capCnt.insert(tmp);
			}
			return capCnt.size();
		}
	private:
		vector<int> parent;
	};
	int findCircleNum(vector<vector<int>>& isConnected) {//省份数量
		int itemCnt = isConnected.size();
		if (itemCnt < 2) {
			return itemCnt;
		}
		findCircleNumSub mySub(itemCnt);
		for (int i = 0; i < itemCnt; i++) {
			for (int j = i + 1; j < itemCnt; j++) {
				if (isConnected[i][j] == 0) {
					continue;
				}
				mySub.addToTree(i, j);
			}
		}
		return mySub.getRes();
	}
	class accountsMergeSub {
	public:
		accountsMergeSub(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
		}
		int findParent(int x) {
			if (x != parent[x]) {
				parent[x] = findParent(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			parent[findParent(y)] = findParent(x);
			return;
		}
	private:
		vector<int> parent;
	};
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {//账户合并
		unordered_map<string, int> mailID;
		unordered_map<string, string> mailName;
		//分配ID
		int id = 0;
		for (vector<string>& mail : accounts) {
			int mailCnt = mail.size();
			string& name = mail[0];
			for (int i = 1; i < mailCnt; i++) {
				if (mailID.count(mail[i]) < 1) {
					mailID[mail[i]] = id++;
					mailName[mail[i]] = name;
				}
			}
		}
		//归并
		accountsMergeSub mySub(id);
		for (vector<string>& account : accounts) {
			string& firstMail = account[1];
			int mailCnt = account.size();
			for (int i = 2; i < mailCnt; i++) {
				mySub.merge(mailID[firstMail], mailID[account[i]]);
			}
		}
		vector<vector<string>> res;
		map<int, unordered_set<string>> mailCluster;
		for (auto& it : mailID) {
			int rootMail = mySub.findParent(mailID[it.first]);
			mailCluster[rootMail].insert(it.first);
		}
		//生成答案
		for (auto& it : mailCluster) {
			string& name = mailName[*it.second.begin()];
			vector<string> tmp = { name };
			for (auto& mail : it.second) {
				tmp.push_back(mail);
			}
			sort(tmp.begin() + 1, tmp.end());
			res.push_back(tmp);
		}
		return res;
	}
	class minSwapsCouplesSub {
	public:
		minSwapsCouplesSub(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int findParent(int x) {
			if (x != parent[x]) {
				parent[x] = findParent(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			parent[findParent(y)] = findParent(x);
			return;
		}
	private:
		vector<int> parent;
	};
	int minSwapsCouples(vector<int>& row) {//情侣牵手
		int peopleCnt = row.size(), coupleCnt = peopleCnt / 2;
		//添加
		minSwapsCouplesSub uf(coupleCnt);
		for (int i = 0; i < peopleCnt; i += 2) {
			//情侣编号
			int left = row[i] / 2;
			int right = row[i + 1] / 2;
			uf.merge(left, right);
		}
		unordered_map<int, int> curMap;
		for (int i = 0; i < coupleCnt; i++) {
			int tmp = uf.findParent(i);
			curMap[tmp]++;
		}
		int res = 0;
		for (auto& it : curMap) {
			res += it.second - 1;
		}
		return res;
	}
	class swimInWaterSub {
	public:
		swimInWaterSub(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int findParent(int x) {
			if (x != parent[x]) {
				parent[x] = findParent(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			parent[findParent(y)] = findParent(x);
			return;
		}
	private:
		vector<int> parent;
	};
	int swimInWater(vector<vector<int>>& grid) {//水位上升的泳池中游泳
		int gridDim = grid.size();
		swimInWaterSub uf(gridDim * gridDim);
		vector<pair<int, int>> curMap(gridDim * gridDim);
		for (int i = 0; i < gridDim; i++) {
			for (int j = 0; j < gridDim; j++) {
				curMap[grid[i][j]] = make_pair(i, j);
			}
		}
		vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
		for (int i = 0; i < gridDim * gridDim; i++) {
			int rolCur = curMap[i].first, colCur = curMap[i].second;
			for (int j = 0; j < 4; j++) {
				int tmpRol = rolCur + dir[j][0], tmpCol = colCur + dir[j][1];
				if (tmpRol < 0 || tmpRol == gridDim || tmpCol < 0 || tmpCol == gridDim) {
					continue;
				}
				if (grid[tmpRol][tmpCol] <= i) {
					uf.merge(rolCur * gridDim + colCur, tmpRol * gridDim + tmpCol);
				}
			}
			if (uf.findParent(0) == uf.findParent(gridDim * gridDim - 1)) {
				return i;
			}
		}
		return -1;
	}
	class hitBricksSub {
	public:
		hitBricksSub(int n) {
			parent.resize(n);
			nodeCnt.resize(n, 1);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int findParent(int x) {
			if (x != parent[x]) {
				parent[x] = findParent(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			int rootX = findParent(x), rootY = findParent(y);
			if (rootX == rootY) {
				return;
			}
			parent[rootY] = rootX;
			nodeCnt[rootX] += nodeCnt[rootY];
			return;
		}
		int retNodeCnt(int x) {
			return nodeCnt[findParent(x)];
		}
	private:
		vector<int> parent, nodeCnt;
	};
	vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {//打砖块
		int rolSize = grid.size(), colSize = grid[0].size();
		int hitCnt = hits.size();
		hitBricksSub uf(rolSize * colSize + 1);
		//标记要敲掉的转
		for (vector<int>& hit : hits) {
			if (grid[hit[0]][hit[1]] == 1) {
				grid[hit[0]][hit[1]] = 2;
			}
		}
		//添加各个簇到并查集
		for (int i = 0; i < rolSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (grid[i][j] != 1) {
					continue;
				}
				if (i == 0) {//墙上的
					uf.merge(rolSize * colSize, i * colSize + j);
				}
				if (i > 0 && grid[i - 1][j] == 1) {//上面有转
					uf.merge((i - 1) * colSize + j, i * colSize + j);
				}
				if (j > 0 && grid[i][j - 1] == 1) {//左面有砖
					uf.merge(i * colSize + j - 1, i * colSize + j);
				}
			}
		}
		vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
		vector<int> res(hitCnt);
		for (int i = hitCnt - 1; i > -1; i--) {
			int rolCur = hits[i][0], colCur = hits[i][1];
			if (grid[rolCur][colCur] == 0) {//剩下的全是2
				res[i] = 0;
				continue;
			}
			int prev = uf.retNodeCnt(rolSize * colSize);
			if (rolCur == 0) {
				uf.merge(rolSize * colSize, colCur);//以防倒三角类型
			}
			for (int j = 0; j < 4; j++) {
				int tmpRol = rolCur + dir[j][0], tmpCol = colCur + dir[j][1];
				if (tmpRol < 0 || tmpRol >= rolSize || tmpCol < 0 || tmpCol >= colSize) {
					continue;
				}
				if (grid[tmpRol][tmpCol] == 1) {
					uf.merge(rolCur * colSize + colCur, tmpRol * colSize + tmpCol);
				}
			}
			int curr = uf.retNodeCnt(rolSize * colSize);
			res[i] = max(0, curr - prev - 1);
			grid[rolCur][colCur] = 1;
		}
		return res;
	}
	class numSimilarGroupsSub {
	public:
		numSimilarGroupsSub(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int findParent(int x) {
			if (x != parent[x]) {
				parent[x] = findParent(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			int rootX = findParent(x), rootY = findParent(y);
			parent[rootY] = rootX;
			return;
		}
		int clusterCnt() {
			unordered_set<int> clusterSet;
			int parentCnt = parent.size();
			for (int i = 0; i < parentCnt; i++) {
				clusterSet.emplace(findParent(i));
			}
			return clusterSet.size();
		}
	private:
		vector<int> parent;
	};
	int numSimilarGroups(vector<string>& strs) {//相似字符串组
		unordered_map<string, int> strMap;
		int strCnt = strs.size();
		int id = 0;
		for (string& str : strs) {
			if (strMap.count(str) < 1) {
				strMap[str] = id++;
			}
		}
		numSimilarGroupsSub uf(id);
		for (int i = 0; i < strCnt; i++) {
			for (int j = i + 1; j < strCnt; j++) {
				if (numSimilarGroupsSililar(strs[i], strs[j])) {
					uf.merge(strMap[strs[i]], strMap[strs[j]]);
				}
			}
		}
		int res = uf.clusterCnt();
		return res;
	}
	bool numSimilarGroupsSililar(string& str1, string& str2) {
		int strLen = str1.size();
		string tmp;
		for (int i = 0; i < strLen; i++) {
			if (str1[i] != str2[i]) {
				tmp.push_back(abs(str1[i] - str2[i]));
			}
		}
		if (tmp.size() != 2) {
			return false;
		}
		for (int i = 1; i < tmp.size(); i++) {
			if (tmp[i] != tmp[0]) {
				return false;
			}
		}
		return true;
	}
	class minMalwareSpreadISub {
	public:
		minMalwareSpreadISub(int n) {
			parent.resize(n);
			clusterCnt.resize(n, 1);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int findParent(int x) {
			if (x != parent[x]) {
				parent[x] = findParent(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			int rootX = findParent(x), rootY = findParent(y);
			if (rootX == rootY) {
				return;
			}
			parent[rootY] = rootX;
			clusterCnt[rootX] += clusterCnt[rootY];
			return;
		}
		int retClusterNode(int x) {
			return clusterCnt[findParent(x)];
		}
	private:
		vector<int> parent;
		vector<int> clusterCnt;
	};
	int minMalwareSpreadI(vector<vector<int>>& grid, vector<int>& initial) {//尽量减少恶意软件的传播
		int gridDim = grid.size();
		minMalwareSpreadISub uf(gridDim);
		for(int i = 0; i < gridDim; i++) {
			for (int j = i + 1; j < gridDim; j++) {
				if (grid[i][j] == 0) {
					continue;
				}
				uf.merge(i, j);
			}
		}
		int initialCnt = initial.size();
		vector<int> infected(gridDim);
		for (int& num : initial) {
			//保存这一个簇由几个节点感染；
			infected[uf.findParent(num)]++;
		}
		sort(initial.begin(), initial.end());
		int maxCnt = INT_MIN, res = initial[0];
		for (int& num : initial) {
			int rootNum = uf.findParent(num);
			if (infected[rootNum] != 1) {
				continue;
			}
			int tmp = uf.retClusterNode(num);
			if (tmp > maxCnt) {
				maxCnt = tmp;
				res = num;
			}
		}
		return res;
	}
	class minMalwareSpreadSub {
	public:
		minMalwareSpreadSub(int n) {
			parent.resize(n);
			clusterCnt.resize(n, 1);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int findParent(int x) {
			if (x != parent[x]) {
				parent[x] = findParent(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			int rootX = findParent(x), rootY = findParent(y);
			if (rootX == rootY) {
				return;
			}
			parent[rootY] = rootX;
			clusterCnt[rootX] += clusterCnt[rootY];
			return;
		}
		int retClusterNode(int x) {
			return clusterCnt[findParent(x)];
		}
	private:
		vector<int> parent;
		vector<int> clusterCnt;
	};
	int minMalwareSpread(vector<vector<int>>& grid, vector<int>& initial) {//尽量减少恶意软件的传播 II
		int gridDim = grid.size();
		sort(initial.begin(), initial.end());
		int maxCnt = INT_MAX, res = initial[0];
		for (int& node : initial) {
			minMalwareSpreadSub uf(gridDim);
			for (int i = 0; i < gridDim; i++) {
				if (i == node) {
					continue;
				}
				for (int j = i + 1; j < gridDim; j++) {
					if (j == node) {
						continue;
					}
					if (grid[i][j] == 1) {
						uf.merge(i, j);
					}
				}
			}
			unordered_set<int> rootSet;
			for (int& infectNode : initial) {
				rootSet.insert(uf.findParent(infectNode));
			}
			int nodeCnt = 0;
			for (auto& rootNode : rootSet) {
				nodeCnt += uf.retClusterNode(rootNode);
			}
			if (nodeCnt < maxCnt) {
				maxCnt = nodeCnt;
				res = node;
			}
		}
		return res;
	}
	class removeStonesSub {
	public:
		removeStonesSub(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int find(int x) {
			if (x != parent[x]) {
				parent[x] = find(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			int rootX = find(x), rootY = find(y);
			if (rootX == rootY) {
				return;
			}
			parent[rootY] = rootX;
			return;
		}
		int connectNodeCnt() {
			int res = 0, n = parent.size();
			for (int i = 0; i < n; i++) {
				if (i == parent[i]) {
					res++;
				}
			}
			return res;
		}
	private:
		vector<int> parent;
	};
	int removeStones(vector<vector<int>>& stones) {//移除最多的同行或同列石头
		int stoneCnt = stones.size();
		if (stoneCnt < 2) {
			return 0;
		}
		removeStonesSub uf(stoneCnt);
		for (int i = 0; i < stoneCnt; i++) {
			for (int j = i + 1; j < stoneCnt; j++) {
				if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
					uf.merge(i, j);
				}
			}
		}
		return stoneCnt - uf.connectNodeCnt();
	}
	class largestComponentSizeSub {
	public:
		largestComponentSizeSub(int n) {
			parent.resize(n);
			nodeCnt.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			for (int i = 100001; i < n; i++) {
				nodeCnt[i] = 1;
			}
			return;
		}
		int find(int x) {
			if (x != parent[x]) {
				parent[x] = find(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			int rootX = find(x), rootY = find(y);
			if (rootX == rootY) {
				return;
			}
			parent[rootY] = rootX;
			nodeCnt[rootX] += nodeCnt[rootY];
			return;
		}
		int maxConnected(int start) {
			int res = 0, n = parent.size();
			for (int i = start; i < n; i++) {
				int tmp = find(i);
				res = max(res, nodeCnt[tmp]);
			}
			return res;
		}
	private:
		vector<int> parent;
		vector<int> nodeCnt;
	};
	int largestComponentSize(vector<int>& nums) {//按公因数计算最大组件大小
		//sort(nums.begin(), nums.end());
		int numsLen = nums.size();
		largestComponentSizeSub uf(numsLen + 100001);
		for (int i = 0; i < numsLen; i++) {
			for (int j = 1; j * j <= nums[i]; j++) {
				if (nums[i] % j == 0) {
					if (j != 1) {
						uf.merge(j, i + 100001);
					}
					uf.merge(nums[i] / j, i + 100001);
				}
			}
		}
		int res = 0;
		return uf.maxConnected(100001);
	}
	class regionsBySlashesSub {
	public:
		regionsBySlashesSub(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int find(int x) {
			if (x != parent[x]) {
				parent[x] = find(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			int rootX = find(x), rootY = find(y);
			if (rootX == rootY) {
				return;
			}
			parent[rootY] = rootX;
			return;
		}
		int countCluster() {
			int n = parent.size();
			int res = 0;
			for (int i = 0; i < n; i++) {
				if (parent[i] == i){
					res++;
				}
			}
			return res;
		}
	private:
		vector<int> parent;
	};
	int regionsBySlashes(vector<string>& grid) {//由斜杠划分区域
		int gridDim = grid.size(), totalGrid = gridDim * gridDim;
		//每一个方块最多有两种分割方式，按照上右下左编号为1234
		regionsBySlashesSub uf(totalGrid * 4);
		vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
		for (int i = 0; i < gridDim; i++) {
			for (int j = 0; j < gridDim; j++) {
				int base = i * gridDim + j;
				if (grid[i][j] == ' ') {
					for (int k = 1; k < 4; k++) {
						uf.merge(base, k * totalGrid + base);
					}
				}
				else if (grid[i][j] == '/') {
					uf.merge(base, 3 * totalGrid + base);
					uf.merge(2 * totalGrid + base, totalGrid + base);
				}
				else {
					uf.merge(base, totalGrid + base);
					uf.merge(2 * totalGrid + base, 3 * totalGrid + base);
				}
				if (i > 0) {
					uf.merge((i - 1) * gridDim + j + totalGrid * 2, base);
				}
				if (j > 0) {
					uf.merge(i * gridDim + j - 1 + totalGrid, totalGrid * 3 + base);
				}
			}
		}
		return uf.countCluster();
	}
	class equationsPossibleSub {
	public:
		equationsPossibleSub(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int find(int x) {
			if (x != parent[x]) {
				parent[x] = find(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			int rootX = find(x), rootY = find(y);
			if (rootX == rootY) {
				return;
			}
			parent[rootY] = rootX;
			return;
		}
		int countCluster() {
			int n = parent.size();
			int res = 0;
			for (int i = 0; i < n; i++) {
				if (parent[i] == i) {
					res++;
				}
			}
			return res;
		}
	private:
		vector<int> parent;
	};
	bool equationsPossible(vector<string>& equations) {//等式方程的可满足性
		equationsPossibleSub uf(26);
		int id = 0;
		unordered_map<char, int> curMap;
		for (string& eq : equations) {
			if (curMap.count(eq[0]) < 1) {
				curMap[eq[0]] = id++;
			}
			if (curMap.count(eq[3]) < 1) {
				curMap[eq[3]] = id++;
			}
		}
		for (string& eq : equations) {
			if (eq[1] == '=') {
				uf.merge(curMap[eq[0]], curMap[eq[3]]);
			}
		}
		for (string& eq : equations) {
			if (eq[1] == '!') {
				int rootX = uf.find(curMap[eq[0]]), rootY = uf.find(curMap[eq[3]]);
				if (rootX == rootY) {
					return false;
				}
			}
		}
		return true;
	}
	class smallestStringWithSwapsSub {
	public:
		smallestStringWithSwapsSub(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			return;
		}
		int find(int x) {
			if (x != parent[x]) {
				parent[x] = find(parent[x]);
			}
			return parent[x];
		}
		void merge(int x, int y) {
			int rootX = find(x), rootY = find(y);
			if (rootX == rootY) {
				return;
			}
			parent[rootY] = rootX;
			return;
		}
		int countCluster() {
			int n = parent.size();
			int res = 0;
			for (int i = 0; i < n; i++) {
				if (parent[i] == i) {
					res++;
				}
			}
			return res;
		}
	private:
		vector<int> parent;
	};
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {//交换字符串中的元素
		int sLen = s.size();
		smallestStringWithSwapsSub uf(sLen);
		for (vector<int>& pair : pairs) {
			uf.merge(pair[0], pair[1]);
		}
		unordered_map<int, vector<char>> charMap;
		for (int i = 0; i < sLen; i++) {
			charMap[uf.find(i)].push_back(s[i]);
		}
		for (auto& it : charMap) {
			sort(it.second.begin(), it.second.end());
		}
		string res(sLen, ' ');
		for (int i = sLen - 1; i > -1; i--) {
			int cur = uf.find(i);
			res[i] = *(charMap[cur].end() - 1);
			charMap[cur].pop_back();
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "dcab";
	string b = "this apple is sour";
	vector<int> inpt1 = { 4, 6, 15, 35 };
	vector<int> inpt2 = { 2,4,1,1,3 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{1, 1, 0},
		{1, 1, 0},
		{0, 0, 1}
	};
	vector<vector<int>> board = {
		{1,0,0,0,1,0,0,0,0,0,1},
		{0,1,0,1,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,1,0,0,0},
		{0,1,0,1,0,1,0,0,0,0,0},
		{1,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,1,0,1,0,0,1,1,0},
		{0,0,0,0,0,0,1,1,0,0,0},
		{0,0,1,0,0,0,1,1,0,0,0},
		{0,0,0,0,0,1,0,0,1,0,0},
		{0,0,0,0,0,1,0,0,0,1,0},
		{1,0,0,0,0,0,0,0,0,0,1}
	};
	vector<vector<int>> equations = { {0, 3}, {1, 2} };
	vector<double> val = { 2.0, 3.0 };
	vector<string> qur = { " /","/ " };
	mySolution.smallestStringWithSwaps(a, equations);
	return 0;
}
#endif

//cookBook-线段树
#if false

class Solution {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class getSkylineSub {
	public:
		getSkylineSub(int n) {
			d.resize(n * 4 + 5, 0);
			lazy.resize(n * 4 + 5, 0);
			return;
		}
		void update(int nodeLeft, int nodeRight, int left, int right, int val, int id) {
			//更新区间最大值，节点左右范围，查询区间范围，更新值，节点id（1开始）
			if (nodeLeft >= left && nodeRight <= right) {//查询区间完全覆盖节点
				lazy[id] = max(val, lazy[id]);
				d[id] = max(lazy[id], d[id]);
				return;
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int sonLeft = id * 2, sonRight = id * 2 + 1;
			if (lazy[id] && nodeLeft != nodeRight) {//后半句判断是不是叶子节点，由于只考虑最大值，只有更新
				lazy[sonLeft] = max(lazy[sonLeft], lazy[id]);
				lazy[sonRight] = max(lazy[sonRight], lazy[id]);
				d[sonLeft] = max(d[sonLeft], lazy[sonLeft]);
				d[sonRight] = max(d[sonRight], lazy[sonRight]);
				lazy[id] = 0;
			}
			if (left <= nodeMid) {//跨区间向左更新
				update(nodeLeft, nodeMid, left, right, val, sonLeft);
			}
			if (right > nodeMid) {//跨期间向右更新
				update(nodeMid + 1, nodeRight, left, right, val, sonRight);
			}
			d[id] = max(d[sonLeft], d[sonRight]);
			return;
		}
		int qury(int nodeLeft, int nodeRight, int left, int right, int id) {
			if (nodeLeft >= left && nodeRight <= right) {
				return d[id];
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int sonLeft = id * 2, sonRight = id * 2 + 1;
			if (lazy[id] && nodeLeft != nodeRight) {
				lazy[sonLeft] = max(lazy[sonLeft], lazy[id]);
				lazy[sonRight] = max(lazy[sonRight], lazy[id]);
				d[sonLeft] = max(d[sonLeft], lazy[sonLeft]);
				d[sonRight] = max(d[sonRight], lazy[sonRight]);
				lazy[id] = 0;
			}
			int res = 0;
			if (left <= nodeMid) {
				res = max(res, qury(nodeLeft, nodeMid, left, right, sonLeft));
			}
			if (right > nodeMid) {
				res = max(res, qury(nodeMid + 1, nodeRight, left, right, sonRight));
			}
			return res;
		}
	private:
		vector<int> d, lazy;
	};
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {//天际线问题
		unordered_map<int, int> curMap, reverseCurMap;
		set<int> curSet;
		for (auto& it : buildings) {
			curSet.insert(it[0]);
			curSet.insert(it[1]);
			curSet.insert(it[1] - 1);
		}
		int id = 1;
		for (auto& it : curSet) {
			curMap[it] = id;
			reverseCurMap[id] = it;
			id++;
		}
		getSkylineSub segTree(id--);
		for (auto& it : buildings) {
			segTree.update(1, id, curMap[it[0]], curMap[it[1] - 1], it[2], 1);
		}
		vector<vector<int>> res;
		int last = -1;
		for (int i = 1; i <= id; i++) {
			int tmp = segTree.qury(1, id, i, i, 1);
			if (tmp != last) {
				res.push_back({ reverseCurMap[i], tmp });
			}
			last = tmp;
		}
		return res;
	}
	class NumArrayI {//区域和检索 - 数组不可变
	public:
		NumArrayI(vector<int>& nums) {
			int numsLen = nums.size();
			data = nums;
			data.insert(data.begin(), 0);
			for (int i = 1; i <= numsLen; i++) {
				data[i] += data[i - 1];
			}
			return;
		}

		int sumRange(int left, int right) {
			return data[right + 1] - data[left];
		}
	private:
		vector<int> data;
	};
	class NumArray {//区域和检索 - 数组可修改
	public:
		NumArray(vector<int>& nums) {
			numsLen = nums.size();
			data.resize(numsLen * 4, 0);
			lazy.resize(numsLen * 4, 0);
			for (int i = 0; i < numsLen; i++) {
				update(i + 1, nums[i]);
			}
			return;
		}
		void update(int index, int val) {
			update(1, numsLen, index, index, val, 1);
			return;
		}
		int sumRange(int left, int right) {
			return qury(1, numsLen, left + 1, right + 1, 1);
		}
	private:
		vector<int> data, lazy;
		int numsLen;
		void update(int nodeLeft, int nodeRight, int segLeft, int segRight, int val, int nodeID) {
			if (segLeft <= nodeLeft && nodeRight <= segRight) {//更改整个区间内容
				data[nodeID] = (nodeRight - nodeLeft + 1) * val;//和
				lazy[nodeID] = val;//单点
				return;
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int leftSon = nodeID * 2, rightSon = nodeID * 2 + 1;
			if (lazy[nodeID] != 0) {
				data[leftSon] = lazy[nodeID] * (nodeMid - nodeLeft + 1);
				data[rightSon] = lazy[nodeID] * (nodeRight - nodeMid);
				lazy[leftSon] = lazy[rightSon] = lazy[nodeID];
				lazy[nodeID] == 0;
			}
			if (segLeft <= nodeMid) {
				update(nodeLeft, nodeMid, segLeft, segRight, val, leftSon);
			}
			if (segRight > nodeMid) {
				update(nodeMid + 1, nodeRight, segLeft, segRight, val, rightSon);
			}
			data[nodeID] = data[leftSon] + data[rightSon];
			return;
		}
		int qury(int nodeLeft, int nodeRight, int segLeft, int segRight, int nodeID) {
			if (segLeft <= nodeLeft && nodeRight <= segRight) {
				return data[nodeID];
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int leftSon = nodeID * 2, rightSon = nodeID * 2 + 1;
			if (lazy[nodeID] != 0) {
				data[leftSon] = lazy[nodeID] * (nodeMid - nodeLeft + 1);
				data[rightSon] = lazy[nodeID] * (nodeRight - nodeMid);
				lazy[leftSon] = lazy[rightSon] = lazy[nodeID];
				lazy[nodeID] == 0;
			}
			int res = 0;
			if (segLeft <= nodeMid) {
				res += qury(nodeLeft, nodeMid, segLeft, segRight, leftSon);
			}
			if (segRight > nodeMid) {
				res += qury(nodeMid + 1, nodeRight, segLeft, segRight, rightSon);
			}
			return res;
		}
	};
	class countSmallerSub {
	public:
		countSmallerSub(int n) {
			data.resize(4 * n);
			lazy.resize(4 * n);
			numsLen = n;
			return;
		}
		void updateTick(int nodeLeft, int nodeRight, int segLeft, int segRight, int rootID) {
			if (segLeft <= nodeLeft && nodeRight <= segRight) {
				data[rootID] += nodeRight - nodeLeft + 1;
				lazy[rootID] = 1;
				return;
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int leftSon = rootID * 2, rightSon = rootID * 2 + 1;
			if (lazy[rootID] != 0) {
				data[leftSon] += nodeMid - nodeLeft + 1;
				data[rightSon] += nodeRight - nodeMid;
				lazy[leftSon] = lazy[rightSon] = lazy[rootID];
				lazy[rootID] = 0;
			}
			if (segLeft <= nodeMid) {
				updateTick(nodeLeft, nodeMid, segLeft, segRight, leftSon);
			}
			if (segRight > nodeMid) {
				updateTick(nodeMid + 1, nodeRight, segLeft, segRight, rightSon);
			}
			data[rootID] = data[leftSon] + data[rightSon];
			return;
		}
		int qury(int nodeLeft, int nodeRight, int segLeft, int segRight, int rootID) {
			if (segLeft <= nodeLeft && nodeRight <= segRight) {
				return data[rootID];
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int leftSon = rootID * 2, rightSon = rootID * 2 + 1;
			if (lazy[rootID] != 0) {
				data[leftSon] += nodeMid - nodeLeft + 1;
				data[rightSon] += nodeRight - nodeMid;
				lazy[leftSon] = lazy[rightSon] = lazy[rootID];
				lazy[rootID] = 0;
			}
			int res = 0;
			if (segLeft <= nodeMid) {
				res += qury(nodeLeft, nodeMid, segLeft, segRight, leftSon);
			}
			if (segRight > nodeMid) {
				res += qury(nodeMid + 1, nodeRight, segLeft, segRight, rightSon);
			}
			return res;
		}
	private:
		int numsLen;
		vector<int> data, lazy;
	};
	vector<int> countSmaller(vector<int>& nums) {//计算右侧小于当前元素的个数
		map<int, int> numMap;
		int id = 1;
		vector<int> numsCopy(nums);
		sort(numsCopy.begin(), numsCopy.end());
		for (int& num : numsCopy) {
			if (numMap.count(num) < 1) {
				numMap[num] = id++;
			}
		}
		countSmallerSub segTree(--id);
		int numsLen = nums.size();
		vector<int> res(numsLen);
		for (int i = numsLen - 1; i > -1; i--) {
			int tmp = numMap[nums[i]];
			segTree.updateTick(1, id, tmp, tmp, 1);
			if (tmp > 1) {
				res[i] = segTree.qury(1, id, 1, tmp - 1, 1);
			}
			else {
				res[i] = 0;
			}
		}
		return res;
	}
	class countRangeSumSub {
	public:
		countRangeSumSub(int n) {
			data.resize(4 * n);
			lazy.resize(4 * n);
			numsLen = n;
			return;
		}
		void update(int nodeLeft, int nodeRight, int segLeft, int segRight, int nodeID) {
			if (segLeft <= nodeLeft && nodeRight <= segRight) {
				data[nodeID] += nodeRight - nodeLeft + 1;
				lazy[nodeID] = 1;
				return;
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int leftSon = nodeID * 2, rightSon = nodeID * 2 + 1;
			if (lazy[nodeID] != 0) {
				data[leftSon] += nodeMid - nodeLeft + 1;
				data[rightSon] += nodeRight - nodeMid;
				lazy[leftSon] = lazy[rightSon] = lazy[nodeID];
				lazy[nodeID] = 0;
			}
			if (segLeft <= nodeMid) {
				update(nodeLeft, nodeMid, segLeft, segRight, leftSon);
			}
			if (segRight > nodeMid) {
				update(nodeMid + 1, nodeRight, segLeft, segRight, rightSon);
			}
			data[nodeID] = data[leftSon] + data[rightSon];
			return;
		}
		int qury(int nodeLeft, int nodeRight, int segLeft, int segRight, int nodeID) {
			if (segLeft <= nodeLeft && nodeRight <= segRight) {
				return data[nodeID];
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int leftSon = nodeID * 2, rightSon = nodeID * 2 + 1;
			if (lazy[nodeID] != 0) {
				data[leftSon] += nodeMid - nodeLeft + 1;
				data[rightSon] += nodeRight - nodeMid;
				lazy[leftSon] = lazy[rightSon] = lazy[nodeID];
				lazy[nodeID] = 0;
			}
			int res = 0;
			if (segLeft <= nodeMid) {
				res += qury(nodeLeft, nodeMid, segLeft, segRight, leftSon);
			}
			if (segRight > nodeMid) {
				res += qury(nodeMid + 1, nodeRight, segLeft, segRight, rightSon);
			}
			return res;
		}
	private:
		vector<int> data, lazy;
		int numsLen;
	};
	int countRangeSum(vector<int>& nums, int lower, int upper) {//区间和的个数
		long long sum = 0;
		vector<long long> prefix = { 0 };
		for (int& num : nums) {
			sum += num;
			prefix.push_back(sum);
		}
		set<long long> numSet;
		for (long long& num : prefix) {
			numSet.insert(num);
			numSet.insert(num - lower);
			numSet.insert(num - upper);
		}
		int id = 1;
		unordered_map<long long, int> numMap;
		for (auto& num : numSet) {
			numMap[num] = id++;
		}
		countRangeSumSub segTree(--id);
		int res = 0;
		for (auto& num : prefix) {
			res += segTree.qury(1, id, numMap[num - upper], numMap[num - lower], 1);
			segTree.update(1, id, numMap[num], numMap[num], 1);
		}
		return res;
	}
	class reversePairsSub {
	public:
		reversePairsSub(int n) {
			data.resize(4 * n);
			lazy.resize(4 * n);
			numsLen = n;
			return;
		}
		void update(int nodeLeft, int nodeRight, int segLeft, int segRight, int nodeID) {
			if (segLeft <= nodeLeft && nodeRight <= segRight) {
				data[nodeID] += nodeRight - nodeLeft + 1;
				lazy[nodeID] = 1;
				return;
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int leftSon = nodeID * 2, rightSon = nodeID * 2 + 1;
			if (lazy[nodeID] != 0) {
				data[leftSon] += nodeMid - nodeLeft + 1;
				data[rightSon] += nodeRight - nodeMid;
				lazy[leftSon] = lazy[rightSon] = lazy[nodeID];
				lazy[nodeID] = 0;
			}
			if (segLeft <= nodeMid) {
				update(nodeLeft, nodeMid, segLeft, segRight, leftSon);
			}
			if (segRight > nodeMid) {
				update(nodeMid + 1, nodeRight, segLeft, segRight, rightSon);
			}
			data[nodeID] = data[leftSon] + data[rightSon];
			return;
		}
		int qury(int nodeLeft, int nodeRight, int segLeft, int segRight, int nodeID) {
			if (segLeft <= nodeLeft && nodeRight <= segRight) {
				return data[nodeID];
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int leftSon = nodeID * 2, rightSon = nodeID * 2 + 1;
			if (lazy[nodeID] != 0) {
				data[leftSon] += nodeMid - nodeLeft + 1;
				data[rightSon] += nodeRight - nodeMid;
				lazy[leftSon] = lazy[rightSon] = lazy[nodeID];
				lazy[nodeID] = 0;
			}
			int res = 0;
			if (segLeft <= nodeMid) {
				res += qury(nodeLeft, nodeMid, segLeft, segRight, leftSon);
			}
			if (segRight > nodeMid) {
				res += qury(nodeMid + 1, nodeRight, segLeft, segRight, rightSon);
			}
			return res;
		}
	private:
		vector<int> data, lazy;
		int numsLen;
	};
	int reversePairs(vector<int>& nums) {//翻转对
		vector<long long> numsCopy;
		for (int& num : nums) {
			numsCopy.push_back(num);
			numsCopy.push_back(1l + 2l * num);
		}
		sort(numsCopy.begin(), numsCopy.end());
		unordered_map<long long, int> numsMap;
		int id = 1;
		for (long long& num : numsCopy) {
			if (numsMap.count(num) < 1) {
				numsMap[num] = id++;
			}
		}
		reversePairsSub segTree(--id);
		int res = 0;
		for (int& num : nums) {
			res += segTree.qury(1, id, numsMap[2l * num + 1l], id, 1);
			segTree.update(1, id, numsMap[num], numsMap[num], 1);
		}
		return res;
	}
	class fallingSquaresSub {//线段树时间常数大一些
	public:
		fallingSquaresSub(int n) {
			data.resize(4 * n);
			lazy.resize(4 * n);
			numsLen = n;
			return;
		}
		void update(int nodeLeft, int nodeRight, int segLeft, int segRight, int val, int nodeID) {
			if (segLeft <= nodeLeft && nodeRight <= segRight) {
				data[nodeID] = (nodeRight - nodeLeft + 1) * val;
				lazy[nodeID] = val;
				return;
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int leftSon = nodeID * 2, rightSon = nodeID * 2 + 1;
			if (lazy[nodeID] != 0) {
				data[leftSon] = (nodeMid - nodeLeft + 1) * val;
				data[rightSon] = (nodeRight - nodeMid) * val;
				lazy[leftSon] = lazy[rightSon] = lazy[nodeID];
				lazy[nodeID] = 0;
			}
			if (segLeft <= nodeMid) {
				update(nodeLeft, nodeMid, segLeft, segRight, val, leftSon);
			}
			if (segRight > nodeMid) {
				update(nodeMid + 1, nodeRight, segLeft, segRight, val, rightSon);
			}
			data[nodeID] = data[leftSon] + data[rightSon];
			return;
		}
		long long qury(int nodeLeft, int nodeRight, int segLeft, int segRight, int nodeID) {
			if (segLeft <= nodeLeft && nodeRight <= segRight) {
				return data[nodeID];
			}
			int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
			int leftSon = nodeID * 2, rightSon = nodeID * 2 + 1;
			if (lazy[nodeID] != 0) {
				data[leftSon] = (nodeMid - nodeLeft + 1) * lazy[nodeID];
				data[rightSon] = (nodeRight - nodeMid) * lazy[nodeID];
				lazy[leftSon] = lazy[rightSon] = lazy[nodeID];
				lazy[nodeID] = 0;
			}
			long long res = 0;
			if (segLeft <= nodeMid) {
				res += qury(nodeLeft, nodeMid, segLeft, segRight, leftSon);
			}
			if (segRight > nodeMid) {
				res += qury(nodeMid + 1, nodeRight, segLeft, segRight, rightSon);
			}
			return res;
		}
	private:
		vector<long long> data, lazy;
		int numsLen;
	};
	vector<int> fallingSquares(vector<vector<int>>& positions) {//掉落的方块
		vector<int> pos;
		for (vector<int>& square : positions) {
			pos.push_back(square[0]);
			pos.push_back(square[0] + square[1] - 1);
		}
		sort(pos.begin(), pos.end());
		unordered_map<int, int> posMap;
		int id = 1;
		for (int& num : pos) {
			if (posMap.count(num) < 1) {
				posMap[num] = id++;
			}
		}
		fallingSquaresSub segTree(--id);
		vector<int> res;
		long long tmp = 0;
		for (vector<int>& square : positions) {
			long long segMax = 0;
			for (int i = 0; i < square[1]; i++) {
				if (posMap.count(square[0] + i) > 0) {
					segMax = max(segMax, segTree.qury(1, id, posMap[square[0] + i], posMap[square[0] + i], 1));
				}
			}
			segTree.update(1, id, posMap[square[0]], posMap[square[0] + square[1] - 1], segMax + square[1], 1);
			tmp = max(tmp, segMax + square[1]);
			res.push_back((int)tmp);
		}
		return res;
	}
	class RangeModule {//Range 模块
	public://可以实现树的动态扩展，非固定节点数量
		RangeModule() {
			segment.clear();
			return;
		}
		void addRange(int left, int right) {
			auto a = segment.lower_bound(left);
			auto b = segment.lower_bound(right);
			if (a == segment.end()) {
				segment[right] = left;
			}
			else {
				int start = a->second;
				auto p = a;
				while (p != b) {
					a++;
					segment.erase(p);
					p = a;
				}
				if (b == segment.end() || b->second > right) {
					segment[right] = min(start, left);
				}
				else {
					b->second = min(start, left);
				}
			}
			return;
		}
		bool queryRange(int left, int right) {
			auto p = segment.lower_bound(right);
			if (p == segment.end() || p->second > left) {
				return false;
			}
			return true;
		}
		void removeRange(int left, int right) {
			auto a = segment.lower_bound(left);
			auto b = segment.lower_bound(right);
			if (a == segment.end() || right <= segment.begin()->second) {
				return;
			}
			else {
				int x = a->second;
				auto p = a;
				while (p != b) {
					a++;
					segment.erase(p);
					p = a;
				}
				if (b != segment.end()) {
					int y = b->first;
					if (b->second < right) {
						segment.erase(b);
						if (right < y) {
							segment[y] = right;
						}
					}
				}
				if (x < left) {
					segment[left] = x;
				}
			}
			return;
		}
	private:
		map<int, int> segment;//右-左
	};
	class MyCalendarThree {//我的日程安排表 III
		//需要动态增加节点的线段树
	public:
		MyCalendarThree() {
			rootNode = new segTreeNode(0, 1e9);
			return;
		}
		int book(int start, int end) {
			return insert(start, end, rootNode);
		}
	private:
		struct segTreeNode {
			int nodeLeft = -1, nodeRight = -1;
			int val = 0;
			int lazy = 0;
			segTreeNode* leftSon = nullptr;
			segTreeNode* rightSon = nullptr;
			segTreeNode(int start, int end) {
				nodeLeft = start, nodeRight = end;
				return;
			}
		};
		segTreeNode* rootNode;
		int insert(int segLeft, int segRight, segTreeNode* root) {
			if (segLeft <= root->nodeLeft && root->nodeRight <= segRight) {//节点范围是插入范围的子集
				//欠债阶段，这种情况是完全确定的，可以确定债权
				root->val++;
				root->lazy++;
			}
			else if (root->nodeLeft < segRight && segLeft < root->nodeRight) {//待插入区间与节点范围有重叠
				int nodeMid = root->nodeLeft + (root->nodeRight - root->nodeLeft) / 2;
				if (root->leftSon == nullptr) {
					root->leftSon = new segTreeNode(root->nodeLeft, nodeMid);
				}
				if (root->rightSon == nullptr) {
					root->rightSon = new segTreeNode(nodeMid, root->nodeRight);
				}
				//还债阶段，因为债务是在完全包含的情况下欠的，所以可以下放
				root->leftSon->val += root->lazy;
				root->rightSon->val += root->lazy;
				root->leftSon->lazy += root->lazy;
				root->rightSon->lazy += root->lazy;
				root->lazy = 0;
				int leftVal = insert(segLeft, segRight, root->leftSon);
				int rightVal = insert(segLeft, segRight, root->rightSon);
				root->val = max(leftVal, rightVal);
			}
			return root->val;
		}
	};
	//class rectangleAreaSub {//紧贴坐标轴的，实际应该使用单轴扫掠
	//public:
	//	rectangleAreaSub(int n) {
	//		data.resize(4 * n);
	//		lazy.resize(4 * n);
	//		return;
	//	}
	//	void update(int nodeLeft, int nodeRight, int segLeft, int segRight, int val, int id) {
	//		if (segLeft <= nodeLeft && nodeRight <= segRight) {
	//			lazy[id] = max(lazy[id], val);
	//			data[id] = max(data[id], lazy[id]);
	//			return;
	//		}
	//		int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
	//		int leftSon = id * 2, rightSon = id * 2 + 1;
	//		if (lazy[id] != 0) {
	//			lazy[leftSon] = max(lazy[leftSon], lazy[id]);
	//			lazy[rightSon] = max(lazy[rightSon], lazy[id]);
	//			data[leftSon] = max(data[leftSon], lazy[leftSon]);
	//			data[rightSon] = max(data[rightSon], lazy[rightSon]);
	//			lazy[id] = 0;
	//		}
	//		if (segLeft <= nodeMid) {
	//			update(nodeLeft, nodeMid, segLeft, segRight, val, leftSon);
	//		}
	//		if (segRight > nodeMid) {
	//			update(nodeMid + 1, nodeRight, segLeft, segRight, val, rightSon);
	//		}
	//		data[id] = max(data[leftSon], data[rightSon]);
	//		return;
	//	}
	//	int qury(int nodeLeft, int nodeRight, int segLeft, int segRight, int id) {
	//		if (segLeft <= nodeLeft && nodeRight <= segRight) {
	//			data[id] = max(data[id], lazy[id]);
	//			return data[id];
	//		}
	//		int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;
	//		int leftSon = id * 2, rightSon = id * 2 + 1;
	//		if (lazy[id] != 0) {
	//			lazy[leftSon] = max(lazy[leftSon], lazy[id]);
	//			lazy[rightSon] = max(lazy[rightSon], lazy[id]);
	//			data[leftSon] = max(data[leftSon], lazy[leftSon]);
	//			data[rightSon] = max(data[rightSon], lazy[rightSon]);
	//			lazy[id] = 0;
	//		}
	//		int res = 0;
	//		if (segLeft <= nodeMid) {
	//			res = max(qury(nodeLeft, nodeMid, segLeft, segRight, leftSon), res);
	//		}
	//		if (segRight > nodeMid) {
	//			res = max(qury(nodeMid + 1, nodeRight, segLeft, segRight, rightSon), res);
	//		}
	//		return res;
	//	}
	//private:
	//	vector<int> data, lazy;
	//};
	//int rectangleArea(vector<vector<int>>& rectangles) {//矩形面积 II
	//	vector<int> pos, resPos;
	//	for (vector<int>& rect : rectangles) {
	//		pos.push_back(rect[0]);
	//		pos.push_back(rect[0] - 1);
	//		pos.push_back(rect[2] - 1);
	//		pos.push_back(rect[2]);
	//		resPos.push_back(rect[0]);
	//		resPos.push_back(rect[2]);
	//	}
	//	sort(pos.begin(), pos.end());
	//	sort(resPos.begin(), resPos.end());
	//	unordered_map<int, int> posMap;
	//	int id = 1;
	//	for (int& pt : pos) {
	//		if (posMap.count(pt) < 1) {
	//			posMap[pt] = id++;
	//		}
	//	}
	//	rectangleAreaSub segTree(--id);
	//	long long res = 0;
	//	for (vector<int>& rect : rectangles) {
	//		segTree.update(1, id, posMap[rect[0]], posMap[rect[2] - 1], rect[3], 1);
	//	}
	//	int mod = 1e9 + 7, lastPoint = resPos[0];
	//	for (int& currentPoint : resPos) {
	//		if (currentPoint == lastPoint) {
	//			continue;
	//		}
	//		res = (res + 1l * (currentPoint - lastPoint) * segTree.qury(1, id, posMap[lastPoint], posMap[currentPoint - 1], 1)) % mod;
	//		lastPoint = currentPoint;
	//	}
	//	return (int)(res % mod);
	//}
	
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "dcab";
	string b = "this apple is sour";
	vector<int> inpt1 = { 2, 4, 3, 5, 1 };
	vector<int> inpt2 = { 2,4,1,1,3 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8}
	};
	vector<vector<int>> board = {
		{1,0,0,0,1,0,0,0,0,0,1},
		{0,1,0,1,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,1,0,0,0},
		{0,1,0,1,0,1,0,0,0,0,0},
		{1,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,1,0,1,0,0,1,1,0},
		{0,0,0,0,0,0,1,1,0,0,0},
		{0,0,1,0,0,0,1,1,0,0,0},
		{0,0,0,0,0,1,0,0,1,0,0},
		{0,0,0,0,0,1,0,0,0,1,0},
		{1,0,0,0,0,0,0,0,0,0,1}
	};
	vector<vector<int>> equations = { {9, 7}, {1, 9}, {3, 1} };
	vector<double> val = { 2.0, 3.0 };
	vector<string> qur = { " /","/ " };
	mySolution;
	
	return 0;
}
#endif

// 图解算法数据结构--动态规划
#if false
class Solution {
public:
	int fib(int n) {
		if (n < 2){
			return n;
		}
		int n_2 = 0, n_1 = 1, n_0 = 0;
		while (--n > 0){
			n_0 = (n_2 + n_1) % 1000000007;
			n_2 = n_1;
			n_1 = n_0;
		}
		return n_0;
    }
	int numWays(int n) {
		n++;
		if (n < 2){
			return n;
		}
		int n_2 = 0, n_1 = 1, n_0 = 0;
		while (--n > 0){
			n_0 = (n_2 + n_1) % 1000000007;
			n_2 = n_1;
			n_1 = n_0;
		}
		return n_0;
    }
	bool isMatch(string s, string p) {
		size_t sLen = s.size(), pLen = p.size(), sCur = 0, pCur = 0;
		vector<vector<int>> dp(sLen + 1, vector<int>(pLen + 1, 0));
		dp[0][0] = 1;
		auto isMatch = [&](int i, int j){// 当前字符是否匹配
			if (i == 0){
				return false;
			}
			if (p[j - 1] == '.'){
				return true;
			}
			return s[i - 1] == p[j - 1];
		};
		for (int i = 0; i <= sLen; i++){
			for (int j = 1; j <= pLen; j++){
				if (p[j - 1] == '*'){//任意数量匹配
					dp[i][j] |= dp[i][j - 2];//数量为 0 匹配
					if (isMatch(i, j - 1)){// 当前字符匹配
						dp[i][j] |= dp[i - 1][j];
					}
				}
				else {
					if (isMatch(i, j)){// 当前字符匹配
						dp[i][j] |= dp[i - 1][j - 1];
					}
				}
			}
		}
		return dp[sLen][pLen] == 1;
    }
	int maxSubArray(vector<int>& nums) {
		size_t numsLen = nums.size();
		int res = nums[0], pre = 0;
		for (int& num : nums){
			pre = max(pre + num, num);//对于单独数列
			res = max(res, pre);//对于所有数列
		}
		return res;
    }
	int translateNum(int num) {
		int n_1 = 1, n_2 = 1, x = 0, y = num % 10, res = 1;
		while (num > 9){
			num /= 10;
			x = num % 10;
			int tmp = x * 10 + y;
			res = tmp > 9 && tmp < 26 ? n_1 + n_2 : n_1;
			n_2 = n_1;
			n_1 = res;
			y = x;
		}
		return res;
    }
	int maxValue(vector<vector<int>>& grid) {
		size_t rolSize = grid.size(), colSize = grid[0].size();
		for (int i = 1; i < rolSize; i++){
			grid[i][0] += grid[i - 1][0];
		}
		for (int i = 1; i < colSize; i++){
			grid[0][i] += grid[0][i - 1];
		}
		for (int i = 1; i < rolSize; i++){
			for (int j = 1; j < colSize; j++){
				grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[rolSize - 1][colSize - 1];
    }
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> chMap;
		size_t sLen = s.size();
		int curLeft = 0, curRight = 0;
		int res = 0;
		while (curRight < sLen){
			char& ch = s[curRight];
			if (chMap.count(ch) && chMap[ch] > 0){
				chMap[s[curLeft++]]--;
			}
			else{
				chMap[s[curRight++]]++;
			}
			res = max(res, curRight - curLeft);
		}
		res = max(res, curRight - curLeft);
		return res;
    }
	int nthUglyNumber(int n) {
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		int cur2 = 1, cur3 = 1, cur5 = 1;
		for (int i = 2; i <= n; i++){
			int num2 = dp[cur2] * 2;
			int num3 = dp[cur3] * 3;
			int num5 = dp[cur5] * 5;
			dp[i] = min(min(num2, num3), num5);
			if (dp[i] == num2){
				cur2++;
			}
			if (dp[i] == num3){
				cur3++;
			}
			if (dp[i] == num5){
				cur5++;
			}
		}
		return dp[n];
    }
	vector<double> dicesProbability(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
		for (int i = 1; i <= 6; i++){
			dp[1][i] = 1;
		}
		for (int i = 2; i <= n; i++){
			for (int j = i; j <= 6 * i; j++){
				for (int cur = 1; cur <= 6; cur++){
					if (j - cur < 1){//最小面值
						break;
					}
					dp[i][j] += dp[i - 1][j - cur];
				}
			}
		}
		double base = 1.0 / pow(6, n);
		vector<double> res(5 * n + 1, 0.0);
		for (int i = n; i <= 6 * n; i++){
			res[i - n] = dp[n][i] * base;
		}
		return res;
    }
	int maxProfit(vector<int>& prices) {
		int cost = INT32_MAX, profit = 0;
		for (int & price : prices){
			cost = min(cost, price);
			profit = max(profit, price - cost);
		}
		return profit;
    }
};
int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "dcab";
	string b = "this apple is sour";
	vector<int> inpt1 = { 7,1,5,3,6,4 };
	vector<int> inpt2 = { 2,4,1,1,3 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8}
	};
	vector<vector<int>> board = {
		{1,0,0,0,1,0,0,0,0,0,1},
		{0,1,0,1,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,1,0,0,0},
		{0,1,0,1,0,1,0,0,0,0,0},
		{1,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,1,0,1,0,0,1,1,0},
		{0,0,0,0,0,0,1,1,0,0,0},
		{0,0,1,0,0,0,1,1,0,0,0},
		{0,0,0,0,0,1,0,0,1,0,0},
		{0,0,0,0,0,1,0,0,0,1,0},
		{1,0,0,0,0,0,0,0,0,0,1}
	};
	vector<vector<int>> equations = { {9, 7}, {1, 9}, {3, 1} };
	vector<double> val = { 2.0, 3.0 };
	vector<string> qur = { " /","/ " };
	mySolution;
	mySolution.maxProfit(inpt1);
	return 0;
}
#endif

// 图解算法数据结构--搜索与回溯算法
#if false
class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Node {
	public:
		int val;
		Node* left;
		Node* right;

		Node() {}

		Node(int _val) {
			val = _val;
			left = NULL;
			right = NULL;
		}

		Node(int _val, Node* _left, Node* _right) {
			val = _val;
			left = _left;
			right = _right;
		}
	};
	bool exist(vector<vector<char>>& board, string word) {
		int rolSize = board.size(), colSize = board[0].size();
		vector<vector<bool>> vist(rolSize, vector<bool>(colSize, false));
		vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		for (int i = 0; i < rolSize; i++){
			for (int j = 0; j < colSize; j++){
				if (existSub(board, vist, i, j, word, 0, rolSize, colSize, dir)){
					return true;
				}
			}
		}
		return false;
    }
	bool existSub(vector<vector<char>>& board, vector<vector<bool>>& vist, int rolCur, int colCur, string& word, int cur, int& rolSize, int& colSize, vector<vector<int>>& dir){
		if (cur == word.size()){
			return true;
		}
		if (word[cur] != board[rolCur][colCur]){
			return false;
		}
		if (cur == word.size() - 1){
			return true;
		}
		vist[rolCur][colCur] = true;
		for (int i = 0; i < 4; i++){
			int tmpRol = rolCur + dir[i][0], tmpCol = colCur + dir[i][1];
			if (tmpCol < 0 || tmpCol >= colSize || tmpRol < 0 || tmpRol >= rolSize || vist[tmpRol][tmpCol]){
				continue;
			}
			if (existSub(board, vist, tmpRol, tmpCol, word, cur + 1, rolSize, colSize, dir)){
				return true;
			}
		}
		vist[rolCur][colCur] = false;
		return false;
	}
	int movingCount(int m, int n, int k) {
		vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		vector<vector<bool>> vist(m, vector<bool>(n, false));
		int res = movingCountSub(vist, 0, 0, m, n, dir, k);
		return res;
    }
	int movingCountSub(vector<vector<bool>>& vist, int rolCur, int colCur, int rolSize, int colSize, vector<vector<int>>& dir, int lim){
		if (rolCur < 0 || rolCur >= rolSize || colCur < 0 || colCur >= colSize || vist[rolCur][colCur]){
			return 0;
		}
		int sum = 0, rolCopy = rolCur, colCopy = colCur;
		while (rolCopy){
			sum += rolCopy % 10;
			rolCopy /= 10;
		}
		while (colCopy){
			sum += colCopy % 10;
			colCopy /= 10;
		}
		if (sum > lim){
			return 0;
		}
		vist[rolCur][colCur] = true;
		int res = 1;
		for (int i = 0; i < 4; i++){
			int tmpRol = rolCur + dir[i][0], tmpCol = colCur + dir[i][1];
			res += movingCountSub(vist, tmpRol, tmpCol, rolSize, colSize, dir, lim);
		}
		// vist[rolCur][colCur] = false;
		return res;
	}
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		return (A != nullptr && B != nullptr) && (isSubStructureSub(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
	bool isSubStructureSub(TreeNode* A, TreeNode* B){
		if (B == nullptr){
			return true;
		}
		if (A == nullptr || A->val != B->val){
			return false;
		}
		return isSubStructureSub(A->left, B->left) && isSubStructureSub(A->right, B->right);
	}
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == nullptr){
			return nullptr;
		}
		TreeNode* tmp = mirrorTree(root->left);
		root->left = mirrorTree(root->right);
		root->right = tmp;
		return root;
    }
	bool isSymmetric(TreeNode* root) {
		return root == nullptr || isSymmetricSub(root->left, root->right);
    }
	bool isSymmetricSub(TreeNode* left, TreeNode* right){
		if (left == nullptr && right == nullptr){
			return true;
		}
		if (left == nullptr || right == nullptr || left->val != right->val){
			return false;
		}
		return isSymmetricSub(left->left, right->right) && isSymmetricSub(left->right, right->left);
	}
	vector<int> levelOrderI(TreeNode* root) {
		queue<TreeNode*> que;
		que.push(root);
		vector<int> res;
		while (!que.empty()){
			root = que.front();
			que.pop();
			if (root == nullptr){
				continue;
			}
			res.push_back(root->val);
			que.push(root->left);
			que.push(root->right);
		}
		return res;
    }
	vector<vector<int>> levelOrderII(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr){
			return res;
		}
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()){
			int queLen = que.size();
			vector<int> tmp;
			while (queLen--){
				root = que.front();
				que.pop();
				tmp.push_back(root->val);
				if (root->left){
					que.push(root->left);
				}
				if (root->right){
					que.push(root->right);
				}
			}
			res.push_back(tmp);
		}
		return res;
    }
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr){
			return res;
		}
		queue<TreeNode*> que;
		que.push(root);
		bool needReverse = false;
		while (!que.empty()){
			int queLen = que.size();
			vector<int> tmp;
			while (queLen--){
				root = que.front();
				que.pop();
				tmp.push_back(root->val);
				if (root->left){
					que.push(root->left);
				}
				if (root->right){
					que.push(root->right);
				}
			}
			if (needReverse){
				reverse(tmp.begin(), tmp.end());
			}
			needReverse = !needReverse;
			res.push_back(tmp);
		}
		return res;
    }
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		vector<int> tmp;
		vector<vector<int>> res;
		pathSumSub(root, 0, target, tmp, res);
		return res;
    }
	void pathSumSub(TreeNode* root, int sum, int target, vector<int>& tmp, vector<vector<int>>& res){
		if (root == nullptr){
			return;
		}
		tmp.push_back(root->val);
		sum += root->val;
		if (root->left == nullptr && root->right == nullptr && sum == target){
			res.push_back(tmp);
		}
		pathSumSub(root->left, sum, target, tmp, res);
		pathSumSub(root->right, sum, target, tmp, res);
		tmp.pop_back();
		return;
	}
	Node* treeToDoublyListI(Node* root) {
		if (root == nullptr){
			return nullptr;
		}
        queue<Node*> que;
		treeToDoublyListDFSI(root, que);
		Node* head = que.front();
		Node* cur = head;
		while (!que.empty()){
			cur->right = que.front();
			que.front()->left = cur;
			cur = que.front();
			que.pop();
		}
		cur->right = head;
		head->left = cur;
		return head;
    }
	void treeToDoublyListDFSI(Node* root, queue<Node*>& que){
		if (root == nullptr){
			return;
		}
		treeToDoublyListDFSI(root->left, que);
		que.push(root);
		treeToDoublyListDFSI(root->right, que);
		return;
	}
	Node* treeToDoublyList(Node* root) {
		if (root == nullptr)   {
			return nullptr;
		}
		Node* head = nullptr;
		Node* pre = nullptr;
		treeToDoublyListDFS(root, head, pre);
		head->left = pre;
		pre->right = head;
		return head;
    }
	void treeToDoublyListDFS(Node* root, Node*& head, Node*& pre){
		if (root == nullptr){
			return;
		}
		treeToDoublyListDFS(root->left, head, pre);
		if (pre != nullptr){
			pre->right = root;
		}
		else {
			head = root;
		}
		root->left = pre;
		pre = root;
		treeToDoublyListDFS(root->right, head, pre);
		return;
	}
	string serialize(TreeNode* root) {
        string res;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()){
			int queLen = que.size();
			while(queLen--){
				TreeNode* cur = que.front();
				que.pop();
				if (cur == nullptr){
					res += "null,";
				}
				else {
					res = res + to_string(cur->val) + ",";
					que.push(cur->left);
					que.push(cur->right);
				}
			}
		}
		return res;
    }
	TreeNode* deserialize(string data) {
        queue<int>* que = dataStrDecode(data);
		if (que->size() == 0 || que->front() == -8964){
			return nullptr;
		}
		queue<TreeNode*> nodeQue;
		TreeNode* head = new TreeNode(que->front());
		TreeNode* cur = nullptr;
		que->pop();
		nodeQue.push(head);
		while (!nodeQue.empty()){
			int queLen = nodeQue.size();
			while (queLen--){
				cur = nodeQue.front();
				nodeQue.pop();
				if (cur == nullptr){
					continue;
				}
				int val = -8964;
				if (!que->empty()){
					val = que->front();
					que->pop();
				}
				if (val != -8964){
					cur->left = new TreeNode(val);
				}
				nodeQue.push(cur->left);
				val = -8964;
				if (!que->empty()){
					val = que->front();
					que->pop();
				}
				if (val != -8964){
					cur->right = new TreeNode(val);
				}
				nodeQue.push(cur->right);
			}
		}
		delete que;
		return head;
    }
	queue<int>* dataStrDecode(string& data){
		queue<int>* que = new queue<int>;
		int dataLen = data.size(), cur = 0;
		while (cur < dataLen){
			if (data[cur] == ',' || data[cur] == '[' || data[cur] == ']'){
				cur++;
				continue;
			}
			if (data[cur] == 'n'){
				que->push(-8964);
				cur += 4;
				continue;
			}
			int sign = 1, tmpVal = 0;
			while (cur < dataLen && data[cur] != ',' && data[cur] != ']'){
				if (data[cur] == '-'){
					sign = -1;
					cur++;
					continue;
				}
				tmpVal = tmpVal * 10 +  data[cur] - '0';
				cur++;
			}
			que->push(tmpVal * sign);
		}
		return que;
	}
	vector<string> permutation(string s) {
		string tmp;
		unordered_set<string> stringSet;
		int sLen = s.size();
		vector<bool> vist(sLen, false);
		permutationSub(s, tmp, stringSet, vist, sLen);
		vector<string> res;
		for (auto& it : stringSet){
			res.push_back(it);
		}
		return res;
    }
	void permutationSub(string& s, string& tmp, unordered_set<string>& stringSet, vector<bool>& vist, int sLen){
		if (tmp.size() == sLen){
			stringSet.emplace(tmp);
			return;
		}
		for (int i = 0; i < sLen; i++){
			if (vist[i]){
				continue;
			}
			vist[i] = true;
			tmp.push_back(s[i]);
			permutationSub(s, tmp, stringSet, vist, sLen);
			tmp.pop_back();
			vist[i] = false;
		}
		return;
	}
	int kthLargest(TreeNode* root, int k) {
		int res = 0;
		kthLargestSub(root, res, k);
		return res;
    }
	void kthLargestSub(TreeNode* root, int& res, int& k){
		if (root == nullptr){
			return;
		}
		kthLargestSub(root->right, res, k);
		if (k == 0){
			return;
		}
		if (--k == 0){
			res = root->val;
			return;
		}
		kthLargestSub(root->left, res, k);
	}
	int maxDepth(TreeNode* root) {
		if (root == nullptr){
			return 0;
		}
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
	bool isBalanced(TreeNode* root) {
		bool valid = true;
		isBalanced(root, valid);
		return valid;
    }
	int isBalanced(TreeNode* root, bool& valid){
		if (root == nullptr || !valid){
			return 0;
		}
		int left = isBalanced(root->left, valid);
		int right = isBalanced(root->right, valid);
		if (abs(left - right) > 1){
			valid = false;
			return 0;
		}
		return max(left, right) + 1;
	}
	int sumNums(int n) {
		n && (n += sumNums(n - 1));
		return n;
    }
	TreeNode* lowestCommonAncestorI(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr){
			return nullptr;
		}
		if (p->val < root->val && q->val < root->val){
			return lowestCommonAncestorI(root->left, p, q);
		}
		else if (p->val > root->val && q->val > root->val){
			return lowestCommonAncestorI(root->right, p, q);
		}
		return root;
    }
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
		lowestCommonAncestorSub(root, p, q, res);
		return res;
    }
	bool lowestCommonAncestorSub(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res){
		if (root == nullptr || res != nullptr){
			return false;
		}
		bool inLeft = lowestCommonAncestorSub(root->left, p, q, res);
		bool inRight = lowestCommonAncestorSub(root->right, p, q, res);
		if (inLeft && inRight || ((root->val == p->val || root->val == q->val) && (inLeft || inRight))){
			res = root;
		}
		return inLeft || inRight || (root->val == p->val || root->val == q->val);
	}
};
int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "abs";
	string b = "this apple is sour";
	vector<int> inpt1 = { 7,1,5,3,6,4 };
	vector<int> inpt2 = { 2,4,1,1,3 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8}
	};
	vector<vector<char>> board = {{'a'}};
	vector<vector<int>> equations = { {9, 7}, {1, 9}, {3, 1} };
	vector<double> val = { 2.0, 3.0 };
	vector<string> qur = { " /","/ " };
	mySolution.permutation(a);
	return 0;
}
#endif

// 图解算法数据结构--分治
#if false
class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Node {
	public:
		int val;
		Node* left;
		Node* right;

		Node() {}

		Node(int _val) {
			val = _val;
			left = NULL;
			right = NULL;
		}

		Node(int _val, Node* _left, Node* _right) {
			val = _val;
			left = _left;
			right = _right;
		}
	};
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int curPos = preorder.size() - 1;
		return buildTreeSub(preorder, inorder, 0, curPos, 0, curPos);
    }
	TreeNode* buildTreeSub(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight){
		if (preLeft > preRight){
			return nullptr;
		}
		TreeNode* root = new TreeNode(preorder[preLeft]);
		int i = 0;
		for (i = 0; i < inRight - inLeft; i++){
			if (inorder[i + inLeft] == preorder[preLeft]){
				break;
			}
		}
		root->left = buildTreeSub(preorder, inorder, preLeft + 1, preLeft + i, inLeft, inLeft + i - 1);
		root->right = buildTreeSub(preorder, inorder, preLeft + i + 1, preRight, inLeft + i + 1, inRight);
		return root;
	}
	double myPow(double x, int n) {
		bool isNeg = n < 0 ? true : false;
		if (n == 0x7fffffff) {
			if (x == 1.0 || x == -1.0) {
				return x;
			}
		}
		int i = 31;
		double res = 1.0, tmp = x;
		while (n != 0) {
			if (n % 2) {
				res *= tmp;
			}
			tmp *= tmp;
			n = n / 2;
		}
		if (isNeg) {
			res = 1 / res;
		}
		return res;
	}
	vector<int> printNumbers(int n) {
		int hi = pow(10, n) - 1;
		int lo = 1;
		vector<int> res(hi - lo + 1);
		for (int i = lo; i <= hi; i++){
			res[i - lo] = i;
		}
		return res;
    }
	bool verifyPostorderI(vector<int>& postorder) {
		return verifyPostorderSub(postorder, 0, postorder.size() - 1);
    }
	bool verifyPostorderSub(vector<int>& postorder, int leftCur, int rightCur){
		if (leftCur >= rightCur){
			return true;
		}
		int cur = leftCur;
		while (cur < rightCur && postorder[cur] < postorder[rightCur]){
			cur++;
		}
		for (int i = cur; i < rightCur; i++){
			if (postorder[i] < postorder[rightCur]){
				return false;
			}
		}
		return verifyPostorderSub(postorder, leftCur, cur - 1) && verifyPostorderSub(postorder, cur, rightCur - 1);
	}
	bool verifyPostorder(vector<int>& postorder) {
		stack<int> stk;
		int root = INT32_MAX;
		for (int i = postorder.size() - 1; i >= 0; i--){
			if (postorder[i] > root){
				return false;
			}
			while (!stk.empty() && stk.top() > postorder[i]){
				root = stk.top();
				stk.pop();
			}
			stk.push(postorder[i]);
		}
		return true;
    }
	int reversePairs(vector<int>& nums) {
		vector<int> tmp(nums);
		return reversePairsSub(nums, tmp, 0, nums.size() - 1);
    }
	int reversePairsSub(vector<int>& nums, vector<int>& tmp, int leftCur, int rightCur){
		if (leftCur >= rightCur){
			return 0;
		}
		int mid = (leftCur + rightCur) / 2;
        int res = reversePairsSub(nums, tmp, leftCur, mid) + reversePairsSub(nums, tmp, mid + 1, rightCur);
        // 合并阶段
        int i = leftCur, j = mid + 1;
        for (int k = leftCur; k <= rightCur; k++)
            tmp[k] = nums[k];
        for (int k = leftCur; k <= rightCur; k++) {
            if (i == mid + 1)
                nums[k] = tmp[j++];
            else if (j == rightCur + 1 || tmp[i] <= tmp[j])
                nums[k] = tmp[i++];
            else {
                nums[k] = tmp[j++];
                res += mid - i + 1; // 统计逆序对
            }
        }
        return res;
	}
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> res(k, 0);
		getLeastNumbersSub(arr, 0, arr.size() - 1);
		for (int i = 0; i < k; i++){
			res[i] = arr[i];
		}
		return res;
    }
	void getLeastNumbersSub(vector<int>& arr, int leftCur, int rightCur){
		if (leftCur >= rightCur){
			return;
		}
		int pivot = arr[leftCur];
		int left = leftCur, right = rightCur;
		while (left < right){
			while (left < right && arr[right] >= pivot){
				right--;
			}
			while (left < right && arr[left] <= pivot){
				left++;
			}
			swap(arr[left], arr[right]);
		}
		swap(arr[leftCur], arr[left]);
		getLeastNumbersSub(arr, leftCur, left - 1);
		getLeastNumbersSub(arr, left + 1, rightCur);
		return;
	}
	string minNumber(vector<int>& nums) {
		minNumberSub(nums, 0, nums.size() - 1);
		string res;
		for (int& num : nums){
			res += to_string(num);
		}
		return res;
    }
	bool minNumberSub1(int num1, int num2){
		string str1 = to_string(num1) + to_string(num2);
		string str2 = to_string(num2) + to_string(num1);
		return str1 <= str2;
	}
	void minNumberSub(vector<int>& nums, int leftCur, int rightCur){
		if (leftCur >= rightCur){
			return;
		}
		int pivot = nums[leftCur];
		int left = leftCur, right = rightCur;
		while (left < right){
			while (left < right && minNumberSub1(pivot, nums[right])){
				right--;
			}
			while (left < right && minNumberSub1(nums[left], pivot)){
				left++;
			}
			swap(nums[left], nums[right]);
		}
		swap(nums[leftCur], nums[left]);
		minNumberSub(nums, leftCur, left - 1);
		minNumberSub(nums, left + 1, rightCur);
		return;
	}
	bool isStraight(vector<int>& nums) {
		isStraightSub(nums, 0, nums.size() - 1);
		int zeroCnt = 0;
		for (int i = 0; i < 4; i++){
			if (nums[i] == 0){
				zeroCnt++;
				continue;
			}
			int diff = nums[i + 1] - nums[i] - 1;
			if (diff < 0){
				return false;
			}
			zeroCnt -= diff;
		}
		return zeroCnt >= 0;
    }
	void isStraightSub(vector<int>& nums, int leftCur, int rightCur){
		if (leftCur >= rightCur){
			return;
		}
		int pivot = nums[leftCur];
		int left = leftCur, right = rightCur;
		while (left < right){
			while (left < right && nums[right] >= pivot){
				right--;
			}
			while (left < right && nums[left] <= pivot){
				left++;
			}
			swap(nums[left], nums[right]);
		}
		swap(nums[left], nums[leftCur]);
		isStraightSub(nums, leftCur, left - 1);
		isStraightSub(nums, left + 1, rightCur);
		return;
	}
};
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    priority_queue<int, vector<int>, less<int>> maxHeap;//栈顶元素大， 所以叫大顶堆
	priority_queue<int, vector<int>, greater<int>> minHeap;//栈顶元素小， 所以叫小顶堆
    void addNum(int num) {
		if (minHeap.size() == maxHeap.size()){
			minHeap.push(num);
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		else{
			maxHeap.push(num);
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
    }
    
    double findMedian() {
		if (maxHeap.size() == minHeap.size()){
			return 0.5 * (maxHeap.top() + minHeap.top());
		}
		return 1.0 * maxHeap.top();
    }
};
int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "abs";
	string b = "this apple is sour";
	vector<int> inpt1 = { 11, 8, 12, 8, 10 };
	vector<int> inpt2 = { 2,4,1,1,3 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8}
	};
	vector<vector<char>> board = {{'a'}};
	vector<vector<int>> equations = { {9, 7}, {1, 9}, {3, 1} };
	vector<double> val = { 2.0, 3.0 };
	vector<string> qur = { " /","/ " };
	mySolution.isStraight(inpt1);
	return 0;
}
#endif

// 图解算法数据结构--查找算法
#if false
class Solution {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Node {
	public:
		int val;
		Node* left;
		Node* right;

		Node() {}

		Node(int _val) {
			val = _val;
			left = NULL;
			right = NULL;
		}

		Node(int _val, Node* _left, Node* _right) {
			val = _val;
			left = _left;
			right = _right;
		}
	};
	int findRepeatNumber(vector<int>& nums) {
		unordered_set<int> numSet;
		for (int& num : nums){
			if (numSet.count(num)){
				return num;
			}
			numSet.emplace(num);
		}
		return -1;
    }
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0){
			return false;
		}
		int rolSize = matrix.size(), colSize = matrix[0].size();
		int rolCur = rolSize - 1, colCur = 0;
		while (rolCur >= 0 && rolCur < rolSize && colCur >= 0 && colCur < colSize){
			if (matrix[rolCur][colCur] == target){
				return true;
			}
			else if (matrix[rolCur][colCur] < target){
				colCur++;
			}
			else {
				rolCur--;
			}
		}
		return false;
    }
	int minArray(vector<int>& nums) {
		int left = 0, right = nums.size() - 1, mid = 0;
		while (left < right){
			mid = left + (right - left) / 2;
			if (nums[mid] > nums[right]){
				left = mid + 1;
			}
			else if (nums[mid] < nums[right]){
				right = mid;
			}
			else {
				right--;
			}
		}
		return nums[left];
    }
	char firstUniqChar(string s) {
		unordered_map<char, int> chMap;
		for (char& ch : s){
			chMap[ch]++;
		}
		for (char& ch : s){
			if (chMap[ch] == 1){
				return ch;
			}
		}
		return ' ';
    }
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0){
			return 0;
		}
		int left = 0, right = nums.size() - 1, lo = 0, hi = 0;
		while (left <= right){
			hi = left + (right - left) / 2;
			if (nums[hi] <= target){
				left = hi + 1;
			}
			else {
				right = hi - 1;
			}
		}
		hi = left;
		if (right >= 0 && nums[right] != target){
			return 0;
		}
		left = 0, right = nums.size() - 1;
		while (left <= right){
			lo = left + (right - left) / 2;
			if (nums[lo] >= target){
				right = lo - 1;
			}
			else {
				left = lo + 1;
			}
		}
		lo = right;
		return hi - lo - 1;
    }
	int missingNumber(vector<int>& nums) {
		int res = 0, numsLen = nums.size();
		for (int i = 0; i < numsLen; i++){
			res ^= nums[i];
			res ^= i;
		}
		res ^= numsLen;
		return res;
    }
};
int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "abs";
	string b = "this apple is sour";
	vector<int> inpt1 = { 0,1,2,3,4,5,6,7,9 };
	vector<int> inpt2 = { 2, 2, 2 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8}
	};
	vector<vector<char>> board = {{'a'}};
	vector<vector<int>> equations = { {9, 7}, {1, 9}, {3, 1} };
	vector<double> val = { 2.0, 3.0 };
	vector<string> qur = { " /","/ " };
	mySolution.missingNumber(inpt1);
	return 0;
}
#endif

// 图解算法数据结构--双指针
#if false
class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Node {
	public:
		int val;
		Node* left;
		Node* right;

		Node() {}

		Node(int _val) {
			val = _val;
			left = NULL;
			right = NULL;
		}

		Node(int _val, Node* _left, Node* _right) {
			val = _val;
			left = _left;
			right = _right;
		}
	};
	ListNode* deleteNode(ListNode* head, int val) {
		ListNode* root = new ListNode(-1);
		root->next = head;
		ListNode* cur = root;
		while (cur->next != nullptr){
			if (cur->next->val == val){
				cur->next = cur->next->next;
				break;
			}
			cur = cur->next;
		}
		cur = root->next;
		delete root;
		return cur;
    }
	vector<int> exchange(vector<int>& nums) {
		vector<int> res(nums);
		int leftCur = 0, rightCur = nums.size() - 1, numsLen = nums.size();
		for (int i = 0; i < numsLen; i++){
			if (nums[i] & 1){
				res[leftCur++] = nums[i];
			}
			else {
				res[rightCur--] = nums[i];
			}
		}
		return res;
    }
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* root = new ListNode(-1);
		root->next = head;
		ListNode* fastCur = root;
		ListNode* slowCur = head;
		while (k--){
			fastCur = fastCur->next;
		}
		while (fastCur->next != nullptr){
			slowCur = slowCur->next;
			fastCur = fastCur->next;
		}
		return slowCur;
    }
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
		return root->next;
    }
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* aCur = headA;
		ListNode* bCur = headB;
		while (aCur != bCur){
			aCur = aCur == nullptr ? headB : aCur->next;
			bCur = bCur == nullptr ? headA : bCur->next;
		}
		return aCur;
    }
	vector<int> twoSum(vector<int>& nums, int target) {
		int numsLen = nums.size();
		int leftCur = 0, rightCur = numsLen - 1;
		while (leftCur < rightCur){
			int sum = nums[leftCur] + nums[rightCur];
			if (sum > target){
				rightCur--;
			}
			else if (sum < target){
				leftCur++;
			}
			else {
				return {nums[leftCur], nums[rightCur]};
			}
		}
		return {};
    }
	string reverseWords(string s) {
		string res;
		int sLen = s.size();
		int left = 0, right = 0;
		while (sLen > 0 && s[sLen - 1] == ' '){
			sLen--;
		}
		while (right < sLen){
			while (right < sLen && s[right] == ' '){
				right++;
			}
			left = right;
			while (right < sLen && s[right] != ' '){
				right++;
			}
			res = s.substr(left, right - left) + ' ' + res;
		}
		res.pop_back();
		return res;
    }
};
int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "abs";
	string b = "this apple is sour";
	vector<int> inpt1 = { 0,1,2,3,4,5,6,7,9 };
	vector<int> inpt2 = { 2, 2, 2 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8}
	};
	vector<vector<char>> board = {{'a'}};
	vector<vector<int>> equations = { {9, 7}, {1, 9}, {3, 1} };
	vector<double> val = { 2.0, 3.0 };
	vector<string> qur = { " /","/ " };
	mySolution.reverseWords("    ");
	return 0;
}
#endif

// 图解算法数据结构--位运算
#if false
class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Node {
	public:
		int val;
		Node* left;
		Node* right;

		Node() {}

		Node(int _val) {
			val = _val;
			left = NULL;
			right = NULL;
		}

		Node(int _val, Node* _left, Node* _right) {
			val = _val;
			left = _left;
			right = _right;
		}
	};
	int hammingWeight(uint32_t n) {
		int res = 0;
		uint32_t cur = 1;
		for (int i = 0; i < 32; i++){
			if (cur & n){
				res++;
			}
			cur <<= 1;
		}
		return res;
    }
	vector<int> singleNumbers(vector<int>& nums) {
		int tmp = 0;
		for (int& num : nums){
			tmp ^= num;
		}
		int x = 0, y = 0;
		int cur = 1;
		while ((cur & tmp) == 0){
			cur <<= 1;
		}
		for (int& num : nums){
			if (num & cur){
				x ^= num;
			}
			else{
				y ^= num;
			}
		}
		return {x, y};
    }
	int singleNumber(vector<int>& nums) {
		int lo = 0, hi = 0;
		for (int& num : nums){
			lo = lo ^ num & ~hi;
			hi = hi ^ num & ~lo;
		}
		return lo;
    }
	int add(int a, int b) {
		while (b != 0){
			int c = (unsigned int)(a & b) << 1;
			a ^= b;
			b = c;
		}
		return a;
    }
};
int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "abs";
	string b = "this apple is sour";
	vector<int> inpt1 = { 0,1,2,3,4,5,6,7,9 };
	vector<int> inpt2 = { 2, 2, 2 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8}
	};
	vector<vector<char>> board = {{'a'}};
	vector<vector<int>> equations = { {9, 7}, {1, 9}, {3, 1} };
	vector<double> val = { 2.0, 3.0 };
	vector<string> qur = { " /","/ " };
	mySolution;
	return 0;
}
#endif

// 图解算法数据结构--数学
#if false
class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Node {
	public:
		int val;
		Node* left;
		Node* right;

		Node() {}

		Node(int _val) {
			val = _val;
			left = NULL;
			right = NULL;
		}

		Node(int _val, Node* _left, Node* _right) {
			val = _val;
			left = _left;
			right = _right;
		}
	};
	int cuttingRopeI(int n) {
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		for (int i = 2; i <= n; i++){
			for (int j = 1; j < i; j++){
				dp[i] = max(max(dp[i], dp[j] * (i - j)), (i - j) * j);
			}
		}
		return dp[n];
    }
	int cuttingRope(int n) {
		if (n < 4){
			return n - 1;
		}
		int b = n % 3, mod = 1000000007;
		long rem = 1, x = 3;
		for (int a = n / 3 - 1; a > 0; a /= 2){
			if (a & 1){
				rem = (rem * x) % mod;
			}
			x = x * x % mod;
		}
		if (b == 0){
			return (int)(rem * 3 % mod);
		}
		if (b == 1){
			return (int)(rem * 4 % mod);
		}
		return (int)(rem * 6 % mod);
    }
	int majorityElement(vector<int>& nums) {
		int cnt = 0, res = -1;
		for (int& num : nums){
			if (cnt == 0 || res == num){
				res = num;
				cnt++;
			}
			else{
				cnt--;
			}
		}
		return res;
    }
	int countDigitOne(int n) {
		int countr = 0;
		for (long long i = 1; i <= n; i *= 10) {
			long long divider = i * 10;
			countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
		}
		return countr;
	}
	int findNthDigit(int n) {
		int digit = 1;
		long start = 1, cnt = 9;
		while (n > cnt){
			n -= cnt;
			start *= 10;
			digit++;
			cnt = digit * start * 9;
		}
		long num = start + (n - 1) / digit;
		return to_string(num)[(n - 1) % digit] - '0';
    }
	vector<vector<int>> findContinuousSequence(int target) {
		int leftCur = 1, rightCur = 1, sum = 0;
		vector<vector<int>> res;
		while (leftCur + rightCur <= target + 1){
			if (sum < target){
				sum += rightCur++;
			}
			else if (sum > target){
				sum -= leftCur++;
			}
			else {
				vector<int> tmp(rightCur - leftCur, 0);
				for (int i = leftCur; i < rightCur; i++){
					tmp[i - leftCur] = i;
				}
				res.push_back(tmp);
				sum += rightCur++;
			}
		}
		return res;
    }
	int lastRemaining(int n, int m) {
        int x = 0;
        for (int i = 2; i <= n; i++) {
            x = (x + m) % i;
        }
        return x;
    }
	vector<int> constructArr(vector<int>& nums) {
		int numsLen = nums.size();
		if (numsLen == 1){
			return {0};
		}
		if (numsLen == 0){
			return {};
		}
		vector<int> res(numsLen, 0);
		vector<int> left(nums), right(nums);
		for (int i = 1; i < numsLen; i++){
			left[i] *= left[i - 1];
			right[numsLen - i - 1] *= right[numsLen - i];
		}
		for (int i = 0; i < numsLen; i++){
			int leftVal = i == 0 ? 1 : left[i - 1];
			int rightVal = i == numsLen - 1 ? 1 : right[i + 1];
			res[i] = leftVal * rightVal;
		}
		return res;
    }
};
int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "abs";
	string b = "this apple is sour";
	vector<int> inpt1 = { 1, 2, 3, 4, 5 };
	vector<int> inpt2 = { 2, 2, 2 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8}
	};
	vector<vector<char>> board = {{'a'}};
	vector<vector<int>> equations = { {9, 7}, {1, 9}, {3, 1} };
	vector<double> val = { 2.0, 3.0 };
	vector<string> qur = { " /","/ " };
	mySolution.constructArr(inpt1);
	return 0;
}
#endif

// 图解算法数据结构--模拟
#if false
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int rolSize = matrix.size();
		if (rolSize == 0){
			return {};
		}
		int colSize = matrix[0].size();
		if (colSize == 0){
			return {};
		}
		int cnt = rolSize * colSize;
		int rolZero = 0, colZero = 0, rolCur = 0, colCur = 0;
		vector<int> res(cnt, 0);
		int cur = 0;
		while (cur < cnt){
			while (cur < cnt && colCur < colSize){
				res[cur++] = matrix[rolCur][colCur++];
			}
			rolZero++;
			rolCur = rolZero;
			colCur = colSize - 1;
			while (cur < cnt && rolCur < rolSize){
				res[cur++] = matrix[rolCur++][colCur];
			}
			colSize--;
			rolCur = rolSize - 1;
			colCur = colSize - 1;
			while (cur < cnt && colCur >= colZero){
				res[cur++] = matrix[rolCur][colCur--];
			}
			rolSize--;
			rolCur = rolSize - 1;
			colCur = colZero;
			while (cur < cnt && rolCur >= rolZero){
				res[cur++] = matrix[rolCur--][colCur];
			}
			colZero++;
			rolCur = rolZero;
			colCur = colZero;
		}
		return res;
    }
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int numsLen = pushed.size();
		if (numsLen == 0){
			return true;
		}
		stack<int> stk;
		int pushCur = 0, popCur = 0;
		while (popCur < numsLen){
			while (stk.empty() || (pushCur < numsLen && stk.top() != popped[popCur])){
				stk.push(pushed[pushCur++]);
			}
			while (!stk.empty() && stk.top() == popped[popCur]){
				stk.pop();
				popCur++;
			}
			if (!stk.empty() && pushCur == numsLen && popCur != numsLen){
				return false;
			}
		}
		return true;
    }
	struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
	void destoryList(ListNode*& root){
        if (root == nullptr){
            return;
        }
        destoryList(root->next);
        delete root;
        root = nullptr;
        return;
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
};
int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "abs";
	string b = "this apple is sour";
	vector<int> inpt1 = { 0, 2, 5, 7, 9 };
	vector<int> inpt2 = { 4, 3, 5, 1, 2 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8}
	};
	vector<vector<char>> board = {{'a'}};
	vector<vector<int>> equations = { {9, 7}, {1, 9}, {3, 1} };
	vector<double> val = { 2.0, 3.0 };
	vector<string> qur = { " /","/ " };
	Solution::ListNode* node = mySolution.vectorToListNode(inpt1);
	mySolution.destoryList(node);
	try {
		mySolution.validateStackSequences(inpt1, inpt2);
	}
	catch (int err){
		;
	}
	return 0;
}
#endif

// 腾讯
#if true
class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
	};
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res(2);
		unordered_map<int, int> numSet;
		for (int i = 0; i < nums.size(); i++){
			int& it = nums[i];
			if (numSet.count(target - it)){
				res[0] = i;
				res[1] = numSet[target - it];
				return res;
			}
			numSet[it] = i;
		}
		return {};
    }
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int numsLen1 = nums1.size(), numsLen2 = nums2.size();
		int cnt = (numsLen1 + numsLen2) / 2;
		int nums1Cur = 0, nums2Cur = 0;
		int tmp = 0;
		while (nums1Cur + nums2Cur < cnt){
			if (nums1Cur == numsLen1){
				tmp = nums2[nums2Cur++];
			}
			else if (nums2Cur == numsLen2){
				tmp = nums1[nums1Cur++];
			}
			else{
				if (nums1[nums1Cur] <= nums2[nums2Cur]){
					tmp = nums1[nums1Cur++];
				}
				else{
					tmp = nums2[nums2Cur++];
				}
			}
		}
		int tmp2 = 0;
		if (nums1Cur == numsLen1){
			tmp2 = nums2[nums2Cur++];
		}
		else if (nums2Cur == numsLen2){
			tmp2 = nums1[nums1Cur++];
		}
		else{
			if (nums1[nums1Cur] <= nums2[nums2Cur]){
				tmp2 = nums1[nums1Cur++];
			}
			else{
				tmp2 = nums2[nums2Cur++];
			}
		}
		if ((numsLen1 + numsLen2) % 2 == 1){
			return (double)tmp2;
		}
		return 0.5 * (tmp + tmp2);
    }
	string longestPalindrome(string s) {
		int sLen = s.size();
		int begin = 0, end = 0;
		for (int i = 0; i < sLen; i++){
			pair<int, int> tmp = longestPalindromeSub(s, i, i);
			if (tmp.second - tmp.first > end - begin){
				begin = tmp.first;
				end = tmp.second;
			}
			tmp = longestPalindromeSub(s, i, i + 1);
			if (tmp.second - tmp.first > end - begin){
				begin = tmp.first;
				end = tmp.second;
			}
		}
		return s.substr(begin, end - begin + 1);
    }
	pair<int, int> longestPalindromeSub(string& s, int left, int right){
		while (left >= 0 && right < s.size() && s[left] == s[right]){
			left--;
			right++;
		}
		return {left + 1, right - 1};
	}
	int myAtoi(string s) {
		int sLen = s.size();
		bool init = false;
		long long res = 0;
		int  sign = 1;
		for(char& ch : s){
			if(!init){
				if (ch == ' '){
					continue;
				}
				if (ch == '-'){
					sign = -1;
				}
				else if (isalpha(ch)){
					return 0;
				}
				else if (isdigit(ch)){
					res = ch - '0';
				}
				else if (ch == '+'){
					sign = 1;
				}
				else {
					return 0;
				}
				init = true;
				continue;
			}
			if(!isdigit(ch)){
				break;
			}
			res *= 10;
			res += ch - '0';
			if (sign > 0 && res > INT32_MAX){
				return INT32_MAX;
			}
			if (sign < 0 && res - 1 > INT32_MAX){
				return INT32_MIN;
			}
		}
		return sign * res;
    }
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0){
			return "";
		}
		int lim = INT32_MAX;
		int cur = 0;
		for (int i = 0; i < strs.size(); i++){
			string& str = strs[i];
			if (str.size() < lim){
				lim = str.size();
				cur = i;
			}
		}
		string res;
		for (int i = 0; i < lim; i++){
			char ch = strs[cur][i];
			res.push_back(ch);
			for (string& str : strs){
				if (str[i] != ch){
					res.pop_back();
					return res;
				}
			}
		}
		return res;
    }
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		size_t numsLen = nums.size();
        if (numsLen < 3){
            return res;
        }
		for (size_t i = 0; i < numsLen - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			size_t k = numsLen - 1;
			for (size_t j = i + 1; j < numsLen - 1; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}
				while (k > j && nums[i] + nums[j] + nums[k] > 0) {
					k--;
				}
				if (j == k) {
					break;
				}
				if (nums[i] + nums[j] + nums[k] == 0) {
					res.emplace_back(vector<int>({ nums[i], nums[j], nums[k] }));
				}
			}
		}
		return res;
	}
	int threeSumClosest(vector<int>& nums, int target) {//最接近的三数之和
		size_t numsLen = nums.size();
		sort(nums.begin(), nums.end());
		int diff = INT32_MAX;
		int res = -1;
		for (size_t i = 0; i < numsLen; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			size_t leftCur = i + 1, rightCur = numsLen - 1;
			while (leftCur < rightCur) {
				int sum = nums[i] + nums[leftCur] + nums[rightCur];
				if (sum == target) {
					return target;
				}
				if (abs(sum - target) < diff) {
					diff = abs(sum - target);
					res = sum;
				}
				if (sum > target) {
					size_t rightCurBak = rightCur - 1;
					while (rightCurBak > leftCur && nums[rightCur] == nums[rightCurBak]) {
						rightCurBak--;
					}
					rightCur = rightCurBak;
				}
				else {
					size_t leftCurBak = leftCur + 1;
					while (leftCurBak < rightCur && nums[leftCur] == nums[leftCurBak]) {
						leftCurBak++;
					}
					leftCur = leftCurBak;
				}
			}
		}
		return res;
	}
	bool isValid(string s) {
		stack<char> stk;
		for (char& ch : s){
			if (ch == '(' || ch == '[' || ch == '{'){
				stk.push(ch);
				continue;
			}
			if (stk.empty()){
				return false;
			}
			char top = stk.top();
			if (top == '[' && ch == ']'){
				stk.pop();
				continue;
			}
			if (top == '(' && ch == ')'){
				stk.pop();
				continue;
			}
			if (top == '{' && ch == '}'){
				stk.pop();
				continue;
			}
			return false;
		}
		return stk.empty();
    }
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()){
            return 0;
        }
		sort(nums.begin(), nums.end());
		size_t left = 1, right = 1;
		while (right < nums.size()){
			if (nums[right] == nums[right - 1]){
				right++;
				continue;
			}
			nums[left++] = nums[right++];
		}
		nums = vector<int>(nums.begin(), nums.begin() + left);
		return left;
    }
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int res = 0;
		while (left < right){
			res = max(res, (right - left) * min(height[left], height[right]));
			if (height[left] < height[right]){
				left++;
			}
			else{
				right--;
			}
		}
		return res;
    }
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0"){
			return "0";
		}
		int cur1 = num1.size() - 1, cur2 = num2.size() - 1;
		unordered_map<int, string> chMap;
		for (char& ch : num2){
			int num = ch - '0';
			if (chMap.count(num) < 1 && num != 0 && num != 1){
				chMap[num] = multiplyMUL(num1, num);
			}
		}
		string subfix = "", res;
		while(cur2 > -1){
			string tmp;
			if (chMap.count(num2[cur2] - '0') > 0){
				tmp = chMap[num2[cur2] - '0'] + subfix;
			}
			else if (num2[cur2] == '0'){
				subfix.push_back('0');
				cur2--;
				continue;
			}
			else{
				tmp = num1 + subfix;
			}
			res = multiplyADD(res, tmp);
			subfix.push_back('0');
			cur2--;
		}
		return res.size() == 0 ? "0" : res;
    }
	string multiplyADD(string& str1, string& str2){
		string res;
		int cur1 = str1.size() - 1, cur2 = str2.size() - 1;
		int remain = 0;
		while (cur1 > -1 || cur2 > -1){
			int digit1 = cur1 < 0 ? 0 : str1[cur1] - '0';
			int digit2 = cur2 < 0 ? 0 : str2[cur2] - '0';
			res.push_back((digit1 + digit2 + remain) % 10 + '0');
			remain = (digit1 + digit2 + remain) / 10;
			cur1--;
			cur2--;
		}
		if (remain != 0){
			res.push_back('0' + remain);
		}
		// reverse(res.begin(), res.end());
		return res;
	}
	string multiplyMUL(string str, int n){
		int cur = str.size() - 1;
		int remain = 0;
		while (cur > -1){
			int digit = str[cur] - '0';
			str[cur] = '0' + (digit * n + remain) % 10;
			remain = (digit * n + remain) / 10;
			cur--;
		}
		if (remain != 0){
			str.insert(str.begin(), '0' + remain);
		}
		return str;
	}
	void reverseString(vector<char>& s) {
		int left = 0, right = s.size() - 1;
		while(left < right){
			swap(s[left++], s[right--]);
		}
		return;
    }
	string reverseWords(string s) {
		stringstream ss(s);
		string res, tmp;
		while(ss >> tmp){
			reverseWordsSub(tmp);
			res = res + tmp + ' ';
		}
		res.pop_back();
		return res;
    }
	void reverseWordsSub(string& s) {
		int left = 0, right = s.size() - 1;
		while(left < right){
			swap(s[left++], s[right--]);
		}
		return;
    }
	vector<int> productExceptSelf(vector<int>& nums) {
		int numsLen = nums.size();
		vector<int> left(numsLen, 1), right(numsLen, 1), res(numsLen, 0);
		for (int i = 1; i < numsLen; i++){
			left[i] = left[i - 1] * nums[i - 1];
			right[numsLen - i - 1] = right[numsLen - i] * nums[numsLen - i];
		}
		for (int i = 0; i < numsLen; i++){
			res[i] = left[i] * right[i];
		}
		return res;
    }
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> numSet;
		for (int& num : nums){
			if (numSet.count(num) > 0){
				return true;
			}
			numSet.emplace(num);
		}
		return false;
    }
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int rolSize = matrix.size();
		if (rolSize == 0){
			return {};
		}
		int colSize = matrix[0].size();
		if (colSize == 0){
			return {};
		}
		int cnt = rolSize * colSize;
		int rolZero = 0, colZero = 0, rolCur = 0, colCur = 0;
		vector<int> res(cnt, 0);
		int cur = 0;
		while (cur < cnt){
			while (cur < cnt && colCur < colSize){
				res[cur++] = matrix[rolCur][colCur++];
			}
			rolZero++;
			rolCur = rolZero;
			colCur = colSize - 1;
			while (cur < cnt && rolCur < rolSize){
				res[cur++] = matrix[rolCur++][colCur];
			}
			colSize--;
			rolCur = rolSize - 1;
			colCur = colSize - 1;
			while (cur < cnt && colCur >= colZero){
				res[cur++] = matrix[rolCur][colCur--];
			}
			rolSize--;
			rolCur = rolSize - 1;
			colCur = colZero;
			while (cur < cnt && rolCur >= rolZero){
				res[cur++] = matrix[rolCur--][colCur];
			}
			colZero++;
			rolCur = rolZero;
			colCur = colZero;
		}
		return res;
    }
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int rolSize = n, colSize = n, rolZero = 0, colZero = 0;
		int rolCur = 0, colCur = 0;
		int num = 0;
		while (num < n * n){
			while (num < n * n && colCur < colSize){
				res[rolCur][colCur++] = ++num;
			}
			rolZero++;
			rolCur = rolZero;
			colCur = colSize - 1;
			while (num < n * n && rolCur < rolSize){
				res[rolCur++][colCur] = ++num;
			}
			colSize--;
			rolCur = rolSize - 1;
			colCur = colSize - 1;
			while (num < n * n && colCur >= colZero){
				res[rolCur][colCur--] = ++num;
			}
			rolSize--;
			rolCur = rolSize - 1;
			colCur = colZero;
			while (num < n * n && rolCur >= rolZero){
				res[rolCur--][colCur] = ++num;
			}
			colZero++;
			rolCur = rolZero;
			colCur = colZero;
		}
		return res;
    }
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> res(nums1);
		int cur1 = 0, cur2 = 0, cur = 0;
		while (cur1 < m || cur2 < n){
			if (cur1 == m){
				res[cur++] = nums2[cur2++];
			}
			else if (cur2 == n){
				res[cur++] = nums1[cur1++];
			}
			else if (nums1[cur1] < nums2[cur2]){
				res[cur++] = nums1[cur1++];
			}
			else{
				res[cur++] = nums2[cur2++];
			}
		}
		nums1 = res;
		return;
    }
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr){
			return head;
		}
		ListNode* newHead = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newHead;
    }
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode;
		ListNode* cur = head;
		int remain = 0;
		while (l1 != nullptr || l2 != nullptr || remain != 0){
			int num1 = l1 == nullptr ? 0 : l1->val;
			int num2 = l2 == nullptr ? 0 : l2->val;
			l1 = l1 == nullptr ? nullptr : l1->next;
			l2 = l2 == nullptr ? nullptr : l2->next;
			cur->next = new ListNode;
			cur = cur->next;
			cur->val = (num1 + num2 + remain) % 10;
			remain = (num1 + num2 + remain) / 10;
		}
		return head->next;
    }
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode;
		ListNode* cur = head;
		while (l1 !=nullptr || l2 != nullptr){
			if (l1 == nullptr){
				cur->next = l2;
				l2 = l2->next;
				break;
			}
			else if(l2 == nullptr){
				cur->next = l1;
				l1 = l1->next;
				break;
			}
			else if (l1->val < l2->val){
				cur->next = l1;
				l1 = l1->next;
			}
			else{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
			cur->next = nullptr;
		}
		return head->next;
    }
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0){
			return nullptr;
		}
		vector<ListNode*> tmp;
		while(lists.size() > 1){
			tmp.clear();
			for (int i = 0; i < lists.size(); i += 2){
				ListNode* l1 = lists[i];
				ListNode* l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
				tmp.emplace_back(mergeTwoLists(l1, l2));
			}
			lists = tmp;
		}
		return lists[0];
    }
	ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k){
            return head;
        }
        int cnt = 0;
        ListNode* cur = head;
        ListNode* tail = head;
        while(cur){//找结点数量
            cnt++;
            tail = cur;
            cur = cur->next;
        }
        if (cnt == 1){
            return head;
        }
        k = k % cnt;
        if (k == 0){
            return head;
        }
        cnt = cnt - k;
        cur = head;
        ListNode* last = cur;
        for(int i = 0; i<cnt; i++){
            last = cur;
            cur = cur->next;
        }
        last->next = 0;
        tail->next = head;
        return cur;
    }
	bool hasCycle(ListNode *head) {
		ListNode* slowCur = head;
		ListNode* fastCur = head;
		while (fastCur != nullptr && fastCur->next != nullptr){
			slowCur = slowCur->next;
			fastCur = fastCur->next->next;
			if (slowCur == fastCur){
				return true;
			}
		}
		return false;
    }
	ListNode *detectCycle(ListNode *head) {
        ListNode* slow, * fast;
        slow = fast = head;
        int num = 0;
        while(slow&&fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
            num++;
            if (slow == fast){//获取到了链长
                slow = fast = head;
                for(int i = 0; i<num; i++){
                        fast = fast->next;
                    }
                while(1){
                    if(slow == fast){
                        break;
                    }
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
		ListNode* curB = headB;
		while (curA !=  curB){
			curA = curA == nullptr ? headB : curA->next;
			curB = curB == nullptr ? headA : curB->next;
		}
		return curA;
    }
	void deleteNode(ListNode* node) {
        ListNode* cur = node;
		ListNode* last = node;
		while (cur->next != nullptr){
			cur->val = cur->next->val;
			last = cur;
			cur = cur->next;
		}
		last->next = nullptr;
		delete cur;
		return;
    }
	bool canWinNim(int n) {//Nim 游戏
		return n % 4 != 0;
    }
};
int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "abs";
	string b = "this apple is sour";
	vector<int> inpt1 = { -1, 0, 1, 2, -1, -4 };
	vector<int> inpt2 = { 2, 4 };
	vector<int> inpt3 = { 1, 2, 1 };
	vector<vector<int>> nums = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	vector<vector<char>> board = {{'a'}};
	vector<vector<int>> equations = { {9, 7}, {1, 9}, {3, 1} };
	vector<double> val = { 2.0, 3.0 };
	vector<string> qur = { " /","/ " };
	mySolution;
	return 0;
}
#endif