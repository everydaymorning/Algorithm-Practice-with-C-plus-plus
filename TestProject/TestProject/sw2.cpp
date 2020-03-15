#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int arr[3001];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} 

	int end = n - (k - 1);
	int MAX = 0;
	int MIN = 10001;
	for (int i = 0; i < end; i++) {
		MAX = max(MAX, arr[i]);
		MIN = min(MIN, arr[i]);
	}
	int cost = MAX - MIN;
	cout << cost << '\n';
	return 0;

}