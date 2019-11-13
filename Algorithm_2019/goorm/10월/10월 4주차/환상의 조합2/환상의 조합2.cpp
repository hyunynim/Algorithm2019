#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(2, 200000);
uniform_int_distribution<int> d2(0, 1048575);
ll d[(1 << 20) + 1][2];
void solve() {
	memset(d, 0, sizeof(d));
	//TODO
	int n; scanf("%d", &n);
	vector<int> seq(n + 1);
	int pref = 0;
	ll ans = 0;
	d[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &seq[i]);
		pref ^= seq[i];
		ans += d[pref][i & 1];
		d[pref][i & 1]++;
	}
	printf("%lld", ans);
}
int main() {
	solve();
	return 0;
	srand(time(0));
	char msg[1010];
	int cnt = 2, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen);
		if (cnt <= 3)
			n = rand() % 10 + 4;
		else if (cnt <= 6)
			n = 200000;
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) {
			if (cnt == 6)
				printf("%d ", 0);
			else if (10 <= cnt && cnt <= 15)
				printf("%d ", rand() % 3);
			else
				printf("%d ", cnt <= 3 ? rand() % 10 : d2(gen));
		}
		fclose(fp);


		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 20) break;
	}
}