#include <bits/stdc++.h>
using namespace std;

struct room {
	int idx;
	long long num;
};

struct cmp {
	bool operator()(room a, room b) {
		return a.num < b.num;

	}
};
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	

	
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