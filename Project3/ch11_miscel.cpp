#include "ch11_header.h"
#include <iostream>
#include <cmath>

//cTime
#if 1
cTime::cTime() {
	hour = 8;
	mint = 0;
	sec = 0;
	return;
}
cTime::cTime(int i, int j, int k) {
	setHour(i);
	setMint(j);
	setSec(k);
	return;
}
cTime::~cTime() {
	return;
}
void cTime::show() const {
	cout.width(2);
	cout.fill('0');
	cout << hour << ":";
	cout.width(2);
	cout.fill('0');
	cout << mint << ":";
	cout.width(2);
	cout.fill('0');
	cout << sec << endl;
	return;
}
void cTime::setHour(int i) {
	i = (i > 0) ? i : 0;
	i = (i < 24) ? i : 23;
	hour = i;
	return;
}
void cTime::setMint(int j) {
	j = (j > 0) ? j : 0;
	j = (j < 60) ? j : 59;
	mint = j;
	return;
}
void cTime::setSec(int k) {
	k = (k > 0) ? k : 0;
	k = (k < 60) ? k : 59;
	sec = k;
	return;
}
void cTime::tic() {
	if (sec < 59) {
		sec++;
		return;
	}
	else if (mint < 59) {
		resetTime(1);
		mint++;
		return;
	}
	else if (hour < 23) {
		resetTime(2);
		hour++;
		return;
	}
	else {
		resetTime(3);
		return;
	}
	return;
}
void cTime::resetTime(int i) {
	switch (i) {
	case 3:
		hour = 0;
	case 2:
		mint = 0;
	case 1:
		sec = 0;
	default:
		return;
	}
}
cTime cTime:: operator +(const cTime& op) const {
	int i, j, k;
	i = j = k = 0;
	k = op.sec + this->sec;
	j = op.mint + this->mint + k / 60;
	i = op.hour + this->hour + j / 60;
	k %= 60;
	j %= 60;
	i %= 24;
	return cTime(i, j, k);
}
cTime cTime:: operator -(const cTime& op) const {
	int i, j, k;
	i = j = k = 0;
	k = this->sec - op.sec;
	j = this->mint - op.mint;
	i = this->hour - op.hour;
	if (k < 0) {
		k += 60;
		j--;
	}
	if (j < 0) {
		j += 60;
		i--;
	}
	if (i < 0) {
		i += 24;
	}
	return cTime(i, j, k);
}
cTime cTime::operator += (const cTime& op) {
	*this = *this + op;
	return *this;
}
cTime cTime::operator -= (const cTime& op) {
	*this = *this - op;
	return *this;
}
cTime cTime::operator ++() {
	tic();
	return *this;
}
cTime cTime::operator ++(int) {
	cTime tmp = *this;
	tic();
	return tmp;
}
ostream& operator << (ostream& os, cTime& time) {
	time.show();
	//os << time.hour << endl;
	return os;
}
#endif
//cVector
#if 1
//////////////////////////public/////////////////////////////////
cMyVector::cMyVector() {
	cordX = cordY = ang = mag = 0;
	return;
}
cMyVector::cMyVector(double op1, double op2, char c) {
	if (c == 'c') {
		cordX = op1;
		cordY = op2;
		updatePloar();
		return;
	}
	else {
		mag = op1;
		ang = op2 * deg2radConst;
		updateCord();
		return;
	}
}
cMyVector::~cMyVector() {
	return;
}
cMyVector cMyVector::operator+ (const cMyVector& vtr) const {
	double op1, op2;
	op1 = op2 = 0;
	op1 = this->cordX + vtr.cordX;
	op2 = this->cordY + vtr.cordY;
	return cMyVector(op1, op2);
}
cMyVector cMyVector::operator- (const cMyVector& vtr) const {
	double op1, op2;
	op1 = op2 = 0;
	op1 = this->cordX - vtr.cordX;
	op2 = this->cordY - vtr.cordY;
	return cMyVector(op1, op2);
}
cMyVector& cMyVector::operator+= (const cMyVector& vtr) {
	this->cordX += vtr.cordX;
	this->cordY += vtr.cordY;
	updatePloar();
	return *this;
}
cMyVector& cMyVector::operator-= (const cMyVector& vtr) {
	this->cordX -= vtr.cordX;
	this->cordY -= vtr.cordY;
	updatePloar();
	return *this;
}
double cMyVector::operator* (const cMyVector& vtr) const {
	return this->cordX * vtr.cordX + this->cordY * vtr.cordY;
}
cMyVector cMyVector::operator* (const double& mul) const {
	double op1, op2;
	op1 = op2 = 0;
	op1 = this->cordX * mul;
	op2 = this->cordY * mul;
	return cMyVector(op1, op2);
}
////////////////////////////private////////////////////////////////
double cMyVector::deg2rad(double i) {
	return i * deg2radConst;
}
double cMyVector::red2deg(double i) {
	return i * rad2degConst;
}
void cMyVector::updateCord() {
	cordX = mag * cos(ang);
	cordY = mag * sin(ang);
	return;
}
void cMyVector::updatePloar() {
	mag = sqrt(cordX * cordX + cordY * cordY);
	ang = atan2(cordY, cordX);
	return;
}
ostream& operator<< (ostream& os, const cMyVector& vtr) {
	os.width(5);
	os.fill('0');
	os << "MAG: " << vtr.mag << "\t";
	os.width(5);
	os.fill('0');
	os << "ANG: " << vtr.ang * rad2degConst;
	return os;
}
cMyVector operator* (double mul, cMyVector& vtr) {
	return vtr * mul;
}
#endif