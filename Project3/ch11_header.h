#ifndef _CH11_HEADER_
#define _CH11_HEADER_
#define rad2degConst 57.325
#define deg2radConst 0.0175

#include <string>

using namespace std;

class cTime {
public:
	cTime();
	cTime(int, int, int);
	~cTime();
	void show() const;
	void setHour(int);
	void setMint(int);
	void setSec(int);
	void tic();
	void resetTime(int = 3);
	cTime operator + (const cTime&) const;
	cTime operator - (const cTime&) const;
	cTime operator += (const cTime&);
	cTime operator -= (const cTime&);
	cTime operator ++();
	cTime operator ++(int);//����Ҫ��int
	friend ostream& operator << (ostream&, cTime&);
private:
	int hour;
	int mint;
	int sec;
};
//����һ�����ࣺʸ��cVector
//��Ҫ�����괢�棬�����긨��
class cMyVector {
public:
	cMyVector();
	cMyVector(double, double, char c = 'c');
	~cMyVector();
	cMyVector operator+ (const cMyVector&) const;
	cMyVector operator- (const cMyVector&) const;
	cMyVector& operator+= (const cMyVector&);
	cMyVector& operator-= (const cMyVector&);
	double operator* (const cMyVector&) const;
	cMyVector operator* (const double&) const;
	friend ostream& operator<< (ostream&, const cMyVector&);
	friend cMyVector operator* (double, cMyVector&);
private:
	double cordX;
	double cordY;
	double mag;
	double ang;
	double deg2rad(double);
	double red2deg(double);
	void updateCord();
	void updatePloar();
};
#endif