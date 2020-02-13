#include<bits/stdc++.h>
using namespace std;
void solve(){
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    map<string, int> cnt;
    for(int i = 0; i<n; ++i){
        int num; string str; cin >> num >> str;
        string tmp = "";
        if(num == 1){
            for(int j = 0; j<str.size(); ++j){
                tmp.push_back(str[j]);
                ++cnt[tmp];
            }
        }
        else
            cout << cnt[str] << '\n';
    }
}
int main(){
    srand(time(0));
    freopen("test.txt", "w", stdout);
    printf("10000\n");
    for(int i = 0; i<10000; ++i){
        printf("%d ", rand()%2 + 1);
        for(int j = 0; j<1000; ++j)
            putchar('a');
        puts("");
    }
    freopen("test.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
    solve(); return 0;
}