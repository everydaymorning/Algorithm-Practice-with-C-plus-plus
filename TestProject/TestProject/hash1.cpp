#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	vector<string> participant, completion;
	string ans = "";
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		participant.push_back(s);
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		completion.push_back(s);
	}

	unordered_map<string, int> M;

	for (string s : completion) {
		if (M.end() == M.find(s)) {
			M.insert({ s,1 });
		}
		else {
			M[s] += 1;
		}
	}

	for (string s : participant) {
		if (M.end() == M.find(s)) {
			ans = s;
			break;
		}
		else {
			M[s] -= 1;
			if (M[s] < 0) {
				ans = s;
				break;
			}
		}
	}

	cout << ans;
	return 0;
}