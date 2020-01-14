#include <bits/stdc++.h>
using namespace std;

int n;
string candy[50];
int num_candy() {
	int res = 1;
	for (int i = 0; i < n; i++) { // �� �� ��
		int tmp = 1;
		for (int j = 1; j < n; j++) {
			if (candy[i][j - 1] == candy[i][j]) { // ���� ������ ĵ�� ���� ������ ����
				tmp++;
			}
			else {
				res = max(res, tmp); // ĵ�� ���� �ٸ��� �� ������ ĵ�� ������ ����
				tmp = 1; // ĵ�� ���� �ٽ� 1�� ����
			}
		}
		res = max(res, tmp); // ���� ���� ������ ĵ�� ���� ���Ͽ� �ִ� ����
	}

	for (int i = 0; i < n; i++) { // �� �Ʒ� ��
		int tmp = 1;
		for (int j = 1; j < n; j++) {
			if (candy[j - 1][i] == candy[j][i]) { //���� ������ ĵ�� ���� ������ ����
				tmp++;
			}
			else {
				res = max(res, tmp); // ĵ�� ���� �ٸ��� �� ������ ĵ�� ���� ����
				tmp = 1;
			}
		}
		res = max(res, tmp); // ���� ���� �� ���� ĵ�� ���� ���Ͽ� �ִ� ����
	}

	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> candy[i];
	}


	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			swap(candy[i][j], candy[i][j+1]); // �� �� �ٲٱ�
			result = max(result, num_candy()); // �ٲ��� ���� �ִ� ĵ�� ����
			swap(candy[i][j], candy[i][j+1]); // �ٽ� �ٲٱ�

			swap(candy[j][i], candy[j + 1][i]); // �� �Ʒ� �ٲٱ�
			result = max(result, num_candy()); // �ٲ��� ���� �ִ� ĵ�� ����
			swap(candy[j][i], candy[j + 1][i]); // �ٽ� �ٲٱ�
		}
	}

	cout << result;

	return 0;
}