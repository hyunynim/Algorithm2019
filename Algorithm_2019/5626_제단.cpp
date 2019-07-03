#include<bits/stdc++.h>
using namespace std;
vector<int> seq;
int d[10101][5050], n;
const int mod = 1e9 + 7;
int main(){
        d[0][0] = 1;
        scanf("%d", &n);
        seq.resize(n);
        for(int i = 0; i<n; ++i)
                scanf("%d", &seq[i]);
        if(seq[0] > 0 || seq.back() > 0){
            printf("0"); return 0;
        }
        for(int i = 1; i<10101; ++i){
                for(int j = 0; j<5050; ++j){
                        if(j > 0 && (seq[i-1] == -1 || seq[i-1] == j-1))
                                d[i][j] += d[i-1][j-1];
                        if(j < 5049 && (seq[i-1] == -1 || seq[i-1] == j+1)){
                                d[i][j] += d[i-1][j+1];
                                d[i][j] %= mod;
                        }
                        if(seq[i-1] == -1 || seq[i-1] == j)
                                d[i][j] += d[i-1][j];
                        d[i][j] %= mod;
                }
        }
        printf("%d", d[n-1][0]);
}
