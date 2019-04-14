#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int main() {
	int n, t;
	scanf("%d %d", &n, &t);
	vector<P> seq(n);
	int ans = 1e9, ansI = 0;
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (; a < t; a += b);
		if (ans > a) {
			ans = a;
			ansI = i;
		}
	}
	printf("%d", ansI + 1);
}