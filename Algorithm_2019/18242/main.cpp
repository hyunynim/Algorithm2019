#include<bits/stdc++.h>
using namespace std;
char msg[1010];
int cnt[2][1010];
int main(){
  int n, m; scanf("%d %d", &n, &m);
  int top = 1e9, bot = -1, left = 1e9, right = -1;
  for(int i = 0; i<n; ++i){
    scanf("%s", msg);
    for(int j = 0; j<m; ++j){
      if(msg[j] == '#'){
        top = min(top, i);
        bot = max(bot, i);
        left = min(left, j);
        right = max(right, j);
        ++cnt[0][i];
        ++cnt[1][j];
      }
    }
  }
  if(cnt[0][top] == cnt[0][bot])
    printf("%s\n", cnt[1][left] > cnt[1][right] ? "RIGHT" : "LEFT");

  else
    printf("%s\n", cnt[0][top] > cnt[0][bot] ? "DOWN" : "UP");
}