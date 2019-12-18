#include <bits/stdc++.h>
using namespace std;

int arr[15];
int arr2[15];
bool check[15];
void func(int _s, int cnt) {
	if (cnt == 6) {
		
		for (int i = 0; i < 5; i++) {
			if (arr[i] > arr[i + 1]) return;
		}
		for (int i = 0; i < 6; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

	if (_s > cnt) {
		for (int i = 0; i < _s; i++) {
			if (!check[i]) {
				check[i] = true;
				arr[cnt] = arr2[i];
				func(_s, cnt + 1);
				check[i] = false;
			}
		}
	}
}
int main() {
	int s, num;
	
	while (1) {
		cin >> s;
		if (s == 0) break;
		for (int i = 0; i < s; i++) {
			cin >> num;
			arr2[i] = num;
			
		}

		func(s, 0);
		printf("\n");

	}

	
	return 0;
}