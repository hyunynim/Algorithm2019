#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[2][101010];
int main() {
	int n; scanf("%d", &n);
	vector<ll> s[2];
	for (int i = 0; i < 2; ++i) {
		s[i].resize(n);
		for (int j = 0; j < n; ++j)
			scanf("%lld", &s[i][j]);
	}
	for (int i = n - 1; i >= 0; --i) {
		d[0][i] = max(d[1][i + 1] + s[0][i], d[0][i + 1]);
		d[1][i] = max(d[0][i + 1] + s[1][i], d[1][i + 1]);
	}
	printf("%lld", max(d[0][0], d[1][0]));
}