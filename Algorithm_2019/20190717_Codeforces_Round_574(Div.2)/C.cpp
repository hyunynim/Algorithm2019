#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
ll d[2][101010];
vector<ll> s[2];
int n;
ll go(int cur, int team) {
	if (cur == n - 1) return s[team][cur];
	ll& res = d[team][cur];
	if (~res) return res;
	res = s[team][cur];
	ll tmp = 0;
	for (int i = cur + 1; i < n; ++i) {
		if (s[team][cur] > s[team ^ 1][i])
			tmp = max(tmp, go(i, team ^ 1));
	}
	return res = tmp + res;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < 2; ++i) {
		s[i].resize(n);
		for (int j = 0; j < n; ++j)
			scanf("%lld", &s[i][j]);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max({ ans, go(i, 0), go(i, 1) });
	printf("%lld", ans);
}