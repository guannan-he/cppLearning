#ifndef _TIME_USER_H_
#define _TIME_USER_H_
class Ctime_user {
public:
	Ctime_user();//���캯�����Զ����ã��޷���ֵ���޲���ΪĬ�Ϲ��캯��
	~Ctime_user();//�����������������ڽ�������ã�ֻ����һ��
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