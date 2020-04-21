#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> record;
	vector<pair<string, string>> v;
	vector<string> answer;
	record.push_back("Enter uid1234 Muzi");
	record.push_back("Enter uid4567 Prodo");
	record.push_back("Leave uid1234");
	record.push_back("Enter uid1234 Prodo");
	record.push_back("Change uid4567 Ryan");

	map<string, string> ID;
	for (int i = 0; i < record.size(); i++) {
		if (record[i][0] == 'E') {
			cout << "Enter" << '\n';
			int j = 6;
			string id, name;
			while (1) {
				if (record[i][j] == ' ') {
					j++;
					break;
				}
				id += record[i][j];
				j++;
			}

			while (1) {
				if (j == record[i].size()) {
					break;
				}
				name += record[i][j];
				j++;
			}
			cout << "id: " << id << "  name: " << name << '\n';
			ID[id] = name;
			v.push_back({ "Enter", id });
		}
		else if (record[i][0] == 'L') {
			cout << "Leave" << '\n';
			string id;
			int j = 6;
			while (1) {
				if (j == record[i].size()) {
					break;
				}
				id += record[i][j];
				j++;
			}
			cout << "id: " << id << '\n';

			v.push_back({ "Leave", id });
		}
		else if (record[i][0] == 'C') {
			cout << "Change" << '\n';
			int j = 7;
			string id, name;
			while (1) {
				if (record[i][j] == ' ') {
					j++;
					break;
				}
				id += record[i][j];
				j++;
			}

			while (1) {
				if (j == record[i].size()) {
					break;
				}
				name += record[i][j];
				j++;
			}
			cout << "id: " << id << "  name: " << name << '\n';

			ID[id] = name;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == "Enter") {
			string s = ID[v[i].second];
			answer.push_back(s + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		else if (v[i].first == "Leave") {
			string s = ID[v[i].second];
			answer.push_back(s + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}