#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	string str;
	int n = 0;
	int sum = 0;
	bool zero = false;
	cin >> str;
	int len = str.length();
	vector<int> v;

	for (int i = 0; i < len; i++) {
		n = str[i] - '0';
		v.push_back(n);
		sum += n;
		if (n == 0) zero = true;
	}
	
	if (sum % 3 == 0 && zero == true) {
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); i++) {
			printf("%d", v[i]);
		}
	}
	else {
		cout << "-1" << endl;
	}
	return 0;

	

}