#include<cstdio>
int gcd(int a, int b){
	if (b) return gcd(b, a%b);
	return a;
}
int main(){
	int t; scanf("%d", &t);
	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);
		int ans = 0;
		for (int i = 1; i < n; ++i){
			for (int j = i + 1; j < n; ++j){
				int g = gcd(i * i + j * j + m, i * j);
				if (g == i * j)
					++ans;
			}
		}
		printf("%d\n", ans);
	}
}
