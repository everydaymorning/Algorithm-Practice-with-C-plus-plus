#include <bits/stdc++.h>
using namespace std;
int k; //회전 횟수
bool check[4];
deque<int> dq[4]; // 톱니바퀴 상태 저장 및 회전하기 위한 덱

queue<pair<int, int>> q; // 회전할 톱니바퀴를 저장하기 위한 큐
vector<pair<int, int>> v; // 회전할 톱니바퀴들을 실제로 방향에 따라 회전시키기 위한 벡터
void rotate() {
	for (int i = 0; i < v.size(); i++) { // 톱니바퀴 회전 
		int cur_num = v[i].first;
		int cur_d = v[i].second;
		if (cur_d == 1) { // 시계 방향이면
			int tmp = dq[cur_num].back(); // 현재 톱니바퀴의 마지막 숫자를 tmp에 저장
			dq[cur_num].pop_back(); // 현재 톱니바퀴의 마지막 숫자 삭제
			dq[cur_num].push_front(tmp); // 현재 톱니바퀴의 앞에다가 tmp 삽입
		}
		else { // 시계 반대방향이면
			int tmp = dq[cur_num].front(); // 현재 톱니바퀴의 첫번째 숫자를 tmp에 저장
			dq[cur_num].pop_front(); // 현재 톱니바퀴의 첫번째 숫자 삭제
			dq[cur_num].push_back(tmp); // 현재 톱니바퀴의 뒤에다가 tmp 삽입
		}
	}
}
void check_rotate() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		memset(check, false, sizeof(check));
		v.clear();
		int num, d;
		cin >> num >> d;

		num -= 1; // 인덱스를 0부터 시작하기 위해 입력되는 num값에서 -1
		v.push_back({ num,d }); // 처음 입력받는 톱니바퀴와 방향을 푸쉬
		q.push({ num, d }); // 처음 입력받는 톱니바퀴와 방향을 푸쉬
		check[num] = true; // 해당 톱니바퀴 방문체크
		while (!q.empty()) {
			int cur_num = q.front().first; // 현재 톱니바퀴 숫자
			int cur_d = q.front().second; // 회전할 방향
			q.pop();

			if (cur_num != 0) { // 톱니바퀴가 첫번째가 아니라면
				if (dq[cur_num - 1][2] != dq[cur_num][6] && !check[cur_num - 1]) {
					// 왼쪽 톱니바퀴와 극이 다르고 왼쪽 톱니바퀴를 방문하지 않았다면
					q.push({ cur_num - 1, cur_d * -1 }); // 왼쪽 톱니바퀴 번호와 반대 방향을 큐에 푸쉬
					v.push_back({ cur_num - 1, cur_d * -1 }); // 왼쪽 톱니바퀴 번호와 반대 방향을 벡터에 푸쉬
					check[cur_num - 1] = true; // 왼쪽 톱니바퀴 방문 체크
				}
			}
			if (cur_num != 3) { // 톱니바퀴가 마지막이 아니라면
				if (dq[cur_num][2] != dq[cur_num + 1][6] && !check[cur_num + 1]) {
					// 오른쪽 톱니바퀴와 극이 다르고 오른쪽 톱니바퀴를 방문하지 않았다면
					q.push({ cur_num + 1, cur_d * -1 }); // 오른쪽 톱니바퀴 번호와 반대 방향을 큐에 푸쉬
					v.push_back({ cur_num + 1, cur_d * -1 }); // 오른쪽 톱니바퀴 번호와 반대 방향을 벡터에 푸쉬
					check[cur_num + 1] = true; // 오른쪽 톱니바퀴 방문 체크
				}
			}
		}

		rotate();
	}
}

void count() {
	int cnt = 0;
	if (dq[0][0] == 1) cnt += 1;
	if (dq[1][0] == 1) cnt += 2;
	if (dq[2][0] == 1) cnt += 4;
	if (dq[3][0] == 1) cnt += 8;
	cout << cnt;
}
void INPUT() {
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			dq[i].push_back(str[j] - '0'); // 톱니바퀴 처음 상태 저장
		}
	}
}
void solve() {
	INPUT();
	check_rotate();
	count();
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	solve();
	return 0;
}