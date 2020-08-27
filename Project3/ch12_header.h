#ifndef _CH12_HEADER_
#define _CH12_HEADER_
#define qSize 10
#include <iostream>

using namespace std;


class CGoodDynamicMatrix {
public:
	int colum;
	int row;
	CGoodDynamicMatrix();//默认1x1
	CGoodDynamicMatrix(int, int);//重载ixj
	CGoodDynamicMatrix(const CGoodDynamicMatrix&);//声明时复制，深度拷贝
	~CGoodDynamicMatrix();
	void deleteDynamicMatrix();
	void show() const;
	void fill(char);
	char* operator [](int);//[]操作符重载
	const char* operator [](int) const;//[]操作符重载
	CGoodDynamicMatrix& operator= (const CGoodDynamicMatrix&);//赋值操作符重载，深度内容拷贝
	friend ostream& operator << (ostream&, const CGoodDynamicMatrix&);
private:
	char** matrix;
	char** newDynamicMatrix(int, int);
	void fullCopy(const CGoodDynamicMatrix&);
};

//单向链表
typedef char ITEM;
class cQueue {
public:
	cQueue(int qs = qSize);
	~cQueue();
	bool isEmpty() const;
	bool isFull() const;
	int queueCnt() const;
	bool addQueue(const ITEM& item);
	bool subQueue(ITEM& item);
private:
	struct node {
		ITEM item;
		node* next;
	};
	const int queueSize;
	int queueMenber;
	node* queueStart;
	node* queueEnd;
	cQueue(const cQueue&):queueSize(0) {};
	cQueue& operator= (const cQueue&) {};
};
#endif