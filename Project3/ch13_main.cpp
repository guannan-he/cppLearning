#if 1

#if 1
#include <iostream>
#include "ch13_header.h"
#include <string>

using namespace std;
#endif



#if 0









int main(int argc, char* argv[]) {
	cPlayer player1("cock", "sucker", true);
	cPlayer player2;
	cRatedPlayer ratPlayer1("a", "b", true, true);
	cPlayer player3(ratPlayer1);//可以用派生类初始化基类
	cPlayer* ptRatPlayer1 = &ratPlayer1;//可以用基类指针指向派生类
	player2.resetTable(true);
	cout << player1;
	cout << player2;
	return 0;
}
#endif











#if 0
int main(int argc, char* argv[]) {
	cBrassAccount hgn("hgn", "88000088", 500);
	cBrassAccount hgn1;
	cBrassPlus hgnPlus(hgn);
	cBrassAccount* ptPlus = new cBrassPlus(hgn);//可以用基类指针new派生类，可以访问派生类内容,其实是强制类型转换
	ptPlus->turnOut(800);
	delete ptPlus;//先调用派生析构，然后调用基类析构
	cBrassAccount* ptPlus1 = &hgnPlus;//可以用基类指针指向派生类
	ptPlus1->turnOut(800);
	hgnPlus.turnOut(800);
	hgnPlus.payBack(500);
	hgn.turnOut(600);
	hgn1 = hgn;
	hgn.turnIn(100);
	cout << hgn << endl;
	cout << hgnPlus << endl;
	return 0;
}
#endif



#if 0
int main(int argc, char* argv[]) {
	//cAcctABC hgn;//有纯虚拟函数的不能使用
	//cAcctABC hgn000;
	cBrassABC hgn("hgn", "0001", 100.0);
	cBrassPlusABC hgnPlus(hgn);
	hgn.viewAccount();
	cout << endl;
	hgnPlus.viewAccount();
	cout << endl;
	hgnPlus.turnIn(200);
	hgnPlus.viewAccount();
	cout << endl;
	hgnPlus.turnOut(900);
	hgnPlus.viewAccount();
	cout << endl;
	hgnPlus.turnOut(400);
	hgnPlus.viewAccount();
	cout << endl;
	hgnPlus.payBack(1000);
	hgnPlus.viewAccount();
	cout << endl;
	return 0;
}
#endif

#endif