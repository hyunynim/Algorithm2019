#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1010101];
int d[1010101][2];
const int inf = 1234567890;
bool chk[1010101];
int go(int s, int inc) {
	int & res = d[s][inc];
	if (res != -1) return res;
	res = inc;
	chk[s] = 1;
	for (int i = 0; i < adj[s].size(); ++i) {
		int next = adj[s][i];
		if (!chk[next]) {
			if (inc)
				res += min(go(next, 0), go(next, 1));
			else
				res += go(next, 1);
		}
	}
	chk[s] = 0;
	return res;
}
int main() {
	memset(d, -1, sizeof(d));
	int n;
	scanf("%d", &n);
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	printf("%d", min(go(1, 0), go(1, 1)));
}
