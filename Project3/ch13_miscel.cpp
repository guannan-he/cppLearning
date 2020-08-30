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






cRatedPlayer::cRatedPlayer(string strF, string strL, bool table, bool rate):cPlayer(strF, strL, table) {//用初始化列表
	//cPlayer(strF, strL, table);//要有自己的构造函数
	//fName = strF;
	//lName = strL;
	//hasTable = table;//原来类的私有不可访问，只能用公有部分
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





cBrassAccount::cBrassAccount(string str, string num, double mon) {
	name = str;
	accountNumber = num;
	leftOver = mon;
	return;
}
cBrassAccount::~cBrassAccount() {
	cout << name << "\t" << accountNumber << "\tis canceled type: base." << endl;
	return;
}
cBrassAccount::cBrassAccount(cBrassAccount& acnt) {
	this->name = acnt.name;
	this->accountNumber = acnt.accountNumber + "-1";
	this->leftOver = acnt.leftOver;
	return;
}
cBrassAccount& cBrassAccount::operator= (cBrassAccount& acnt) {
	this->name = acnt.name;
	this->accountNumber = acnt.accountNumber + "-1";
	this->leftOver = acnt.leftOver;
	return *this;
}
void cBrassAccount::turnIn(double mon) {
	leftOver += mon;
	return;
}
bool cBrassAccount::turnOut(double mon) {
	if (leftOver >= mon) {
		leftOver -= mon;
		return true;
	}
	else {
		return false;
	}
}
double cBrassAccount::getLeft() const {
	return leftOver;
}
void cBrassAccount::resetName(string str) {
	name = str;
	return;
}
ostream& operator<< (ostream& os, cBrassAccount& usr) {
	os << "User: " << usr.name << "\tAccount Number: " << usr.accountNumber << "\tleft: " << usr.leftOver;
	return os;
}




cBrassPlus::cBrassPlus(string str, string num, double mon, double mxLoa, double defRate, double defOwe) :cBrassAccount(str, num, mon) {
	maxLoan = mxLoa;
	rate = defRate;
	owesBank = defOwe;
	return;
}
cBrassPlus::cBrassPlus(cBrassPlus& usr, double mxLoa, double defRate, double defOwe) {
	this->maxLoan = mxLoa;
	this->rate = defRate;
	this->owesBank = defOwe;
	return;
}
cBrassPlus::cBrassPlus(cBrassAccount& usr, double mxLoa, double defRate, double defOwe):cBrassAccount(usr){
	this->maxLoan = mxLoa;
	this->rate = defRate;
	this->owesBank = defOwe;
	return;
}
cBrassPlus::~cBrassPlus() {
	cout<< "\tis canceled type: derive." << endl;
	return;
}
void cBrassPlus::resetMax(double mxLoan) {
	maxLoan = mxLoan;
	return;
}
void cBrassPlus::resetRate(double defRate) {
	rate = defRate;
	return;
}
void cBrassPlus::payBack(double mon) {
	owesBank -= mon;
	if (owesBank >= 0) {
		return;
	}
	else {
		turnIn(-1 * owesBank);//直接访问，未定义virtual
		owesBank = 0;
		return;
	}
}
bool cBrassPlus::turnOut(double mon) {
	double left = getLeft();
	double owes = left - mon;
	if (owes >= 0) {
		cBrassAccount::turnOut(mon);
		return true;
	}
	else if (owes + maxLoan >= 0) {
		cBrassAccount::turnOut(left);//定义了virtual， 使用基类方法
		owesBank = -1 * owes * (rate + 100) / 100;
		return true;
	}
	else {
		return false;
	}
}
ostream& operator<< (ostream& os, cBrassPlus& pls) {
	cBrassAccount* pt = &pls;
	//pt->;//读不出基类私有数据，只是转换一下类型，实现数据保护
	os << *pt;//可以用指针访问基类
	os << "\tRate: " << pls.rate << "\tmax loan: " << pls.maxLoan << "\tnow owes: " << pls.owesBank;
	return os;
}



////////////////////////////////////////////
void cAcctABC::turnIn(double mon) {
	balance += mon;
	return;
}
bool cAcctABC::turnOut(double mon) {
	if (balance >= mon) {
		balance -= mon;
		return true;
	}
	else {
		return false;
	}
}
void cAcctABC::viewAccount() const {
	cout << "munber: " << getAccountNumber() << "\tname: " << getName() << "\tleft:" << getLeft();
}

bool cBrassABC::turnOut(double mon) {
	return cAcctABC::turnOut(mon);
}
void cBrassABC::viewAccount() const {
	cAcctABC::viewAccount();
	return;
}

bool cBrassPlusABC::turnOut(double mon) {
	if (getLeft() >= mon) {
		return cAcctABC::turnOut(mon);
	}
	else if (getLeft() + maxLoan > mon) {
		owesBank = (mon - getLeft()) * (rate + 100) / 100;
		return cAcctABC::turnOut(getLeft());
	}
	else
		return false;
}
void cBrassPlusABC::viewAccount() const {
	cAcctABC::viewAccount();
	cout << "\trate: " << rate << "\tmax loan: " << maxLoan << "\toews bank: " << owesBank;
	return;
}

void cBrassPlusABC::resetMax(double mxLoan) {
	maxLoan = mxLoan;
	return;
}
void cBrassPlusABC::resetRate(double defRate) {
	rate = defRate;
	return;
}
void cBrassPlusABC::payBack(double mo) {
	owesBank -= mo;
	if (owesBank >= 0) {
		return;
	}
	else {
		turnIn(-1 * owesBank);
		owesBank = 0;
		return;
	}
}

