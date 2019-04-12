#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) 
		scanf("%d", &seq[i]);
	
	int l = 0, r = n - 1;
	while (l < r) {
		if (seq[l] != seq[r]) ans = max(ans, r - l);
		--r;
	}
	l = 0; r = n - 1;
	while (l < r) {
		if (seq[l] != seq[r]) ans = max(ans, r - l);
		++l;
	}
	printf("%d", ans);
}