#include<bits/stdc++.h>
using namespace std;
struct EDGE {
	int to, w;
};
typedef long long ll;
vector<EDGE> adj[101010];
bool chk[101010];
bool operator < (EDGE e1, EDGE e2) {
	return e1.w > e2.w;
}
ll prim(vector<EDGE> & ans, int v) {
	ll wSum = 0;
	priority_queue<EDGE> q;
	chk[1] = 1;
	for (int i = 0; i < adj[1].size(); ++i)
		q.push(adj[1][i]);
	while (q.size()) {
		int cur = q.top().to;
		ll w = q.top().w;
		q.pop();
		if (chk[cur]) continue;
		chk[cur] = 1;
		wSum += w;
		ans.push_back({ cur, w });
		for (int i = 0; i < adj[cur].size(); ++i)
			if (!chk[adj[cur][i].to])
				q.push(adj[cur][i]);
	}
	return wSum;
}