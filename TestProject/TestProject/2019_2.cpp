#include <bits/stdc++.h>
using namespace std;
vector<int> answer, st;
int arr[501];
vector<pair<int, double>> v;
bool cmp(pair<int, double> p1, pair<int, double> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second > p2.second;
}
vector<int> solution(int N, vector<int> stages) {
	int size = stages.size();
	for (int i = 0; i < stages.size(); i++) {
		arr[stages[i]]++;
	}
	
	for (int i = 1; i <= N; i++) {
		double tmp = (double)arr[i] / size;
		v.push_back({ i, tmp });
		size -= arr[i];
	}

	sort(v.begin(), v.end(), cmp);
	
	for (int i = 0; i < v.size(); i++) {
		answer.push_back(v[i].first);
	}
	return answer;

}
int main() {
	int a = 4;
	st = { 4,4,4,4,4 };
	answer = solution(a, st);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}