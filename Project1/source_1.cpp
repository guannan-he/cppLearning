#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <vector>
#include <student.h>
#include <time_user.h>
#include <date_user.h>

using namespace std;
#if 0
void nothing(void);
typedef unsigned short int u8;
enum color
{
    red,
    blue,
    puple
};


int main()
{
    int a = 0;
    int b = 0;
    int* pa = &a;
    u8 llm = 8;
    a++;
    //std::byte k = 0;
    wchar_t cock = 'a';
    color c = puple;
    b = blue;
    //color c = blue;
    //b = c.blue;
    for (int i = 0; i <= 30; i++)
    {
        i = i;
    }
    nothing();
    cout << "Hello, world!" << endl;
    return 0;
}

//using namespace cock;
void nothing(void) {
    cout << "None!" << endl;
    return;
}
#endif

#if 0 //枚举
enum time
{
    first, second,
    third, forth, fifth
};

int main()
{
    enum time a = fifth;
    if (a == fifth)
    {
        cout << "Succeed!";
    }
    return 0;
}
#endif

#if 0
int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        cout << "argument is: " << argv[i] << "\t," << i << " th in " << argc << endl;
    }
    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {
    //char* inptval[10];
    //int i = 0;
    //for (i = 0; i < 10; i++) {
    //    cin >> inptval[i];
    //}
    //for (i = 0; i < 10; i++) {
    //    cout << inptval[i]<<endl;
    //}不行的原因是只分配了10个连续地址，地址没有指向有效空间
    string str1 = "cock";
    cout << str1 << endl;
    str1 += " cock";
    cout << str1 << endl;
    //str1 -= " cock";不支持-=
    //cout << str1 << endl;
    string strspace[10];
    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {
    vector<int> vtr1;
    vector<int> vtr2(vtr1);
    vector<int> vtr3 = vtr1;
    vector<int> vtr4(10,100);
    vector<int> vtr5(100);
    vector<string> vtr6(10,"cock");
    vtr6.push_back("arse");
    vtr4.pop_back();
    int v4Recv1 = vtr4.at(2);
    int v4IsEmpty = vtr4.empty();
    //int v4Recv2 = vtr4.at(9);
    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {
    string temp;
    vector<string> store;
    int byteCnt = 0;

    while (getline(cin,temp)) {
        if (temp == ":q") {//退出条件
            break;
        }
        store.push_back(temp);//储存
        byteCnt += temp.size();//字数统计
    }
    cout << "total byte count is: " << byteCnt << "\t total line couint is: " << store.size() << endl;
    for (int i = 0; i < store.size(); i++) {
        cout << store.at(i) << endl;//访问输出
    }
    return 0;
}

#endif

#if 0
typedef struct {
    int a;
    vector<int> b[1000];
} bigstruct;
void swap(int&, int&);
int main(int argc, char* argv[]) {
    bigstruct struc1;
    struc1.a = 1;
    int b = 10;
    int* a = &b;
    int &c = b;
    int d = 20;
    cout << &b << endl;
    cout << a << endl;
    cout << *a << endl;
    cout << &a << endl;
    c++;
    cout << b << endl;
    cout << c << endl;
    swap(b, d);
    return 0;
}
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}

#endif

#if 0
template<typename T>
T add(T a, T b) {
    return a + b;
}
int add_int(int a, int b) {
    return a + b;
}
int main(int argc, char* argv[]) {
    int a = 2;
    int b = 3;
    float c = 3.2;
    float d = 6.4;
    double e = 2.5;
    double f = 2.5;
    cout << "2 + 3 = " << add(a, b) << endl;
    cout << "3.2 + 6.4 = " << add(c, d) << endl;
    //cout << "2 + 3.2" << add(a, c) << endl;

    return 0;
}

#endif

#if 0

//typedef struct {
//    string name;
//    int age;
//    string add;
//} student;


//using namespace std;

int main(int argc, char* argv[]) {
    //student a1;
    //a1.name = "cock";
    //cout << a1.name << endl;
    student a1;
    student* ptA1 = &a1;
    student& b = a1;
    a1.print_info();
    a1.change_name("Cock");//访问要靠公有接口
    a1.print_info();
    //cout<<a1.name<<endl; 私有成员不可访问
    (*ptA1).print_info();
    ptA1->print_info();
    b.print_info();
    return 0;
}

#endif

#if 0
void func1(Ctime_user time) {
    int i = time.getHour();
    return;
}
void func2(Ctime_user& time) {
    int i = time.getHour();
    return;
}
int main(int argc, char* argv[]) {
    Ctime_user tm;
    for (int i = 0; i <= 60; i++) {
        tm.print_time();
        tm.tick();
    }
    Ctime_user tm1(tm);
    Ctime_user tm2;
    func1(tm1);
    func2(tm1);
    tm.print_time();
    tm1.print_time();
    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

#if 0
int main(int argc, char* argv[]) {

    return 0;
}

#endif

