#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	int j = 0;
	if (n < 2) {
		printf("���α׷� ����");
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		
		if (n % i == 0) {
			n /= i;
			arr[j++] = i;
			i--;
		}
		
	}

	if (j == 1) {
		printf("�Ҽ�");
		return 0;
	}

	for (int i = 0; i < j; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}