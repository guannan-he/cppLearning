#ifndef _CH11_HEADER_
#define _CH11_HEADER_

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
	cTime operator ++(int);//后置要加int
	friend ostream& operator << (ostream&, cTime&);
private:
	int hour;
	int mint;
	int sec;
};
//定义一个新类：矢量cVector
#endif