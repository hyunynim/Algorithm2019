#include<cstdio>
#include<algorithm>
using namespace std;
int r[505];
int c[505];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int sum = 0, mx = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int num, cnt = 0;
			scanf("%d", &num);
			while (num) {
				cnt += num % 10 == 9;
				num /= 10;
			}
			r[i] += cnt;
			c[j] += cnt;
			mx = max({ r[i], c[j], mx });
			sum += cnt;
		}
	}
	printf("%d", sum - mx);
}