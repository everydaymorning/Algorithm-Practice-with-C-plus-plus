#include <bits/stdc++.h>
using namespace std;
//�ִ����� 1850 
//string���� �����ϴٰ� �޸��ʰ� ���� Ǯ�̸� ���� �ٽ� ������
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