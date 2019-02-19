#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll sum[1025][1025];
ll num[1025][1025];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<ll> s1(n), s2(m);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &s1[i]);
	for (int i = 0; i < m; ++i)
		scanf("%lld", &s2[i]);

	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			num[i][j] = s1[i - 1] ^ s2[j - 1];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			sum[i][j] = sum[i - 1][j] ^ sum[i][j - 1] ^ sum[i - 1][j - 1] ^ num[i][j];
		}
	}
	ll ans = 0;
	for(int i = 1; i<=n; ++i)
		for(int j = 1; j<=m; ++j)
			
}