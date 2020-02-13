#include<bits/stdc++.h>
using namespace std;
struct POS{
        int x, y;
};
vector<int> adj[101010];
bool chk[101010];
int main(){
        int n, m; scanf("%d %d", &n, &m);
        vector<POS> seq(n);
        for(int i = 0; i<n; ++i)
                scanf("%d %d", &seq[i].x, &seq[i].y);
        int from, to;
        for(int i = 0; i<m; ++i){
                scanf("%d %d", &from, &to);
                adj[from].push_back(to);
                adj[to].push_back(from);
        }
        queue<int> q;
        int ans = 2e9;
        for(int i = 1; i<=n; ++i){
                if(chk[i]) continue;
                q.push(i);
                chk[i] = 1;
                int mx, my, Mx, My;
                mx = Mx = seq[i - 1].x;
                my = My = seq[i - 1].y;
                while(q.size()){
                        int cur = q.front(); q.pop();
                        int x = seq[cur - 1].x, y = seq[cur - 1].y;
                        mx = min(mx, x);
                        my = min(my, y);
                        Mx = max(Mx, x);
                        My = max(My, y);
                        for(int j = 0; j<adj[cur].size(); ++j){
                                if(!chk[adj[cur][j]]){
                                        chk[adj[cur][j]] = 1;
                                        q.push(adj[cur][j]);
                                }
                        }
                }
                ans = min(ans, 2 * (Mx - mx + My - my));
        }
        printf("%d", ans);
}
