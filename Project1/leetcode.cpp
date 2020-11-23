#define NULL 0
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <list>
#include <iostream>
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
				string *cur = getID(points[i], points[j]);
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
#if true

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
};

int main(int argc, char* argv[]) {
	Solution mySolution;
	mySolution.fib(10);
	return 0;
}

#endif