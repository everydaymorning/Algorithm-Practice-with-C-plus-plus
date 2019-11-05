#include <bits/stdc++.h>

using namespace std;

int main() {
	char number[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int arr[10] = { 0 };
	string room;
	cin >> room;
	int room_len = room.length();
	
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < room_len; j++) {
			if (number[i] == room[j]) arr[i]++;
		}
	}
	
	arr[6] += arr[9];
	arr[6] = arr[6] / 2 + arr[6] % 2;
	int max = 0;
	for (int i = 0; i < 9; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	
	cout << max << endl;

	return 0;
}