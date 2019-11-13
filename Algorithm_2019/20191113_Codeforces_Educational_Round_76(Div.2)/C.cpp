#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
vector<int> adj[202020];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> seq(n);
		int ans = 1e9;
		int l = 1e9, r = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &seq[i]);
			if (i && seq[i-1] == seq[i])
				ans = 2;
			adj[seq[i]].push_back(i);
			l = min(l, seq[i]);
			r = max(r, seq[i]);
		}
			for (int i = l; i <= r; ++i) {
				for (int j = 0; j < adj[i].size(); ++j) {
					for (int k = j + 1; k < adj[i].size(); ++k) {
						ans = min(ans, adj[i][k] - adj[i][j] + 1);
					}
				}
				adj[i].clear();
			}
			printf("%d\n", (n == 1 || ans > 1e6) ? -1 : ans);
	}
}