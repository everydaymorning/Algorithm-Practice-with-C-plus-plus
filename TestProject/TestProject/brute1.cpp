#include <bits/stdc++.h>
using namespace std;
int arr1[5] = { 1,2,3,4,5 };
int arr2[8] = { 2,1,2,3,2,4,2,5 };
int arr3[10] = { 3,3,1,1,2,2,4,4,5,5 };
int cnt[3];
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	vector<int> answer;
	for (int i = 0; i < v.size(); i++) {
		if (arr1[i % 5] == v[i]) cnt[0]++;
	}

	for (int i = 0; i < v.size(); i++) {
		if (arr2[i % 8] == v[i]) cnt[1]++;
	}

	for (int i = 0; i < v.size(); i++) {
		if (arr3[i % 10] == v[i]) cnt[2]++;
	}

	int MAX = 0;
	MAX = max(max(cnt[0], cnt[1]), cnt[2]);

	for (int i = 0; i < 3; i++) {
		if (MAX == cnt[i]) {
			answer.push_back(i + 1);
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;

	
}