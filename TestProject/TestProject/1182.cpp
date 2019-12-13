#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
	int n, res;
	int cnt = 0;
	cin >> n >> res;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	int v_size = v.size();
	int v_pow = (int)pow(2, n);
	
	for (int i = 1; i < v_pow; i++) {
		int tmp = i;
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (tmp % 2 == 1) {
				//printf("%d ", v.at(j));
				sum += v.at(j);
				
			}
			tmp /= 2;
			
		}
		
		//printf("\n");
		if (sum == res) cnt++;
	}

	printf("%d", cnt);
	return 0;
}