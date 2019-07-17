#include<bits/stdc++.h>
using namespace std;
vector<int> r[50505], c[50505];
string str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> str;
			for (int j = 0; j < m; ++j) {
				if (str[j] == '.') {
					r[i].push_back(j);
					c[j].push_back(i);
				}
			}
		}
		int ans = 1e9;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int chk = binary_search(r[i].begin(), r[i].end(), j);
				ans = min(ans, (int)(r[i].size() + c[j].size() - chk));
			}
			r[i].clear();
		}
		printf("%d\n", ans);
		for (int i = 0; i < m; ++i) c[i].clear();
	}
}