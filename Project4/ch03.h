#ifndef _CH03_HEADER_
#define _CH03_HEADER_
#include <iostream>

using namespace std;
template<class ITEM>
struct node {
	ITEM item;
	node* next = 0;
};
template<class IT>
class cLinearList {
public:
	cLinearList();
	cLinearList(IT);
	~cLinearList();
	int menberCnt();
	void frontAdd(const IT&);
	void rearAdd(const IT&);
	IT& frontSub();
	IT& rearSub();
private:
	node<IT>* rootNode;//头只保存地址
	node<IT>* tailNode;
	int member = 0;
};


template<class IT>
cLinearList<IT>::cLinearList() {//不好，多用了一个没有用的根节点
	rootNode = new node<IT>;
	rootNode->next = 0;
	tailNode = rootNode;
	return;
}
template<class IT>
cLinearList<IT>::cLinearList(IT item) {
	cLinearList<IT>::cLinearList();
	this->rearAdd(item);
	return;
}
template<class IT>
cLinearList<IT>::~cLinearList() {
	while (member) {
		frontSub();
	}
	return;
}
template<class IT>
int cLinearList<IT>::menberCnt() {
	return member;
}

template<class IT>
void cLinearList<IT>::frontAdd(const IT& item) {//头添加
	node<IT>* tmp = new node<IT>;
	rootNode->item = item;
	tmp->next = rootNode;
	rootNode = tmp;
	member++;
	return;
}
template<class IT>
void cLinearList<IT>::rearAdd(const IT& item) {//尾添加
	tailNode->next = new node<IT>;
	tailNode = tailNode->next;
	tailNode->item = item;
	member++;
	return;
}
template<class IT>
IT& cLinearList<IT>::frontSub() {//头删除
	node<IT>* tmp = rootNode;
	rootNode = rootNode->next;
	delete tmp;
	member--;
	return rootNode->item;
}

template<class IT>
IT& cLinearList<IT>::rearSub() {//尾删除
	node<IT>* tmp = rootNode;
	while (tmp->next != tailNode) {
		tmp = tmp->next;
	}
	IT val = tmp->item;
	delete tailNode;
	tailNode = tmp;
	member--;
	return val;
}

//static int member = 0;



#endif