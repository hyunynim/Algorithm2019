#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int p, m, f, c; scanf("%d %d %d %d", &p, &m, &f, &c);
		int ans1 = m / p, ans2 = m / p;
		int coupon = (m / p) * c;
		ans1 += coupon / f;
		while (coupon >= f) {
			int tmp = coupon / f;
			coupon %= f;
			coupon += tmp * c;
			ans2 += tmp;
		}
		printf("%d\n", ans2 - ans1);
	}
}