#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;
vector<P> pos;
const int mod = 1e9 + 7;
int n;
int d[3][202020];
int go(int s, int f) {
	if (s == n) return 0;
	int & res = d[f][s];
	if (res != -1) return res;
	res = 0;
	if (f == 0) {
		for (int i = s + 1; i < n; ++i) {
			if (pos[s].second > pos[i].second) {
				res += go(s + 1, 1);
				res %= mod;
			}
		}
	}
	else if (f == 1) {
		for (int i = s + 1; i < n; ++i) {
			if (pos[s].second < pos[i].second) {
				res += go(s + 1, 2);
				res %= mod;
			}
		}
	}
	else if (f == 2)
		return 1;

	return res;
}
int main() { 
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	pos.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &pos[i].first, &pos[i].second);
	sort(pos.begin(), pos.end());
	int ans = 0;
	for (int i = 0; i < n - 2; ++i) {
		ans += go(i, 0);
		ans %= mod;
	}
	printf("%d", ans);
}