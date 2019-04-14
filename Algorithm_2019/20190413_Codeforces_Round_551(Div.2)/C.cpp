#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	char msg[303030];
	scanf("%s", msg);
	int cnt = 0, pCnt = 0;
	for (int i = 0; i < n; ++i)
		if (msg[i] == '(')
			++pCnt;
	for (int i = 0; i < n; ++i) {
		if (i == n - 1) {
			if (msg[i] == '?') {
				--cnt;
				msg[i] = ')';
			}
			else if (msg[i] == '(') {
				printf(":("); return 0;
			}
			else
				--cnt;
		}
		else {
			if (msg[i] == '(') 
				++cnt;
			else if (msg[i] == ')') {
				--cnt;
				if (cnt <= 0) {
					printf(":(");
					return 0;
				}
			}
			else {
				if (pCnt < n / 2) {
					msg[i] = '(';
					++cnt;
					++pCnt;
				}
				else{
					msg[i] = ')';
					--cnt;
					if (cnt <= 0) {
						printf(":(");
						return 0;
					}
				}
			}
		}
	}
	if (cnt)
		printf(":(");
	else
		printf("%s", msg);
}