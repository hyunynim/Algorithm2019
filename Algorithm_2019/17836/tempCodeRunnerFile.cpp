#include<bits/stdc++.h>
using namespace std;
struct POS{
  int x, y, g;
};
int main(){
  int n, m, t; scanf("%d %d %d", &n, &m, &t);
  int board[101][101];
  for(int i = 0; i<n; ++i)
    for(int j = 0; j<m; ++j)
     scanf("%d", &board[i][j]);
  int chk[2][101][101];
  memset(chk, 0x3f, sizeof(chk));
  chk[0][0][0] = 0;
  queue<POS> q;
  q.push({0, 0, 0});
  int dx[] = {0, 0, -1 , 1};
  int dy[] = {-1, 1, 0, 0};
  while(q.size()){
    int x = q.front().x, y = q.front().y, g = q.front().g;
    q.pop();
    if(x == n - 1 && y == m - 1){
      if(chk[g][x][y] > t) break;
      printf("%d", chk[g][x][y]); return 0;
    }
    for(int i = 0; i<4; ++i){
      int nx = dx[i] + x, ny = dy[i] + y, nd = chk[g][x][y] + 1;
      if(0 <= nx && nx < n && 0 <= ny && ny < m){
        g = (g || board[nx][ny] == 2);
        if(chk[g][nx][ny] > nd && (board[nx][ny] == 0 || g)){
          chk[g][nx][ny] =nd;
          q.push({nx, ny, g});
        }
      }
    }
  }
  printf("Fail");
}