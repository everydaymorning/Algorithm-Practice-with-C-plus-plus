#include <bits/stdc++.h>
using namespace std;
int k; //ȸ�� Ƚ��
bool check[4];
deque<int> dq[4]; // ��Ϲ��� ���� ���� �� ȸ���ϱ� ���� ��

queue<pair<int, int>> q; // ȸ���� ��Ϲ����� �����ϱ� ���� ť
vector<pair<int, int>> v; // ȸ���� ��Ϲ������� ������ ���⿡ ���� ȸ����Ű�� ���� ����
void rotate() {
	for (int i = 0; i < v.size(); i++) { // ��Ϲ��� ȸ�� 
		int cur_num = v[i].first;
		int cur_d = v[i].second;
		if (cur_d == 1) { // �ð� �����̸�
			int tmp = dq[cur_num].back(); // ���� ��Ϲ����� ������ ���ڸ� tmp�� ����
			dq[cur_num].pop_back(); // ���� ��Ϲ����� ������ ���� ����
			dq[cur_num].push_front(tmp); // ���� ��Ϲ����� �տ��ٰ� tmp ����
		}
		else { // �ð� �ݴ�����̸�
			int tmp = dq[cur_num].front(); // ���� ��Ϲ����� ù��° ���ڸ� tmp�� ����
			dq[cur_num].pop_front(); // ���� ��Ϲ����� ù��° ���� ����
			dq[cur_num].push_back(tmp); // ���� ��Ϲ����� �ڿ��ٰ� tmp ����
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

		num -= 1; // �ε����� 0���� �����ϱ� ���� �ԷµǴ� num������ -1
		v.push_back({ num,d }); // ó�� �Է¹޴� ��Ϲ����� ������ Ǫ��
		q.push({ num, d }); // ó�� �Է¹޴� ��Ϲ����� ������ Ǫ��
		check[num] = true; // �ش� ��Ϲ��� �湮üũ
		while (!q.empty()) {
			int cur_num = q.front().first; // ���� ��Ϲ��� ����
			int cur_d = q.front().second; // ȸ���� ����
			q.pop();

			if (cur_num != 0) { // ��Ϲ����� ù��°�� �ƴ϶��
				if (dq[cur_num - 1][2] != dq[cur_num][6] && !check[cur_num - 1]) {
					// ���� ��Ϲ����� ���� �ٸ��� ���� ��Ϲ����� �湮���� �ʾҴٸ�
					q.push({ cur_num - 1, cur_d * -1 }); // ���� ��Ϲ��� ��ȣ�� �ݴ� ������ ť�� Ǫ��
					v.push_back({ cur_num - 1, cur_d * -1 }); // ���� ��Ϲ��� ��ȣ�� �ݴ� ������ ���Ϳ� Ǫ��
					check[cur_num - 1] = true; // ���� ��Ϲ��� �湮 üũ
				}
			}
			if (cur_num != 3) { // ��Ϲ����� �������� �ƴ϶��
				if (dq[cur_num][2] != dq[cur_num + 1][6] && !check[cur_num + 1]) {
					// ������ ��Ϲ����� ���� �ٸ��� ������ ��Ϲ����� �湮���� �ʾҴٸ�
					q.push({ cur_num + 1, cur_d * -1 }); // ������ ��Ϲ��� ��ȣ�� �ݴ� ������ ť�� Ǫ��
					v.push_back({ cur_num + 1, cur_d * -1 }); // ������ ��Ϲ��� ��ȣ�� �ݴ� ������ ���Ϳ� Ǫ��
					check[cur_num + 1] = true; // ������ ��Ϲ��� �湮 üũ
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
			dq[i].push_back(str[j] - '0'); // ��Ϲ��� ó�� ���� ����
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