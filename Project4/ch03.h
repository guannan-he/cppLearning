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
	friend ostream& operator<< <IT> (ostream&, cLinearList<IT>&);//��ԪҪ��ģ���ʶ
private:
	node<IT>* rootNode;//ͷֻ�����ַ
	node<IT>* tailNode;
	int member = 0;
};


template<class IT>
cLinearList<IT>::cLinearList() {//���ã�������һ��û���õĸ��ڵ�
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
	node<IT>* tmp = rootNode->next;
	while (member) {
		rootNode->next = tmp->next;
		delete tmp;
		tmp = rootNode->next;
		member--;
	}
	delete rootNode;
	return;
}
template<class IT>
int cLinearList<IT>::menberCnt() {
	return member;
}

template<class IT>
void cLinearList<IT>::frontAdd(const IT& item) {//ͷ���
	node<IT>* tmp = new node<IT>;
	tmp->item = item;
	tmp->next = rootNode->next;
	rootNode->next = tmp;
	member++;
	return;
}
template<class IT>
void cLinearList<IT>::rearAdd(const IT& item) {//β���
	tailNode->next = new node<IT>;
	tailNode = tailNode->next;
	tailNode->item = item;
	member++;
	return;
}
template<class IT>
IT& cLinearList<IT>::frontSub() {//ͷɾ��
	node<IT>* tmp = rootNode->next;
	IT val = tmp->item;
	rootNode->next = tmp->next;
	delete tmp;
	member--;
	return val;
}

template<class IT>
IT& cLinearList<IT>::rearSub() {//βɾ��
	node<IT>* tmp = rootNode;
	while (tmp->next != tailNode) {
		tmp = tmp->next;
	}
	IT val = tmp->item;
	delete tailNode;
	tailNode = tmp;
	tailNode->next = 0;
	member--;
	return val;
}

template<class IT>
ostream& operator<< (ostream& os, cLinearList<IT>& list) {
	int i = list.member;
	node<IT>* tmp = list.rootNode;
	cout << "contents:" << endl;
	while (i) {
		tmp = tmp->next;
		os << tmp << ":\t" << tmp->item << endl;
		i--;
	}
	return os;
}




#endif