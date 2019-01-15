#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
#include<unordered_map>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
struct Segment {
	vector<int> tree;
	vector<int> seq;
	unordered_map<int, int> nodeNo;
	Segment(int n) {
		seq.resize(n);
		int log = ceil(log2(n));
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

	void update(int node, int s, int e, int i, ll u) {
		if (i < s || i > e) return;
		tree[node] += u;
		if (s != e) {
			update(node * 2, s, (s + e) / 2, i, u);
			update(node * 2 + 1, (s + e) / 2 + 1, e, i, u);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}
};

int main() {
	int n;
	scanf("%d", &n);
	Segment s(1000000);
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &b);
			printf("%d\n", s.query(1, 1, 1000000, b));
		}
		else {
			scanf("%d %d", &b, &c);
			s.update(1, 1, 1000000, b, c);
		}
	}
}