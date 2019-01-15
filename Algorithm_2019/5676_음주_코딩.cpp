#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
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
			tree[node] = tree[node * 2] * tree[node * 2 + 1];
		}
	}

	ll query(int node, int s, int e, int i, int j) {
		if (e < i || s > j) return 1;
		if (i <= s && e <= j) return tree[node];
		return query(node * 2, s, (s + e) / 2, i, j) * query(node * 2 + 1, (s + e) / 2 + 1, e, i, j);
	}

	void update(int node, int s, int e, int i, ll u) {
		if (i < s || i > e) return;
		if(s == e)
			tree[node] = u;
		else{
			update(node * 2, s, (s + e) / 2, i, u);
			update(node * 2 + 1, (s + e) / 2 + 1, e, i, u);
			tree[node] = tree[node * 2] * tree[node * 2 + 1];
		}
	}
};

int main() {
	int n, k;
	while (~scanf("%d %d", &n, &k)) {
		Segment s(n);
		for (int i = 1; i <= n; ++i) {
			int num; scanf("%d", &num);
			if (num == 0) s.seq[i] = 0;
			else if (num < 0) s.seq[i] = -1;
			else s.seq[i] = 1;
		}
		s.init(1, 1, n);
		for (int i = 0; i < k; ++i) {
			char cmd[2]; int a, b;
			scanf("%s %d %d", cmd, &a, &b);
			if (cmd[0] == 'C') {
				if (b < 0) b = -1;
				else if (b > 0) b = 1;
				s.update(1, 1, n, a, b);
			}
			else {
				int ans = s.query(1, 1, n, a, b);
				if (ans == 0) putchar('0');
				else if (ans < 0) putchar('-');
				else putchar('+');
			}
		}
		puts("");
	}
}