#include<bits/stdc++.h>
using namespace std;
int mat[101][101];
int main() {
	int n, m, h;
	scanf("%d %d %d", &n, &m, &h);
	vector<int> frontView(m), leftView(n);
	for (int i = 0; i < m; ++i)
		scanf("%d", &frontView[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &leftView[i]);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &mat[i][j]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mat[i][j] == 0) printf("0 ");
			else
				printf("%d ", min(leftView[i], frontView[j]));
		}
		puts("");
	}
}