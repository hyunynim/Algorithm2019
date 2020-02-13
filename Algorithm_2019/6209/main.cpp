#include<bits/stdc++.h>
using namespace std;
vector<int> seq;
  int d, n, m;
int chk(int mid){
  int cur = 0;
  int res = 0;
  for(int i = 0; i<seq.size() - 1; ++i){
    if(seq[i] - cur >= mid) cur = seq[i];
    else ++res;
  }
  return seq.back() - cur >= mid ? res : 1e9;
}
int main(){
  scanf("%d %d %d", &d, &n, &m);
  seq.resize(n);
  for(int i = 0; i<n; ++i)
    scanf("%d", &seq[i]);
  sort(seq.begin(), seq.end());
  seq.push_back(d);
  int l = 1, r = 1e9;
  int ans = 0;
  while(l <= r){
    int mid = (l + r) >> 1;
    int res = chk(mid);
    if(res > m)
      r = mid - 1;
    else {
      ans = max(ans, mid);
      l = mid + 1;
    }
  }
  printf("%d", ans);
}