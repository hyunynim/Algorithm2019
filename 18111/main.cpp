#include<bits/stdc++.h>
using namespace std;
int board[505][505];
  int n, m, b;
int chk(int b, int mid){
  int inv = b;
  int res = 0;
  for(int i = 0; i<n; ++i){
    for(int j = 0; j<m; ++j){
      if(board[i][j] > mid){
        res += (board[i][j] - mid) * 2;
        inv += (board[i][j] - mid);
      }
      if(board[i][j] < mid){
        res += (mid - board[i][j]);
        inv -= (mid - board[i][j]);
      }
    }
  }
  return (inv >= 0 ? res : -1);
}
int main(){ 
  scanf("%d %d %d", &n, &m, &b);
  int sum = 0;
  for(int i = 0; i<n; ++i){
    for(int j = 0; j<m; ++j){
      scanf("%d", &board[i][j]);
      sum += board[i][j];
    }
  }
  if(n == 0 || m == 0){
    printf("0 0");
    return 0;
  }
  int ans = 1e9, ansH = 0;
  for(int i = 0; i<256; ++i){
    int res = chk(b, i);
    if(~res){
      if(ans > res){
        ans = res;
        ansH = i;
      }
      else if(ans == res)
        ansH = max(i, ansH);
    }
    if(sum + b < i * n * m)
      break;
  }
  printf("%d %d", ans, ansH);
}