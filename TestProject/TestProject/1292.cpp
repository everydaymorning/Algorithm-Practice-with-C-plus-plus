#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	vector<int> v;

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j <= i; j++) {
			v.push_back(i+1);
		}
	}

	int sum = 0;
	for (int i = a-1; i <= b-1; i++) {
		sum += v.at(i);
	}

	printf("%d", sum);

	return 0;
}