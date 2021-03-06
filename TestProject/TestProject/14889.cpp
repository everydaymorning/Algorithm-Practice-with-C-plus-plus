#include <bits/stdc++.h>
using namespace std;
// 스타트와 링크 BOJ 14889 
int arr[21][21];
int n;
vector<int> start, link;
int mn = 2147483637;
void dfs(int idx) {
	if (idx >= n) {
		if (start.size() == link.size()) {
			int startSum = 0;
			int linkSum = 0;
			for (int i = 0; i < start.size(); i++) {
				for (int j = i + 1; j < start.size(); j++) {
					startSum += arr[start[i]][start[j]] + arr[start[j]][start[i]];
				}
			}

			for (int i = 0; i < link.size(); i++) {
				for (int j = i + 1; j < link.size(); j++) {
					linkSum += arr[link[i]][link[j]] + arr[link[j]][link[i]];
				}
			}

			mn = min(mn, abs(startSum - linkSum));
			//cout << "계산값: " << abs(startSum - linkSum) << '\n';
			//cout << "size 같아서 들어온 if문, 현재 최솟값 :  " << mn << '\n';
		}
		//cout << "dfs 종료:  " << idx << '\n';
		return;
	}

	start.push_back(idx);
	//cout << "start idx: " << idx << '\n';
	
	dfs(idx + 1);
	start.pop_back();

	link.push_back(idx);
	//cout << "link idx: " << idx << '\n';
	
	dfs(idx + 1);
	link.pop_back();
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0);

	cout << mn;

	return 0;

}