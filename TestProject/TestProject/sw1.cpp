#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int MAP[51][51];
int TEMP[51][51];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> MAP[i][j];
			}
		}

		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < m-1; j++) {
				for (int k = i; k < i + 2; k++) {
					bool flag = false;
					for (int l = j; l < j + 2; l++) {
						if (MAP[k][l] == 0) {
							flag = true;
							break;
						}
						TEMP[k][l] = 1;
					}
					if (flag) break;
				}
			}
		}
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (MAP[i][j] != TEMP[i][j]) {
					flag = true;
				}
			}
		}
		if (!flag) cout << "YES" << '\n';
		else cout << "NO" << '\n';

		memset(TEMP, 0, sizeof(TEMP));
	}
	return 0;
}