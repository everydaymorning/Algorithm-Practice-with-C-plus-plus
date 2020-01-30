#include <bits/stdc++.h>
using namespace std;
//조합 0의 개수 BOJ 2004
int fiveCount(int a) { // a!에서 5의 개수를 반환
	int cnt = 0;
	for (long long i = 5; a / i >= 1; i *= 5) {
		cnt += a / i;
	}

	return cnt;
}

int twoCount(int a) { // a!에서 2의 개수를 반환
	int cnt = 0;
	for (long long i = 2; a / i >= 1; i *= 2) {
		cnt += a / i;
	}
	return cnt;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int a, b;
	cin >> a >> b;
	
	int five = 0;
	int two = 0;

	five += fiveCount(a); // a!의 5의 개수
	if (a != b) five -= fiveCount(a - b); // (a-b)!의 5의 개수만큼 빼줌
	if (b != 0) five -= fiveCount(b); // b!의 5의 개수만큼 빼줌

	two += twoCount(a); // a!의 2의 개수
	if (a != b) two -= twoCount(a - b); // (a-b)!의 2의 개수만큼 빼줌
	if (b != 0) two -= twoCount(b); // b!의 2의 개수만큼 빼줌

	cout << min(two, five); 
	return 0;
}