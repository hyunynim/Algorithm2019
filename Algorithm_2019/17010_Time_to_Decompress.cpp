#include<cstdio>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n; char msg[10];
		scanf("%d %s", &n, msg);
		for (int i = 0; i < n; ++i)
			printf("%c", msg[0]);
		puts("");
	}
}