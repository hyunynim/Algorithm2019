#include<bits/stdc++.h>

using namespace std;
struct jew{
        int m, v;
};
int main(){
        multiset<int> bag;
        int n, k; scanf("%d %d", &n, &k);
        vector<jew> seq(n);
        for(int i = 0; i<n; ++i)
                scanf("%d %d", &seq[i].m, &seq[i].v);
        sort(seq.begin(), seq.end(), [](jew a, jew b){
                return a.v > b.v;
        });
        for(int i = 0; i<k; ++i){
                scanf("%d", &n);
                bag.insert(n);
        }

        long long ans = 0;
        for(auto i : seq){
                auto it = bag.lower_bound(i.m);
                if(it != bag.end()){
                        ans += i.v;
                        bag.erase(it);
                }
        }
        printf("%lld", ans);
}
