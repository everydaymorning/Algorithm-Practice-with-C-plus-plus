#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		double x1, x2, y1, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		double dis = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) printf("-1"); // 원이 겹칠 때
			else printf("0"); // 원이 안겹칠 때
		}
		else if (abs(r1 - r2) == dis || r1 + r2 == dis) printf("1"); // 원이 내접하거나 외접할 때 1개
		else if (abs(r1 - r2) < dis && r1 + r2 > dis) printf("2"); // 원의 교차점이 2개
		else printf("0");
		printf("\n");
	}

	return 0;
}