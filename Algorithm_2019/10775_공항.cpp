#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
struct Segment {
	vector<ll> tree;
	vector<ll> seq;
	Segment(int n) {
		seq.resize(n + 1);
		int log = ceil(log2(n));
		int t = (1 << (log + 1));
		tree.resize(t + 1);
	}

	void init(int node, int s, int e) {
		if (s == e) {
			tree[node] = seq[s];
		}
		else {
			init(node * 2, s, (s + e) / 2);
			init(node * 2 + 1, (s + e) / 2 + 1, e);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}

	ll query(int node, int s, int e, int i, int j) {
		if (e < i || s > j) return 0;
		if (i <= s && e <= j) return tree[node];
		return query(node * 2, s, (s + e) / 2, i, j) + query(node * 2 + 1, (s + e) / 2 + 1, e, i, j);
	}

	void update(int node, int s, int e, int i, ll u) {
		if (i < s || i > e) return;
		tree[node] += u;
		if (s != e) {
			update(node * 2, s, (s + e) / 2, i, u);
			update(node * 2 + 1, (s + e) / 2 + 1, e, i, u);
		}
	}
};
int main() {
	int g, p;
	scanf("%d %d", &g, &p);
	int num;
	Segment s(g);
	s.init(1, 1, g);
	int ans = 0;
	for (int i = 0; i < p; ++i) {
		scanf("%d", &num);
		if (s.query(1, 1, g, 1, num) >= num)
			break;
		else
			s.update(1, 1, g, num, 1);
		++ans;
	}
	printf("%d", ans);
}