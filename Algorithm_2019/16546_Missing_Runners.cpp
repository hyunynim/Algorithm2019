#include<cstdio>
bool chk[1 << 17];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int num; scanf("%d", &num);
		chk[num] = 1;
	}
	for (int i = 1; i < n + 1; ++i) {
		if (!chk[i]) {
			printf("%d", i); return 0;
		}
	}
}