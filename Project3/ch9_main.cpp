#if 0

#if 1
#define MAX_STACK 100
#define MAX_BUFFER 1000
#include <iostream>
#include <new>

using namespace std;
#endif



#if 1
char* bottom = 0;
char* now = 0;
char* bufferLoca = 0;
void bufferInit() {//�ֹ������ڴ�ռ�
	bufferLoca = new char[MAX_BUFFER];
	return;
}
void bufferDelete() {//�ͷ��ڴ�
	delete[] bufferLoca;
	bufferLoca = 0;
	return;
}
void stackInit() {//ջ��ʼ��
	bottom = new char [MAX_STACK];
	now = bottom - 1;
}
void push(char tmp) {//��ջ
	if (now - bottom < MAX_STACK - 1) {//Ҫ-1���±��0��ʼ������Խ��
		*(++now) = tmp;
		return;
	}
	else {
		return;
	}
}
char pop() {//��ջ
	if (now - bottom >= 0)
		return *(now--);
	else
		return -1;
}
void deleteStack() {//����ջ
	delete[] bottom;
	now = 0;
	bottom = 0;
	return;
}


int main(int argc, char* argv[]) {//����������
	char i = '2', j = '5', k = '8', m = '12';
	char c = 'c';
	{
		int n = 5;
		int i = 3;
		int x = 17;
		
	}
	string str = "cock";
	stackInit();
	for (int st = 0; st < 98; st++) {
		push('c');
		;
	}
	push(i);
	push(j);
	push(k);
	cout << pop() << "\t" << pop() << "\t" << endl;
	deleteStack();
	bufferInit();
	char* buff_0 = new(bufferLoca) char[10];
	buff_0[0] = 'c';
	buff_0[1] = 'o';
	char* buff_1 = new(bufferLoca + sizeof(char) * 10) char[10];//�ֶ�ָ����ʼλ��
	buff_1[0] = 'c';
	bufferDelete();
	buff_0 = 0;
	buff_1 = 0;
	return 0;
}
#endif








#if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif

#endif