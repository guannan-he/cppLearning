#if 0

#if 1
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <ch4_dynamicMatrix.h>
using namespace std;
#endif



#if 1
typedef struct playerInfo {
	string name = "Jane Doe";
	int age = -1;
	double weigth = -0.1;
} playerInfo;

typedef union serialNumber {
	int snInt;
	char snStr[20];
} serialNumber;

void matrix_gen(int i, int j) {
	const int x = 2;
	const int y = 2;
	char matrix[x][y];//必须在 编译之前就确定大小
}
char** matrix_new(int i, int j) {//二维动态数组创建
	int k = 0;
	char** mtr = new char*[i];// [j] ;
	for (k = 0; k < i; k++) {
		char* tmp = new char[j];
		mtr[k] = tmp;
	}
	return mtr;
}
void deleteMatrix(char** mat, int i, int j) {//释放数组
	int k = 0;
	for (k = 0; k < i; k++) {
		delete[] mat[k];
	}
	delete[] mat;
	return;
}
enum switchCase {case0, case1, case2, case3, case4};







/////////////////////////////////////////////////////////////////


int main(int argc, char* argv[]) {
	string cock;
	playerInfo meek;
	playerInfo cocker = {
		"cock",
		20,
		100.2
	};
	playerInfo* ptmeek = &meek;
	meek.name = "Jphn Doe";
	meek.age = 30;
	meek.weigth = 100.2;
	cout << ptmeek->age << endl;
	serialNumber sn1, sn2;
	sn1.snInt = 7045;
	strcpy_s((sn2.snStr), "N092");
	switchCase caseNum;
	caseNum = switchCase(2);
	//string strCaseName = (string)caseNum;
	int i = case2;
	matrix_gen(2, 2);
	playerInfo* ptmeek_1 = new playerInfo;
	char** ptMatrix = matrix_new(3, 5);
	int mtrxTri[2][2];//c风格数组
	CdynamicMatrix dyMatrix(2, 3);//类实现动态数组
	CdynamicMatrix dyMatrix1;
	CdynamicMatrix* ptDyMatrix = &dyMatrix;
	dyMatrix.matrix[0][0] = 'a';
	cout << **(dyMatrix.matrix) << endl;
	cout << (int*)"cock" << endl;
	dyMatrix.deleteDynamicMatrix();
	deleteMatrix(ptMatrix, 3, 5);//内嵌的动态数组
	delete ptmeek_1;//只能释放new出来的
	return 0;
}
#endif








#if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif













#endif