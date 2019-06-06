#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
        ll t; scanf("%lld", &t);
        int n; scanf("%d", &n);
        vector<ll> s1(n + 1), sum1(n + 1);
        for(int i = 1; i<=n; ++i){
                scanf("%lld", &s1[i]);
                sum1[i] = sum1[i - 1] + s1[i];
        }
        int m; scanf("%d", &m);
        vector<ll> s2(m + 1), sum2(m + 1);
        for(int i = 1; i<=m; ++i){
                scanf("%lld", &s2[i]);
                sum2[i] = sum2[i - 1] + s2[i];
        }
        vector<ll> seq1, seq2;
        for(int i = 1; i<=n; ++i)
                for(int j = i; j<=n; ++j)
                        seq1.push_back(sum1[j] - sum1[i - 1]);
        for(int i = 1; i<=m; ++i)
                for(int j = i; j<=m; ++j)
                        seq2.push_back(sum2[j] - sum2[i - 1]);
        sort(seq1.begin(), seq1.end());
        sort(seq2.begin(), seq2.end());
        auto l = seq1.begin();
        auto r = seq2.rbegin();
        ll ans = 0;
        while(l != seq1.end() && r != seq2.rend()){
                ll sum = *l + *r;
                if(sum == t){
                        ll c1 = upper_bound(seq1.begin(), seq1.end(), *l) - lower_bound(seq1.begin(), seq1.end(), *l);
                        ll c2 = upper_bound(seq2.begin(), seq2.end(), *r) - lower_bound(seq2.begin(), seq2.end(), *r);
                        ans += c1 * c2;
                        l += c1;
                        r += c2;
                }
                else if(sum < t)
                        ++l;
                else
                        ++r;
        }
        printf("%lld", ans);
}
