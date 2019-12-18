#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);

	deque<int> v1;
	deque<int> v2;
	deque<int> v3;
	for (int i = 0; i < a; i++) {
		int t;
		scanf_s("%d", &t);
		v1.push_back(t);
	}

	for (int i = 0; i < b; i++) {
		int t;
		scanf_s("%d", &t);
		v2.push_back(t);
	}

	while (1) {
		int v1_size = v1.size();
		int v2_size = v2.size();
		if (v1_size == 0 || v2_size == 0) break;
		if (v1_size != 0 && v2_size != 0) {
			if (v1.at(0) > v2.at(0)) {
				v3.push_back(v2.at(0));
				v2.pop_front();
			}
			else {
				v3.push_back(v1.at(0));
				v1.pop_front();
			}
		}
	}
	int size1 = v1.size();
	int size2 = v2.size();

	int v3_size = v3.size();
	for (int i = 0; i < v3_size; i++) {
		printf("%d ", v3.at(i));
	}

	if (size1 == 0) {
		for (int i = 0; i < size2; i++) {
			printf("%d ", v2.at(i));
		}
	}
	else if (size2 == 0) {
		for (int i = 0; i < size1; i++) {
			printf("%d ", v1.at(i));
		}
	}

	return 0;
}