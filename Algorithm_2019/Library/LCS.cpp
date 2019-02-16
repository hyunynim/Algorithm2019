#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

// O(n^2)

int dp[1004][1004];
int len1, len2;
char msg[2][1234];

void printAns(int i, int j) {
	if (dp[i][j] == 0)
		return;
	else {
		int cur = dp[i][j];
		if (cur != dp[i - 1][j] && cur != dp[i][j - 1]) {
			printAns(i - 1, j - 1);
			printf("%c", msg[0][j - 1]);
		}
		else {
			if (cur == dp[i - 1][j]) {
				printAns(i - 1, j);
			}
			else
				printAns(i, j - 1);
		}
	}
}

int main() {
	scanf("%s %s", msg[0], msg[1]);
	for (int i = 0; msg[1][i] != '\0'; ++i) {
		for (int j = 0; msg[0][j] != '\0'; ++j) {
			if (msg[1][i] == msg[0][j]) 
				dp[i + 1][j + 1] = dp[i][j] + 1;
			
			else
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	len1 = strlen(msg[0]); len2 = strlen(msg[1]);
	
	printf("%d\n", dp[len2][len1]);
	printAns(len2, len1);
}