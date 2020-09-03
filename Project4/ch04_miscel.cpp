#include "ch04.h"
#include <iostream>
#include <string>
using namespace std;




double inversePoland(string& str) {
	cStack<char>* tail = middle2Tail(str);
	tail->viewALL();
	delete tail;
	return 0;
}

cStack<char>* middle2Tail(string& str) {
	cStack<char>* tail = new cStack<char>;
	cStack<char>* symbol = new cStack<char>;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {//略去空格
			continue;
		}
		else if ((str[i] <= '9') && (str[i] >= '0')) {//遇到数字直接压栈
			tail->push(str[i]);
		}
		else {//符号压栈
			symbol->push(str[i]);
		}
		if (symbol->cnt() && symbol->view() == ')') {//遇到括号取出
			symbol->pop();
			while (symbol->cnt() && symbol->view() != '(') {
				tail->push(symbol->pop());
			}
			symbol->pop();
		}
	}
	delete symbol;
	return tail;
}