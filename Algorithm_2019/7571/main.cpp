#include<bits/stdc++.h>
using namespace std;
struct POS{
  int x, y;
};
int chk(vector<POS> & seq, int x, int y){
  int res = 0;
  for(int i = 0; i<seq.size(); ++i)
    res += (abs(seq[i].x - x) + abs(seq[i].y - y));
  return res;
}
int main(){
  int n, m; scanf("%d %d", &n, &m);
  vector<int> x(m), y(m);
  vector<POS> seq;
  for(int i = 0; i<m; ++i){
    scanf("%d %d", &x[i], &y[i]);
    seq.push_back({x[i], y[i]});
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int xx, yy;
  if(m % 2){
    xx = x[m / 2];
    yy = y[m / 2];
  }
  else{
    xx = (x[m / 2] + x[m / 2 - 1]) / 2;
    yy = (y[m / 2] + y[m / 2 - 1]) / 2;
  }
  int ans = 1e9;
  for(int i = max(0, xx - 1); i <= min(n, xx + 1); ++i)
    for(int j = max(0, yy - 1); j <= min(n, yy + 1); ++j)
      ans = min(chk(seq, i, j), ans);
  printf("%d", ans);
}