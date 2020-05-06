#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, l; scanf("%d %d", &l, &n);
		int m = -1e9, M = -1e9;
		for (int i = 0; i < n; ++i) {
			int num; scanf("%d", &num);
			m = max(m, min(num, l - num));
			M = max(M, max(num, l - num));
		}
		printf("%d %d\n", min(l - m, M), max(l - m, M));
	}
}