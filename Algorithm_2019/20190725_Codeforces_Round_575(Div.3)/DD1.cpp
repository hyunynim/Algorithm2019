#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int n, k; cin >> n >> k;
		string str, rgb = "RGB", s[3] = { "" };
		cin >> str;
		int ans = 1e9;
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < 3; ++j) {
				s[j].push_back(rgb[(i + j) % 3]);
			}
		}
		for (int i = 0; i <= n - k; ++i) {
			for (int t = 0; t < 3; ++t) {
				int cnt = 0;
				for (int j = 0; j < k; ++j) 
					cnt += (str[i + j] != s[t][j]);
				ans = min(ans, cnt);
			}
		}
		cout << ans << '\n';
	}
}