#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll seq[505050], sum[505050];
void solve1() {
	scanf("%d", &n);
	int ne = 0, po = 0;
	ll sum = 0, m = 1e9;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &seq[i]);
		if (seq[i] < 0)
			++ne;
		else
			++po;
		sum += abs(seq[i]);
		m = min(abs(seq[i]), m);
	}
	if (n == 1)
		printf("%d", seq[0]);
	else {
		if (ne && po)
			printf("%lld", sum);
		else
			printf("%lld", sum - 2 * m);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &seq[i]);
		sum[i + 1] = sum[i] + abs(seq[i]);
	}
	if (n == 1) {
		printf("%lld", seq[0]);
		return 0;
	}
	ll ans = -1e18;
	for (int i = 1; i < n; ++i) {
		ll s = sum[i - 1] + sum[n] - sum[i + 1];
		ans = max({ ans, seq[i - 1] - seq[i] + s, seq[i] - seq[i - 1] + s });
	}
	printf("%lld", ans);
}