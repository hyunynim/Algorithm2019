#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> seq(n);
	int cnt[1010] = { 0 };
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		++cnt[seq[i]];
	}
	int ans = 0;
	int flag = 0;
	for (int i = 1; i < 1010; ++i) {
		if (cnt[i] % 2) {
			if (flag)
				ans += (cnt[i] - 1);
			else
				ans += cnt[i];
			flag ^= 1;
		}
		else
			ans += cnt[i];
	}
	printf("%d", ans);
}