#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll adjMat[8][8] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
};
vector<int> adj[8];
int d[8][101010];
int main(){
        for(int i = 0; i<8; ++i)
                for(int j = 0; j<8; ++j)
                        if(adjMat[i][j]) adj[i].push_back(j);
        int t; scanf("%d", &t);
        d[0][0] = 1;
        for(int i = 1; i<=t; ++i){
                for(int j = 0; j<8; ++j){
                        for(int k = 0; k<adj[j].size(); ++k){
                                d[j][i] += d[adj[j][k]][i -1];
                                d[j][i] %= mod;
                        }
                }
        }
        printf("%d", d[0][t]);
}
