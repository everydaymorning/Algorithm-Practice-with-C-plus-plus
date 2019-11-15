#include <bits/stdc++.h>

using namespace std;

int board[502][502]; // �׸��� ǥ���ϱ� ���� ����
bool vis[502][502]; // �ش� ĭ�� �湮�ߴ��� ǥ���ϱ� ���� ����
int dx[4] = { 1,0,-1,0 }; 
int dy[4] = { 0,1,0,-1 }; // �����¿츦 ���� ����

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m; // �׸� ũ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int mx = 0; // �׸��� �ִ밪
	int num = 0; // �׸��� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue; // �׸��� �ƴϰų� �湮�� ���� �Ѿ

			num++; // �׸��� ���� ����
			queue<pair<int, int>> q;
			vis[i][j] = 1; // �ش� ĭ�� �湮�ߴٴ� ǥ��
			q.push(make_pair(i, j)); // �ش� ĭ�� ť�� ����

			int area = 0; // �׸��� ���̸� ���ϱ� ���� ����
			while (!q.empty()) {
				area++; // �׸��� ���� ����
				auto cur = q.front(); // ť�� ù��° ���Ҹ� cur�� ����
				q.pop(); // ť�� ���� ����
				for (int dir = 0; dir < 4; dir++) { // ���� ��ġ�� �����¿� ������ �˻��ϱ� ���� �ݺ���
					int nx = cur.first + dx[dir]; 
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // �迭�� ������ ����� �Ѿ
					if (vis[nx][ny] || board[nx][ny] != 1) continue; // �迭�� ������ ����� �ʰ� �ش� ĭ�� �湮�߰ų� �׸��� �ƴϸ� �Ѿ
					vis[nx][ny] = 1; // �ش� ĭ�� �湮�ߴٰ� ǥ��
					q.push(make_pair(nx, ny)); // �湮���� �ʰ� �׸��� ���� ť�� ����
				}
			}
			mx = max(mx, area); // STL �Լ� , area�� mx���� ũ�� mx�� area ����
		}
	}

	cout << num << '\n' << mx << '\n'; // �׸��� ������ �ִ� ���� ���
	return 0;
}