#if 0
#if 1
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
#endif



#if 0
int main(int argc, char* argv[]) {
	int nInt = INT_MAX;
	short nShort = SHRT_MAX;
	long nLong = LONG_MAX;
	cout << nInt << endl;
	cout << nShort << endl;
	cout << nLong << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(long long) << endl;
	__int64 side = 210303199999999991;
	cout << side << endl;
	return 0;
}
#endif
#if 0
int main(int argc, char* argv[]) {
	int sec = 0, mint = 0, deg = 0;
	cout << "deg:" << endl;
	cin >> deg;
	cout << "mint:" << endl;
	cin >> mint;
	cout << "sec:" << endl;
	cin >> sec;
	float act = 0.0;
	act = deg + mint / 60.0 + sec / 3600.0;
	cout << act << endl;
	return 0;
}
#endif

#if 0
int main(int argc, char* argv[]) {
	long total = 0;
	int day = 0, hr = 0, min = 0, sec = 0;
	cin >> total;
	sec = total % 60;
	total /= 60;
	min = total % 60;
	total /= 60;
	hr = total % 24;
	day = total / 24;
	cout << day << ":" << hr << ":" << min << ":" << sec << endl;
	return 0;
}
#endif

#if 1
int main(int argc, char* argv[]) {

	return 0;
}
#endif
#endif