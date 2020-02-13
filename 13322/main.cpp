#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("test.txt", "r", stdin);
  int n; cin >> n;
  for(int i = 0; i<n; ++i){
    int num; string str;
    cin >> num >> str;
    if(str.size() < 1 || str.size() > 20)
      cout << str;
  }
}