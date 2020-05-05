#include <bits/stdc++.h>
using namespace std;


vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	priority_queue<pair<int, int>, vector<pair<int, int>, greater<>>> pq;
	
	for (int i = 0; i < room_number.size(); i++) {
		
	}



	return answer;
}

int main() {
	long long a = 10;
	vector<long long> room = { 1,3,4,1,3,1 };
	vector<long long> ans = solution(a, room);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}