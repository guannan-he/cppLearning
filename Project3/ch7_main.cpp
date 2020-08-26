#if 0

#if 1
#include <iostream>
#include <fstream>
using namespace std;
#endif



#if 1
void printMatrix(int matrix[][3], int c, int r) {
	int i;
	int j;
	for (i = 0; i < c; i++) {
		for (j = 0; j < r; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	return;
}
int stepMulti(int n) {
	if (n > 1)
		return n * stepMulti(n - 1);
	return 1;
}
int main(int argc, char* argv[]) {
	int matrix[2][3] = {
		{2,3,4},
		{5,6,7}
	};
	printMatrix(matrix, 2, 3);
	cout << endl << endl;
	int n = 3;
	cout << stepMulti(n) << endl;
	return 0;
}
#endif







#if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif

#endif