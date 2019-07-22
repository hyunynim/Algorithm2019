#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool prime[1010101] = { 1, 1 };
vector<int> adj[1010];
map<pair<int, int>, int> chk;
int main() {
	for (int i = 2; i * i <= 1010100; ++i) {
		if (prime[i]) continue;
		for (int j = i * i; j < 1010101; j += i)
			prime[j] = 1;
	}
	vector<int> p;
	for (int i = 0; i < 1010101; ++i) 
		if (!prime[i])p.push_back(i);
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		adj[i].push_back(i + 1 <= n ? i + 1 : 1);
		adj[i + 1 <= n ? i + 1 : 1].push_back(i);
	}
	int w = *lower_bound(p.begin(), p.end(), n);
	int cnt = w - n;
		for (int i = 1; i <= n; ++i) {
			if (cnt == 0) break;
			if (adj[i].size() == 2) {
				for (int j = i + 2; j <= n; ++j) {
					if (adj[j].size() == 2) {
						adj[i].push_back(j);
						adj[j].push_back(i);
						--cnt;
						break;
					}
				}
			}
		}
	printf("%d\n", *lower_bound(p.begin(), p.end(), n));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < adj[i].size(); ++j) {
			int x = i, y = adj[i][j];
			if (x > y) swap(x, y);
			if (chk[{x, y}] == 0) {
				printf("%d %d\n", x, y);
				chk[{x, y}] = 1;
			}
		}
	}
}