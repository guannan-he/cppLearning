#ifndef _CH14_HEADER_
#define _CH14_HEADER_
#include <iostream>
#include <valarray>

using namespace std;

class cStudent {
	typedef valarray<double> dataDB;
public:
	cStudent();
	explicit cStudent(const int);
	cStudent(const string&);
	cStudent(const string&, int);
	cStudent(const string&, const dataDB&);
	cStudent(const string&, const double, int);
	~cStudent();
	double average() const;
	const string& getName() const;
	double operator[] (int) const;
	friend istream& operator>> (istream&, cStudent&);
	friend istream& getline(istream&, cStudent&);
	friend ostream& operator<< (ostream&, cStudent&);
private:
	string name;
	dataDB scores;
};



#endif