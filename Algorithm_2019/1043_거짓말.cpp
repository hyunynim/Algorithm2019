#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#define MAX_SIZE 101
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
			if (p[y] < p[x]) p[x] = y;
			else p[y] = x;
			sz[y] = sz[x] += sz[y];
		}
		return sz[x];
	}
};
bool t[101];

int main() {
	int n, m, k, num;
	DISJOINT s;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &num);
		s.Union(0, num);
	}
	int ans = 0;
	vector<int> seq[101];
	for (int i = 0; i < m; ++i) {
		scanf("%d", &k);
		seq[i].resize(k);
		for (int j = 0; j < k; ++j) 
			scanf("%d", &seq[i][j]);
		
		for (int j = 1; j < k; ++j)
			s.Union(seq[i][j], seq[i][0]);
	}
	for (int i = 0; i < m; ++i) {
		bool ok = 1;
		for (int j = 0; j < seq[i].size(); ++j) {
			if (s.Find(seq[i][j]) == 0) {
				ok = 0; break;
			}
		}
		if (ok) ++ans;
	}
	printf("%d", ans);
}