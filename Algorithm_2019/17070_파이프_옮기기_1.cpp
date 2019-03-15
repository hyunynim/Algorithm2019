#include<cstdio>
#include<string.h>
int d[3][101][101];
int wall[101][101];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &wall[i][j]);
	d[0][1][2] = 1;	//- \ |

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == 1 && (j == 1 || j == 2)) continue;
			for (int k = 0; k < 3; ++k) {
				if (k == 0) {
					if(wall[i][j] == 0)
						d[k][i][j] += d[0][i][j - 1];
					if (wall[i - 1][j] == 0)
						d[k][i][j] += d[1][i][j - 1];
				}
				else if (k == 1) {
					d[k][i][j] += d[0][i - 1][j - 1] + d[1][i - 1][j - 1] + d[2][i - 1][j - 1];
				}
				else
					d[k][i][j] += d[2][i - 1][j] + d[1][i - 1][j];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 3; ++i)
		ans += d[i][n][n];
	printf("%d", ans);
}