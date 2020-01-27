#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	
	int min1 = min(w - x, x);
	int min2 = min(h - y, y);
	
	cout << min(min1, min2);

	return 0;
}