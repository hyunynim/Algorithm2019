#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int k, n;
	scanf("%d %d", &k, &n);
	vector<ll> seq(k);
	unordered_map<ll, int> chk;
	priority_queue<ll, vector<ll>, greater<ll>> q;
	for (int i = 0; i < k; ++i) {
		scanf("%lld", &seq[i]);
		q.push(seq[i]);
		chk[seq[i]] = 1;
	}
	ll lim = seq[0];
	while (1) {
		ll cur = q.top(); q.pop(); --n;
		if (q.size() > 20000) {
			while (n && q.size() && q.top() < lim) {
				cur = q.top(); --n; q.pop();
			}
		}
		if (n == 0) {
			printf("%lld", cur);
			return 0;
		}
		for (int i = 0; i < seq.size(); ++i) {
			if (cur * seq[i] < (1LL << 31) && chk[cur * seq[i]] == 0) {
				chk[cur * seq[i]] = 1;
				q.push(cur * seq[i]);
			}
		}
		lim *= seq[0];
	}
}