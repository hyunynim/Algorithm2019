#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(2, 16);
uniform_int_distribution<int> d2(0, 1000);
uniform_int_distribution<int> d3(0, 10);

int n, num, cost[20][20];
int d[1 << 16][16];
const int inf = 1e9;
int TSP(int s, int stat) {
	if (stat == (1 << n) - 1)
		return cost[s][0] ? cost[s][0] : inf;
	int& res = d[stat][s];
	if (res != -1) return res;
	res = inf;
	for (int i = 0; i < n; ++i)
		if ((stat & (1 << i)) == 0 && cost[s][i])
			res = min(res, TSP(i, stat | (1 << i)) + cost[s][i]);
	return res;
}
void solve() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &cost[i][j]);
	printf("%d", TSP(0, 1));
}
int main() {
	solve();
	return 0;
	srand(time(0));
	char msg[1010];
	int cnt = 3, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);
		int n = d1(gen);
		if (cnt == 1) n = 3;
		else if (cnt == 2) n = 5;
		else if (cnt == 3) n = 6;
		else if (cnt <= 6) n = 16;
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) printf("0 ");
				else if(cnt <= 3) printf("%d ", rand() % 5 ? d3(gen) : 0);
				else printf("%d ", rand() % 5 ? d2(gen) : 0);
			}
			puts("");
		}
		fclose(fp);
		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 1) break;
	}
}