#include<bits/stdc++.h>
using namespace std;
int main(){
        int t; scanf("%d", &t);
        while(t--){
                int chk[1010101] = {0};
                int a, b; scanf("%d %d", &a, &b);
                printf("%d.", a/b);
                a %= b;
                bool zero = 0;
                string ans = "";
                while(1){
                        a *= 10;
                        //printf("%d %d\n", a, b);
                        if(a % b == 0){
                                printf("%s", ans.c_str());
                                if(a/b)
                                        printf("%d", a / b);
                                printf("(0)\n");
                                break;
                        }
                        else{
                                int idx = chk[a];
                                if(idx){
                                        printf("%s", ans.substr(0, idx - 1).c_str());
                                        printf("(%s)\n", ans.substr(idx - 1).c_str());
                                        break;
                                }
                                else{
                                        chk[a] = ans.size() + 1;
                                        ans.push_back(a / b + '0');
                                        a %= b;
                                }
                        }
                }
        }
}
