#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
int main() {
	ll n, k; scanf("%lld %lld", &n, &k);
	vector<ll> seq;
	for (ll i = 1; i * i <= (1LL << 33); ++i)
		seq.push_back((i + 1) * i / 2);
	for (int i = 0; i < seq.size(); ++i) {
		if (seq[i] - (n - i - 1) == k) {
			printf("%d", n - (i + 1));
			return 0;
		}
	}
}