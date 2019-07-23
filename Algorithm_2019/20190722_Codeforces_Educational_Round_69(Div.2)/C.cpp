#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
int d[2][303030];
vector<int> seq;
int n, k;
int main() {
	scanf("%d %d", &n, &k);
	memset(d, -1, sizeof(d));
	seq.resize(n);
	vector<int> sum;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		if (i)
			sum.push_back(seq[i] - seq[i - 1]);
	}
	sort(sum.begin(), sum.end());
	for (int i = 0; i < k - 1; ++i)
		sum.pop_back();
	int ans = 0; for (int i = 0; i < sum.size(); ++i)
		ans += sum[i];
	printf("%d", ans);
}