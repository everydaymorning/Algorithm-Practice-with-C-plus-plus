#include <bits/stdc++.h>
using namespace std;
int k;
int MAP[5][9];

int reverse_d(int d) {
	if (d == 1) return -1;
	else return 1;
}

void solution(int num, int d) {
	if (d == 1) {
		int tmp = MAP[num][7];
		for (int i = 7; i > 0; i--) {
			MAP[num][i] = MAP[num][i - 1];
		}
		MAP[num][0] = tmp;
	}
	else {
		int tmp = MAP[num][0];
		for (int i = 0; i < 7; i++) {
			MAP[num][i] = MAP[num][i + 1];
		}
		MAP[num][7] = tmp;
	}
}

int count_point() {
	int cnt = 0;
	if (MAP[1][0] == 1) cnt += 1;
	if (MAP[2][0] == 1) cnt += 2;
	if (MAP[3][0] == 1) cnt += 4;
	if (MAP[4][0] == 1) cnt += 8;
	return cnt;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 1; i <= 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			MAP[i][j] = str[j] - '0';
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		int num, d;
		cin >> num >> d;
		int nd = reverse_d(d);
		if (num == 1) {
			if (d == 1) {
				if (MAP[num][2] != MAP[num + 1][6]) {
					if (MAP[num + 1][2] != MAP[num + 2][6]) {
						if (MAP[num + 2][2] != MAP[num + 3][6]) {
							solution(num, d);
							solution(num + 1, nd);
							solution(num + 2, d);
							solution(num + 3, nd);
						}
						else {
							solution(num, d);
							solution(num + 1, nd);
							solution(num + 2, d);
						}
					}
					else {
						solution(num, d);
						solution(num + 1, nd);
					}
				}
				else {
					solution(num, d);
				}
			}
			else {
				if (MAP[num][2] != MAP[num + 1][6]) {
					if (MAP[num + 1][2] != MAP[num + 2][6]) {
						if (MAP[num + 2][2] != MAP[num + 3][6]) {
							solution(num, d);
							solution(num + 1, nd);
							solution(num + 2, d);
							solution(num + 3, nd);
						}
						else {
							solution(num, d);
							solution(num + 1, nd);
							solution(num + 2, d);
						}
					}
					else {
						solution(num, d);
						solution(num + 1, nd);
					}
				}
				else {
					solution(num, d);
				}

			}

		}
		else if (num == 2) {
			if (d == 1) {
				if (MAP[num - 1][2] != MAP[num][6]) {
					solution(num - 1, nd);
				}
				if (MAP[num][2] != MAP[num + 1][6]) {
					if (MAP[num + 1][2] != MAP[num + 2][6]) {
						solution(num, d);
						solution(num + 1, nd);
						solution(num + 2, d);
					}
					else {
						solution(num, d);
						solution(num + 1, nd);
					}
				}
				else {
					solution(num, d);
				}
			}
			else {
				if (MAP[num - 1][2] != MAP[num][6]) {
					solution(num - 1, nd);
				}
				if (MAP[num][2] != MAP[num + 1][6]) {
					if (MAP[num + 1][2] != MAP[num + 2][6]) {
						solution(num, d);
						solution(num + 1, nd);
						solution(num + 2, d);
					}
					else {
						solution(num, d);
						solution(num + 1, nd);
					}
				}
				else {
					solution(num, d);
				}
			}
		}
		else if (num == 3) {
			if (d == 1) {
				if (MAP[num - 1][2] != MAP[num][6]) {
					if (MAP[num - 2][2] != MAP[num - 1][6]) {
						solution(num - 1, nd);
						solution(num - 2, d);
					}
					else {
						solution(num - 1, nd);
					}
				}
				if (MAP[num][2] != MAP[num + 1][6]) {
					solution(num, d);
					solution(num + 1, nd);
				}
				else {
					solution(num, d);
				}
			}
			else {
				if (MAP[num - 1][2] != MAP[num][6]) {
					if (MAP[num - 2][2] != MAP[num - 1][6]) {
						solution(num - 1, nd);
						solution(num - 2, d);
					}
					else {
						solution(num - 1, nd);
					}
				}
				if (MAP[num][2] != MAP[num + 1][6]) {
					solution(num, d);
					solution(num + 1, nd);
				}
				else {
					solution(num, d);
				}
			}
		}
		else if (num == 4) {
			if (d == 1) {
				if (MAP[num - 1][2] != MAP[num][6]) {
					if (MAP[num - 2][2] != MAP[num - 1][6]) {
						if (MAP[num - 3][2] != MAP[num - 2][6]) {
							solution(num, d);
							solution(num - 1, nd);
							solution(num - 2, d);
							solution(num - 3, nd);
						}
						else {
							solution(num, d);
							solution(num - 1, nd);
							solution(num - 2, d);
						}
					}
					else {
						solution(num, d);
						solution(num - 1, nd);
					}
				}
				else {
					solution(num, d);
				}
			}
			else {
				if (MAP[num - 1][2] != MAP[num][6]) {
					if (MAP[num - 2][2] != MAP[num - 1][6]) {
						if (MAP[num - 3][2] != MAP[num - 2][6]) {
							solution(num, d);
							solution(num - 1, nd);
							solution(num - 2, d);
							solution(num - 3, nd);
						}
						else {
							solution(num, d);
							solution(num - 1, nd);
							solution(num - 2, d);
						}
					}
					else {
						solution(num, d);
						solution(num - 1, nd);
					}
				}
				else {
					solution(num, d);
				}
			}
		}
	}

	int res = count_point();
	cout << res;
	return 0;
}