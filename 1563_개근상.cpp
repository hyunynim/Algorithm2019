#include<bits/stdc++.h>
using namespace std;
int d[2][1<<2][1010], n;
const int mod = 1e6;
int go(int s, int l, int stat){
        stat %= 4;
        if(s == n) return l < 2;
        if(l == 2) return 0;
        int & res = d[l][stat][s];
        if(res != -1) return res;
        res = 0;
        if(stat % 4 < 3)
                res += go(s + 1, l, (stat << 1) | 1);
        res += go(s + 1, l, (stat << 1)) + go(s + 1, l + 1, (stat << 1));
        res %= mod;
        return res;
}
int main(){
        memset(d, -1, sizeof(d));
        scanf("%d", &n);
        printf("%d", go(0, 0, 0));
}
