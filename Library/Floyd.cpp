#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define VMAX 111
#define INF 1e9
int n, m, a, b, w;

int dist[VMAX][VMAX];
int path[VMAX][VMAX];
void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}
}

void getPath(int i, int j, vector<int> & p) {
	if (i == j)
		return;
	else {
		if (path[i][j] == j) {
			p.push_back(j);
			return;
		}
		getPath(path[i][j], j, p);
		getPath(i, path[i][j], p);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dist[i][j] = INF;
			path[i][j] = -1;
			if (i == j) {
				dist[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		a; b;
		dist[a][b] = min(dist[a][b], w);
		path[a][b] = b;
	}
	floyd();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d ", dist[i][j] >= INF ? 0 : dist[i][j]);
		}
		printf("\n");
	}
	vector<int> vtmp;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			vtmp.clear();
			getPath(i, j, vtmp);
			if (vtmp.size()) {
				printf("%d ", vtmp.size() + 1);
				printf("%d ", i);
			}
			else
				printf("0");
			for (auto k = vtmp.rbegin(); k != vtmp.rend(); ++k)
				printf("%d ", *k);
			puts("");
		}
	}
}