#include "ch12_header.h"
#include <iostream>

using namespace std;

#if 1
CGoodDynamicMatrix::CGoodDynamicMatrix(int i, int j) {
	colum = i;
	row = j;
	matrix = newDynamicMatrix(colum, row);
}
CGoodDynamicMatrix::CGoodDynamicMatrix() {
	row = 1;
	colum = 1;
	matrix = newDynamicMatrix(colum, row);
}
char** CGoodDynamicMatrix::newDynamicMatrix(int i, int j) {
	int k = 0;
	char** mtr = new char* [i];// [j] ;
	for (k = 0; k < i; k++) {
		char* tmp = new char[j];
		mtr[k] = tmp;
	}
	return mtr;
}
CGoodDynamicMatrix::CGoodDynamicMatrix(const CGoodDynamicMatrix& source) {
	fullCopy(source);
	return;
}
CGoodDynamicMatrix::~CGoodDynamicMatrix() {
	deleteDynamicMatrix();
	return;
}
void CGoodDynamicMatrix::deleteDynamicMatrix() {
	int k = 0;
	for (k = 0; k < colum; k++) {
		delete[] matrix[k];
		matrix[k] = 0;
	}
	delete[] matrix;
	matrix = 0;
	return;
}
void CGoodDynamicMatrix::show() const{
	int i, j;
	for (i = 0; i < colum; i++) {
		for (j = 0; j < row; j++) {
			cout << "\t" << matrix[i][j];
		}
		cout << endl;
	}
}
void CGoodDynamicMatrix::fill(char c) {
	int i, j;
	for (i = 0; i < colum; i++) {
		for (j = 0; j < row; j++) {
			matrix[i][j] = c;
		}
	}
}
char* CGoodDynamicMatrix::operator [] (int i) {
	return matrix[i];
}
const char* CGoodDynamicMatrix::operator [](int i) const {
	return matrix[i];
}

CGoodDynamicMatrix& CGoodDynamicMatrix::operator= (const CGoodDynamicMatrix& source) {
	fullCopy(source);
	return *this;
}

ostream& operator<< (ostream& os, const CGoodDynamicMatrix& mtx) {
	mtx.show();
	return os;
}
void CGoodDynamicMatrix::fullCopy(const CGoodDynamicMatrix& source) {
	colum = source.colum;
	row = source.row;
	matrix = newDynamicMatrix(colum, row);
	int i, j;
	for (i = 0; i < colum; i++) {
		for (j = 0; j < row; j++) {
			matrix[i][j] = source.matrix[i][j];
		}
	}
	return;
}

#endif

#if 1
cQueue::cQueue(int qs):queueSize(qs){
	queueMenber = 0;
	queueStart = new node;
	queueEnd = queueStart;
	return;
}
cQueue::~cQueue() {
	char tmp;
	while (this->subQueue(tmp));
	return;
}
bool cQueue::isEmpty() const {
	return queueMenber == 0;
}
bool cQueue::isFull() const {
	return queueMenber == queueSize;
}
int cQueue::queueCnt() const {
	return queueMenber;
}
bool cQueue::addQueue(const ITEM& item) {
	if (isFull()) {
		return false;
	}
	else {
		queueEnd->next = new node;
		queueEnd = queueEnd->next;
		queueEnd->next = 0;
		queueEnd->item = item;
		queueMenber++;
		return true;
	}
}
bool cQueue::subQueue(ITEM& item) {
	node* tmp;
	if (isEmpty()) {
		return false;
	}
	else {
		tmp = queueStart;
		queueStart = queueStart->next;
		item = queueStart->item;
		queueMenber--;
		delete tmp;
		return true;
	}
}
#endif