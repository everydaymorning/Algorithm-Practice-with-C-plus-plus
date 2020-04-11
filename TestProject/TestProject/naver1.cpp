#include <bits/stdc++.h>
using namespace std;
int check[1001];
int main() {
	vector<vector<int>> delivery;
	int n;
	cin >> n;
	delivery.push_back({ 3,5,0 });
	delivery.push_back({ 1,3,1 });
	delivery.push_back({ 5,4,0 });
	delivery.push_back({ 2,5,0 });

	string answer;
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < delivery.size(); i++) {
			if (delivery[i][2] == 1) {
				check[delivery[i][0]] = 2;
				check[delivery[i][1]] = 2;
			}
			else if (delivery[i][2] == 0) {
				if (check[delivery[i][0]] == 2 || check[delivery[i][1]] == 2) {
					if (check[delivery[i][0]] == 2) {
						check[delivery[i][1]] = 3;
					}
					else if (check[delivery[i][1]] == 2) {
						check[delivery[i][0]] = 3;
					}
				}
				else if (check[delivery[i][0]] == 3 || check[delivery[i][1]] == 3) {
					if (check[delivery[i][0]] == 3) {
						check[delivery[i][1]] = 0;
					}
					else if (check[delivery[i][1]] == 3) {
						check[delivery[i][0]] = 0;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 2) {
			answer += "O";
		}
		else if (check[i] == 3) {
			answer += "X";
		}
		else {
			answer += "?";
		}
	}
	cout << answer;
	return 0;
}