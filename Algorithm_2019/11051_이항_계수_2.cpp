#include<cstdio>
int d[1010][1010];
const int mod = 1e4 + 7;
int main() {
	for (int i = 1; i < 1010; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i)
				d[i][j] = 1;
			else if (j == 1 || j == i - 1)
				d[i][j] = i;
			else
				d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
			d[i][j] %= mod;
		}
	}
	int n, k; scanf("%d %d", &n, &k);
	printf("%d", d[n][k]);
}