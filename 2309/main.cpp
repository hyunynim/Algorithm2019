#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d", &t);
    for(int TC = 1; TC<=t; ++TC){
        printf("#%d ", TC);
        char msg[1010]; scanf("%s", msg);
        int chk[101] = {0};
        for(int i = 0; msg[i]; ++i){
            int c = msg[i] - '0';
            if(chk[c])
                chk[c] = 0;
            else
                chk[c] = 1;
        }
        int ans = 0;
        for(int i = 0; i<10; ++i)
            ans += chk[i];
        printf("%d\n", ans);
    }
}