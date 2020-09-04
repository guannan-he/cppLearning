#ifndef _CH06_HEADER_
#define _CH06_HEADER_
#include <iostream>

using namespace std;

template<class NODETYPE>
class treeNode {//node
public:
	NODETYPE item;
	bool isData = false;
	treeNode<NODETYPE>* L = 0;//左
	treeNode<NODETYPE>* R = 0;//右
	treeNode<NODETYPE>* patent = 0;//我是你爸爸
	bool canDelete() const;
};

template<class NODETYPE>
bool treeNode<NODETYPE>::canDelete() const {//判断节点能不能删
	return !(this->L || this->R);
}
/// <summary>
/// ////////////////////////////////////////////////////////////////////////////////////////
/// </summary>
/// <typeparam name="TREETYPE"></typeparam>
template<class TREETYPE>
class cTree {//tree
public:
	cTree();
	cTree(TREETYPE);
	~cTree();
	bool canDelete() const;
	//bool canDelete(const treeNode<TREETYPE>* ptr) const;
	int treeDepth()const;
	void preOrder(const treeNode<TREETYPE>*) const;
	void inOrder(const treeNode<TREETYPE>*) const;
	void postOrder(const treeNode<TREETYPE>*) const;


private:
	treeNode<TREETYPE>* rootNode;
	int depth;//根节点为1层
	int nodeCnt = 0;
};
/// <summary>
/// //////////////////////////////////////////////////////////////////////////////////////
/// </summary>
/// <typeparam name="TREETYPE"></typeparam>
template<class TREETYPE>
cTree<TREETYPE>::cTree() {//不生成根节点
	rootNode = 0;
	depth = 0;
	return;
}

template<class TREETYPE>
cTree<TREETYPE>::cTree(TREETYPE val) {
	//cTree<TREETYPE>::cTree();//错误分析见ch03
	rootNode = new treeNode<TREETYPE>;
	depth = 1;
	rootNode->item = val;
	rootNode->isData = true;
	nodeCnt++;
	return;
}

template<class TREETYPE>
cTree<TREETYPE>::~cTree() {//销毁
	return;
}

template<class TREETYPE>
bool cTree<TREETYPE>::canDelete() const {//判断本树能不能删
	if (this->rootNode)
		return rootNode->canDelete();//只有一个节点
	else 
		return true;//没有节点
}

template<class TREETYPE>
int cTree<TREETYPE>::treeDepth()const {
	return depth;
}

template<class TREETYPE>
void cTree<TREETYPE>::preOrder(const treeNode<TREETYPE>* ptr) const {//递归前序访问（操作->左->右）
	if (!ptr) {
		return;
	}
	else if(ptr->isData){//有数据
		//operations
		cout << ptr->item << endl;
		//operations
		preOrder(ptr->L);
		preOrder(ptr->R);
		return;
	}
	else {
		return;
	}
}

template<class TREETYPE>
void cTree<TREETYPE>::inOrder(const treeNode<TREETYPE>*) const {//递归中序访问（左->操作->右）
	if (!ptr) {
		return;
	}
	else if (ptr->isData) {//有数据
		preOrder(ptr->L);
		//operations
		cout << ptr->item << endl;
		//operations
		preOrder(ptr->R);
		return;
	}
	else {
		return;
	}
	return;
}

template<class TREETYPE>
void cTree<TREETYPE>::postOrder(const treeNode<TREETYPE>*) const {//递归后序访问（左->右->操作）
	if (!ptr) {
		return;
	}
	else if (ptr->isData) {//有数据
		preOrder(ptr->L);
		preOrder(ptr->R);
		//operations
		cout << ptr->item << endl;
		//operations
		return;
	}
	else {
		return;
	}
	return;
}

//template<class TREETYPE>



/*
template<class TREETYPE>
template<class TREETYPE>
template<class TREETYPE>
template<class TREETYPE>
*/
#endif