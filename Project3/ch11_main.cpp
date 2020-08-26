#if 1

#if 1
#include <iostream>
#include "ch11_header.h"
#include "ch4_dynamicMatrix.h"
using namespace std;
#endif



#if 1









int main(int argc, char* argv[]) {
	cTime timeNow(23, 58, 58);
	timeNow.resetTime();
	cTime firstTime(23, 59, 59);
	cTime secondTime(23, 59, 59);
	//cTime tmp = cTime(23, 59, 58);
	cTime sumTime = firstTime + secondTime;
	sumTime.show();
	sumTime = sumTime + cTime(0, 0, 2);
	sumTime.show();
	sumTime = sumTime - cTime(0, 0, 2);
	sumTime.show();
	sumTime += cTime(0, 0, 2);
	sumTime.show();
	sumTime -= cTime(0, 0, 2);
	sumTime.show();
	++sumTime;
	sumTime.show();
	cout << sumTime << endl;
	//sumTime << cout << endl;
	sumTime.show();
	//timeNow.show();
	CdynamicMatrix* newMatrix = new CdynamicMatrix(2, 3);
	newMatrix->matrix[0][0] = 'a';
	cout << *newMatrix[0][0] << endl;
	*newMatrix[0][1] = 'v';
	cout << *newMatrix[0][1] << endl;
	delete newMatrix;
	cout << "Done!" << endl;
	return 0;
}
#endif











#if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif

#endif