#include <bits/stdc++.h>
using namespace std;

int alphabet[26];
int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	for (int i = 0; i < n; i++) {
		cin >> alphabet[i];
	}
	int str_size = str.size();
	stack<double> s;

	for (int i = 0; i < str_size; i++) {
		if (str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/') {
			double a = s.top();
			s.pop();
			double b = s.top(); // 스택 구조상 b가 먼저 들어온 값이므로 b를 기준으로 계산
			s.pop();

			switch (str[i]) {
			case '+':
				s.push(b + a);
				break;
			case '-':
				s.push(b - a);
				break;
			case '*':
				s.push(b * a);
				break;
			case '/':
				s.push(b / a);
				break;
			}
		}
		else {
			s.push(alphabet[str[i] - 'A']); // 해당하는 인덱스의 문자에서 'A'를 빼면 입력했던 alphabet 배열의 값을 push 가능
			//ex) 'C' - 'A' = 2이기 때문에 alphabet[2]에 저장했던 3을 스택에 push
		}
	}

	double result = s.top();
	printf("%.2f", result);

	return 0;
}