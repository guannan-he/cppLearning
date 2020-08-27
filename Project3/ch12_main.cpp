#if 1

#if 1
#include <iostream>
#include "ch12_header.h"

using namespace std;
#endif



#if 1









int main(int argc, char* argv[]) {
	CGoodDynamicMatrix dm(5, 5);
	dm.fill('_');
	CGoodDynamicMatrix* dmCopy = new CGoodDynamicMatrix(dm);
	CGoodDynamicMatrix* dmCopy1 = new CGoodDynamicMatrix;
	*dmCopy1 = dm;
	dm[0][0] = '1';
	*dmCopy[0][0] = '2';
	*dmCopy1[0][0] = '3';
	cout << dm << endl;
	cout << *dmCopy << endl;
	cout << *dmCopy1 << endl;
	delete dmCopy1;
	delete dmCopy;
	return 0;
}
#endif











#if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif

#endif