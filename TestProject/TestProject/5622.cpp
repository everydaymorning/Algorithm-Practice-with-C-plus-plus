#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;

	int sum = 0;
	int str_size = str.size();
	for (int i = 0; i < str_size; i++) {
		if (str.at(i) == 'A' || str.at(i) == 'B' || str.at(i) == 'C') {
			sum += 3;
		}
		else if (str.at(i) == 'D' || str.at(i) == 'E' || str.at(i) == 'F') {
			sum += 4;
		}
		else if (str.at(i) == 'G' || str.at(i) == 'H' || str.at(i) == 'I') {
			sum += 5;
		}
		else if (str.at(i) == 'J' || str.at(i) == 'K' || str.at(i) == 'L') {
			sum += 6;
		}
		else if (str.at(i) == 'M' || str.at(i) == 'N' || str.at(i) == 'O') {
			sum += 7;
		}
		else if (str.at(i) == 'P' || str.at(i) == 'Q' || str.at(i) == 'R' || str.at(i) == 'S') {
			sum += 8;
		}
		else if (str.at(i) == 'T' || str.at(i) == 'U' || str.at(i) == 'V') {
			sum += 9;
		}
		else if (str.at(i) == 'W' || str.at(i) == 'X' || str.at(i) == 'Y' || str.at(i) == 'Z') {
			sum += 10;
		}
	}

	printf("%d", sum);
}