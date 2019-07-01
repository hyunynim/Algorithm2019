#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int k, n;
	scanf("%d %d", &k, &n);
	vector<ll> seq(k);
	priority_queue<int> q;
	for (int i = 0; i < k; ++i) {
		scanf("%lld", &seq[i]);
		q.push(-seq[i]);
	}
	ll lim = seq.back() * seq.back();
	while (1) {
		ll cur = -q.top();
		q.pop(); --n;
		if (n == 0) {
			printf("%lld", cur);
			return 0;
		}
		for (int i = 0; i < seq.size(); ++i) {
			if (cur * seq[i] < (1LL << 31))
				q.push(-(cur * seq[i]));
			if (cur % seq[i] == 0)
				break;
		}
	}
}