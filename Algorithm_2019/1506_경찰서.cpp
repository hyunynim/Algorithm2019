#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int d[101][101];
int main() {
	int n; scanf("%d", &n);
	vector<int> price(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &price[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &d[i][j]);
			if (d[i][j] == 0)d[i][j] = 1000000;
		}
	}
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", d[i][j] >= 1000000 ? 0 : d[i][j]);
		}
		puts("");
	}
}