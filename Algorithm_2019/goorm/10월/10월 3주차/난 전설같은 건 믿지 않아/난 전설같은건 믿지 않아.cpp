#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d(2, 50000);
void go(int s, int from, int to) {
	if (s == 0) return;
	int tmp = 6 - from - to;
	go(s - 1, from, tmp);
	printf("%d %d\n", s, to);
	go(s - 1, tmp, to);
}
void solve() {
	int n, k; scanf("%d %d", &n, &k);
	go(n, 1, k);
}
int main() {
	char msg[1010];
	int cnt = 1, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);

		FILE* fp = freopen(msg, "w", stdout);
		int n = cnt;
		int k = rand() % 2 + 2;
		printf("%d %d", n, k);

		fclose(fp);


		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 20) break;
	}
}