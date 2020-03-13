#include <bits/stdc++.h>
using namespace std;
struct info {
	int idx;
	int cnt;
	int num;
};

bool cmp(info a, info b) {
	if (a.cnt == b.cnt) return a.idx < b.idx;
	return a.cnt > b.cnt;
}
info INFO[1001];
info TMP[1001];
int main() {
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		INFO[i].idx = 0;
		INFO[i].cnt = 0;
		INFO[i].num = 0;
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		INFO[i].idx = i;
		INFO[i].num = a;
		
		for (int j = 0; j <= i; j++) {
			if (INFO[j].num == INFO[i].num) {
				INFO[j].cnt++;
				cout << "i: " << i << "  j: " << j << '\n';
				break;
			}
		}
	}
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (INFO[i].cnt != 0) {
			TMP[j].idx = INFO[i].idx;
			TMP[j].num = INFO[i].num;
			TMP[j].cnt = INFO[i].cnt;
			j++;
		}
	}
	sort(TMP, TMP + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << "cnt: " << TMP[i].cnt << "  num: " << TMP[i].num << '\n';
	}
	for (int i = 0; i < j; i++) {
		while (TMP[i].cnt > 0) {
			TMP[i].cnt--;
			cout << TMP[i].num << " ";
		}
	}
	return 0;
}