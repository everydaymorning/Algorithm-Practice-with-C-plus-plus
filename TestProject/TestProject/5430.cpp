#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		deque<int> dq;
		string tmp;
		cin >> tmp;

		int tmp_len = tmp.length();
		int n;
		cin >> n;

		string arr;
		cin >> arr;
		int arr_len = arr.length();
		string ss = "";
		for (int j = 0; j < arr_len; j++) {
			if (n == 0) break;
			if (arr[j] == '[') continue;
			if (arr[j] == ']') {
				dq.push_back(atoi(ss.c_str()));
				break;
			}
			if (arr[j] != ',') {
				ss += arr[j];
				continue;
			}
			else {
				dq.push_back(atoi(ss.c_str()));
				ss = "";
			}

		}


		bool r = false;
		bool flag = true;
		bool r_empty = false;

		for (int k = 0; k < tmp_len; k++) {
			if (tmp[k] == 'R') {
				r = !r;
			}
			else {
				if (dq.empty()) {
					flag = !flag;
					cout << "error" << '\n';
					break;
				}
				if (r == true) {
					dq.pop_back();

				}
				else {
					dq.pop_front();

				}


			}
		}

		if (flag) {

			int dq_size = dq.size();
			if (dq_size == 0) cout << "[]" << '\n';
			else {
				cout << "[";
				if (r == false) {
					for (int j = 0; j < dq_size; j++) {
						if (j == dq_size - 1) {
							cout << dq.front() << "]" << '\n';
							break;
						}
						else {
							cout << dq.front() << ",";
							dq.pop_front();
						}

					}
				}
				else {
					for (int j = 0; j < dq_size; j++) {
						if (j == dq_size - 1) {
							cout << dq.back() << "]" << '\n';
							break;
						}
						else {
							cout << dq.back() << ",";
							dq.pop_back();
						}

					}
				}
			}
		}

	}

	return 0;
}