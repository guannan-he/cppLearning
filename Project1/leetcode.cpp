#define NULL 0
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <list>
#include <iostream>
#include <set>
#include <numeric>
#include <algorithm>
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
		for(size_t i = 0; i < rol; i++) {
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
		while (i < numsLen && nums[i] == nums[i - 1]) {//去除开头重复
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
			for(size_t j =0 ; j < m; j++) {
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
				if (abs(num1 - num2) <= d ) {
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
		{1, 1}};
	vector<vector<int>> matrix = {
		{} };
	vector<string> wordList = { "bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb" };
	vector<string> wdLst2 = { "aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa" };
	mySolution.canReach(nums, 2);
	return 0;
}
#endif

//cookBook-字符串
#if true

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
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	string a = "10";
	string b = "1011";
	mySolution.numDecodings(a);
	return 0;
}
#endif