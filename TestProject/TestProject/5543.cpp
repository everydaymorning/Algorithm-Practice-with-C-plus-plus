#include <bits/stdc++.h>
using namespace std;
int burger[3];
int drink[2];
int MIN_BURGER = 2001;
int MIN_DRINK = 2001;
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> burger[i];
		MIN_BURGER = min(MIN_BURGER, burger[i]);
	}

	for (int i = 0; i < 2; i++) {
		cin >> drink[i];
		MIN_DRINK = min(MIN_DRINK, drink[i]);
	}
	cout << MIN_BURGER + MIN_DRINK - 50;
	return 0;
}