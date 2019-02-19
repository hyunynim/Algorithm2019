#include<cstdio>
typedef long long ll;
ll d[1010101] = { 1, 2, 7, 22 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 4; i <= n; ++i) {
		d[i] = 3 * d[i - 1] + d[i - 2] - d[i - 3];
		d[i] %= 1000000007;
	}
	printf("%lld", d[n]);
}