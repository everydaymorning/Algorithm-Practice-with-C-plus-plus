#include <bits/stdc++.h>
using namespace std;
//���� 0�� ���� BOJ 2004
int fiveCount(int a) { // a!���� 5�� ������ ��ȯ
	int cnt = 0;
	for (long long i = 5; a / i >= 1; i *= 5) {
		cnt += a / i;
	}

	return cnt;
}

int twoCount(int a) { // a!���� 2�� ������ ��ȯ
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

	five += fiveCount(a); // a!�� 5�� ����
	if (a != b) five -= fiveCount(a - b); // (a-b)!�� 5�� ������ŭ ����
	if (b != 0) five -= fiveCount(b); // b!�� 5�� ������ŭ ����

	two += twoCount(a); // a!�� 2�� ����
	if (a != b) two -= twoCount(a - b); // (a-b)!�� 2�� ������ŭ ����
	if (b != 0) two -= twoCount(b); // b!�� 2�� ������ŭ ����

	cout << min(two, five); 
	return 0;
}