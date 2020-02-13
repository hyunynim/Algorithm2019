#include<bits/stdc++.h>
using namespace std;
int main(){
  char msg[1010];
  while(1){
    fgets(msg ,1000, stdin);
    int a = 0, b = 0;
    bool chk = 0;
    for(int i = 0; msg[i]; ++i){
      if(msg[i] == ' ' || msg[i] == '\n'){
        chk = 1; continue;
      }
      if(chk)
        b = b * 10 + msg[i] - '0';
      else
        a = a * 10 + msg[i] - '0';
    }
    printf("%d\n", a + b);
  }
}