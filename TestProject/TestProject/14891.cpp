#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;

int k;
int sum;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> s1;
	cin >> s2;
	cin >> s3;
	cin >> s4;

	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			if (b == 1) {
				if (s1.at(2) != s2.at(6)) {
					if (s2.at(2) != s3.at(6)) {
						if (s3.at(2) != s4.at(6)) {
							char tmp = s1.at(7);
							for (int j = 7; j > 0; j--) {
								s1.at(j) = s1.at(j - 1);
							}
							s1.at(0) = tmp;
							
							tmp = s2.at(0);
							for (int j = 0; j < 7; j++) {
								s2.at(j) = s2.at(j + 1);
							}
							s2.at(7) = tmp;

							tmp = s3.at(7);
							for (int j = 7; j > 0; j--) {
								s3.at(j) = s3.at(j - 1);
							}
							s3.at(0) = tmp;
							
							tmp = s4.at(0);
							for (int j = 0; j < 7; j++) {
								s4.at(j) = s4.at(j + 1);
							}
							s4.at(7) = tmp;
						}
						else {
							char tmp = s1.at(7);
							for (int j = 7; j > 0; j--) {
								s1.at(j) = s1.at(j - 1);
							}
							s1.at(0) = tmp;

							tmp = s2.at(0);
							for (int j = 0; j < 7; j++) {
								s2.at(j) = s2.at(j + 1);
							}
							s2.at(7) = tmp;

							tmp = s3.at(7);
							for (int j = 7; j > 0; j--) {
								s3.at(j) = s3.at(j - 1);
							}
							s3.at(0) = tmp;
						}
					}
					else {
						char tmp = s1.at(7);
						for (int j = 7; j > 0; j--) {
							s1.at(j) = s1.at(j - 1);
						}
						s1.at(0) = tmp;

						tmp = s2.at(0);
						for (int j = 0; j < 7; j++) {
							s2.at(j) = s2.at(j + 1);
						}
						s2.at(7) = tmp;
					}
				}
				else {
					char tmp = s1.at(7);
					for (int j = 7; j > 0; j--) {
						s1.at(j) = s1.at(j - 1);
					}
					s1.at(0) = tmp;
				}
			}
			else {
				if (s1.at(2) != s2.at(6)) {
					if (s2.at(2) != s3.at(6)) {
						if (s3.at(2) != s4.at(6)) {
							char tmp = s1.at(0);
							for (int j = 0; j < 7; j++) {
								s1.at(j) = s1.at(j + 1);
							}
							s1.at(7) = tmp;

							tmp = s2.at(7);
							for (int j = 7; j > 0; j--) {
								s2.at(j) = s2.at(j - 1);
							}
							s2.at(0) = tmp;

							tmp = s3.at(0);
							for (int j = 0; j < 7; j++) {
								s3.at(j) = s3.at(j + 1);
							}
							s3.at(7) = tmp;

							tmp = s4.at(7);
							for (int j = 7; j > 0; j--) {
								s4.at(j) = s4.at(j - 1);
							}
							s4.at(0) = tmp;
						}
						else {
							char tmp = s1.at(0);
							for (int j = 0; j < 7; j++) {
								s1.at(j) = s1.at(j + 1);
							}
							s1.at(7) = tmp;

							tmp = s2.at(7);
							for (int j = 7; j > 0; j--) {
								s2.at(j) = s2.at(j - 1);
							}
							s2.at(0) = tmp;

							tmp = s3.at(0);
							for (int j = 0; j < 7; j++) {
								s3.at(j) = s3.at(j + 1);
							}
							s3.at(7) = tmp;
						}
					}
					else {
						char tmp = s1.at(0);
						for (int j = 0; j < 7; j++) {
							s1.at(j) = s1.at(j + 1);
						}
						s1.at(7) = tmp;

						tmp = s2.at(7);
						for (int j = 7; j > 0; j--) {
							s2.at(j) = s2.at(j - 1);
						}
						s2.at(0) = tmp;
					}
				}
				else {
					char tmp = s1.at(0);
					for (int j = 0; j < 7; j++) {
						s1.at(j) = s1.at(j + 1);
					}
					s1.at(7) = tmp;
				}
			}
		}
		else if (a == 2) {
			if (b == 1) {
				if (s1.at(2) != s2.at(6)) {
					char tmp = s1.at(0);
					for (int j = 0; j < 7; j++) {
						s1.at(j) = s1.at(j + 1);
					}
					s1.at(7) = tmp;
				}
				if (s2.at(2) != s3.at(6)) {
					if (s3.at(2) != s4.at(6)) {
						char tmp = s2.at(7);
						for (int j = 7; j > 0; j--) {
							s2.at(j) = s2.at(j - 1);
						}
						s2.at(0) = tmp;

						tmp = s3.at(0);
						for (int j = 0; j < 7; j++) {
							s3.at(j) = s3.at(j + 1);
						}
						s3.at(7) = tmp;

						tmp = s4.at(7);
						for (int j = 7; j > 0; j--) {
							s4.at(j) = s4.at(j - 1);
						}
						s4.at(0) = tmp;
					}
					else {
						char tmp = s2.at(7);
						for (int j = 7; j > 0; j--) {
							s2.at(j) = s2.at(j - 1);
						}
						s2.at(0) = tmp;

						tmp = s3.at(0);
						for (int j = 0; j < 7; j++) {
							s3.at(j) = s3.at(j + 1);
						}
						s3.at(7) = tmp;
					}
				}
				else {
					char tmp = s2.at(7);
					for (int j = 7; j > 0; j--) {
						s2.at(j) = s2.at(j - 1);
					}
					s2.at(0) = tmp;
				}
			}
			else {
				if (s1.at(2) != s2.at(6)) {
					char tmp = s1.at(7);
					for (int j = 7; j > 0; j--) {
						s1.at(j) = s1.at(j - 1);
					}
					s1.at(0) = tmp;
				}
				if (s2.at(2) != s3.at(6)) {
					if (s3.at(2) != s4.at(6)) {
						char tmp = s2.at(0);
						for (int j = 0; j < 7; j++) {
							s2.at(j) = s2.at(j + 1);
						}
						s2.at(7) = tmp;

						tmp = s3.at(7);
						for (int j = 7; j > 0; j--) {
							s3.at(j) = s3.at(j - 1);
						}
						s3.at(0) = tmp;

						tmp = s4.at(0);
						for (int j = 0; j < 7; j++) {
							s4.at(j) = s4.at(j + 1);
						}
						s4.at(7) = tmp;
					}
					else {
						char tmp = s2.at(0);
						for (int j = 0; j < 7; j++) {
							s2.at(j) = s2.at(j + 1);
						}
						s2.at(7) = tmp;

						tmp = s3.at(7);
						for (int j = 7; j > 0; j--) {
							s3.at(j) = s3.at(j - 1);
						}
						s3.at(0) = tmp;
					}
				}
				else {
					char tmp = s2.at(0);
					for (int j = 0; j < 7; j++) {
						s2.at(j) = s2.at(j + 1);
					}
					s2.at(7) = tmp;
				}
			}
		}
		else if (a == 3) {
			if (b == 1) {
				if (s3.at(2) != s4.at(6)) {
					char tmp = s4.at(0);
					for (int j = 0; j < 7; j++) {
						s4.at(j) = s4.at(j + 1);
					}
					s4.at(7) = tmp;
				}
				if (s2.at(2) != s3.at(6)) {
					if (s1.at(2) != s2.at(6)) {
						char tmp = s1.at(7);
						for (int j = 7; j > 0; j--) {
							s1.at(j) = s1.at(j - 1);
						}
						s1.at(0) = tmp;

						tmp = s2.at(0);
						for (int j = 0; j < 7; j++) {
							s2.at(j) = s2.at(j + 1);
						}
						s2.at(7) = tmp;

						tmp = s3.at(7);
						for (int j = 7; j > 0; j--) {
							s3.at(j) = s3.at(j - 1);
						}
						s3.at(0) = tmp;
					}
					else {
						char tmp = s2.at(0);
						for (int j = 0; j < 7; j++) {
							s2.at(j) = s2.at(j + 1);
						}
						s2.at(7) = tmp;

						tmp = s3.at(7);
						for (int j = 7; j > 0; j--) {
							s3.at(j) = s3.at(j - 1);
						}
						s3.at(0) = tmp;
					}
				}
				else {
					char tmp = s3.at(7);
					for (int j = 7; j > 0; j--) {
						s3.at(j) = s3.at(j - 1);
					}
					s3.at(0) = tmp;
				}
			}
			else {
				if (s3.at(2) != s4.at(6)) {
					char tmp = s4.at(7);
					for (int j = 7; j > 0; j--) {
						s4.at(j) = s4.at(j - 1);
					}
					s4.at(0) = tmp;
				}
				if (s2.at(2) != s3.at(6)) {
					if (s1.at(2) != s2.at(6)) {
						char tmp = s1.at(0);
						for (int j = 0; j < 7; j++) {
							s1.at(j) = s1.at(j + 1);
						}
						s1.at(7) = tmp;

						tmp = s2.at(7);
						for (int j = 7; j > 0; j--) {
							s2.at(j) = s2.at(j - 1);
						}
						s2.at(0) = tmp;

						tmp = s3.at(0);
						for (int j = 0; j < 7; j++) {
							s3.at(j) = s3.at(j + 1);
						}
						s3.at(7) = tmp;
					}
					else {
						char tmp = s2.at(7);
						for (int j = 7; j > 0; j--) {
							s2.at(j) = s2.at(j - 1);
						}
						s2.at(0) = tmp;

						tmp = s3.at(0);
						for (int j = 0; j < 7; j++) {
							s3.at(j) = s3.at(j + 1);
						}
						s3.at(7) = tmp;
					}
				}
				else {
					char tmp = s3.at(0);
					for (int j = 0; j < 7; j++) {
						s3.at(j) = s3.at(j + 1);
					}
					s3.at(7) = tmp;
				}
			}
		}
		else if (a == 4) {
			if (b == 1) {
				if (s3.at(2) != s4.at(6)) {
					if (s2.at(2) != s3.at(6)) {
						if (s1.at(2) != s2.at(6)) {
							char tmp = s1.at(0);
							for (int j = 0; j < 7; j++) {
								s1.at(j) = s1.at(j + 1);
							}
							s1.at(7) = tmp;

							tmp = s2.at(7);
							for (int j = 7; j > 0; j--) {
								s2.at(j) = s2.at(j - 1);
							}
							s2.at(0) = tmp;

							tmp = s3.at(0);
							for (int j = 0; j < 7; j++) {
								s3.at(j) = s3.at(j + 1);
							}
							s3.at(7) = tmp;

							tmp = s4.at(7);
							for (int j = 7; j > 0; j--) {
								s4.at(j) = s4.at(j - 1);
							}
							s4.at(0) = tmp;
						}
						else {
							char tmp = s2.at(7);
							for (int j = 7; j > 0; j--) {
								s2.at(j) = s2.at(j - 1);
							}
							s2.at(0) = tmp;

							tmp = s3.at(0);
							for (int j = 0; j < 7; j++) {
								s3.at(j) = s3.at(j + 1);
							}
							s3.at(7) = tmp;

							tmp = s4.at(7);
							for (int j = 7; j > 0; j--) {
								s4.at(j) = s4.at(j - 1);
							}
							s4.at(0) = tmp;
						}
					}
					else {
						char tmp = s3.at(0);
						for (int j = 0; j < 7; j++) {
							s3.at(j) = s3.at(j + 1);
						}
						s3.at(7) = tmp;

						tmp = s4.at(7);
						for (int j = 7; j > 0; j--) {
							s4.at(j) = s4.at(j - 1);
						}
						s4.at(0) = tmp;
					}
				}
				else {
					char tmp = s4.at(7);
					for (int j = 7; j > 0; j--) {
						s4.at(j) = s4.at(j - 1);
					}
					s4.at(0) = tmp;
				}
			}
			else {
				if (s3.at(2) != s4.at(6)) {
					if (s2.at(2) != s3.at(6)) {
						if (s1.at(2) != s2.at(6)) {
							char tmp = s1.at(7);
							for (int j = 7; j > 0; j--) {
								s1.at(j) = s1.at(j - 1);
							}
							s1.at(0) = tmp;

							tmp = s2.at(0);
							for (int j = 0; j < 7; j++) {
								s2.at(j) = s2.at(j + 1);
							}
							s2.at(7) = tmp;

							tmp = s3.at(7);
							for (int j = 7; j > 0; j--) {
								s3.at(j) = s3.at(j - 1);
							}
							s3.at(0) = tmp;

							tmp = s4.at(0);
							for (int j = 0; j < 7; j++) {
								s4.at(j) = s4.at(j + 1);
							}
							s4.at(7) = tmp;
						}
						else {
							char tmp = s2.at(0);
							for (int j = 0; j < 7; j++) {
								s2.at(j) = s2.at(j + 1);
							}
							s2.at(7) = tmp;

							tmp = s3.at(7);
							for (int j = 7; j > 0; j--) {
								s3.at(j) = s3.at(j - 1);
							}
							s3.at(0) = tmp;

							tmp = s4.at(0);
							for (int j = 0; j < 7; j++) {
								s4.at(j) = s4.at(j + 1);
							}
							s4.at(7) = tmp;
						}
					}
					else {
						char tmp = s3.at(7);
						for (int j = 7; j > 0; j--) {
							s3.at(j) = s3.at(j - 1);
						}
						s3.at(0) = tmp;

						tmp = s4.at(0);
						for (int j = 0; j < 7; j++) {
							s4.at(j) = s4.at(j + 1);
						}
						s4.at(7) = tmp;
					}
				}
				else {
					char tmp = s4.at(0);
					for (int j = 0; j < 7; j++) {
						s4.at(j) = s4.at(j + 1);
					}
					s4.at(7) = tmp;
				}
			}
		}

		//cout << s1 << '\n';

		//cout << s2 << '\n';

		//cout << s3 << '\n';

		//cout << s4 << '\n';
	}

	if (s1.at(0) == '1') {
		sum += 1;
	}
	if (s2.at(0) == '1') {
		sum += 2;
	}
	if (s3.at(0) == '1') {
		sum += 4;
	}
	if (s4.at(0) == '1') {
		sum += 8;
	}
	cout << sum;
	return 0;
}