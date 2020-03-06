#include <bits/stdc++.h>
using namespace std;
int total;
int arr[10];
int sum;
int main() {
	cin >> total;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	cout << total - sum;
	return 0;
}