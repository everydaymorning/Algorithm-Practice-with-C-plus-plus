#include <bits/stdc++.h>
using namespace std;

vector<long long> num;
vector<char> op;
vector<char> op1 = { '+', '-', '*' };
long long TEMP[101];
bool check[1000];
long long MAX;
long long solution(string expression) {
	string s = "";
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '-' || expression[i] == '*' || expression[i] == '+') {
			long long tmp = stoll(s);
			num.push_back(tmp);
			s = "";
			op.push_back(expression[i]);
			continue;
		}
		s += expression[i];
	}
	long long tmp = stoll(s);
	num.push_back(tmp);
	for (int i = 0; i < num.size(); i++) {
		TEMP[i] = num[i];
	}
	do {
		int sum = 0;
		for (int i = 0; i < op1.size(); i++) {
			for (int j = 0; j < op.size(); j++) {
				if (op1[i] == op[j]) {
					if (op1[i] == '+') {
						sum = TEMP[i] + TEMP[i + 1];
					}
					else if (op1[i] == '-') {
						sum = TEMP[i] - TEMP[i + 1];
					}
					else if (op1[i] == '*') {
						sum = TEMP[i] * TEMP[i + 1];
					}
				}
			}
		}

	} while (next_permutation(op1.begin(), op1.end()));
	return MAX;
}
int main() {
	string str = "100-200*300-500+20";
	long long ans = solution(str);
	cout << ans;
	return 0;
}