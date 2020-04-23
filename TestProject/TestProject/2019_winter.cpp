#include <bits/stdc++.h>
using namespace std;

int main() {
	int answer = 0;
	stack<int> s[31];
	stack<int> bucket;
	vector<vector<int>> board;
	board.push_back({ 0,0,0,0,0 });
	board.push_back({ 0,0,1,0,3 });
	board.push_back({ 0,2,5,0,1 });
	board.push_back({ 4,2,4,4,2 });
	board.push_back({ 3,5,1,3,1 });
	int n = board.size();
	cout << "n: " << n << '\n';
	vector<int> moves;
	moves.push_back(1);
	moves.push_back(5);
	moves.push_back(3);
	moves.push_back(5);
	moves.push_back(1);
	moves.push_back(2);
	moves.push_back(1);
	moves.push_back(4);
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if(board[j][i] != 0) s[idx].push(board[j][i]);
		}
		idx++;
	}
	
	for (int i = 0; i < moves.size(); i++) {
		int loc = moves[i];
		if (s[loc - 1].empty()) continue;

		if (bucket.empty()) {
			bucket.push(s[loc - 1].top());
		}
		else {
			if (bucket.top() == s[loc - 1].top()) {
				bucket.pop();
				answer += 2;
			}
			else {
				bucket.push(s[loc - 1].top());
			}
		}
		s[loc - 1].pop();
		
	}
	cout << answer;
	return 0;
}