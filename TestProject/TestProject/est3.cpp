#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	int res = 0;
	bool possible = true;
	bool start = false;
	for (int i = 0; i < v.size(); i++) {
		vector<int> tmp;
		bool ne = false;
		for (int j = 1; j < v.size() - 1; j++) {
			if ((v[j] > v[j - 1] && v[j] > v[j + 1]) || (v[j] < v[j - 1] && v[j] < v[j + 1])) {
				continue;
			}
			else {
				ne = true;
				break;
			}
		}
		if (ne) {
			for (int j = 0; j < v.size(); j++) {
				if (i == j) continue;
				tmp.push_back(v[j]);
			}

			bool flag = true;
			for (int j = 1; j < tmp.size() - 1; j++) {
				if (tmp[j] > tmp[j - 1] && tmp[j] > tmp[j + 1]) {
					continue;
				}
				else if (tmp[j] < tmp[j - 1] && tmp[j] < tmp[j + 1]) {
					continue;
				}
				else {
					flag = false;
					break;
				}
			}
			if (flag) {
				res++;
			}
		}
		else {
			start = true;
			break;
		}
	}
	if (start) {
		cout << "0";
	}
	else if (!start && res > 0) {
		cout << res;
	}
	else if (!start && res == 0) {
		cout << "-1";
	}
	return 0;
}