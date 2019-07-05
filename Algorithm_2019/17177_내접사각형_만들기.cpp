#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
        ll a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
        double tmp = (a * a - b * b) * (a * a - c * c);
        int k = (int)sqrt(tmp);
        if(k * k != tmp || k - b*c <= 0 || (k - b*c) % a){
                printf("-1");
                return 0;
        }
        printf("%lld", (k - b*c) / a);
}
