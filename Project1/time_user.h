#ifndef _TIME_USER_H_
#define _TIME_USER_H_
class Ctime_user {
public:
	Ctime_user();//构造函数，自动调用，无返回值，无参数为默认构造函数
	~Ctime_user();//析构函数，生命周期结束后调用，只能有一个
	Ctime_user(Ctime_user& time);
	int getHour();
	int getMinute();
	int getSecond();
	static int number;
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	void tick();
	void print_time();
private:
	int nHour;
	int nMinute;
	int nSecond;
};
#endif