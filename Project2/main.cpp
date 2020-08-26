#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

//51nob #1000 �����������
#if 0
int main(int argc, char* argv[]) {
	string str1,str2;
	string res = "";
	char tmp,tmp1,tmp2;
	int i, j, cycle;
	int plus = 0;
	cin >> str1;
	cin >> str2;
	i = str1.size();
	j = str2.size();
	cycle = i;
	if (j > i) {
		cycle = j;
	}
	for (int k = 0; k < cycle; k++) {
		tmp1 = '0';
		tmp2 = '0';
		if (k < i) {
			tmp1 = str1.back();
			str1.pop_back();
		}
		if (k < j) {
			tmp2 = str2.back();
			str2.pop_back();
		}
		tmp = tmp1 + tmp2 - '0' - '0' + plus;
		plus = 0;
		if (tmp > 9) {
			tmp -= 10;
			plus = 1;
		}
		tmp += '0';
		res = tmp + res;
	}
	if (plus){
		res = '1' + res;
	}
	cout << res << endl;
	return 0;
}
#endif

//51nob #1005 �����������-����
#if 0
int main(int argc, char* argv[]) {
	string str1, str2;
	string res = "";
	int op1, op2, cnt, val1, val2;
	int op1S = 1;
	int op2S = 1;
	int plus = 0;
	char tmp;
	cin >> str1;
	cin >> str2;
	op1 = str1.size();
	op2 = str2.size();
	//ȡ����
	if (str1[0] == '-') {
		op1 -= 1;
		op1S = -1;
	}
	if (str2[0] == '-') {
		op2 -= 1;
		op2S = -1;
	}
	//ȡѭ������
	cnt = op1;
	if (op2 > op1) {
		cnt = op2;
	}
	//�ӷ�
	op1 = str1.size();
	op2 = str2.size();
	//ͬ����
	if ((op1S * op2S) > 0) {
		for (int i = 0; i < cnt; i++) {
			//ȡ���һ���ַ�
			val1 = 0;
			val2 = 0;
			if (op1 > i) {
				val1 = str1[op1 - 1 - i] - '0';
				//str1.pop_back();
			}
			if (op2 > i) {
				val2 = str2[op2 - 1 - i] - '0';
				//str2.pop_back();
			}
			if (val1 == '-' - '0')
				val1 = 0;
			if (val2 == '-' - '0')
				val2 = 0;
			tmp = val1 + val2 + plus;
			plus = 0;
			if (tmp > 9) {
				tmp -= 10;
				plus = 1;
			}
			tmp += '0';
			res = tmp + res;
		}
		if (plus == 1)
			res = '1' + res;
		if (op1S < 0)
			res = '-' + res;
	}
	//����
	else {

	}
	cout << res << endl;
	return 0;
}
#endif

//#1005 �����������-�ݹ�
#if 0
//��ӵݹ麯��
int add_rec(string& str1, string& str2, string& res, int len, int num) {
	int plus = 0;
	char val1, val2, tmp;
	val1 = str1[num];
	val2 = str2[num];
	if (num < len - 1)
		plus = add_rec(str1, str2, res, len, num + 1);
	tmp = val1 + val2 - '0' - '0' + plus;
	plus = 0;
	if (tmp > 9) {
		tmp -= 10;
		plus = 1;
	}
	tmp += '0';
	res[num] = tmp;
	return plus;

}
//�����ݹ飬��һ��Ϊ��,�ҳ��ȳ�
int sub_rec(string& str1, string& str2, string& res, int len, int num) {
	int plus = 0;
	char val1, val2, tmp;
	val1 = str1[num];
	val2 = str2[num];
	if (num < len - 1)
		plus = sub_rec(str1, str2, res, len, num + 1);
	tmp = val1 - val2 + plus;
	plus = 0;
	if ((tmp < 0) && (num != 0)) {
		tmp += 10;
		plus = -1;
	}
	if ((tmp < 0) && (num == 0)) {
		tmp = -1 * tmp;
		plus = -1;
	}
	tmp += '0';
	res[num] = tmp;
	return plus;
}
// ��ת����
void inverse_sign(string& res) {
	if (res[0] == '0') {
		return;
	}
	if (res[0] == '-') {
		res = res.substr(1);
		return;
	}
	res = '-' + res;
	return;
}
int main(int argc, char* argv[]) {
	string str1, str2;
	int len1, len2, lenRes, cnt, diff, plus, sign1, sign2;
	cin >> str1;
	cin >> str2;
	len1 = str1.size();
	len2 = str2.size();
	//ȡ���Ų�ȥ������
	sign1 = 1;
	sign2 = 1;
	if (str1[0] == '-') {
		sign1 = -1;
		len1 -= 1;
		str1 = str1.substr(1);
	}
	if (str2[0] == '-') {
		sign2 = -1;
		len2 -= 1;
		str2 = str2.substr(1);
	}
	//����
	if (len1 > len2) {
		cnt = len1;
		diff = len1 - len2;
		for (int i = 0; i < diff; i++) {
			str2 = '0' + str2;
		}
	}
	else {
		cnt = len2;
		diff = len2 - len1;
		for (int i = 0; i < diff; i++) {
			str1 = '0' + str1;
		}
	}
	string res(cnt, '0');
	//����
	plus = 0;
	//����
	if (sign1 + sign2 == 2) {
		plus = add_rec(str1, str2, res, cnt, 0);
		if (plus == 1) {
			res = '1' + res;
		}
	}
	//����
	if (sign1 + sign2 == -2) {
		plus = add_rec(str1, str2, res, cnt, 0);
		if (plus == 1) {
			res = '1' + res;
		}
		res = '-' + res;
	}
	//��Ч���ȳ��ŵ�һλ
	if (sign1 + sign2 == 0){
		if (len1 > len2) {
			plus = sub_rec(str1, str2, res, cnt, 0);
			lenRes = res.size();
			int i = 0;
			while ((res[i] == '0') && i < lenRes)
				i++;
			res = res.substr(i);
			if (res == "")
				res = "0";
			if (plus < 0) {
				inverse_sign(res);
			}
			if (sign1 < 0) {
				inverse_sign(res);
			}
		}
		if (len1 < len2) {
			plus = sub_rec(str2, str1, res, cnt, 0);
			lenRes = res.size();
			int i = 0;
			while ((res[i] == '0') && i < lenRes)
				i++;
			res = res.substr(i);
			if (res == "")
				res = "0";
			
			if (plus < 0) {
				inverse_sign(res);
			}
			if (sign2 < 0) {
				inverse_sign(res);
			}
		}
		if (len1 == len2) {
			
			if (str1[0] > str2[0]) {
				plus = sub_rec(str1, str2, res, cnt, 0);
				lenRes = res.size();
				int i = 0;
				while ((res[i] == '0') && i < lenRes)
					i++;
				res = res.substr(i);
				if (res == "")
					res = "0";
				if (plus < 0) {
					inverse_sign(res);
				}
				if (sign1 < 0) {
					inverse_sign(res);
				}
			}
			else {
				plus = sub_rec(str2, str1, res, cnt, 0);
				lenRes = res.size();
				int i = 0;
				while ((res[i] == '0') && i < lenRes)
					i++;
				res = res.substr(i);
				if (res == "")
					res = "0";

				if (plus < 0) {
					inverse_sign(res);
				}
				if (sign2 < 0) {
					inverse_sign(res);
				}
			}
		}
	}


	
	cout << res << endl;

	return 0;
}
#endif

//#1006 ���������
# if 0
//����ʽ ��һ��Ϊ����ʽ
void find_str(string& str1, string& str2, string& res, int len1, int len2) {
	//int mat[len1][len2];
	int i, j, j_last;
	j_last = 0;
	char tmp;
	for (i = 0; i < len1; i++) {
		tmp = str1[i];
		for (j = j_last; j < len2; j++) {
			if (tmp == str2[j]) {
				res += tmp;
				j_last = j + 1;
				break;
			}
		}
	}
	return;
}

int main(int argc, char* argv[]) {
	string str1, str2, res;
	res = "";
	int len1, len2;
	cin >> str1;
	cin >> str2;
	len1 = str1.size();
	len2 = str2.size();
	find_str(str1, str2, res, len1, len2);
	cout << res << endl;
	return 0;
}
#endif

# if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif

# if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif

# if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif