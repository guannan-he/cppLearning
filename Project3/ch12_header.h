#ifndef _CH12_HEADER_
#define _CH12_HEADER_
#define qSize 10
#include <iostream>

using namespace std;


class CGoodDynamicMatrix {
public:
	int colum;
	int row;
	CGoodDynamicMatrix();//Ĭ��1x1
	CGoodDynamicMatrix(int, int);//����ixj
	CGoodDynamicMatrix(const CGoodDynamicMatrix&);//����ʱ���ƣ���ȿ���
	~CGoodDynamicMatrix();
	void deleteDynamicMatrix();
	void show() const;
	void fill(char);
	char* operator [](int);//[]����������
	const char* operator [](int) const;//[]����������
	CGoodDynamicMatrix& operator= (const CGoodDynamicMatrix&);//��ֵ���������أ�������ݿ���
	friend ostream& operator << (ostream&, const CGoodDynamicMatrix&);
private:
	char** matrix;
	char** newDynamicMatrix(int, int);
	void fullCopy(const CGoodDynamicMatrix&);
};

//��������
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