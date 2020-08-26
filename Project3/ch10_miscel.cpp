#include "ch10_header.h"
#include <iostream>

//��Ʊ��
cStock::cStock() {
	shareVal = 0.0;
	totalVal = 0.0;
	totalSpend = 0.0;
	averageVal = 0.0;
	profit = 0.0;
	return;
}
cStock::cStock(string str, int num, double pric) {
	companyName = str;
	shares = num;
	shareVal = pric;
	averageVal = pric;
	profit = 0.0;
	totalSpend = 0.0;
	totalSpend += transcendValue(num, pric);
	setTotal();
	return;
}
cStock::~cStock() {
	cout << "All Sold!" << endl;
	sell(shares, shareVal);
	averageVal = 0;
	show();
	return;
}
void cStock:: setTotal() {
	totalVal = shares * shareVal;
	return;
}
void cStock::acquire(const string str = "NaN", int num = 0, double pric = 0.0) {//��ʼ����
	companyName = str;
	shares = num;
	shareVal = pric;
	averageVal = pric;
	totalSpend += transcendValue(num, pric);
	setTotal();
	return;
}
double cStock::transcendValue(int num, double pric) {//���׽��
	return num * pric;
}
void cStock::buy(int num, double pric) {//����
	shareVal = pric;
	setTotal();
	num = (num > 0) ? num : 0;//��������
	totalSpend += transcendValue(num, pric);
	shares += num;
	setTotal();
	averageVal = totalSpend / shares;
	profit = totalVal - totalSpend;
	return;
}
void cStock::sell(int num, double pric) {//����
	shareVal = pric;
	setTotal();
	num = (num > 0) ? num : 0;//������ȯ
	num = (shares > num) ? num : shares;//���ó���
	totalSpend -= transcendValue(num, pric);
	shares -= num;
	setTotal();
	averageVal = totalSpend / shares;
	profit = totalVal - totalSpend;
	return;
}
void cStock::update(double pric) {//�۸�仯
	shareVal = pric;
	setTotal();
	averageVal = totalSpend / shares;
	profit = totalVal - totalSpend;
	return;
}
void cStock::show() const {
	cout << "Company Name: " << companyName << endl;
	cout << "Total Shares: " << shares << endl;
	cout << "Current Price: " << shareVal << endl;
	cout << "Current Value: " << totalVal << endl;
//	cout << "Total Invest: " << totalSpend << endl;
	cout << "Average Cost: " << averageVal << endl;
	cout << "Profit: " << profit << endl;
	return;
}
/// <summary>
/// ///////////////////////////////////////
/// </summary>
cStack::cStack() {
	size = 10;
	pool = new item[size];
	return;
}
cStack::cStack(int n) {
	size = n;
	pool = new item[size];//�����ڴ���ʱ����
	return;
}
cStack::~cStack() {
	delete[] pool;
	pool = 0;
	cout << "Pool DEleted!" << endl;
	return;
}
bool cStack::stackPush(item& i) {
	if (pointer < size) {
		pool[pointer++] = i;
		return true;
	}
	else
		return false;
}
bool cStack::stackPop(item& i) {
	if (pointer > 0) {
		i = pool[--pointer];
		return true;
	}
	else
		return false;
}
bool cStack::isEmpty() const {
	return pointer == 0;
}
bool cStack::isFull() const {
	return pointer == size;
}