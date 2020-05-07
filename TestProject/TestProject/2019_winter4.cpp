#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp;

long long find(long long a) {
	if (mp[a] == 0) return a;
	return mp[a] = find(mp[a]);
}
vector<long long> solution(long long k, vector<long long> room_number) {

	vector<long long> answer;
	
	for (int i = 0; i < room_number.size(); i++) {
		long long tmp = find(room_number[i]);
		answer.push_back(tmp);
		mp[tmp] = tmp + 1;
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