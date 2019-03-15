#include<cstdio>

char circle[101][101] = { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };

int main() {
	int n;
	scanf("%d", &n);
	int m = 0, mi = 0;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < n; ++j) {
			int num; scanf("%d", &num);
			if (m < num) {
				m = num; mi = i;
			}
		}
	}
	printf("%s", circle[mi]);
}