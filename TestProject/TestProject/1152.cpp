#include <iostream>
using namespace std;

int main() {
	char str[1000001];
	int cnt = 0;
	int len = 0;
	
	cin.getline(str, 1000001, '\n'); // 최대 크기 1000000을 넘기지 않는 char 문자열 저장

	for (int i = 0; i < 1000001; i++) {
		if (str[i] == '\0') { // char 배열의 끝은 null값이기 때문에 i번째가 문자열의 끝이라면
			len = i; // len 변수에 현재 i값 저장한 후 for문 탈출
			break;
		}
	}

	for (int i = 0; i < len; i++) { // 위에서 저장한 len의 길이까지 반복문 수행
		if (str[i] == ' ' && i != 0) { // 현재 i번째 문자열이 공백이고 i가 0이 아니라면
			if (str[i - 1] != ' ') { // i-1번째 문자열이 공백이 아니라면, 즉 공백이 아니라는 것은 문자라는 뜻
				cnt++; // 문자의 개수 +1
			}
		}
		else if (i == (len - 1) && str[i] != ' ') { // 현재 i번째 값이 문장의 끝이고 공백이 아니라면 마지막 문자라는 뜻이므로 
			cnt++; // 문자의 개수 +1
		}
	}

	printf("%d", cnt); // 문자의 개수 출력


	return 0;
}