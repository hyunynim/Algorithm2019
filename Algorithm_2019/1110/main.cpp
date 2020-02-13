#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; scanf("%d", &n);
  int ans = 0;
  int next = n;
  do{
    int tmp = next;
    int sum = 0;
    while(tmp){
      sum += tmp % 10;
      tmp /= 10;
    }
    next = (next % 10) * 10 + sum % 10;
    ++ans;
  }while(n != next);
  printf("%d", ans);
}