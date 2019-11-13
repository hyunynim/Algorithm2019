#include<bits/stdc++.h>
using namespace std;
int main() {
	int q; scanf("%d", &q);
	while (q--) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		printf("%lld\n", (a + b + c) / 2);
	}
}