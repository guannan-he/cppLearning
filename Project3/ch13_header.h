#ifndef _CH13_HEADER_
#define _CH13_HEADER_
#include <iostream>
#include <string>

using namespace std;
/// <summary>
/// ////////////////////////////////////////////////////////////////////////////////////////
/// </summary>
class cPlayer {//����
public:
	cPlayer(string strF = "Joe", string strL = "Doe", bool table = false);
	~cPlayer();
	friend ostream& operator<< (ostream&, const cPlayer&);
	bool isTable() const;
	void resetTable(bool bl = false);
private:
	string fName;
	string lName;
	bool hasTable;
	cPlayer& operator= (cPlayer&){}//���ø�ֵ
	cPlayer(cPlayer&) {}//���ó�ʼ��
};
/// <summary>
/// ////////////////////////////////////////////////////////////////////////////////////////
/// </summary>
class cRatedPlayer : public cPlayer {//������ֻ�ܷ��ʹ��в���
public:
	cRatedPlayer(string strF = "Joe", string strL = "Doe", bool table = false, bool rate = false);
	bool isRated();
	void resetRate(bool bl = false);
private:
	bool rated;
	cRatedPlayer& operator= (cRatedPlayer&){}
	cRatedPlayer(cRatedPlayer&){}
};



#endif