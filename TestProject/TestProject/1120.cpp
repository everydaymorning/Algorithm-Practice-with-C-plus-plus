#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	int dif = 0;
	
	cin >> a >> b;

	int len_a = a.length();
	int len_b = b.length();
	dif = len_a;
	for (int i = 0; i <= len_b - len_a; i++) {
		int tmp = 0;

		for (int j = 0; j < len_a; j++) {
			if (a[j] != b[i + j]) {
				tmp++;
			}
		}

		if (dif > tmp) dif = tmp;
	}

	cout << dif << endl;
	
	return 0;

}