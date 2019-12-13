#include <bits/stdc++.h>

using namespace std;
bool issued1[40];
bool issued2[40];
bool issued3[40];
int rst;
void func(int _n, int cnt) {
	if (_n == cnt) {
		rst++;
		//printf("%d \n", rst);
		return;
	}

	if (_n > cnt) {
		for (int i = 0; i < _n; i++) {
			if (!issued1[i] && !issued2[i + cnt] && !issued3[i - cnt + _n - 1]) {
				issued1[i] = true;
				issued2[i + cnt] = true;
				issued3[i - cnt + _n - 1] = true;
				//printf("함수 실행 전 i: %d    cnt: %d\n", i, cnt);
				func(_n, cnt + 1);
				//printf("함수 실행 후 i: %d    cnt: %d\n", i, cnt);
				issued1[i] = false;
				issued2[i + cnt] = false;
				issued3[i - cnt + _n - 1] = false;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;

	func(n, 0);

	printf("%d", rst);
	return 0;

}