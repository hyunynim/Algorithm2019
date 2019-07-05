#include<bits/stdc++.h>
using namespace std;
int main(){
        int n, m; scanf("%d %d", &n, &m);
        int ans = n;
        while(n){
                ans += n / m;
                n /= m;
        }
        printf("%d", ans);
}
