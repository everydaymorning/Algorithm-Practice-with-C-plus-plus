#include <bits/stdc++.h>
using namespace std;


int main() {
	string str;
	cin >> str;

	int str_size = str.size();
	string tmp = "";
	int num = 0;
	bool minus = false;
	for (int i = 0; i <= str_size; i++) {
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0') { // 문자열의 끝에 왔을 때도 연산해야함
			if (minus) {
				num -= stoi(tmp);
			}
			else {
				num += stoi(tmp);
			}
			tmp = "";
			if(str[i] == '-') minus = true;

		}
		else {
			tmp += str[i];
		}
	}
	
	cout << num;
	return 0;
}