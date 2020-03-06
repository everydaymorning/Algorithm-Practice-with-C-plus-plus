#include <bits/stdc++.h>
using namespace std;
int arr[5];
int day, cnt;
int main() {
	cin >> day;

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (arr[i] == day) cnt++;
	}
	cout << cnt;
	return 0;
}