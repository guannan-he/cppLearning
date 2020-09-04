#ifndef _CH06_HEADER_
#define _CH06_HEADER_
#include <iostream>

using namespace std;

template<class NODETYPE>
class treeNode {//node
public:
	NODETYPE item;
	bool isData = false;
	treeNode<NODETYPE>* L = 0;//��
	treeNode<NODETYPE>* R = 0;//��
	treeNode<NODETYPE>* patent = 0;//������ְ�
	bool canDelete() const;
};

template<class NODETYPE>
bool treeNode<NODETYPE>::canDelete() const {//�жϽڵ��ܲ���ɾ
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
	int depth;//���ڵ�Ϊ1��
	int nodeCnt = 0;
};
/// <summary>
/// //////////////////////////////////////////////////////////////////////////////////////
/// </summary>
/// <typeparam name="TREETYPE"></typeparam>
template<class TREETYPE>
cTree<TREETYPE>::cTree() {//�����ɸ��ڵ�
	rootNode = 0;
	depth = 0;
	return;
}

template<class TREETYPE>
cTree<TREETYPE>::cTree(TREETYPE val) {
	//cTree<TREETYPE>::cTree();//���������ch03
	rootNode = new treeNode<TREETYPE>;
	depth = 1;
	rootNode->item = val;
	rootNode->isData = true;
	nodeCnt++;
	return;
}

template<class TREETYPE>
cTree<TREETYPE>::~cTree() {//����
	return;
}

template<class TREETYPE>
bool cTree<TREETYPE>::canDelete() const {//�жϱ����ܲ���ɾ
	if (this->rootNode)
		return rootNode->canDelete();//ֻ��һ���ڵ�
	else 
		return true;//û�нڵ�
}

template<class TREETYPE>
int cTree<TREETYPE>::treeDepth()const {
	return depth;
}

template<class TREETYPE>
void cTree<TREETYPE>::preOrder(const treeNode<TREETYPE>* ptr) const {//�ݹ�ǰ����ʣ�����->��->�ң�
	if (!ptr) {
		return;
	}
	else if(ptr->isData){//������
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
void cTree<TREETYPE>::inOrder(const treeNode<TREETYPE>*) const {//�ݹ�������ʣ���->����->�ң�
	if (!ptr) {
		return;
	}
	else if (ptr->isData) {//������
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
void cTree<TREETYPE>::postOrder(const treeNode<TREETYPE>*) const {//�ݹ������ʣ���->��->������
	if (!ptr) {
		return;
	}
	else if (ptr->isData) {//������
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