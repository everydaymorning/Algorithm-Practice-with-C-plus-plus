#include <iostream>
using namespace std;
// Student ID: 201433853
// Name: �̼���
int n; // input n
int col[15]; // �� �÷��� �ش��ϴ� ���� �����ϱ� ���� �迭 (10�̻� �׽�Ʈ�� ���� ����� 15�� ����)
int total; // ����� ���� ������ ����
bool promising(int idx) {
	int k = 1;
	bool flag = true;

	while (k < idx && flag) {
		if ((col[idx] == col[k]) || abs(col[idx] - col[k]) == idx - k) {
			flag = false;
		}
		k++;
	}
	return flag;
}
void queens(int idx) {
	if (promising(idx)) {
		if (idx == n) {
			total++;
			cout << total << ": [";
			for (int i = 1; i <= n; i++) {
				if (i == n) cout << "<" << i << "," << col[i] << ">";
				else cout << "<" << i << "," << col[i] << ">, ";
			}
			cout << "]\n";
		}
		else {
			for (int i = 1; i <= n; i++) {
				col[idx + 1] = i;
				queens(idx + 1);
			}
		}
	}
}
int main() {
	cin >> n;
	queens(0);
	cout << "Total number: " << total;
	return 0;
}