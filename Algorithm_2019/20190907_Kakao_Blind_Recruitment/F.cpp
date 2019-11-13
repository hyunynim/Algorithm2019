#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 101;
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
int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 1e9;
	sort(dist.begin(), dist.end());
	vector<int> seq;
	for (int i = 0; i < weak.size(); ++i)
		seq.push_back(i == weak.size() - 1 ? n - weak.back() + weak[0] : weak[i + 1] - weak[i]);

	return answer > 1e8 ? -1 : answer;
}

int main() {
	int n; scanf("%d", &n);
	vector<int> a(4), b(4);
	for (int i = 0; i < 4; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < 4; ++i)
		scanf("%d", &b[i]);
	printf("%d", solution(n, a, b));
}