#ifndef _DATE_USER_H_
#define _DATE_USER_H_

class Cdate_user {
public:
	int getMonth();
	int getDay();
	int getWeek();
	void setMonth(int);
	void setDay(int);
	void setWeek(int);
	friend int read_private();
	Cdate_user(int, int, int);
	~Cdate_user();
	static int number;
private:
	int nMonth;
	int nDay;
	int nWeek;
};

#endif#pragma once
