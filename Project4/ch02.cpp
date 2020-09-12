#if 1

//Big brother is watching you
//⣿⣿⣿⣿⣿⠟⠋⠄⠄⠄⠄⠄⠄⠄⢁⠈⢻⢿⣿⣿⣿⣿⣿⣿⣿
//⣿⣿⣿⣿⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⡀⠭⢿⣿⣿⣿⣿
//⣿⣿⣿⣿⡟⠄⢀⣾⣿⣿⣿⣷⣶⣿⣷⣶⣶⡆⠄⠄⠄⣿⣿⣿⣿
//⣿⣿⣿⣿⡇⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠄⠄⢸⣿⣿⣿⣿
//⣿⣿⣿⣿⣇⣼⣿⣿⠿⠶⠙⣿⡟⠡⣴⣿⣽⣿⣧⠄⢸⣿⣿⣿⣿
//⣿⣿⣿⣿⣿⣾⣿⣿⣟⣭⣾⣿⣷⣶⣶⣴⣶⣿⣿⢄⣿⣿⣿⣿⣿
//⣿⣿⣿⣿⣿⣿⣿⣿⡟⣩⣿⣿⣿⡏⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
//⣿⣿⣿⣿⣿⣿⣹⡋⠘⠷⣦⣀⣠⡶⠁⠈⠁⠄⣿⣿⣿⣿⣿⣿⣿
//⣿⣿⣿⣿⣿⣿⣍⠃⣴⣶⡔⠒⠄⣠⢀⠄⠄⠄⡨⣿⣿⣿⣿⣿⣿
//⣿⣿⣿⣿⣿⣿⣿⣦⡘⠿⣷⣿⠿⠟⠃⠄⠄⣠⡇⠈⠻⣿⣿⣿⣿
//⣿⣿⣿⣿⡿⠟⠋⢁⣷⣠⠄⠄⠄⠄⣀⣠⣾⡟⠄⠄⠄⠄⠉⠙⠻
//⡿⠟⠋⠁⠄⠄⠄⢸⣿⣿⡯⢓⣴⣾⣿⣿⡟⠄⠄⠄⠄⠄⠄⠄⠄
//⠄⠄⠄⠄⠄⠄⠄⣿⡟⣷⠄⠹⣿⣿⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄
//⠄⠄⠄⠄⠄⠄⣸⣿⡷⡇⠄⣴⣾⣿⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄
//⠄⠄⠄⠄⠄⠄⣿⣿⠃⣦⣄⣿⣿⣿⠇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
//⠄⠄⠄⠄⠄⢸⣿⠗⢈⡶⣷⣿⣿⡏⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄



#if 1

#define MAXELENUM 10

#include <iostream>

using namespace std;
#endif



#if 1
class nodeElement {
public:
	int data = 0;
	int cur = 0;
};

class staticList {
public:
	staticList() {
		data[0].cur = 0;
		for (int i = 1; i < MAXELENUM - 1; i++) {
			data[i].cur = i + 1;
		}
		data[MAXELENUM - 1].cur = 1;
		return;
	}
	bool addElement(int val) {//队尾添加元素
		int current = data[0].cur;
		int dataCur;
		if (member >= MAXELENUM - 1) {
			return false;
		}
		else {
			while (data[current].cur) {//找队尾
				current = data[current].cur;
			}
			dataCur = newElement();//申请新元素下标
			data[dataCur].cur = data[current].cur;//链接元素
			data[current].cur = dataCur;
			data[dataCur].data = val;
			return true;
		}
	}
	bool deleteElement() {//队尾删除元素
		int pos = 0;
		int cur = 0;
		if (member<=0){
			return false;
		else {
			while (data[pos].cur) {//找队尾
				cur = data[pos].cur;
				pos = cur;
			}
			data[cur].cur = 0;
			deleteMember(pos);//删除元素作为第一个分配元素
			return true;
		}
	
private:
	nodeElement data[MAXELENUM];
	int member = 0;
	int newElement() {//分配内存
		int i = data[MAXELENUM - 1].cur;
		data[MAXELENUM - 1].cur = data[i].cur;
		member++;
		return i;
	}
	void deleteMember(int i) {//删除内存
		data[i].cur = data[MAXELENUM - 1].cur;
		data[MAXELENUM - 1].cur = i;
		member--;
		return;
	}
};






int main(int argc, char* argv[]) {
	staticList mylist;
	mylist.addElement(5);
	mylist.addElement(4);
	mylist.addElement(3);
	mylist.addElement(2);
	mylist.addElement(1);

	return 0;
}
#endif











#if 0
int main(int argc, char* argv[]) {

	return 0;
}
#endif

#endif