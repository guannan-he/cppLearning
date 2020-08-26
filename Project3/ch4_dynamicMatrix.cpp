#include <ch4_dynamicMatrix.h>
CdynamicMatrix::CdynamicMatrix(int i, int j) {
	colum = i;
	row = j;
	matrix = newDynamicMatrix(colum, row);
}
CdynamicMatrix::CdynamicMatrix() {
	row = 1;
	colum = 1;
	matrix = newDynamicMatrix(colum, row);
}
char** CdynamicMatrix::newDynamicMatrix(int i, int j) {
	int k = 0;
	char** mtr = new char* [i];// [j] ;
	for (k = 0; k < i; k++) {
		char* tmp = new char[j];
		mtr[k] = tmp;
	}
	return mtr;
}
CdynamicMatrix::~CdynamicMatrix() {
	deleteDynamicMatrix();
	return;
}
void CdynamicMatrix::deleteDynamicMatrix() {
	int k = 0;
	for (k = 0; k < colum; k++) {
		delete[] matrix[k];
		matrix[k] = 0;
	}
	delete[] matrix;
	matrix = 0;
	return;
}char* CdynamicMatrix::operator [] (int i) {
	return matrix[i];
}