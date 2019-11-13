#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d(5, 10000);
void solve() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());
	ll ans = 0, tmp = 0;
	for (int i = 0; i < n; ++i) {
		ans += seq[i] + tmp;
		tmp += seq[i];
	}
	cout << ans;
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 2;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);
		int n = d(gen);
		if (cnt < 4) n = 1000000;
		else
			n = d(gen);
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) 
			printf("%d ", cnt == 2 ? 1000 : rand() % 1000 + 1);

		fclose(fp);
		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 10) break;
	}
}