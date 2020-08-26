#include <student.h>
void student::change_age(int i) {//类外部定义函数
    age = i;
    return;
}
void student::change_name(string str) {
    name = str;
    return;
}
void student::print_info() {
    std::cout << name << ", " << age << ", " << addr << std::endl;
    return;
}