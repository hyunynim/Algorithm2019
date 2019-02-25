#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#define MAX_SIZE 3030
using namespace std;

struct DISJOINT {
	vector<int> p;
	vector<int> sz;
	DISJOINT() {
		p.resize(MAX_SIZE);
		sz.resize(MAX_SIZE);
		for (int i = 0; i < MAX_SIZE; ++i) {
			p[i] = i;
			sz[i] = 1;
		}
	}
	int Find(int x) {
		if (x == p[x])
			return  x;
		else
			return p[x] = Find(p[x]);
	}
	int Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if (x != y) {
			p[y] = x;
			sz[y] = sz[x] += sz[y];
		}
		return sz[x];
	}
};
struct line {
	int x1, x2, y1, y2;
};
int main() {
	int n;
	scanf("%d", &n);
	vector<line> l(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d %d", &l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
		if (l[i].x1 > l[i].x2) swap(l[i].x1, l[i].x2);
		if (l[i].y1 > l[i].y2) swap(l[i].y1, l[i].y2);
	}
	DISJOINT s;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (l[i].x1 <= l[j].x1 && l[j].x1 <= l[i].x2
				|| l[i].x1 <= l[j].y2 && l[j].y2 <= l[i].x2
				|| l[i].y1 <= l[j].y1 && l[j].y1 <= l[j].y1
				|| l[i].y1 <= l[j].y2 && l[j].y2 <= l[i].y1
				|| l[j].x1 <= l[i].x1 && l[i].x1 <= l[j].x2
				|| l[j].x1 <= l[i].y2 && l[i].y2 <= l[j].x2
				|| l[j].y1 <= l[i].y1 && l[i].y1 <= l[j].y1
				|| l[j].y1 <= l[i].y2 && l[i].y2 <= l[j].y1
				)
				ans = max(ans, s.Union(i, j));
		}
	}
	int g = 0;
	for (int i = 0; i < n; ++i)
		if (s.Find(i) == i) ++g;
	printf("%d\n%d", g, ans);
}