#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
        int n; scanf("%d", &n);
        vector<int> seq(n);
        for(int i = 0; i<n; ++i)
                scanf("%d", &seq[i]);
        char msg[1010101];
        getchar();
        fgets(msg, 101010, stdin);
        vector<int> tmp;
        for(int i = 0; msg[i] != '\0'; ++i){
                if('a' <= msg[i] && msg[i] <= 'z')
                        tmp.push_back(msg[i] - 'a' + 27);
                else if('A' <= msg[i] && msg[i] <= 'Z')
                        tmp.push_back(msg[i] - 'A' + 1);
                else if(msg[i] == ' ')
                        tmp.push_back(0);
        }
        sort(seq.begin(), seq.end());
        sort(tmp.begin(), tmp.end());
        if(tmp == seq)
                putchar('y');
        else
                putchar('n');
}
