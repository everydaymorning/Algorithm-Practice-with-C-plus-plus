#include <bits/stdc++.h>
using namespace std;
int sudoku[82][82];
bool ROW[10][10];
bool COL[10][10];
bool SQUARE[10][10];

void dfs(int cnt) {
	if (cnt == 81) { // 스도쿠가 다 채워졌으면 출력하고 프로그램 종료
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << '\n';
		}
		exit(0);
	}
	//좌표 설정
	int x = cnt / 9;
	int y = cnt % 9;

	if (sudoku[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (!ROW[x][i] && !COL[y][i] && !SQUARE[(x / 3) * 3 + (y / 3)][i]) {
				// 행에 i가 없고 열에 i가 없고 작은 사각형에 i가 없으면
				ROW[x][i] = true;
				COL[y][i] = true;
				SQUARE[(x / 3) * 3 + (y / 3)][i] = true;
				sudoku[x][y] = i; // i에 해당하는 숫자를 넣어줌
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
			if (sudoku[i][j] != 0) { // 0이 아니면
				ROW[i][sudoku[i][j]] = true; // i번째 행에 sudoku[i][j]에 해당하는 숫자가 존재한다는 것을 표시
				COL[j][sudoku[i][j]] = true; // j번째 열에 sudoku[i][j]에 해당하는 숫자가 존재한다는 것을 표시
				SQUARE[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true; // (i / 3) * 3 + (j / 3)번째 작은 사각형에 sudoku[i][j]에 해당하는 숫자가 존재한다는 것을 표시
			}
		}
	}

	dfs(0);

	return 0;
}