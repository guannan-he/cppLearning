#include "ch14_header.h"
#include <iostream>
#include <valarray>
#include <string>

using namespace std;

cStudent::cStudent() :name("NULL"), scores() {
	return;
}
cStudent::cStudent(const int n):name("NULL"), scores(n){
	return;
}

cStudent::cStudent(const string& str):name(str), scores() {
	return;
}
cStudent::cStudent(const string& str, int n): name(str), scores(n) {
	return;
}
cStudent::cStudent(const string& str, const dataDB& a) : name(str), scores(a) {
	return;
}
cStudent::cStudent(const string& str, const double scr, int n) : name(str), scores(scr, n) {
	return;
}
cStudent::~cStudent() {
	return;
}
double cStudent::average() const {
	return (scores.size() > 0) ? scores.sum() / scores.size() : 0;
}
const string& cStudent::getName() const {
	return name;
}
double cStudent::operator[] (int n) const {
	return scores[n];
}
istream& operator>> (istream& is, cStudent& stu) {
	is >> stu.name;
	return is;
}
istream& getline(istream& is, cStudent& stu) {
	getline(is, stu.name);
	return is;
}
ostream& operator<< (ostream& os, cStudent& stu) {
	os << stu.name << ":";
	for (int i = 0; i < stu.scores.size(); i++) {
		cout << endl << stu[i];
	}
	//os << stu.scores;
	return os;
}

///////////////////////////////////////////////////////////////////
