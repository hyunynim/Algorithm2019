#include<cstdio>
#include<string.h>
typedef long long ll;
ll d[2][1010101] = { {1, 2, 7 }, {1, 3, 10} };
int mod = 1e9 + 7;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; ++i) {
		d[0][i] = 2 * d[0][i - 1] + 3 * d[0][i - 2] + 2 * d[1][i - 3];
		d[1][i] = d[1][i - 1] + d[0][i];
		d[0][i] %= mod;
		d[1][i] %= mod;
	}
	printf("%lld", d[0][n]);
}