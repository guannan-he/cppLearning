#ifndef _DYNAMIC_MATRIX_
#define _DYNAMIC_MATRIX_
class CdynamicMatrix {
public:
	int colum;
	int row;
	char** matrix;
	CdynamicMatrix();//Ĭ��1x1
	CdynamicMatrix(int, int);//����ixj
	~CdynamicMatrix();
	void deleteDynamicMatrix();
	char* operator [](int);//[]����������
private:
	char** newDynamicMatrix(int, int);
};
#endif
