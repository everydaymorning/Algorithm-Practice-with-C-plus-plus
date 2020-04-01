#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> lost, reserve;
void solution() {
	int answer = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(1);
	}

	for (int i = 0; i < lost.size(); i++)
		v[lost[i] - 1]--;

	for (int i = 0; i < reserve.size(); i++)
		v[reserve[i] - 1]++;

	for (int i = 0; i < reserve.size(); i++) {
		if (v[i] == 2) {
			if (i == 0) {
				if (v[i + 1] == 0) {
					v[i + 1] = 1;
					v[i] = 1;
				}
			}
			else if (i == n-1) {
				if (v[i - 1] == 0) {
					v[i - 1] = 1;
					v[i] = 1;
				}
			}
			else {
				if (v[i - 1] == 0) {
					v[i - 1] = 1;
					v[i] = 1;
				}
				else if (v[i + 1] == 0) {
					v[i + 1] = 1;
					v[i] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (v[i] > 0)
			answer++;
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << '\n';
	cout << answer;
}
int main() {
	cin >> n;
	
	lost.push_back(3);
	//lost.push_back(4);

	reserve.push_back(1);
	//reserve.push_back(3);
	//reserve.push_back(5);

	solution();
	return 0;
}