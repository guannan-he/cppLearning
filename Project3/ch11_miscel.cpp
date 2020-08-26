#include "ch11_header.h"
#include <iostream>
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
	switch (i){
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
