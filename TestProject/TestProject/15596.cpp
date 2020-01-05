#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll sum(vector<int>& a) {
	int sum = 0;
	int a_size = a.size();
	for (int i = 0; i < a_size; i++) {
		sum += a.at(i);
	}
	return sum;
}
int main() {
	vector<int> b(300000);
	sum(b);

	return 0;
}