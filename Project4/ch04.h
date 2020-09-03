#ifndef _CH04_HEADER_
#define _CH04_HEADER_


#include <iostream>
#include <string>

using namespace std;



template<class NODETYPE>
struct node {
	NODETYPE val = 0;
	node* next = 0;
};

template<class CLASSTYPE>
class cStack {
public:
	cStack();
	~cStack();
	void push(CLASSTYPE);
	CLASSTYPE pop();
	CLASSTYPE view();
	void viewALL();
	int cnt();
private:
	node<CLASSTYPE>* rootNode;
	int member = 0;
};
template<class CLASSTYPE>
cStack<CLASSTYPE>::cStack() {
	rootNode = new node<CLASSTYPE>;
	return;
}
template<class CLASSTYPE>
cStack<CLASSTYPE>::~cStack() {
	node<CLASSTYPE>* tmp;
	while (member) {
		tmp = rootNode->next;
		rootNode->next = tmp->next;
		delete tmp;
		member--;
	}
	delete rootNode;
	return;
}
template<class CLASSTYPE>
void cStack<CLASSTYPE>::push(CLASSTYPE cls) {//Í·Ìí¼Ó
	node<CLASSTYPE>* newNode = new node<CLASSTYPE>;
	newNode->val = cls;
	newNode->next = rootNode->next;
	rootNode->next = newNode;
	member++;
	return;

}
template<class CLASSTYPE>
CLASSTYPE cStack<CLASSTYPE>::pop() {//Í·É¾³ý
	node<CLASSTYPE>* tmp = rootNode->next;
	CLASSTYPE val = tmp->val;
	rootNode->next = tmp->next;
	delete tmp;
	member--;
	return val;
}

template<class CLASSTYPE>
CLASSTYPE cStack<CLASSTYPE>::view() {
	return rootNode->next->val;
}

template<class CLASSTYPE>
int cStack<CLASSTYPE>::cnt() {
	return member;
}
template<class CLASSTYPE>
void cStack<CLASSTYPE>::viewALL() {
	node<CLASSTYPE>* tmp = rootNode;
	while (tmp->next) {
		cout << tmp->val << endl;
		tmp = tmp->next;
	}
	cout << tmp->val << endl;
	return;
}


double inversePoland(string&);
cStack<char>* middle2Tail(string&);


#endif