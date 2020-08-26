#if 0

#if 1
#include <iostream>

using namespace std;
#endif



#if 1
inline int addPonter(int i, int j) {//内联函数,递归调用编译器忽略内联
	return i + j;
}
template<class anyType>//必须加在函数声明前面
void swapPos(anyType& a, anyType& b) {
	anyType tmp;
	tmp = a;
	a = b;
	b = tmp;
	return;
}
template<> void swapPos<char>(char& a, char& b) {//重载函数摸板
	return;
}
typedef struct {
	char* name;
	int len;
} annoy;
void setAnnoy(annoy& annoyMenber, string str) {
	char* pt = new char[str.length() + 1];
	int i = 0;
	while (str[i]) {
		pt[i] = str[i];
		i++;
	}
	pt[i] = '\0';
	annoyMenber.name = pt;
	annoyMenber.len = i - 1;
}

int main(int argc, char* argv[]) {
	cout << addPonter(1, 2) << endl;
	int i = 1;
	int& j = i;
	cout << &i << endl;
	cout << &j << endl;
	///////////////////引用一次性认准不能改/////////////////////
	int a = 1;
	int b = 2;
	int* pa = &a;
	int& ra = *pa;
	cout << ra << endl;
	pa = &b;
	cout << ra << endl;
	ra = 3;
	cout << ra << endl;
	swapPos(a, b);
	double c = 1.1;
	double d = 1.2;
	swapPos(c, d);
	char e = 'r';
	char f = 'k';
	swapPos(e, f);
	annoy annoying;
	string str = "hello";
	setAnnoy(annoying, str);
	delete[] annoying.name;
//cock:goto dick;
//dick:goto cock;
	//swapPos(a);
	return 0;
}
#endif











#if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif

#endif