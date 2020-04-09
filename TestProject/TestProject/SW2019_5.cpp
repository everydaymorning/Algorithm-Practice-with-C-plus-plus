#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> words;
	int n;
	cin >> n;
	unordered_map<string, int> MAP;
	words.push_back("tank");
	words.push_back("kick");
	words.push_back("know");
	words.push_back("wheel");
	words.push_back("land");
	words.push_back("dream");
	words.push_back("mother");
	words.push_back("robot");
	words.push_back("tank");
	int cnt = 0;
	bool flag = true;
	string s;
	for (int i = 0; i < words.size(); i++) {
		if ((i + 1) % n == 0) cnt++;
		//cout << "s.back: " << s.back() << " " << words[i][0] << '\n';
		if (MAP[words[i]] || (!s.empty() && (s.back() != words[i][0]))) {
			cout << (i % n) + 1 << " " << cnt;
			flag = false;
			break;
		}
		else {
			MAP[words[i]]++;
			s = words[i];
		}
	}
	if (flag) {
		cout << "0" << " 0";
	}

	return 0;
}