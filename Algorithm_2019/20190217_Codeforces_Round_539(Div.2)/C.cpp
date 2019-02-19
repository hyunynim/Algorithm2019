#include<cstdio>
#include<string.h>
#include<algorithm>
#include<utility>
#include<functional>
#include<map>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

ll d[(1 << 20) + 1][2];
int main() {
	int n; scanf("%d", &n);
	vector<int> seq(n + 1);
	int pref = 0;
	ll ans = 0;
	d[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &seq[i]);
		pref ^= seq[i];
		ans += d[pref][i & 1];
		d[pref][i & 1]++;
	}
	printf("%lld", ans);
}