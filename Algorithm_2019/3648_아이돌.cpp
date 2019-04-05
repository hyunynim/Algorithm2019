#include<cstdio>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
int num[20000];
bool check[20000];
void dfs(vector<vector<int>> &a, int x, vector<int> &s) {
	if (check[x])
		return;

	check[x] = 1;
	for (int next : a[x])
		dfs(a, next, s);

	s.push_back(x);
}
void dfs2(vector<vector<int>> &a, int x, int &cnt) {
	if (check[x])
		return;

	check[x] = 1;
	num[x] = cnt;
	for (int next : a[x])
		dfs2(a, next, cnt);

}
int node(int x, int n) {
	if (x > 0)
		return x - 1;

	else
		return 2 * n + x;

}
int main() {
	int n, m; 
	while (~scanf("%d %d", &n, &m)) {
		memset(num, 0, sizeof(num));
		memset(check, 0, sizeof(check));
		vector<vector<int>> a(2 * n), ar(2 * n);
		while (m--) {
			int from, to;
			scanf("%d %d", &from, &to);
			a[node(-from, n)].push_back(node(to, n));
			ar[node(to, n)].push_back(node(-from, n));
			a[node(-to, n)].push_back(node(from, n));
			ar[node(from, n)].push_back(node(-to, n));
		}
		vector<int> s;
		for (int i = 0; i < 2 * n; i++)
			check[i] = 0;

		for (int i = 0; i < 2 * n; i++)
			dfs(a, i, s);

		for (int i = 0; i < 2 * n; i++) {
			check[i] = 0;
			num[i] = 0;
		}
		int cnt = 0;
		for (int i = 2 * n - 1; i >= 0; i--) {
			if (check[s[i]] == 0) {
				dfs2(ar, s[i], cnt);
				cnt += 1;
			}
		}
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			if (i == 0 && num[i] < num[2 * n - i - 1]) ok = 0;
			else {
				if (num[i] == num[2 * n - i - 1])
					ok = 0;
			}
		}

		printf("%s\n", ok ? "yes" : "no");
		a.clear(); ar.clear(); s.clear();
	}
	return 0;
}