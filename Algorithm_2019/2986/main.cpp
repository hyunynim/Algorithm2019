#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; scanf("%d", &n);
  if(n <= 2) printf("%d", n - 1);
  else{
    int ans = 0;
    for(int i = 2; i * i <= n; ++i){
      if(n % i == 0){
        ans = i; break;
      }
    }
    if(ans)
      printf("%d", n - (n / ans));
    else
      printf("%d", n - 1);
    
  }
}