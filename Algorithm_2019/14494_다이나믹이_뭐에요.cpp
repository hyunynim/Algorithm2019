#include<cstdio>

typedef long long ll;

ll d[1010][1010];
const ll mod = 1e9 + 7;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	d[1][1] = 1;
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			if (i == 1 && j == 1) continue;
			d[i][j] = d[i - 1][j] + d[i][j - 1] + d[i-1][j-1];
			d[i][j] %= mod;
		}
	}
	printf("%lld", d[n][m]);
}