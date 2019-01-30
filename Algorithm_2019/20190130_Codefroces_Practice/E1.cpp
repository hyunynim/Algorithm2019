#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> seq;
int n, m;
vector<pair<int, int>> seg;
int d[1010][2];
const int inf = -123456789;
int cur[1010];
int ans[1010];
int mmax;
int calc() {
	int mm = inf, nn = -inf;
	for (int i = 0; i < n; ++i) {
		mm = max(mm, seq[i]);
		nn = min(nn, seq[i]);
	}
	if (mmax < mm - nn) {
		mmax = mm - nn;
		for (int i = 0; i < m; ++i)
			ans[i] = cur[i];
	}
	return mm - nn;
}
int go(int s, bool c) {
	if (s == m) {
		return calc();
	}
	int res = inf;
	res = max(res, go(s + 1, 0));
	for (int i = seg[s].first - 1; i < seg[s].second; ++i)
		--seq[i];
	cur[s] = 1;
	res = max(res, go(s + 1, 1));
	cur[s] = 0;
	for (int i = seg[s].first - 1; i < seg[s].second; ++i)
		++seq[i];
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	seq.resize(n);
	seg.resize(m);
	for (int i = 0; i < n; ++i)
		d[i][0] = d[i][1] = inf;
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	for (int i = 0; i < m; ++i)
		scanf("%d %d", &seg[i].first, &seg[i].second);
	printf("%d\n", go(0, 0));
	vector<int> pick;
	for (int i = 0; i < m; ++i)
		if (ans[i]) pick.push_back(i + 1);
	printf("%d\n", pick.size());
	for (int i : pick)
		printf("%d ", i);
}