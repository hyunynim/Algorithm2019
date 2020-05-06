#include<bits/stdc++.h>
#include<chrono>
#include<random>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
mt19937 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());
/*Templates end*/
int d[101][101010];
int n, k;
vector< pair<int, int> > seq;
int go(int cur, int w) {
	if (cur == n) return 0;
	int& res = d[cur][w];
	if (~res) return res;
	res = 0;
	if (w >= seq[cur].first)
		res = max(res, go(cur + 1, w - seq[cur].first) + seq[cur].second);
	res = max(res, go(cur + 1, w));
}
void solve() {
	//TODO here
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &k);
	seq.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &seq[i].first, &seq[i].second);
	printf("%d", go(0, k));
}
int main() {
#ifndef ONLINE_JUDGE
	//Run in local
	//freopen("./test/1.input", "r", stdin);
#endif
	solve();
	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}
