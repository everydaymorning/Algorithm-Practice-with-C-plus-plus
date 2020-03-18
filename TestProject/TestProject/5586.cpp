#include <bits/stdc++.h>
using namespace std;

int main() {
	int joi = 0;
	int ioi = 0;
	string str;
	cin >> str;
	for (int i = 1; i < str.size() - 1; i++) {
		if (str[i - 1] == 'J' && str[i] == 'O' && str[i + 1] == 'I') {
			joi++;
			i++;
		}
		else if (str[i - 1] == 'I' && str[i] == 'O' && str[i + 1] == 'I') {
			ioi++;
			i++;
		}
	}
	cout << joi << '\n' << ioi;
	return 0;
}