#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int n, k; scanf("%d %d", &n, &k);
		vector<ll> seq(n);
		vector<int> x(n + 1);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &seq[i]);
			x[i + 1] = x[i] ^ (seq[i] % 2);
		}
		int f = 1;
		vector<int> ans;
		for (int i = 1; i <= n; ++i) {
			if (ans.size() == k - 1) break;
			if (x[i] == f) {
				ans.push_back(i);
				f ^= 1;
			}
		}
		if (ans.size() == k - 1 && x.back() == k % 2) {
			puts("YES");
			for (int i = 0; i < ans.size(); ++i)
				printf("%d ", ans[i]);
			printf("%d", n);
			puts("");
		}
		else
			puts("NO");
		ans.clear();
		seq.clear();
		x.clear();
	}
}