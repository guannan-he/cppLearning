#if 0

#if 1
#include <iostream>
#include <new>
//#include <tree>
#include "ch10_header.h"

using namespace std;
#endif



#if 0









int main(int argc, char* argv[]) {
	cStock* hgn = new cStock;
	cStock* hgn1 = new cStock("qianHaiKaiYuanJinYinZhuBao", 20, 1.3);
	cStock* hgn2 = new cStock;
	hgn->acquire("zhongOuShiDaiXianFengA", 20, 12.5);
	//hgn->show();
	//hgn->update(1.72);
	//hgn->show();
	hgn->buy(15, 18.25);
	//hgn->show();
	hgn->sell(110, 1.9);
	//hgn->show();
	//hgn1->show();
	hgn1->update(2.5);
	//hgn1->show();
	*hgn2 = *hgn;
	//hgn2->show();
	delete hgn;
	delete hgn1;
	delete hgn2;
	hgn = 0;
	hgn1 = 0;
	hgn2 = 0;
	return 0;
}
#endif











#if 1
int main(int argc, char* argv[]) {
	cStack* newPool = new cStack(20);
	char c = 'c';
	char a = 'a';
	for (int i = 0; i < 25; i++) {
		newPool->stackPush(c);
		;
	}
	newPool->stackPop(a);
	cout << a << endl;
	delete newPool;
	newPool = 0;
	return 0;
}
#endif

#endif