#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> adj[101010];
int chk[101010];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	chk[1] = 1;
	while (q.size()) {
		int cur = q.front().first; 
		int dist = q.front().second;
		q.pop();
		for (int j = 0; j < adj[cur].size(); ++j) {
			if (chk[adj[cur][j]]) continue;
			else {
				chk[adj[cur][j]] = dist + 1;
				q.push({ adj[cur][j], dist + 1 });
			}
		}
	}
	vector<int> ans(n);
	vector<int> dat;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &ans[i]);
		ans[i] = chk[ans[i]];
		dat.push_back(ans[i]);
	}
	sort(ans.begin(), ans.end());
	if (ans != dat)
		printf("0");
	else
		printf("1");
}