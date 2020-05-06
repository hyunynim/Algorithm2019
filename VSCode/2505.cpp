#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d", &n);
    vector<int> seq(n);
    vector<int> ans;
    bool flag = 0;
    for(int i = 0; i<n; ++i){
        scanf("%d", &seq[i]);
        if(i && seq[i - 1] > seq[i])
            flag = 1;
        else if(flag && seq[i - 1] < seq[i]){
            ans.push_back(i - 1);
            ans.push_back(seq[i - 1] - 1);
        }
    }
    if(ans[0] > ans[1]) swap(ans[0], ans[1]);
    reverse(seq.begin() + ans[0], seq.end() + ans[1] + 1);
    flag = 0;
    for(int i = 1; i<n; ++i){
        if(seq[i - 1] > seq[i])
            flag = 1;
        else if(flag && seq[i - 1] < seq[i]){
            ans.push_back(i - 1);
            ans.push_back(seq[i - 1] - 1);
        }
    }
    if(ans[2] > ans[3]) swap(ans[2], ans[3]);
    reverse(seq.begin() + ans[2], seq.end() + ans[3] + 1);
    printf("%d %d\n%d %d", ans[0], ans[1], ans[2], ans[3]);
}