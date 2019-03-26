#include<cstdio>
typedef long long ll;
int main() {
	int t; scanf("%d", &t); int cnt = 1;
	while (t--) {
		ll p, q;
		ll fibo[10101] = { 1, 1 };
		scanf("%lld %lld", &p, &q);
		for (int i = 2; i < p; ++i) {
			fibo[i] = fibo[i - 1] + fibo[i - 2];
			fibo[i] %= q;
		}
		printf("Case #%d: %lld\n", cnt++, fibo[p - 1]);
	}
}