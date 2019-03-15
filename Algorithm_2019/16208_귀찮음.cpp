#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

int main() {
	int n;
	scanf("%d", &n);
	vector<ll> seq(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &seq[i]);
		sum += seq[i];
	}
	sort(seq.begin(), seq.end());
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += seq[i] * (sum - seq[i]);
		sum -= seq[i];
	}
	printf("%lld", ans);
}