#include<bits/stdc++.h>
using namespace std;
bool chk[10101] = {1, 0};
int check(int n){
  int res = n;
  while(n){
    res += n % 10;
    n /= 10;
  }
  return res;
}
void solve(){
  for(int i = 1; i<=10000; ++i){
    bool ok = 1;
    for(int j = 1; j<=20000; ++j){
      if(check(j) == i){
        ok = 0; break;
      }
    }
    if(ok)
      printf("%d\n", i);
  }
}
int main(){
  for(int i = 1; i<=10000; ++i)
    if(check(i) == 12)
      printf("%d\n", i);
  return 0;
  for(int i = 1; i<= 10000; ++i){
    if(!chk[i]){
      printf("%d\n", i);
      for(int j = i; j <= 10000;){
        int sum = j;
        int tmp = j;
        while(tmp){
          sum += tmp % 10;
          tmp /= 10;
        }
        chk[sum] = 1;
        j = sum;
      }
    }
  }
}