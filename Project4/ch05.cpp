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
	for (i = 1; i < str.length(); i++) {//�Ӵ�����
		tmpK = 0;
		for (j = 0; j < i; j++) {//׺���ȣ�0��������
			for (k = 0; k < j; k++) {//�ж����
				if (str[k] != str[i - j + k]) {
					break;
				}
			}
			if (k == j && k > tmpK) {//��׺β��Ŀǰ��β�
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
	for (i = j = 0; i < strS.length(); cnt++) {//i������ѭ������
		if (strS[i] == strP[j]) {//ƥ��
			i++;
			j++;
		}
		else {//ʧ��
			j = next[j];
		}
		if (j == -1) {//�����һ��ʧ�䣬��λ
			j = 0;
			i++;
		}
		if (j == strP.length()) {//�жϵ���β
			pos = i - j;
			break;
		}
		if (cnt > limit) {//��ֹ�Ҳ�����ѭ��
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