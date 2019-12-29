#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int t;
		cin >> t;
		v.push_back(t);
		sum += t;
	}
	sort(v.begin(), v.end());

	
	for (int i = 0; i < 9; i++) {	
		for (int j = i+1; j < 9; j++) {
			if (sum - v.at(i) - v.at(j) == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						printf("%d\n", v.at(k));
					}
					
				}
				return 0;
			}
		}
	}
	
	return 0;
}