#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
struct DISJOINT {
	vector<int> p;
	vector<int> sz;
	DISJOINT(int n) {
		p.resize(n + 1);
		sz.resize(n + 1);
		for (int i = 0; i < n + 1; ++i) {
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