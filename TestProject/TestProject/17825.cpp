#include <bits/stdc++.h>
using namespace std;
int DICE[11];
int MAL[4];

int MAP[33];
int TEMP[33];
bool check[33];
int SCORE[33];
int ans;

void dfs(int cnt, int sum) {
	if (cnt == 10) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int here = MAL[i];
		int next = here;
		int dist = DICE[cnt];

		if (TEMP[next] > 0) {
			next = TEMP[next];
			dist--;
		}

		for (int j = 0; j < dist; j++) {
			next = MAP[next];
		}

		if (next != 21 && check[next]) continue;

		check[here] = false;
		check[next] = true;
		MAL[i] = next;

		dfs(cnt + 1, sum + SCORE[next]);

		MAL[i] = here;
		check[next] = false;
		check[here] = true;

	}
}
void setting() {
	for (int i = 0; i < 21; i++) {
		MAP[i] = i + 1;
	}
	MAP[21] = 21; // µµÂøÁöÁ¡
	MAP[22] = 23; MAP[23] = 24; MAP[24] = 25;
	MAP[25] = 26; MAP[26] = 27; MAP[27] = 20;
	MAP[28] = 29; MAP[29] = 30; MAP[30] = 25;
	MAP[31] = 32; MAP[32] = 25;

	TEMP[5] = 22; TEMP[10] = 31; TEMP[15] = 28;
	TEMP[25] = 26;

	for (int i = 0; i < 21; i++) {
		SCORE[i] = i * 2;
	}
	SCORE[22] = 13; SCORE[23] = 16; SCORE[24] = 19;
	SCORE[25] = 25; SCORE[26] = 30; SCORE[27] = 35;
	SCORE[28] = 28; SCORE[29] = 27; SCORE[30] = 26;
	SCORE[31] = 22; SCORE[32] = 24;
}
void INPUT() {
	for (int i = 0; i < 10; i++) {
		cin >> DICE[i];
	}
}
void solution() {
	setting();
	INPUT();
	dfs(0, 0);
	cout << ans;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solution();
	return 0;

}