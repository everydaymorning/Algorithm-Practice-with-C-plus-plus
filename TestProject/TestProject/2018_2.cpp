#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<char> alpha;
vector<pair<int, char>> option;
vector<int> ans;
int solution(string dartResult) {
	int total = 0;
	int idx = 0;
	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] >= '0' && dartResult[i] <= '9') {
			int num = dartResult[i] - '0';
			if (num == 1) {
				if (dartResult[i + 1] == '0') {
					num = 10;
					i++;
				}
			}
			v.push_back(num);
			idx++;
		}
		else if (dartResult[i] >= 'A' && dartResult[i] <= 'Z') {
			alpha.push_back(dartResult[i]);
		}
		else {
			option.push_back({ idx, dartResult[i] });
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int num = 0;
		if (alpha[i] == 'S') {
			num = (int)pow(v[i], 1);
		}
		else if (alpha[i] == 'D') {
			num = (int)pow(v[i], 2);
		}
		else if (alpha[i] == 'T') {
			num = (int)pow(v[i], 3);
		}
		ans.push_back(num);
	}
	for (int i = 0; i < option.size(); i++) {
		int index = option[i].first - 1;
		char op = option[i].second;
		if (op == '*') {
			if (index == 0) {
				ans[index] *= 2;
			}
			else {
				ans[index - 1] *= 2;
				ans[index] *= 2;
			}
		}
		else if (op == '#'){
			ans[index] *= -1;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		total += ans[i];
	}
	return total;
}

int main() {
	string dart = "1D2S#10S";
	int ans = solution(dart);
	cout << ans;
	return 0;
}