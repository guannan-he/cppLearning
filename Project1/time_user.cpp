#include <time_user.h>
#include <iostream>
Ctime_user::Ctime_user() {
	nHour = 8;
	nMinute = 0;
	nSecond = 0;
	number++;
}
Ctime_user::~Ctime_user() {
	nHour = 8;
	nMinute = 0;
	nSecond = 0;
	number--;
}
Ctime_user::Ctime_user(Ctime_user& time) {
	nHour = time.getHour();
	nMinute = time.getMinute();
	nSecond = time.getSecond();
	tick();
	number++;
}
int Ctime_user::getHour() {
	return nHour;
}
int Ctime_user::getMinute() {
	return nMinute;
}
int Ctime_user::getSecond() {
	return nSecond;
}
void Ctime_user::setHour(int i) {
	if (i < 0) {
		i = 0;
	}
	if (i > 23) {
		i = 23;
	}
	nHour = i;
	return;
}
void Ctime_user::setMinute(int i) {
	if (i < 0) {
		i = 0;
	}
	if (i > 59) {
		i = 59;
	}
	nMinute = i;
	return;
}
void Ctime_user::setSecond(int i) {
	if (i < 0) {
		i = 0;
	}
	if (i > 59) {
		i = 59;
	}
	nSecond = i;
	return;
}
void Ctime_user::print_time() {
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << getHour() << ":";
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << getMinute() << ":";
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << getSecond() << std::endl;
	return;
}
void Ctime_user::tick() {
	int sec = getSecond();
	int mint = getMinute();
	int hr = getHour();
	if (sec < 59){
		setSecond(sec + 1);
		return;
	}
	else if (mint < 59) {
		setSecond(0);
		setMinute(mint + 1);
		return;
	}
	else if (hr < 23) {
		setSecond(0);
		setMinute(0);
		setHour(hr + 1);
		return;
	}
	else {
		setSecond(0);
		setMinute(0);
		setHour(0);
		return;
	}
}
int Ctime_user::number = 0;