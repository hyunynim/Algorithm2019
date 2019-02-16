#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<string.h>
#include<tuple>
#define INF 100000000
using namespace std;
typedef tuple<int, int, int> P;
vector<P> edge;

int n, m, w, dist[512];
bool canGo = 1;

void BellmanFord(int s) {
	for (int i = s; i <= n; ++i) {
		for (int j = 0; j < edge.size(); ++j) {
			int from, to, w;
			tie(from, to, w) = edge[j];
			if (dist[from] != INF && dist[to] > dist[from] + w) {
				dist[to] = dist[from] + w;
				if (i == n) canGo = 0;
			}
		}
	}
}