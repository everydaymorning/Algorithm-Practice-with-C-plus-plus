#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> sheets;
	string answer_sheet;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		sheets.push_back(s);
	}
	cin >> answer_sheet;
	int MAX = 0;
	int con_max = 0;
	for (int i = 0; i < sheets.size() - 1; i++) {
		for (int j = i+1; j < sheets.size(); j++) {
			int cnt = 0;
			int cont = 0;
			
			for (int k = 0; k < sheets[i].size(); k++) {
				if (sheets[i][k] == sheets[j][k]) {
					if (sheets[i][k] != answer_sheet[k] && sheets[j][k] != answer_sheet[k]) {
						cnt++;
						cont++;
					}
				}
				else {
					con_max = max(con_max, cont);
					cont = 0;
				}
			}
			int sum = 0;
			if (con_max == 0) {
				sum = cnt + pow(cont, 2);
			}
			else {
				sum = cnt + pow(con_max, 2);
			}
			MAX = max(MAX, sum);
		}
	}

	cout << MAX;
	return 0;
}