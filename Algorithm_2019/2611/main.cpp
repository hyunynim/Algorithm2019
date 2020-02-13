#include<bits/stdc++.h>
using namespace std;
struct EDGE{
  int to, w;
};
int chk[2][1010];
vector<EDGE> adj[1010];
void print(int s, int f){
  if(s == 1 && f){
    printf("1\n");
    return;
  }
  printf("%d ", s);
  print(chk[1][s], 1);
}
int go(int s, int f){
  if(s == 1 && f) return 0;
  int & res = chk[0][s];
  if(res) return res;
  for(int i = 0; i<adj[s].size(); ++i){
    int nx = adj[s][i].to;
    int next = go(nx, 1) + adj[s][i].w;
    if(res < next){
      res = next;
      chk[1][s] = nx;
    }
  }
  return res;
}
int main(){
  int n, m; scanf("%d %d", &n, &m);
  for(int i = 0; i<m; ++i){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    adj[a].push_back({b, c});
  }
  printf("%d\n", go(1, 0));
  print(1, 0);
}