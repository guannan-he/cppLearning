#if 1

#if 1
#include <iostream>
#include "ch03.h"
using namespace std;
#endif



#if 1









int main(int argc, char* argv[]) {
	node<char> newEle;
	newEle.item = 'c';
	cLinearList<char> list;
	cLinearList<char>* list2 = new cLinearList<char>;
	(*list2).frontAdd('5');
	delete list2;
	list.rearAdd('a');
	list.rearAdd('b');
	list.frontAdd('c');
	list.rearAdd('e');
	list.rearAdd('f');
	cout << list.frontSub() << endl;
	cout << list.frontSub() << endl;
	list.rearAdd('f');
	list.frontAdd('f');
	cout << list.rearSub() << endl;
	return 0;
}
#endif











#if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif

#endif