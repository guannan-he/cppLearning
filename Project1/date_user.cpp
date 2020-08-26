#include <date_user.h>
Cdate_user::Cdate_user(int i = 1, int j = 1, int k = 1) {
	nMonth = i;
	nDay = j;
	nWeek = k;
	number++;
}
Cdate_user::~Cdate_user() {
	number--;
}
int Cdate_user::getMonth() {
	return nMonth;
}
int Cdate_user::getDay() {
	return nDay;
}
int Cdate_user::getWeek() {
	return nWeek;
}
void Cdate_user::setMonth(int i) {
	nMonth = i;
}
void Cdate_user::setDay(int i) {
	nDay = i;
}
void Cdate_user::setWeek(int i) {
	nWeek = i;
}
int Cdate_user::number = 0;