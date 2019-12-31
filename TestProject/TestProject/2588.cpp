#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int one = b / 100;
	int two = b % 100 / 10;
	int three = b % 10;

	int sum1 = a * three;
	int sum2 = a * two;
	int sum3 = a * one;

	printf("%d\n", sum1);
	printf("%d\n", sum2);
	printf("%d\n", sum3);

	sum2 *= 10;
	sum3 *= 100;

	printf("%d", sum1 + sum2 + sum3);

	return 0;
}