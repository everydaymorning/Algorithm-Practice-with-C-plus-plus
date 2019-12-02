#include <bits/stdc++.h>

using namespace std;

long long tmp[31][31];
long long func(int w, int h) {
	if (w == 0) return 1;

	long long &result = tmp[w][h];
	if (result != -1) return result;

	result = 0;
	result = func(w - 1, h + 1);

	if (h > 0) result += func(w, h - 1);

	return result;

}
int main() {

	int max = 1000;

	while (max != 0) {
		memset(tmp, -1, sizeof(tmp));
		int t;
		cin >> t;

		if (t == 0) break;

		long long res = func(t, 0);
		printf("%lld\n", res);
		max--;
	}

	return 0;
}