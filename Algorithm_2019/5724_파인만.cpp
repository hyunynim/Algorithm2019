#include<cstdio>

typedef long long ll;
int main(){
	while (1){
		ll num;
		scanf("%lld", &num);
		if (num == 0) return 0;
		printf("%lld\n", (num * (num + 1) * (2 * num + 1)) / 6);
	}
}
