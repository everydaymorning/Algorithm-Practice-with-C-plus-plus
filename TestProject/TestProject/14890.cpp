#include <bits/stdc++.h>
using namespace std;
int n, l;
int MAP[101][101];
int MAP2[101][101];
int cnt;
bool canRoad(int x, int y) {
	int tmp = MAP[x][y + 1];
	for (int k = y + 1; k < y + 1 + l; k++) {
		if (MAP[x][k] != tmp) return false; 
	}
	return true;
}

bool canRoad2(int x, int y) {
	int tmp = MAP2[x][y + 1];
	for (int k = y + 1; k < y + 1 + l; k++) { // ���� ��ġ���� ���� L��ŭ ����
		if (MAP2[x][k] != tmp) return false; // ���� ���̰� �ٸ��� ���� ��ġ���� ���� ��ġ ���ϹǷ� false ����
	}
	return true; // ���̰� ��� ������ true ����
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
			MAP2[j][i] = MAP[i][j]; // �������� ��üũ�� ���� �ϱ� ���� ���� ������ �ű�
		}
	}

	for (int i = 0; i < n; i++) {
		bool flag = true; // flag�� false�� ���θ� ������ ���Ͽ� ���� �� �� ����
		int road_len = 1; // ���� ������ ���� �� ���� ����
		for (int j = 0; j < n - 1; j++) {
			if (MAP[i][j] == MAP[i][j + 1]) road_len++; // ���� ��ġ�� ���� ��ġ�� ���̰� ������ ���� ���� 1 ����
			else if (MAP[i][j] + 1 == MAP[i][j + 1]) { // ���� ��ġ���� ���� ��ġ�� ���� ���
				if (road_len >= l) { // ���θ� ��ġ�� �� �ִ� ���̸� 
					road_len = 1; // ���� ���� 1�� �ʱ�ȭ
				}
				else { // ���θ� ��ġ�� �� ���� ���̸�
					flag = false; // �� ���� ��� ����
					break;
				}
			}
			else if (MAP[i][j] == MAP[i][j + 1] + 1) { // ���� ��ġ�� ���� ��ġ���� ������
				if (canRoad(i, j)) { // ���� ��ġ���� ���̰� L�� ���θ� ��ġ�� �� ������
					j = j + l - 1; // ��ġ ����
					road_len = 0; // ���� ���� 0���� �ʱ�ȭ , 1�� �ʱ�ȭ�ϸ� ���ΰ� ��ĥ �� ����
				}
				else { // ���� ��ġ ���ϸ�
					flag = false; // �� ���� ��� ����
					break;
				}
			}
			else if (abs(MAP[i][j] - MAP[i][j + 1]) >= 2) { // ���� ��ġ�� ���� ��ġ�� ���� ���̰� 2�̻��̸�
				flag = false; // �� ���� ��� ����
				break;
			}
		}
		if (flag) {
			cnt++;
		}
	}

	for (int i = 0; i < n; i++) {
		bool flag = true;
		int road_len = 1;
		for (int j = 0; j < n - 1; j++) {
			if (MAP2[i][j] == MAP2[i][j + 1]) road_len++;
			else if (MAP2[i][j] + 1 == MAP2[i][j + 1]) {
				if (road_len >= l) {
					road_len = 1;
				}
				else {
					flag = false;
					break;
				}
			}
			else if (MAP2[i][j] == MAP2[i][j + 1] + 1) {
				if (canRoad2(i, j)) {
					j = j + l - 1;
					road_len = 0;
				}
				else {
					flag = false;
					break;
				}
			}
			else if (abs(MAP2[i][j] - MAP2[i][j + 1]) >= 2) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}