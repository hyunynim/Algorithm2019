#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll song[101];
int main(){
    int n, e; scanf("%d %d", &n, &e);
    int cur = 0;
    for(int i = 0; i<e; ++i){
        int k; scanf("%d", &k);
        bool chk = 0;
        vector<int> camp;
        for(int j = 0; j<k; ++j){
            int a; scanf("%d", &a);
            if(a == 1) chk = 1;
            camp.push_back(a);
        }
        if(chk){
            for(int j = 0; j<camp.size(); ++j)
                song[camp[j]] |= (1LL << cur);
            ++cur;
        }
        else{
            for(int j = 0; j<camp.size(); ++j){
                if(j == 0)
                    for(int k = 1; k<camp.size(); ++k)
                        song[camp[j]] |= song[camp[k]];
                else
                    song[camp[j]] = song[camp[0]];
            }
        }
    }
    puts("1");
    for(int i = 2; i<=n; ++i)
        if((song[1] ^ song[i]) == 0)
            printf("%d\n", i);
}