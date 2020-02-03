#include <bits/stdc++.h>
using namespace std;
int sudoku[82][82];
bool ROW[10][10];
bool COL[10][10];
bool SQUARE[10][10];

void dfs(int cnt) {
	if (cnt == 81) { // ������ �� ä�������� ����ϰ� ���α׷� ����
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << '\n';
		}
		exit(0);
	}
	//��ǥ ����
	int x = cnt / 9;
	int y = cnt % 9;

	if (sudoku[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (!ROW[x][i] && !COL[y][i] && !SQUARE[(x / 3) * 3 + (y / 3)][i]) {
				// �࿡ i�� ���� ���� i�� ���� ���� �簢���� i�� ������
				ROW[x][i] = true;
				COL[y][i] = true;
				SQUARE[(x / 3) * 3 + (y / 3)][i] = true;
				sudoku[x][y] = i; // i�� �ش��ϴ� ���ڸ� �־���
				dfs(cnt + 1);
				sudoku[x][y] = 0;
				ROW[x][i] = false;
				COL[y][i] = false;
				SQUARE[(x / 3) * 3 + (y / 3)][i] = false;
			}
		}
	}
	else {
		dfs(cnt + 1);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] != 0) { // 0�� �ƴϸ�
				ROW[i][sudoku[i][j]] = true; // i��° �࿡ sudoku[i][j]�� �ش��ϴ� ���ڰ� �����Ѵٴ� ���� ǥ��
				COL[j][sudoku[i][j]] = true; // j��° ���� sudoku[i][j]�� �ش��ϴ� ���ڰ� �����Ѵٴ� ���� ǥ��
				SQUARE[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true; // (i / 3) * 3 + (j / 3)��° ���� �簢���� sudoku[i][j]�� �ش��ϴ� ���ڰ� �����Ѵٴ� ���� ǥ��
			}
		}
	}

	dfs(0);

	return 0;
}