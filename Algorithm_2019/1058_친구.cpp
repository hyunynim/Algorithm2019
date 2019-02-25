#include<cstdio>
#include<algorithm>

using namespace std;

int adj[101][101];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[101];
		scanf("%s", msg);
		for (int j = 0; j < n; ++j) {
			if (msg[j] == 'Y')
				adj[i][j] = 1;
			else
				adj[i][j] = 10101010;
		}
	}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (adj[i][j] > 10000000 || i == j)
				adj[i][j] = 0;
			if (adj[i][j] && adj[i][j] <= 2)
				++cnt;
		}
		ans = max(cnt, ans);
	}
	printf("%d", ans);
}