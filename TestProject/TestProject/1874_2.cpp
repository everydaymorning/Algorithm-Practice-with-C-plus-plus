#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> s;
queue<int> q;
string str;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}
	bool flag = false;
	int num = 1;
	while (!q.empty()) {
		
		if (num <= q.front()) {
			str += '+';
			s.push(num);
			num++;
		}
		else {
			if (s.top() >= q.front()) {
				s.pop();
				q.pop();
				str += '-';
			}
			else {
				flag = true;
				break;
			}

		}
	}
	if (flag) cout << "NO";
	else {
		for (int i = 0; i < str.length(); i++) {
			cout << str[i] << '\n';
		}
	}
	
	return 0;

}