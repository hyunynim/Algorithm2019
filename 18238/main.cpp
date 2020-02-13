#include<bits/stdc++.h>
using namespace std;
int main(){
  char msg[111]; scanf("%s", msg);
  int ans = 0;
  char cur = 'A';
  for(int i = 0; msg[i]; ++i){
    ans += min(abs(cur - msg[i]), 26 - abs(cur - msg[i]));
 //   printf("%d\n", min(abs(cur - msg[i]), 26 - abs(cur - msg[i])));
    cur = msg[i];
  }
  printf("%d\n", ans);
}