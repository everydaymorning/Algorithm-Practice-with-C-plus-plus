#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<string, int> um;
	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < v.size(); i++) {
		um.insert({ v[i],1 });
	}
	
	for (int i = 0; i < um.size() - 1; i++) {
		
	}


}