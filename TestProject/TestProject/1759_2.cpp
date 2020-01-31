#include <bits/stdc++.h>
using namespace std;
char alpha[16];
int l, c;
bool check[16];
vector<char> v;
int ja, mo;
void dfs(int idx, int cnt) {
	if (cnt == l) {
		if (mo >= 1 && ja >= 2) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			}
			cout << '\n';
		}
		
		return;
	}

	for (int i = idx; i < c; i++) {
		if (check[i]) continue;
		check[i] = true;
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u') {
			mo++;
		}
		else {
			ja++;
		}
		v.push_back(alpha[i]);
		dfs(i, cnt + 1);
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u') {
			mo--;
		}
		else {
			ja--;
		}
		v.pop_back();
		check[i] = false;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		cin >> alpha[i];
	}

	sort(alpha, alpha + c);
	dfs(0, 0);


	return 0;
}