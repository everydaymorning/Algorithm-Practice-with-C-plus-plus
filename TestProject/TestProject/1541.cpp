#include <bits/stdc++.h>
using namespace std;

//�Ҿ���� ��ȣ BOJ 1541
int main() { 
	string str;
	cin >> str;

	int str_size = str.size();
	string tmp = "";
	int num = 0;
	bool minus = false; // ���꿡�� -�� ���� �� ���� false
	for (int i = 0; i <= str_size; i++) {
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0') { // ���ڿ��� ���� ���� ���� �����ؾ���
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
			tmp += str[i]; // �ǿ����ڸ� ���ڿ��� �ǿ����� ����
		}
	}
	
	cout << num;
	return 0;
}