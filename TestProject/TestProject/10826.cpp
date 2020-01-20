#include <bits/stdc++.h>
using namespace std;
string str_dp[10001];

string sum(string x, string y) {
	long long num;
	int carry = 0;
	string result;

	reverse(x.begin(), x.end()); 
	reverse(y.begin(), y.end());

	while (x.length() < y.length()) { // 자릿수 맞춰주기
		x += '0';
	}
	while (x.length() > y.length()) { // 자릿수 맞춰주기
		y += '0';
	}

	for (int i = 0; i < (int)x.length(); i++) {
		num = (x[i] - '0' + y[i] - '0' + carry) % 10; // 1의 자리부터 더한 뒤 올림이 발생하면 carry를 더함
		result.append(to_string(num));
		carry = (x[i] - '0' + y[i] - '0' + carry) / 10; // 각 자릿수에서 발생한 올림수를 저장
	}

	if (carry != 0) {
		result.append(to_string(carry)); // 만약 carry가 남아있다면 더하기
	}

	reverse(result.begin(), result.end());

	return result;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	
	str_dp[0] = '0';
	str_dp[1] = '1';

	for (int i = 2; i <= n; i++) {
		str_dp[i] = sum(str_dp[i - 2], str_dp[i - 1]);
	}
	cout << str_dp[n];
	return 0;

}