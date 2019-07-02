#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c2i(char * msg){
        int res = 1000 * (msg[0] - 'A');
        int num = 0;
        for(int i = 2; msg[i] != '\0'; ++i)
                num = num * 10 + msg[i] - '0';
        return res + num;
}
int main(){
        int n; scanf("%d", &n);
        vector<int> seq;
        vector<int> tmp;
        char msg[101];
        for(int i = 0; i<n; ++i){
                for(int j = 0; j<5; ++j){
                        scanf("%s", msg);
                        seq.push_back(c2i(msg));
                        tmp.push_back(seq.back());
                }
        }
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        stack<int> s;
        for(int i = 0; i<n * 5; ++i){
                if(tmp.back() == seq[i])
                        tmp.pop_back();
                else if(s.size() && s.top() == tmp.back()){
                        tmp.pop_back();
                        s.pop();
                        --i;
                }
                else
                        s.push(seq[i]);
        }
        while(s.size()){
                if(s.top() == tmp.back()){
                        s.pop(); tmp.pop_back();
                }
                else{
                        printf("BAD");
                        return 0;
                }
        }
        printf("GOOD");
}
