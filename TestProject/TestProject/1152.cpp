#include <iostream>
using namespace std;

int main() {
	char str[1000001];
	int cnt = 0;
	int len = 0;
	
	cin.getline(str, 1000001, '\n');

	for (int i = 0; i < 1000001; i++) {
		if (str[i] == '\0') {
			len = i;
			break;
		}
	}

	for (int i = 0; i < len; i++) {
		if (str[i] == ' ' && i != 0) {
			if (str[i - 1] != ' ') {
				cnt++;
			}
		}
		else if (i == (len - 1) && str[i] != ' ') {
			cnt++;
		}
	}

	printf("%d", cnt);


	return 0;
}