#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<utility>
#include<functional>

using namespace std;
typedef pair<int, int> P;
const int inf = 1e9;
const int V_MAX = 1010;
vector<P> adj[V_MAX];
int v, e, st;

vector<int> dijkstra(int st) {
	bool chk[V_MAX] = { 0 };
	priority_queue<P, vector<P>, greater<P>> q;
	vector<int> ans;
	ans.resize(V_MAX + 1);

	q.push({ 0, st });
	fill(ans.begin(), ans.end(), inf);
	int sz = 1;
	ans[st] = 0;
	while (q.size()) {
		int x = q.top().second;
		int d = q.top().first;
		q.pop();
		if (chk[x])
			continue;
		chk[x] = 1;
		++sz;
		for (auto p : adj[x]) {
			if (p.second + d < ans[p.first]) {
				ans[p.first] = p.second + d;
				q.push({ p.second + d , p.first });
			}
		}
	}
	return ans;
}
int calc(string s1, string s2) {
	int res = 0;
	for (int i = 0; i < s1.size(); ++i)
		res += (s1[i] - s2[i]) * (s1[i] - s2[i]);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;  cin >> n;
	vector<string> seq(n);
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int cost = calc(seq[i], seq[j]);
			adj[i].push_back({ j, cost });
			adj[j].push_back({ i, cost });
		}
	}
	int s, e;
	cin >> s >> e;
	vector<int> ans = dijkstra(s - 1);
	cout << ans[e - 1];
}