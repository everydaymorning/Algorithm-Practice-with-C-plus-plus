#include <bits/stdc++.h>
using namespace std;
int arr[27];
bool check[27];
int main() {
	char alpha[27] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	
	memset(arr, -1, sizeof(arr));

	string str;
	cin >> str;
	int str_size = str.size();
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < str_size; j++) {
			if (str.at(j) == alpha[i]) {
				if (check[i]) continue;
				arr[i] = j;
				check[i] = true;
			}
		}
	}
	
	for (int i = 0; i < 26; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}