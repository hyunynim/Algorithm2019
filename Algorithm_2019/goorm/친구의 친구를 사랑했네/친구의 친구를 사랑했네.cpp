#include<bits/stdc++.h>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(2, 500);
bool chk[10101];
vector<int> adj[10101];
int go(int cur) {
	chk[cur] = 1;
	int res = 1;
	for (int i = 0; i < adj[cur].size(); ++i) {
		int next = adj[cur][i];
		if (!chk[next])
			res += go(next);
	}
	return res;
}
bool solve() {
	int v, e; cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int from, to; cin >> from >> to;
		adj[from].push_back(to);
	}
	int ans = 0, ansV = 0;
	for (int i = 1; i <= v; ++i) {
		memset(chk, 0, sizeof(chk));
		if (!chk[i]) {
			int res = go(i);
			if (res > ans) {
				res = ans;
				ansV = i;
			}
		}
	}
	cout << ansV;
	return 0;
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 1, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen);
		if (cnt <= 3)
			n = rand() % 5 + 5;
		else if (cnt <= 6)
			n = 1000;

		uniform_int_distribution<int> d2(1, n * (n - 1) / 2);
		int e = min(d2(gen), 100000);
		if (cnt <= 3)
			e = rand() % 10 + 5;
		else if (cnt <= 4)
			e = 10000;
		printf("%d %d\n", n, e);
		uniform_int_distribution<int> d3(1, n);
		unordered_map<int, int> check;
		while (e--) {
			int n1 = d3(gen);
			int n2 = d3(gen);
			if (n1 == n2 || check[n1 * 100000 + n2]) {
				e++; continue;
			}
			check[n1 * 100000 + n2] = 1;
			printf("%d %d\n", n1, n2);
		}
		fclose(fp);
		check.clear();

		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 10) break;
	}
}