#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
struct TIME {
	int s, e, ind;
};
int main() {
	int t; scanf("%d", &t);
	for (int TC = 1; TC <= t; ++TC) {
		int n, q;
		scanf("%d %d", &n, &q);
		vector<P> seq(n);
		for (int i = 0; i < n; ++i)
			scanf("%lld %lld", &seq[i].second, &seq[i].first);
		sort(seq.begin(), seq.end());
		vector<TIME> query(q);
		for (int i = 0; i < q; ++i) {
			scanf("%d %d", &query[i].s, &query[i].e);
			query[i].ind = i + 1;
		}
		sort(query.begin(), query.end(), [](TIME t1, TIME t2) {
			if (t1.s == t2.s) 
				return t1.e > t2.e;
			return t1.s < t2.s;
		});

	}
}