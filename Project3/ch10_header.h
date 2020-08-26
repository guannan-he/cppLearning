#ifndef _CH10_HEADER_
#define _CH10_HEADER_

#include <string>

using namespace std;

//π…∆±¿‡
class cStock {
public:
	cStock();
	cStock(string, int, double);
	~cStock();
	void acquire(string, int, double);
	void buy(int, double);
	void sell(int, double);
	void update(double);
	void show() const;
private:
	string companyName = "NaN";
	int shares = 0;
	double shareVal;
	double totalVal;
	double totalSpend;
	double averageVal;
	double profit;
	void setTotal();
	double transcendValue(int, double);
protected:
};

//’ª
typedef char item;
class cStack {
public:
	cStack();
	cStack(int);
	~cStack();
	bool stackPush(item&);
	bool stackPop(item&);
	bool isEmpty() const;
	bool isFull() const;
	int size;
private:
	int pointer = 0;
	item* pool;
};
#endif