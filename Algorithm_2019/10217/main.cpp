#include<bits/stdc++.h>
using namespace std;
#define VMAX 101
const int inf = 1e9;
struct EDGE{
	int to, w, c;
};
vector<EDGE> adj[VMAX];
bool operator < (EDGE e1, EDGE e2) {
	return e1.w == e2.w ? e1.c > e2.c : e1.w > e2.w;
}
 int n, m, k; 
int dijkstra(int s){
	vector<int> ans[10101];
  for(int i = 0; i<10101; ++i){
    ans[i].resize(101);
    fill(ans[i].begin(), ans[i].end(), 1e9);
  }
	priority_queue<EDGE> q;
	q.push({s, 0, 0});
	ans[0][s] = 0;
	while(q.size()){
		int cur = q.top().to, w = q.top().w, c = q.top().c;
		q.pop();
		for(int i = 0; i<adj[cur].size(); ++i){	
      int nx = adj[cur][i].to, nw = adj[cur][i].w + w, nc = adj[cur][i].c + c;
			if(ans[nc][nx] > nw && k >= nc){
				ans[nc][nx] = nw;
				q.push({ nx, nw, nc });
			}
		}
	}
  int res = 1e9;
  for(int i = 0; i<10101; ++i)
    res = min(res, ans[i][n]);
  return res;
}
int main(){
  int t; scanf("%d", &t);
  while(t--){
    for(int i = 0; i<101; ++i)
      adj[i].clear();
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i<k; ++i){
      int from, to, w, c;
      scanf("%d %d %d %d", &from, &to, &c, &w);
      adj[from].push_back({to, w, c});
    }
    int ans = dijkstra(1);
    if(ans >= 1e8)
      puts("Poor KCM");
    else
      printf("%d\n", ans);
    
  }
}