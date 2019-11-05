#include <iostream>

using namespace std;

int main() {
	int won = 1000;
	int n;
	int cnt = 0;
	cin >> n;

	int rst = won - n;
	while (rst>0) {
		
		if (rst / 500 > 0) {
			cnt++;
			rst -= 500;
			continue;
		}

		if (rst / 100 > 0) {
			cnt++;
			rst -= 100;
			continue;
		}
		if (rst / 50 > 0) {
			cnt++;
			rst -= 50;
			continue;
		}

		if (rst / 10 > 0) {
			cnt++;
			rst -= 10;
			continue;
		}

		if (rst / 5 > 0) {
			cnt++;
			rst -= 5;
			continue;
		}

		if (rst / 1 > 0) {
			cnt++;
			rst -= 1;
			continue;
		}
	}

	cout << cnt;

	return 0;

}