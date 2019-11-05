#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v1(3, 5);

	cout << v1.size() << endl; //3
	v1.push_back(7); // {5, 5, 5, 7}
	cout << v1[0] << ' ' << v1[1] << ' ' << v1[2] << ' ' << v1[3] << '\n';
	vector<int> v2(2); // {0, 0}
	v2.insert(v2.begin() + 1, 3); //{0, 3, 0}
	cout << v2[0] << ' ' << v2[1] << ' ' << v2[2] << '\n';

	vector<int> v3 = { 1,2,3,4 }; // {1,2,3,4}
	v3.erase(v3.begin() + 2); // {1,2,4}
	cout << v3[0] << ' ' << v3[1] << ' ' << v3[2] << '\n';

	vector<int> v4; // {}
	v4 = v3; // {1,2,4}

	cout << v4[0] << ' ' << v4[1] << ' ' << v4[2] << '\n'; // {1,2,4}
	v4.pop_back();// {1,2}
	v4.clear(); //{}

	return 0;
}