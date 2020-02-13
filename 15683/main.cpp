#include<bits/stdc++.h>
using namespace std;
int board[10][10];
int ans = 1e9, n, m;
struct CAM{
  int num, x, y;
  vector<int> f;
}; //1: 4, 2: 2, 3: 4, 4: 4, 5: 1
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
vector<vector<int>> face = {{0}, {0, 2}, {0, 1}, {0, 1, 2}, {0, 1, 2, 3}};
vector<CAM> seq;
void fillIt(CAM s){
  int x = s.x, y = s.y;
  for(int i = 0; i<s.f.size(); ++i){
    int f = s.f[i];
    for(int j = 0; j<8; ++j){
      int nx = dx[f]*j + x, ny = dy[f]*j + y;
      if(0 <= nx && nx < n && 0 <= ny && ny < m){
        if(board[nx][ny] != 6) board[nx][ny] = 7;
        else break;
      }
    } 
  }
}
void go(int s){
  if(s == seq.size()){
    //check
    for(int i = 0; i<seq.size(); ++i)
      fillIt(seq[i]);
    int sum = 0;
    for(int i = 0; i<n; ++i){
      for(int j = 0; j<m; ++j){
        if(board[i][j] == 0)
          ++sum;
        if(board[i][j] == 7)
          board[i][j] = 0;
      }
    }
    ans = min(ans, sum);
    return;
  }
  for(int i = 0; i<4; ++i){
    vector<int> prev = seq[s].f;
    if(seq[s].num != 5){
      for(int j = 0; j<seq[s].f.size(); ++j){
       seq[s].f[j] += i;
       seq[s].f[j] %= 4;
      }
    }
    go(s + 1);
    seq[s].f = prev;
  }
}
int main(){
  scanf("%d %d", &n, &m);
  for(int i = 0; i<n; ++i){
    for(int j = 0; j<m; ++j){
     scanf("%d", &board[i][j]);
     if(board[i][j] && board[i][j] < 6) seq.push_back({board[i][j], i, j, face[board[i][j] - 1]});
    }
  }
  go(0);
  printf("%d\n", ans);
}