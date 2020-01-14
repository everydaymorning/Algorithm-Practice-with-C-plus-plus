#include <bits/stdc++.h>
using namespace std;

int n;
string candy[50];
int num_candy() {
	int res = 1;
	for (int i = 0; i < n; i++) { // 양 옆 비교
		int tmp = 1;
		for (int j = 1; j < n; j++) {
			if (candy[i][j - 1] == candy[i][j]) { // 가로 방향의 캔디가 서로 같으면 증가
				tmp++;
			}
			else {
				res = max(res, tmp); // 캔디가 서로 다르면 그 동안의 캔디 갯수를 저장
				tmp = 1; // 캔디 갯수 다시 1로 세팅
			}
		}
		res = max(res, tmp); // 행이 끝날 때마다 캔디 갯수 비교하여 최댓값 저장
	}

	for (int i = 0; i < n; i++) { // 위 아래 비교
		int tmp = 1;
		for (int j = 1; j < n; j++) {
			if (candy[j - 1][i] == candy[j][i]) { //세로 방향의 캔디가 서로 같으면 증가
				tmp++;
			}
			else {
				res = max(res, tmp); // 캔디가 서로 다르면 그 동안의 캔디 갯수 저장
				tmp = 1;
			}
		}
		res = max(res, tmp); // 열이 끝날 때 마다 캔디 갯수 비교하여 최댓값 저장
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
			swap(candy[i][j], candy[i][j+1]); // 양 옆 바꾸기
			result = max(result, num_candy()); // 바꿨을 때의 최대 캔디 갯수
			swap(candy[i][j], candy[i][j+1]); // 다시 바꾸기

			swap(candy[j][i], candy[j + 1][i]); // 위 아래 바꾸기
			result = max(result, num_candy()); // 바꿨을 때의 최대 캔디 갯수
			swap(candy[j][i], candy[j + 1][i]); // 다시 바꾸기
		}
	}

	cout << result;

	return 0;
}