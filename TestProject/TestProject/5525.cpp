#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, s;
	cin >> n >> s;
	string str;
	cin >> str;
	int cnt = 0;
	int check = 0;
	for (int i = 1; i < s - 1; i++) {

		if (str[i - 1] == 'I' && str[i] == 'O' && str[i + 1] == 'I') {
			check++;
			if (check == n) {
				cnt++;
				check--;
			}
			i++;
		}
		else check = 0;

	}
	cout << cnt;
	return 0;
}