#include <bits/stdc++.h>
using namespace std;

//잃어버린 괄호 BOJ 1541
int main() { 
	string str;
	cin >> str;

	int str_size = str.size();
	string tmp = "";
	int num = 0;
	bool minus = false; // 연산에서 -가 나올 때 까지 false
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
			tmp += str[i]; // 피연산자면 문자열로 피연산자 저장
		}
	}
	
	cout << num;
	return 0;
}