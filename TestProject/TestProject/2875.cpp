#include <iostream>

using namespace std;

int main() {
	int n, m, k;
	int team = 0;
	cin >> n >> m >> k;

	
	while (n >= 2 && m >= 1 && m + n >= k + 3) {
		n -= 2;
		m--;
		team++;
	}

	
	cout << team << endl;

	return 0;
}