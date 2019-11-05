#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	cin >> str;
	int str_len = str.length();
	list<char> a;
	//list<char>::iterator it; // list의 원소들을 출력하기 위한 반복자 선언
	for (int i = 0; i < str_len; i++) {
		a.push_back(str.at(i));
	}
	list<char>::iterator it;
	
	auto cursor = a.end();

	int n;
	cin >> n;
	string tmp;
	getline(cin, tmp);

	for (int i = 0; i < n; i++) {
		string sel;
		getline(cin, sel);

		if (sel.at(0) == 'L') {
			if (cursor != a.begin()) cursor--;
		}
		else if (sel.at(0) == 'D') {
			if (cursor != a.end()) cursor++;
		}
		else if (sel.at(0) == 'B') {
			if (cursor != a.begin()) {
				cursor--;
				cursor = a.erase(cursor);
			}
		}
		else {
			a.insert(cursor, sel[2]);
		}
	}
	for (it = a.begin(); it != a.end(); it++) {
		cout << *it;
	}
	return 0;
}