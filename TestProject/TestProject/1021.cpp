#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	deque<int> dq;
	

	deque<int> v;

	cin >> n >> m;
	int cnt = 0;
	
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		
		v.push_back(t);
	}
	while (1) {
		int l = 0, r = 0;
		deque<int> tmp1 = dq;
		deque<int> tmp2 = dq;
		//cout << dq.front() << " " << v.front() << endl;
		if (dq.front() == v.front()) {
			
			dq.pop_front();
			v.pop_front();
			if (v.size() == 0) break;
			continue;
		}
		else {
			while (tmp1.front() != v.front()) {
				tmp1.push_back(tmp1.front());
				tmp1.pop_front();
				l++;
			}

			while (tmp2.front() != v.front()) {
				tmp2.push_front(tmp2.back());
				tmp2.pop_back();
				r++;
			}
		}

		//cout << "l: " << l << endl;
		//cout << "r: " << r << endl;

		if (l <= r) {
			for (int i = 0; i < l; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			//cout << dq.front() << '\n';
			dq.pop_front();
			v.pop_front();
			cnt += l;
		}
		else {
			for (int i = 0; i < r; i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			//cout << dq.front() << '\n';
			dq.pop_front();
			v.pop_front();
			cnt += r;
		}

		if (v.size() == 0) break;

	}

	cout << cnt << '\n';
	return 0;
}