#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; 
ll d[6][10][111];
const ll mod = 1e9 + 7;
ll go(int s, int cur, int cnt){
  if(s == n - 1) return 1;
  ll & res = d[cnt][cur][s];
  if(~res) return res;
  res = 0;
  if(cur - 1 >= 0 && (cnt > 2 || (cnt <= 2 && cnt - 1 >= 0))) res += go(s + 1, cur - 1, cnt <= 2 ? cnt - 1 : 1);
  if(cur + 1 < 10 && (cnt < 2 || (cnt >= 2 && cnt + 1 < 5))) res += go(s + 1, cur + 1, cnt >= 2 ? cnt + 1 : 3);
  res %= mod;
  return res;
}
int main(){
  memset(d, -1 ,sizeof(d));
  scanf("%d", &n);
  ll ans = 0;
  for(int i = 0; i<10; ++i){
    ans += go(0, i, 2);
    ans %= mod;
  }
  printf("%lld", ans);
}