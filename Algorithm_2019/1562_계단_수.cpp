#include<bits/stdc++.h>

using namespace std;
int d[101][11][1 << 10];
const int mod = 1e9;
int main(){
        int n;
        scanf("%d", &n);
        int ans = 0;
        for(int i = 1; i<10; ++i)
                d[1][i][1 << i] = 1;
        for(int i = 2; i<=n; ++i){
                for(int j = 0; j<10; ++j){
                        for(int k = 1023; k>=0; --k){
                                if(j > 0)
                                        d[i][j][k | (1 << j)] += d[i - 1][j - 1][k]; 
                                if(j < 9)
                                        d[i][j][k | (1 << j)] += d[i - 1][j + 1][k];
                                d[i][j][k | (1 << j)] %= mod;
                        }
                }
        }
        for(int i = 0; i<10; ++i){
                ans += d[n][i][1023];
                ans %= mod;
        }
        printf("%d", ans);
}
