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
	cPlayer player3(ratPlayer1);//�������������ʼ������
	cPlayer* ptRatPlayer1 = &ratPlayer1;//�����û���ָ��ָ��������
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
	cBrassAccount* ptPlus = new cBrassPlus(hgn);//�����û���ָ��new�����࣬���Է�������������,��ʵ��ǿ������ת��
	ptPlus->turnOut(800);
	delete ptPlus;//�ȵ�������������Ȼ����û�������
	cBrassAccount* ptPlus1 = &hgnPlus;//�����û���ָ��ָ��������
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
	//cAcctABC hgn;//�д����⺯���Ĳ���ʹ��
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