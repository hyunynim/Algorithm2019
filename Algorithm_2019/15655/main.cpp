#include<bits/stdc++.h>
using namespace std;
/*
int main(){
  int n, m; scanf("%d %d", &n, &m);
  vector<int> seq(n), per;
  for(int i = 0; i<n; ++i){
    scanf("%d", &seq[i]);
    per.push_back(i < m ? 1 : 0);
  }

  sort(seq.begin(), seq.end());

  do{
    for(int i = 0; i<n; ++i)
      if(per[i]) printf("%d ", seq[i]);
    puts("");
  }while(prev_permutation(per.begin(), per.end()));
}
*/
vector<int> seq;
int n, m;
void go(vector<int> & tmp){
  if(tmp.size() == m){
    for(int i = 1; i<m; ++i)
      if(tmp[i - 1] >= tmp[i]) return;
    for(auto i : tmp)
      printf("%d ", i);
    puts("");
    return;
  }
  for(int i = 0; i<n; ++i){
    tmp.push_back(seq[i]);
    go(tmp);
    tmp.pop_back();
  }
}
int main(){
  scanf("%d %d", &n, &m);
  seq.resize(n);
  for(int i = 0; i<n; ++i)
    scanf("%d", &seq[i]);
  sort(seq.begin(), seq.end());
  vector<int> tmp;
  go(tmp);
}