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
	for (int k = y + 1; k < y + 1 + l; k++) { // 다음 위치부터 길이 L만큼 동안
		if (MAP2[x][k] != tmp) return false; // 길의 높이가 다르면 다음 위치에서 경사로 설치 못하므로 false 리턴
	}
	return true; // 높이가 모두 같으면 true 리턴
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
			MAP2[j][i] = MAP[i][j]; // 열에서의 길체크를 쉽게 하기 위해 열을 행으로 옮김
		}
	}

	for (int i = 0; i < n; i++) {
		bool flag = true; // flag가 false면 경사로를 만들지 못하여 길을 갈 수 없음
		int road_len = 1; // 같은 높이의 길을 간 길의 개수
		for (int j = 0; j < n - 1; j++) {
			if (MAP[i][j] == MAP[i][j + 1]) road_len++; // 현재 위치와 다음 위치의 높이가 같으면 길의 개수 1 증가
			else if (MAP[i][j] + 1 == MAP[i][j + 1]) { // 현재 위치보다 다음 위치가 높을 경우
				if (road_len >= l) { // 경사로를 설치할 수 있는 길이면 
					road_len = 1; // 경사로 길이 1로 초기화
				}
				else { // 경사로를 설치할 수 없는 길이면
					flag = false; // 이 길은 통과 못함
					break;
				}
			}
			else if (MAP[i][j] == MAP[i][j + 1] + 1) { // 현재 위치가 다음 위치보다 높으면
				if (canRoad(i, j)) { // 다음 위치부터 길이가 L인 경사로를 설치할 수 있으면
					j = j + l - 1; // 위치 조정
					road_len = 0; // 길의 개수 0으로 초기화 , 1로 초기화하면 경사로가 겹칠 수 있음
				}
				else { // 경사로 설치 못하면
					flag = false; // 이 길은 통과 못함
					break;
				}
			}
			else if (abs(MAP[i][j] - MAP[i][j + 1]) >= 2) { // 현재 위치와 다음 위치의 높이 차이가 2이상이면
				flag = false; // 이 길은 통과 못함
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