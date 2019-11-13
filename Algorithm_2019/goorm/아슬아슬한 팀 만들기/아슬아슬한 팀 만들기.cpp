#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(2, 1000);
uniform_int_distribution<int> d2(1, 100000);
vector<int> adj[2020];
int chk[2020];
bool go(int s, int color) {
	chk[s] = color;
	for (int i = 0; i < adj[s].size(); ++i) {
		if (chk[adj[s][i]] == -1)
			go(adj[s][i], color ^ 1);
		else if (chk[s] == chk[adj[s][i]])
			return 0;
	}
	return 1;
}
bool solve() {
	//TODO
	memset(chk, -1, sizeof(chk));

	int v, e;
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; ++i)
		adj[i].clear();
	for (int i = 0; i < e; ++i) {
		int from, to;
		scanf("%d %d", &from, &to);
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	bool ans = 1;
	for (int i = 1; i <= v; ++i) {
		if (chk[i] == -1)
			ans &= go(i, 0);
		else
			ans &= go(i, chk[i]);
	}
	if (ans) {
		printf("yes");
		return 1;
	}
	else {
		printf("no");
		return 0;
	}
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 9, tmp;
	bool a = 1;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen);
		int e = d2(gen);
		if (cnt <= 3) n = rand() % 5 + 5;
		else if (cnt <= 6)
			n = 1000;
		if (cnt <= 3) {
			e = rand() % 10 + 5;
			e = min(e, 100000);
		}
		else if (cnt == 4)
			e = 100000;
		else
			e = min(e, 100000);
		printf("%d %d\n", n, e);
		uniform_int_distribution<int> d3(1, n);
		map<int, int> check;
		if (cnt % 2 == 0) {
			while (e--) {
				int n1 = d3(gen);
				int n2 = d3(gen);
				if (n1 == n2 || check[n1 * 10000 + n2]) {
					++e;
					continue;
				}
				check[n1 * 10000 + n2] = 1;
				printf("%d %d\n", n1, n2);
			}
		}
		else {
			vector<int> s[2];
			for (int i = 1; i <= n; ++i)
				s[rand() % 2].push_back(i);
			if (s[0].empty()) {
				s[0].push_back(s[1].back());
				s[1].pop_back();
			}
			else if (s[1].empty()) {
				s[1].push_back(s[0].back());
				s[0].pop_back();
			}
			uniform_int_distribution<int> sRand1(0, s[0].size() - 1);
			uniform_int_distribution<int> sRand2(0, s[1].size() - 1);
			while (e--) {
				int n1 = s[0][sRand1(gen)];
				int n2 = s[1][sRand2(gen)];
				if (check[n1 * 10000 + n2]) {
					++e;
					continue;
				}
				check[n1 * 10000 + n2] = 1;
				printf("%d %d\n", n1, n2);
			}
		}
		check.clear();
		fclose(fp);


		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 10) break;
	}
}