#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int num[20000];
bool check[20000];
void dfs(vector<vector<int>> &a, int x, vector<int> &s) {
	if (check[x]) {
		return;
	}
	check[x] = true;
	for (int next : a[x]) {
		dfs(a, next, s);
	}
	s.push_back(x);
}
void dfs2(vector<vector<int>> &a, int x, int &cnt) {
	if (check[x]) {
		return;
	}
	check[x] = true;
	num[x] = cnt;
	for (int next : a[x]) {
		dfs2(a, next, cnt);
	}
}
int node(int x, int n) {
	if (x > 0) {
		return x - 1;
	}
	else {
		return 2 * n + x;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(2 * n), ar(2 * n);
	while (m--) {
		int from, to;
		cin >> from >> to;
		a[node(-from, n)].push_back(node(to, n));
		ar[node(to, n)].push_back(node(-from, n));
		a[node(-to, n)].push_back(node(from, n));
		ar[node(from, n)].push_back(node(-to, n));
	}
	vector<int> s;
	for (int i = 0; i < 2 * n; i++) {
		check[i] = false;
	}
	for (int i = 0; i < 2 * n; i++) {
		dfs(a, i, s);
	}
	for (int i = 0; i < 2 * n; i++) {
		check[i] = false;
		num[i] = 0;
	}
	int cnt = 0;
	for (int i = 2 * n - 1; i >= 0; i--) {
		if (check[s[i]] == false) {
			dfs2(ar, s[i], cnt);
			cnt += 1;
		}
	}
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (num[i] == num[2 * n - i - 1]) {
			ok = false;
		}
	}
	printf("%d\n", ok ? 1 : 0);
	if (!ok) return 0;
	for (int i = 0; i < n; i++) {
		if (num[i] < num[2 * n - i - 1])
			printf("0 ");
		else
			printf("1 ");
	}
	puts("");
	return 0;
}