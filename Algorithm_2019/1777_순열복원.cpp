#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
vector<int> ans;
struct Segment {
	vector<int> tree;
	vector<int> seq;
	Segment(int n) {
		seq.resize(n + 1);
		int log = ceil(log2(n + 1));
		int t = (1 << (log + 1));
		tree.resize(t);
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

	int query(int node, int s, int e, int i) {
		if (s == e) {
			tree[node]--;
			return s;
		}
		int ans;
		if (tree[node * 2] >= i)
			ans = query(node * 2, s, (s + e) / 2, i);
		else
			ans = query(node * 2 + 1, (s + e) / 2 + 1, e, i - tree[node * 2]);
		--tree[node];
		return ans;
	}

	void update(int node, int s, int e, int i, int u) {
		if (i < s || i > e) return;
		if (s == e) {
			tree[node] = u;
			return;
		}
		update(node * 2, s, (s + e) / 2, i, u);
		update(node * 2 + 1, (s + e) / 2 + 1, e, i, u);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
};

int main() {
	int n;
	scanf("%d", &n);
	Segment s(n);
	ans.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		s.seq[i] = 1;
	s.init(1, 1, n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)scanf("%d", &seq[i]);
	reverse(seq.begin(), seq.end());
	for (int i = 0; i < n; ++i) {
		int num = seq[i];
		++num;
		if (i == 0) {
			ans[num] = n - i;
			s.update(1, 1, n, num, 0);
			continue;
		}
		int pos = s.query(1, 1, n, num);
		ans[pos] = n - i;
	}
	reverse(ans.begin() + 1, ans.end());
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
}