#include <bits/stdc++.h>
using namespace std;
//최대공약수 1850 
//string으로 접근하다가 메모리초과 떠서 풀이를 보고 다시 접근함
long long gcd(long long a, long long b) {
	if (a % b == 0) {
		return b;
	}

	return gcd(b, a % b);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long a, b;
	cin >> a >> b;
	
	long long cnt = gcd(a, b);
	for (int i = 0; i < cnt; i++) {
		cout << "1";
	}

	return 0;

}