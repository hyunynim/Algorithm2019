#include<bits/stdc++.h>
using namespace std;
vector<int> song[101];
int main(){
  int n, e; scanf("%d %d", &n, &e);
  int cur = 1;
  for(int i = 0; i<e; ++i){
    int k; scanf("%d", &k);
    bool chk = 0;
    vector<int> tmp;
    for(int j = 0; j<k; ++j){
      int a; scanf("%d", &a);
      if(a == 1) chk = 1;
      tmp.push_back(a);
    }
    if(chk){
      for(int j = 0; j<tmp.size(); ++j)
        song[tmp[j]].push_back(cur);
      ++cur;
    }
    else{
      vector<int> song2;
      for(int j = 0; j<tmp.size(); ++j){
        for(int k = 0; k<song[tmp[j]].size(); ++k)
          song2.push_back(song[tmp[j]][k]);
      }
      sort(song2.begin(), song2.end());
      song2.erase(unique(song2.begin(), song2.end()), song2.end());
      for(int j = 0; j<tmp.size(); ++j)
        song[tmp[j]] = song2;
    }
    tmp.clear();
  }
  vector<int> ans;
  ans.push_back(1);
  for(int i = 2; i<=n; ++i)
    if(song[i].size() == song[1].size()) ans.push_back(i);
  for(auto i : ans)
    printf("%d\n", i);
}