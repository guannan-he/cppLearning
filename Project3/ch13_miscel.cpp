#include "ch13_header.h"
#include <iostream>
#include <string>

using namespace std;

cPlayer::cPlayer(string strF, string strL, bool table) {
	fName = strF;
	lName = strL;
	hasTable = table;
	return;
}

cPlayer::~cPlayer() {
	return;
}
ostream& operator<< (ostream& os, const cPlayer& player) {
	os << player.fName << "-" << player.lName << ": ";
	if (player.hasTable) {
		os << "has a table." << endl;
		return os;
	}
	else {
		os << "doesn't have a table." << endl;
		return os;
	}
}
bool cPlayer::isTable() const {
	return hasTable;
}
void cPlayer::resetTable(bool bl) {
	hasTable = bl;
}






cRatedPlayer::cRatedPlayer(string strF, string strL, bool table, bool rate):cPlayer(strF, strL, table) {//�ó�ʼ���б�
	//cPlayer(strF, strL, table);//Ҫ���Լ��Ĺ��캯��
	//fName = strF;
	//lName = strL;
	//hasTable = table;//ԭ�����˽�в��ɷ��ʣ�ֻ���ù��в���
	rated = rate;
	return;
}
bool cRatedPlayer::isRated() {
	return rated;
}
void cRatedPlayer::resetRate(bool bl) {
	rated = bl;
	return;
}
