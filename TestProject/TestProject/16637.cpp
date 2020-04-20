#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int num[10];
char oper[10];
int MAX = -2147483647;
int len;
int calculate(int a, int b, char op) {
	if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else if (op == '*') {
		return a * b;
	}
}
void dfs(int cnt, int sum) {
	if (cnt >= len) {
		MAX = max(MAX, sum);
		return;
	}
	dfs(cnt + 1, calculate(sum, num[cnt + 1], oper[cnt]));

	if (cnt + 1 < len) {
		int tmp = calculate(num[cnt + 1], num[cnt + 2], oper[cnt + 1]);
		dfs(cnt + 2, calculate(sum, tmp, oper[cnt]));
	}

}
int main() {
	cin >> n;
	cin >> str;
	len = n / 2;
	int j = 0;
	int k = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			num[j] = str[i] - '0';
			j++;
		}
		else {
			oper[k] = str[i];
			k++;
		}
	}
	dfs(0, num[0]);
	cout << MAX;
	return 0;
}