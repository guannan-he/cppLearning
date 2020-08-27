#if 1

#if 1
#include <iostream>
#include "ch12_header.h"

using namespace std;
#endif



#if 0









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











#if 1
int main(int argc, char* argv[]) {
	cQueue que(3);
	//cQueue que1(que);//不可访问
	cQueue que2;
	//que2 = que;//不可访问，定义在私有
	int i = 0;
	while (que.addQueue('a' + i)) {
		cout << char('a' + i) << endl;
		i++;
	}
	char non = 'p';
	i = 0;
	while (que.subQueue(non)) {
		cout << non << endl;
		i++;
	}
	que.addQueue('a' + i);
	cout<< char('a' + i) << endl;
	que.subQueue(non);
	que.addQueue('a' + i);
	return 0;
}
#endif

#endif