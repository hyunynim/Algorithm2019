#include<bits/stdc++.h>
int main() {
	int t;
	scanf("%d", &t);
	for (int TC = 1; TC <= t; ++TC) {
		int n;
		scanf("%d", &n);
		int c[1010] = { 0 };
		int r[1010] = { 0 };
		bool board[1010][1010] = { 0 };
		char msg[1234];
		for (int i = 0; i < n; ++i) {
			scanf("%s", msg);
			for (int j = 0; j < n; ++j) {
				if (msg[j] == 'B') {
					c[i]++;
					r[j]++;
					board[i][j] = 1;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int k = c[i] + r[j] - (board[i][j]);
				if (k % 2)
					++ans;
			}
		}
		printf("#%d %d\n", TC, ans);
	}
}
