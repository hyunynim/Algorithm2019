#include<bits/stdc++.h>
using namespace std;
int adj[111][111];
int main(){
  memset(adj, 0x3f, sizeof(adj));
  int n, m; scanf("%d %d", &n, &m);
  for(int i = 0; i<m; ++i){
    int a, b; scanf("%d %d", &a, &b);
    adj[a][b] = adj[b][a] = 1;
  }
  for(int k = 1; k<=n; ++k)
    for(int i = 1; i<=n; ++i)
      for(int j = 1; j<=n; ++j)
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
  int ans = -1;
  for(int i = 1; i<=n; ++i)
    for(int j = 1; j<=n; ++j)
      if(adj[i][j] < 1000 || i != j) ans = max(ans, adj[i][j]);
  if(ans < 7)
    printf("Small World!\n");
  else
    printf("Big World!\n");
}