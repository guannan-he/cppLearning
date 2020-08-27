#ifndef _CH12_HEADER_
#define _CH12_HEADER_

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
	CGoodDynamicMatrix& operator= (const CGoodDynamicMatrix&);//赋值操作符重载，深度内容拷贝
	friend ostream& operator << (ostream&, const CGoodDynamicMatrix&);
private:
	char** matrix;
	char** newDynamicMatrix(int, int);
	void fullCopy(const CGoodDynamicMatrix&);
};

#endif