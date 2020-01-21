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
			double b = s.top(); // ���� ������ b�� ���� ���� ���̹Ƿ� b�� �������� ���
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
			s.push(alphabet[str[i] - 'A']); // �ش��ϴ� �ε����� ���ڿ��� 'A'�� ���� �Է��ߴ� alphabet �迭�� ���� push ����
			//ex) 'C' - 'A' = 2�̱� ������ alphabet[2]�� �����ߴ� 3�� ���ÿ� push
		}
	}

	double result = s.top();
	printf("%.2f", result);

	return 0;
}