#include <iostream>

using namespace std;

int main() {
	int t = 0;
	
	int tmp = 0;
	int m_result = 0;
	int save = 0;
	cin >> t;
	int array[1000] = { 0 };

	for (int i = 0; i < t; i++) {
		cin >> array[i];
	}

	for (int i = 0; i < t-1; i++) {
		for (int j = i + 1; j < t; j++) {
			if (array[i] > array[j]) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}

	for (int i = 0; i < t; i++) {
		save += array[i];
		m_result = m_result + save;

	}
	
	printf("%d", m_result);

	return 0;
}