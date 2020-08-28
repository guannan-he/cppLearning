#if 0

#if 1
#include <iostream>
#include "ch12_header.h"

using namespace std;
#endif



#if 0









int main(int argc, char* argv[]) {
	CGoodDynamicMatrix dm(5, 5);
	dm.fill('_');
	CGoodDynamicMatrix* dmCopy = new CGoodDynamicMatrix(dm);
	CGoodDynamicMatrix* dmCopy1 = new CGoodDynamicMatrix;
	*dmCopy1 = dm;
	dm[0][0] = '1';
	*dmCopy[0][0] = '2';
	*dmCopy1[0][0] = '3';
	cout << dm << endl;
	cout << *dmCopy << endl;
	cout << *dmCopy1 << endl;
	delete dmCopy1;
	delete dmCopy;
	return 0;
}
#endif











#if 0
int main(int argc, char* argv[]) {
	cQueue que(3);
	//cQueue que1(que);//不可访问
	cQueue que2;
	//que2 = que;//不可访问，定义在私有
	int i = 0;
	while (que.addQueue('a' + i)) {
		cout << char('a' + i) << endl;
		i++;
	}
	char non = 'p';
	i = 0;
	while (que.subQueue(non)) {
		cout << non << endl;
		i++;
	}
	que.addQueue('a' + i);
	cout<< char('a' + i) << endl;
	que.subQueue(non);
	que.addQueue('a' + i);
	return 0;
}






#endif





#if 1
bool newCustomer(int x = 6) {
	return ((rand() * x / RAND_MAX) < 1);
}
int main(int argc, char* argv[]) {
	ITEM tmp;//已经将cCustomer定义为ITEM
	//queue gen
	int queueLen = 0;
	cout << "input queue size:" << endl;
	cin >> queueLen;
	//queueLen = (queueLen < qSize) ? qSize : queueLen;
	cQueue* newQueue = new cQueue(queueLen);
	//
	int waitTime, totalWaitTime, totalLine, joinedCustomer, servedCustomer, rejectedCustomer, totalHour, totalMinute;
	int customerPerHour = 0;
	double customerInterval = 0;
	const int minPerHour = 60;
	waitTime = totalWaitTime = totalLine = joinedCustomer = servedCustomer = rejectedCustomer = 0;
	cout << "input simulate hours:" << endl;
	cin >> totalHour;
	//totalHour = (totalHour < 1) ? 1 : totalHour;
	totalMinute = totalHour * minPerHour;
	cout << "input average customers per hour:" << endl;
	cin >> customerPerHour;
	//customerPerHour = (customerPerHour < 6) ? 6 : customerPerHour;
	customerInterval = minPerHour / double(customerPerHour);
	//
	for (int i = 0; i < totalMinute; i++) {
		if (newCustomer(customerInterval)) {//add
			if (newQueue->isFull()) {//reject
				rejectedCustomer++;
			}
			else {
				servedCustomer++;
				tmp.set(i);
				newQueue->addQueue(tmp);
			}
		}
		if (waitTime <= 0 && !newQueue->isEmpty()) {//sub
			newQueue->subQueue(tmp);
			waitTime = tmp.proctm();
			totalWaitTime += i - tmp.when();
			servedCustomer++;
		}
		if (waitTime > 0) {//wait
			waitTime--;
		}
		totalLine += newQueue->queueCnt();
	}
	joinedCustomer = servedCustomer + rejectedCustomer;
	double averageLen = totalLine / double(totalMinute);
	double averageTime = totalWaitTime / double(totalMinute);
	cout << "report:" << endl;
	cout << joinedCustomer << "\tcustomers joined the line" << endl;
	cout << servedCustomer << "\tcustomers served" << endl;
	cout << rejectedCustomer << "\tcustomers rejected" << endl;
	cout << "average line length:\t" << averageLen << endl;
	cout << "average wait time:\t" << averageTime << endl;
	delete newQueue;
	return 0;
}
#endif




#endif