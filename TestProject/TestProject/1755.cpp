#include <bits/stdc++.h>
using namespace std;
string zero = "zero";
string one = "one";
string two = "two";
string three = "three";
string four = "four";
string five = "five";
string six = "six";
string seven = "seven";
string eight = "eight";
string nine = "nine";

bool cmp(string a, string b) {
	int n1 = stoi(a);
	int n2 = stoi(b);
	string str1, str2;
	for (int i = 0; i < a.size(); i++) {
		int tmp1 = a[i] - '0';

		if (tmp1 == 1) str1 += one;
		else if (tmp1 == 0) str1 += zero;
		else if (tmp1 == 2) str1 += two;
		else if (tmp1 == 3) str1 += three;
		else if (tmp1 == 4) str1 += four;
		else if (tmp1 == 5) str1 += five;
		else if (tmp1 == 6) str1 += six;
		else if (tmp1 == 7) str1 += seven;
		else if (tmp1 == 8) str1 += eight;
		else if (tmp1 == 9) str1 += nine;
	}

	for (int i = 0; i < b.size(); i++) {
		int tmp2 = b[i] - '0';
		if (tmp2 == 1) str2 += one;
		else if (tmp2 == 0) str2 += zero;
		else if (tmp2 == 2) str2 += two;
		else if (tmp2 == 3) str2 += three;
		else if (tmp2 == 4) str2 += four;
		else if (tmp2 == 5) str2 += five;
		else if (tmp2 == 6) str2 += six;
		else if (tmp2 == 7) str2 += seven;
		else if (tmp2 == 8) str2 += eight;
		else if (tmp2 == 9) str2 += nine;
	}
	return str1 < str2;


}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int m, n;
	cin >> m >> n;

	vector<string> v;
	for (int i = m; i <= n; i++) {
		string num = to_string(i);
		v.push_back(num);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
		if ((i + 1) % 10 == 0) cout << '\n';

	}
	return 0;
}