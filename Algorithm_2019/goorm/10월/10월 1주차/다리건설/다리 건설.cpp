#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d(5, 1000);

void solve() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);

	vector<int> lis;
	lis.push_back(seq[0]);
	for (int i = 1; i < n; ++i) {
		auto it = lower_bound(lis.begin(), lis.end(), seq[i]);
		if (it == lis.end())
			lis.push_back(seq[i]);
		else
			*it = seq[i];
	}
	printf("%d", lis.size());
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 1, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);
		int n = d(gen);
		if (cnt <= 3)
			n = rand() % 5 + 5;
		else if (cnt <= 6)
			n = 1000;
		bool chk[1010] = { 0 };
		printf("%d\n", n);
		uniform_int_distribution<int> d2(1, n);
		for (int i = 0; i < n; ++i) {
			if (cnt == 5)
				printf("%d ", i + 1);
			else if (cnt == 6)
				printf("%d ", n - i);
			else {
				int num;
				while (chk[num = d2(gen)]);
				chk[num] = 1;
				printf("%d ", num);
			}
		}
		fclose(fp);
		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 10) break;
	}
}