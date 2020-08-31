#ifndef _CH14_HEADER_
#define _CH14_HEADER_
#include <iostream>
#include <valarray>

using namespace std;

class cStudent {
public:
	cStudent();
	cStudent(const string&);
	cStudent(const string&, int);
	cStudent(const string&, const valarray&);
	cStudent(const string&, const double, int);
	~cStudent();
	double average() const;
	const string& getName() const;
	double operator[] (int) const;
private:
	string name;
	valarray<double> scores;
};


#endif