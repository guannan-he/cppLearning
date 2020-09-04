//KMP
#if 0

#if 1
#include <iostream>
#include <string>

using namespace std;
#endif



#if 1


int* getNext(string str) {
	int* next = new int[str.length()];
	int i, j, k, tmpK;
	for (i = 1; i < str.length(); i++) {//子串长度
		tmpK = 0;
		for (j = 0; j < i; j++) {//缀长度，0代表自身
			for (k = 0; k < j; k++) {//判断相等
				if (str[k] != str[i - j + k]) {
					break;
				}
			}
			if (k == j && k > tmpK) {//到缀尾且目前队尾最长
				tmpK = k;
			}
		}
		next[i] = tmpK;
	}
	next[0] = -1;
	return next;
}

int main(int argc, char* argv[]) {
	string strS("ABCDABCDEFQDX");
	string strP("EFQ");
	int* next = getNext(strP);
	for (int i = 0; i < strP.length(); i++) {//display next
		cout << next[i] << endl;
	}
	int i, j, cnt, pos, limit;
	limit = ((strS.length() - strP.length() + 1) * strP.length());
	cnt = 0;
	for (i = j = 0; i < strS.length(); cnt++) {//i自增在循环体中
		if (strS[i] == strP[j]) {//匹配
			i++;
			j++;
		}
		else {//失配
			j = next[j];
		}
		if (j == -1) {//如果第一个失配，换位
			j = 0;
			i++;
		}
		if (j == strP.length()) {//判断到队尾
			pos = i - j;
			break;
		}
		if (cnt > limit) {//防止找不到死循环
			pos = -1;
			break;
		}
	}
	delete next;
	return i - j;
}







#endif











#if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif

#endif