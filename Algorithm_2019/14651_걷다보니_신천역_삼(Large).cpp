#include<cstdio>
typedef long long ll;
int n;
ll d[34343][3][3];
ll mod = 1e9 + 9;
int main() {
	scanf("%d", &n);
	d[1][0][0] = 0;
	d[1][0][1] = 1;
	d[1][0][2] = 1;
	for (int i = 2; i <= 33333; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					d[i][j][(j + k) % 3] += d[i - 1][k][l];
					d[i][j][(j + k) % 3] %= mod;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < 3; ++i) {
		ans += d[n][i][(3 - i) % 3];
		ans %= mod;
	}
	printf("%lld", ans);
}