#include <iostream>
using namespace std;
// Student ID: 201433853
// Name: 이수권
int n; // input n
int col[15]; // 각 컬럼에 해당하는 값을 저장하기 위한 배열 (10이상 테스트를 위해 사이즈를 15로 잡음)
int total; // 경우의 수를 저장할 변수
bool promising(int idx) {
	int k = 1;
	bool flag = true;
	cout << "idx: " << idx << '\n';
	cout << "col[" << idx << "]: " << col[idx] << "  col[" << k << "]: " << col[k] << '\n';
	while (k < idx && flag) {
		if ((col[idx] == col[k]) || abs(col[idx] - col[k]) == idx - k) {
			flag = false;
		}
		k++;
	}
	cout << "k: " << k << '\n';
	return flag;
}
void queens(int idx) {

	if (promising(idx)) {
		if (idx == n) {
			total++;
			cout << total << ": [";
			for (int i = 1; i <= n; i++) {
				if (i == n) cout << "<" << i << "," << col[i] << ">";
				else cout << "<" << i << "," << col[i] << ">, ";
			}
			cout << "]\n";
		}
		else {
			for (int i = 1; i <= n; i++) {
				col[idx + 1] = i;
				cout << "col[" << idx+1 << "]: " << col[idx + 1] << '\n';
				queens(idx + 1);
			}
		}
	}
}
int main() {
	cin >> n;
	queens(0);
	cout << "Total number: " << total;
	return 0;
}