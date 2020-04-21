#include <bits/stdc++.h>
using namespace std;
int arr1[17] = { 9,20,28,18,11 };
int arr2[17] = { 30, 1, 21, 17, 28 };
int n;
vector<string> answer;
string MAP1[17];
string MAP2[17];
int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num = arr1[i];
		string s;

		for (int j = n - 1; j >= 0; j--) {
			if ((int)(num / pow(2,j)) == 0) {
				s += "0";
			}
			else {
				s += "1";
				num -= pow(2, j);
			}
		}
		MAP1[i] = s;
		s = "";
	}

	for (int i = 0; i < n; i++) {
		int num = arr2[i];
		string s;

		for (int j = n - 1; j >= 0; j--) {
			if ((int)(num / pow(2, j)) == 0) {
				s += "0";
			}
			else {
				s += "1";
				num -= pow(2, j);
			}
		}
		MAP2[i] = s;
		s = "";
	}

	for (int i = 0; i < n; i++) {
		string s;
		for (int j = 0; j < n; j++) {
			if (MAP1[i][j] == '1' || MAP2[i][j] == '1') {
				s += "#";
			}
			else if (MAP1[i][j] == '0' && MAP2[i][j] == '0') {
				s += " ";
			}
		}
		answer.push_back(s);
		s = "";
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}