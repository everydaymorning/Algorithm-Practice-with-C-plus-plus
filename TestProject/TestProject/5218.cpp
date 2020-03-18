#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		cout << "Distances: ";
		for (int i = 0; i < a.size(); i++) {
			if ((int)a[i] <= b[i]) {
				cout << (int)b[i] - (int)a[i] << " ";
			}
			else {
				cout << (int)(b[i] + 26) - (int)a[i] << " ";
			}
		}
		cout << '\n';
	}
	return 0;
}