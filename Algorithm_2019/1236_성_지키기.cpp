#include<cstdio>
int r[55], c[55];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		char msg[1234];
		scanf("%s", msg);
		for (int j = 0; j < m; ++j) {
			if (msg[j] == 'X') {
				++r[i];
				++c[j];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (r[i] == 0 && c[j] == 0) {
				++r[i]; ++c[j];
				++ans;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (r[i] == 0) {
				++r[i]; ++ans;
				continue;
			}
			if (c[j] == 0) {
				++c[j]; ++ans;
				continue;
			}
		}
	}
	printf("%d", ans);
}