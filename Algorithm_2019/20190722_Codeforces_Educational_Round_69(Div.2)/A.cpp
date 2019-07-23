#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> seq(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &seq[i]);
		sort(seq.begin(), seq.end());
		int ans = seq.back();
		seq.pop_back();
		printf("%d\n", min(min(ans, seq.back()) - 1, (int)seq.size() - 1));
	}
}