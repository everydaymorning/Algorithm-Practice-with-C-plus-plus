#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int str_size = str.length();
		int score = 0;
		int sum = 0;
		for (int i = 0; i < str_size; i++) {
			if (str[i] == 'O') score++;
			else if (str[i] == 'X') score = 0;
			sum += score;
		}

		printf("%d\n", sum);
	}

	return 0;
}