#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x[201];
	int y[201];
	int rank[201];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];

	}

	for (int i = 0; i < n; i++) {
		int k = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			
			if (x[i] < x[j] && y[i] < y[j]) {
				k++;
			}
		}
		rank[i] = k;
	}

	for (int i = 0; i < n; i++) {
		cout << rank[i] << ' ';
	}
	return 0;
}