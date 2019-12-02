#include <bits/stdc++.h>

using namespace std;

int cnt;
char multi[32];
int arr[35];
int carry[35];
void TwoLargeInteger(int multiNum, int start)
{
	int tmp;
	
	arr[34] = start;
	for (int i = 0; i < multiNum; i++)
	{
		memset(carry, 0, sizeof(int) * 35);
		for (int j = 34; j >= 1; j--)
		{
			tmp = 2 * arr[j];
			if (tmp >= 10)
			{
				carry[j - 1]++;
				arr[j] = tmp - 10;
			}
			else
				arr[j] = tmp;
		}
		for (int m = 33; m >= 0; m--)
			arr[m] += carry[m];
	}
	if (arr[34] != 0)
	{
		arr[34] -= 1;
		return;
	}
	else
	{
		for (int j = 34; j >= 1; j--)
		{
			if (arr[j] >= 0)
			{
				arr[j] -= 1;
				break;
			}
			else
			{
				arr[j] += 9;
				arr[j - 1] -= 1;

			}
		}
	}
}
void hanoi(int m, int from, int tmp, int to) {


	if (m == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		hanoi(m - 1, from, to, tmp);
		printf("%d %d\n", from, to);
		hanoi(m - 1, tmp, from, to);
	}


}
int main() {
	int N;
	cin >> N;
	
	TwoLargeInteger(N, 1);
	int i = 0;
	while (arr[i] == 0)
		i++;
	for (int j = i; i <= 34; i++)
		printf("%d", arr[i]);
	
	printf("\n");
	if (N <= 20) {
		hanoi(N, 1, 2, 3);
	}
	


	return 0;

}