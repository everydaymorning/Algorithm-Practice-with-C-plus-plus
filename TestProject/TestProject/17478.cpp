#include <bits/stdc++.h>
using namespace std;
int n;
void recur(int a) {
	for (int i = n; i > a; i--) {cout << "____";}
	cout << '"' << "����Լ��� ������?" << '"' << '\n';
	if (a == 0) {
		for (int i = n; i > a; i--) { cout << "____"; }
		cout << '"' << "����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����" << '"' << '\n';
	}
	else {
		for (int i = n; i > a; i--) { cout << "____"; }
		cout << '"' << "�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
		for (int i = n; i > a; i--) { cout << "____"; }
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
		for (int i = n; i > a; i--) { cout << "____"; }
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������." << '"' << '\n';
		recur(a - 1);
	}
	for (int i = n; i > a; i--) { cout << "____"; }
	cout << "��� �亯�Ͽ���." << '\n';
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
	recur(n);

	return 0;
}