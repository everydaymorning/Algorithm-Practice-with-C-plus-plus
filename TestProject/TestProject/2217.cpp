#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int k = 0;
	int weight[100000] = { 0 };
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}

	sort(weight, weight + n);
	for (int i = 0; i < n; i++) {
		weight[i] = weight[i] * (n - i);
	}

	sort(weight, weight + n);

	cout << weight[n-1];
	return 0;
}