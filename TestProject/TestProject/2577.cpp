#include <bits/stdc++.h>

using namespace std;

int main() {
	char arr[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int cnt_arr[10] = {0};
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	
	int sum = a * b * c;
	string tmp_sum = to_string(sum);
	int len_sum = tmp_sum.length();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < len_sum; j++) {
			if (arr[i] == tmp_sum[j]) {
				cnt_arr[i]++;
			}
		}
	}
	
	for (int i = 0; i < 10; i++) {
		cout << cnt_arr[i] << endl;
	}

	return 0;
}