#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> id_list;
	id_list.push_back("JAY");
	id_list.push_back("JAY ELLE JAY MAY");
	id_list.push_back("MAY ELLE MAY");
	id_list.push_back("ELLE MAY");
	id_list.push_back("ELLE ELLE ELLE");
	id_list.push_back("MAY");

	int k;
	cin >> k;

	map<string, int> MAP;
	int ans = 0;
	for (int i = 0; i < id_list.size(); i++) {
		vector<string> v;
		string s;

		map<string, int> M1;
		for (int j = 0; j < id_list[i].size(); j++) {
			
			if (id_list[i][j] == ' ') {
				v.push_back(s);
				s = "";
			}
			else s += id_list[i][j];
		}
		v.push_back(s);
		
		for (int j = 0; j < v.size(); j++) {
			M1[v[j]]++;
			if (M1[v[j]] > 1) continue;
			if (MAP[v[j]] < k) {
				cout << "MAP: " << v[j] << "  " << MAP[v[j]] << '\n';
				
				ans++;
			}
			MAP[v[j]]++;

		}

	}
	cout << ans;
	return 0;
}