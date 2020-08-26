#ifndef _DYNAMIC_MATRIX_
#define _DYNAMIC_MATRIX_
class CdynamicMatrix {
public:
	int colum;
	int row;
	char** matrix;
	CdynamicMatrix();//默认1x1
	CdynamicMatrix(int, int);//重载ixj
	~CdynamicMatrix();
	void deleteDynamicMatrix();
	char* operator [](int);//[]操作符重载
private:
	char** newDynamicMatrix(int, int);
};
#endif
