#ifndef _CH12_HEADER_
#define _CH12_HEADER_

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
	CGoodDynamicMatrix& operator= (const CGoodDynamicMatrix&);//��ֵ���������أ�������ݿ���
	friend ostream& operator << (ostream&, const CGoodDynamicMatrix&);
private:
	char** matrix;
	char** newDynamicMatrix(int, int);
	void fullCopy(const CGoodDynamicMatrix&);
};

#endif