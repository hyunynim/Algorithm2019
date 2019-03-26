#include<cstdio>
#include<algorithm>

using namespace std;

#define VMAX 521
#define INF 1e9
int n, m, a, b;

int graph[2][VMAX][VMAX];

void floyd(bool gt) {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				graph[gt][i][j] = min(graph[gt][i][j], graph[gt][i][k] + graph[gt][k][j]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				graph[k][i][j] = INF;
				if (i == j)
					graph[k][i][j] = 0;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		--a; --b;
		graph[0][a][b] = min(graph[0][a][b], 1);
		graph[1][b][a] = min(graph[1][b][a], 1);
	}
	floyd(0); floyd(1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (graph[0][i][j] >= INF)
				graph[0][i][j] = 0;
			if (graph[1][i][j] >= INF)
				graph[1][i][j] = 0;
			graph[0][i][j] = max(graph[0][i][j], graph[1][i][j]);
			if (graph[0][i][j] == 0)
				++cnt;
		}
		if (cnt == 1)
			++ans;
	}
	printf("%d", ans);
}