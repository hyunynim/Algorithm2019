#include<cstdio>

typedef long long ll;
int main(){
	int t; scanf("%d", &t);
	while (t--){
		int n; scanf("%d", &n);
		printf("Pairs for %d: ", n);
		int l = 1, r = n - 1;
		while (l < r){
			if (l != 1) printf(", ");
			printf("%d %d", l, r);
			++l; --r;
		}
		puts("");
	}
}
