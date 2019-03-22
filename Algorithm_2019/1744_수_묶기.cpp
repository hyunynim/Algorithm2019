#include<bits/stdc++.h>

using namespace std;
const int emp = -1e7;
int main(){
        int n; scanf("%d", &n);
        vector<int> po, ne;
        int ans = 0, zero = 0;
        int tmp;
        for(int i = 0; i<n; ++i){
                scanf("%d", &tmp);
                if(tmp > 1)
                        po.push_back(tmp);
                else if(tmp < 0)
                        ne.push_back(tmp);
                else if(tmp == 0)
                        ++zero;
                else
                        ++ans;
        }
        sort(po.begin(), po.end());
        sort(ne.begin(), ne.end());
        reverse(po.begin(), po.end());

        if(po.size() % 2)
                po.push_back(1);
        if(ne.size() % 2)
                ne.push_back(zero ? 0 : 1);

        for(int i = 0; i<po.size(); ++i)
                if(i % 2)
                        ans += po[i] * po[i-1];
        for(int i = 0; i<ne.size(); ++i)
                if(i % 2)
                        ans += ne[i] * ne[i-1];
        printf("%d", ans);
}
