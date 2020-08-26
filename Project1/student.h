#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//void print_info();
//void change_name(string);
//void change_age(int);
class student {
public:
    void print_info();
    void change_name(string);
    void change_age(int);//类内部声明
private:
    string name = "John Doe";
    int age = -1;
    int sn = -1;
    string addr = "10 Dowing St.";
    //protected:
    //    int k = 0;
};
//using namespace student;
#endif 