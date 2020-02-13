#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string str;
  int jmp = 2;
  while(cin >> str){
    if(str[1] == 'a') return 0;
    string ans = "";
    for(int i = 0; i < str.size(); i += jmp)
      ans += str[i];
    ++jmp;
    cout << ans << '\n';
  }  
}