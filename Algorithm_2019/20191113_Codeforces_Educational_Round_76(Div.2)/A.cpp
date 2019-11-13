#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, x, a, b; scanf("%d %d %d %d", &n, &x, &a, &b);
		if (a > b) swap(a, b);
		int d = abs(a - b);
		int l = a - 1;
		int r = n - b;
		printf("%d\n", d + min(x, l + r));
	}
}