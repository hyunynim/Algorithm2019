#include<cstdio>

typedef long long ll;
int main(){
	int n;
	int a = 0, b = 0;
	scanf("%d", &n);
	while (n--){
		int q, w;
		scanf("%d %d", &q, &w);
		if (q > w) ++a;
		else if (q < w) ++b;
	}
	printf("%d %d", a, b);
}
