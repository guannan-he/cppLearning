#include "ch14_header.h"
#include <iostream>
#include <valarray>
#include <string>

using namespace std;

cStudent::cStudent() :name("NULL"), scores() {
	return;
}
cStudent::cStudent(const string& str):name(str), scores() {
	return;
}
cStudent::cStudent(const string& str, int n): name(str), scores(n) {
	return;
}
cStudent::cStudent(const string& str, const valarray& a) : name(str), scores(a) {
	return;
}
cStudent::cStudent(const string& str, const double scr, int n) : name(str), scores(scr, n) {
	return;
}
cStudent::~cStudent() {
	return;
}
double cStudent::average() const {
	return scores.sum() / scores.size();
}
const string& cStudent::getName() const {
	return name;
}
double cStudent::operator[] (int n) const {
	return scores[n];
}