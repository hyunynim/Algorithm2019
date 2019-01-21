#include<bits/stdc++.h>

using namespace std;

double d[1<<20];
double per[20][20];
int n, num;
double go(int mask, int s){
        if(s == n) return 1.0;
        double & res = d[mask];
        if(res >= 0.0) return res;
        res = 0.0;
        for(int i = 0; i<n; ++i){
                if(mask & (1 << i)) continue;
                res = max(res, go(mask | (1 << i), s + 1) * per[s][i]);
        }
        return res; 
}
int main(){
        for(int i = (1 << 20) - 1; i>=0; --i) d[i] = -123.0;
        scanf("%d", &n);
        for(int i = 0; i<n; ++i){
                for(int j = 0; j<n; ++j){
                        scanf("%d", &num);
                        per[i][j] = (double)num / 100.0;
                }
        }

        printf("%.6lf", go(0, 0) * 100.0);
}
