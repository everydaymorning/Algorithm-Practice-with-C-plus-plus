#include <bits/stdc++.h>
using namespace std;
char arr[17];
char arr2[17];
bool check[17];
void func(int _l, int _c, int start, int cnt) {
	int mo = 0;
	int ja = 0;
	if (_l == cnt) {
	

		for (int i = 0; i < _l; i++) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'u' || arr[i] == 'o') mo++;
			else ja++;
		}
		if (mo < 1 || ja < 2) return;

		for (int i = 0; i < _l; i++) {
			printf("%c", arr[i]);
		}
		printf("\n");
		return;
	}


	for (int i = start; i < _c; i++) {
		if (!check[i]) {
			check[i] = true;
			arr[cnt] = arr2[i];
			func(_l, _c, i + 1, cnt + 1);
			check[i] = false;
		}
	}

}
int main() {
	int l, c;
	cin >> l >> c;
	int mo = 0;
	int ja = 0;
	for (int i = 0; i < c; i++) {
		char t;
		cin >> t;
		arr2[i] = t;
	}
	sort(arr2, arr2 + c);
	func(l, c, 0, 0);

	return 0;

}