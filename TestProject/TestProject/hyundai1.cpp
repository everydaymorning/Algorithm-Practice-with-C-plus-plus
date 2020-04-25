#include <bits/stdc++.h>
using namespace std;

int SUM[5];
vector<int> solution(vector<string> purchase) {
	vector<int> answer;
	vector<string> v[366];
	for (int i = 0; i < purchase.size(); i++) {
		string s;
		for (int j = 0; j < purchase[i].size(); j++) {
			if (purchase[i][j] == '/' || purchase[i][j] == ' ') {
				v[i].push_back(s);
			}
			s += purchase[i][j];
		}
		v[i].push_back(s);


	}

	return answer;
}
int main() {
	vector<string> p;
	p = { "2019/01/01 5000", "2019/01/20 15000", "2019/02/09 90000" };
	vector<int> d;
	d = solution(p);
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	return 0;
}