#include<cstdio>
int cnt[4040404];
int main() {
	int n, num; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		cnt[num + 2000000]++;
	}
	for (int i = 0; i < 4040404; ++i) {
		for (int j = 0; j < cnt[i]; ++j)
			printf("%d ", i - 2000000);
	}
}