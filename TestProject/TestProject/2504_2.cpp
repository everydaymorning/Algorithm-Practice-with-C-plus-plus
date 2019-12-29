#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	stack<char> s;
	stack<int> s2;
	int str_size = str.size();
	bool impossible = false;
	int tmp = 1;
	int num = 0;
	for (int i = 0; i < str_size; i++) {
		char c = str.at(i);
		if (c == '(') {
			s.push(c);
			tmp *= 2;
		}
		else if (c == '[') {
			s.push(c);
			tmp *= 3;
		}
		else if (c == ')' && (s.empty() || s.top() != '(')) {
			impossible = true;
			break;
		}
		else if (c == ']' && (s.empty() || s.top() != '[')) {
			impossible = true;
			break;
		}
		else if (c == ')') {
			if (str.at(i - 1) == '(') {
				num += tmp;
			}
			s.pop();
			tmp /= 2;
		}
		else if (c == ']') {
			if (str.at(i - 1) == '[') {
				num += tmp;
			}
			s.pop();
			tmp /= 3;
		}
		
	}
	if (impossible || !s.empty()) {
		printf("0");
	}
	else {
		printf("%d", num);
	}

	
	return 0;
}