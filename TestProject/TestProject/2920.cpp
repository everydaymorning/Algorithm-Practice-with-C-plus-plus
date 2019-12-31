#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[8] = { 1,2,3,4,5,6,7,8 };
	int arr2[8] = { 8,7,6,5,4,3,2,1 };
	int tmp[8] = { 0 };
	int asc = 0;
	int desc = 0;
	for (int i = 0; i < 8; i++) {
		cin >> tmp[i];
		
		if (tmp[i] == arr[i]) asc++;
		else if (tmp[i] == arr2[i]) desc++;
	}
	
	if (asc == 8) printf("ascending");
	else if (desc == 8) printf("descending");
	else printf("mixed");

	return 0;
}