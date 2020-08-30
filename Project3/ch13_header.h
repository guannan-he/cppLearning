#ifndef _CH13_HEADER_
#define _CH13_HEADER_
#include <iostream>
#include <string>

using namespace std;
/// <summary>
/// ////////////////////////////////////////////////////////////////////////////////////////
/// </summary>
class cPlayer {//基类
public:
	cPlayer(string strF = "Joe", string strL = "Doe", bool table = false);
	~cPlayer();
	friend ostream& operator<< (ostream&, const cPlayer&);
	bool isTable() const;
	void resetTable(bool bl = false);
private:
	string fName;
	string lName;
	bool hasTable;
	//cPlayer& operator= (cPlayer&){}//禁用赋值
	//cPlayer(cPlayer&) {}//禁用初始化
};
/// <summary>
/// ////////////////////////////////////////////////////////////////////////////////////////
/// </summary>
class cRatedPlayer : public cPlayer {//派生类只能访问公有部分
public:
	cRatedPlayer(string strF = "Joe", string strL = "Doe", bool table = false, bool rate = false);
	bool isRated();
	void resetRate(bool bl = false);
private:
	bool rated;
	//cRatedPlayer& operator= (cRatedPlayer&){}
	//cRatedPlayer(cRatedPlayer&){}
};
////////////////////////////////////////////////////////////////////////////////////////////
class cBrassAccount {
public:
	cBrassAccount(string str = "Cock Sucker", string num = "00000000", double mon = 0.0);
	virtual ~cBrassAccount();//virtual特性可以自动继承，以后不用声明，但是为了醒目，还是声明
	cBrassAccount(cBrassAccount&);
	cBrassAccount& operator= (cBrassAccount&);
	void turnIn(double mon = 0);
	virtual bool turnOut(double mon = 0);
	double getLeft() const;
	void resetName(string str = "INVALID");
	friend ostream& operator<< (ostream&, cBrassAccount&);
private:
	string name;
	string accountNumber;
	double leftOver;
};
class cBrassPlus : public cBrassAccount {
public:
	cBrassPlus(string str = "Cock Sucker", string num = "00000000", double mon = 0.0, double mxLoa = 500, double defRate = 10, double defOwe = 0);
	cBrassPlus(cBrassPlus&, double mxLoa = 500, double defRate = 10, double defOwe = 0);
	cBrassPlus(cBrassAccount&, double mxLoa = 500, double defRate = 10, double defOwe = 0);
	virtual ~cBrassPlus();
	void resetMax(double mxLoan = 500);
	void resetRate(double defRate = 10);
	void payBack(double mon = 0);
	virtual bool turnOut(double mon = 0);
	friend ostream& operator<< (ostream&, cBrassPlus&);
private:
	double maxLoan;
	double rate;
	double owesBank;
};

class cAcctABC {
public:
	cAcctABC(string str1 = "Joe Doe", string str2 = "-1", double blce = 0.0): name(str1), accountNumber(str2), balance(blce){};
	virtual ~cAcctABC() {};
	void turnIn(double mon = 0);
	virtual bool turnOut(double mon = 0);
	//virtual void viewAccount() const = 0;//纯虚函数声明，目的是强迫使用接口
	virtual void viewAccount() const;
	double getLeft() const { return balance; };
protected:
	const string getAccountNumber() const { return accountNumber; };//要加上const修饰
	const string getName() const { return name; };
private:
	string name;
	string accountNumber;
	double balance;
};

class cBrassABC : public cAcctABC {
public:
	cBrassABC(string str1 = "Joe Doe", string str2 = "-1", double blce = 0.0) : cAcctABC(str1, str2, blce){};
	virtual ~cBrassABC() {};
	virtual bool turnOut(double mon = 0);
	virtual void viewAccount() const;
protected:
private:
};
class cBrassPlusABC :public cAcctABC {
public:
	cBrassPlusABC(string str1 = "Joe Doe", string str2 = "-1", double blce = 0.0, double mx = 500.0, double rte = 10, double obk = 0.0): cAcctABC(str1, str2, blce) , maxLoan(mx), rate(rte), owesBank(obk){};
	cBrassPlusABC(cAcctABC& base, double mx = 500.0, double rte = 10, double obk = 0.0) :cAcctABC(base), maxLoan(mx), rate(rte), owesBank(obk) {};//普通升级VIP
	~cBrassPlusABC() {};
	virtual bool turnOut(double mon = 0);
	virtual void viewAccount() const;
	void resetMax(double mxLoan = 500);
	void resetRate(double defRate = 10);
	void payBack(double mon = 0);
protected:
private:
	double maxLoan;
	double rate;
	double owesBank;
};

#endif