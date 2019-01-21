#include<bits/stdc++.h>

using namespace std;

int cost[17][17];
int d[1<<17];
int n, must, on;
const int inf = 1234567890;
int go(int mask, int cnt){
        if(cnt >= must)
                return 0;
        
        int & res = d[mask];    
        if(res != -1) return res;
        res = inf;
        for(int i = 0; i<n; ++i){
                if(mask & (1 << i)){
                        for(int j = 0; j<n; ++j){
                                if(mask & (1 << j)) continue;
                                res = min(res, go(mask | (1 << j), cnt + 1) + cost[i][j]);      
                        }
                }
        }
        return res;
}

int main(){
        memset(d, -1, sizeof(d));
        scanf("%d", &n);
        for(int i = 0; i<n; ++i)
                for(int j = 0; j<n; ++j)
                        scanf("%d", &cost[i][j]);       
        char msg[123];
        scanf("%s", msg);
        int oncnt = 0;
        for(int i = 0; i<n; ++i){
                if(msg[i] == 'Y'){
                        on |= (1 << i);
                        ++oncnt;
                }
        }
        scanf("%d", &must);
        if(must <= oncnt){
                printf("0");
                return 0;
        }
        int ans = inf;
        for(int i = 0; i<n; ++i)
                if(on & (1 << i))
                        ans = min(ans, go(on, oncnt));

        printf("%d", ans == 1234567890 ? -1 : ans);
}
