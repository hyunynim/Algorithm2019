#include<bits/stdc++.h>
using namespace std;
int main(){
        int n, m; scanf("%d %d", &n, &m);
        vector<int> seq(m);
        for(int i = 0; i<m; ++i)
                scanf("%d", &seq[i]);

        int sum = 0;
        for(int i = 1; i<=n; ++i){
                for(int j = 0; j<m; ++j){
                        if(i % seq[j] == 0){
                                sum += i;
                                break;
                        }
                }
        }
        printf("%d", sum);
}
