#include <bits/stdc++.h>
using namespace std;
int h1[101][101];
int h2[101][101];
int res[101][101];
int main() {
	int a, b, m;
	cin >> a >> b;
	
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> h1[i][j];
		}
	}

	cin >> b >> m;

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < m; j++) {
			cin >> h2[i][j];
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < b; k++) {
				res[i][j] += h1[i][k] * h2[k][j];
				
			}
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

	return 0;

}