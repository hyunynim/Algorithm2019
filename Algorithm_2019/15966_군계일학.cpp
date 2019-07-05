#include<bits/stdc++.h>
using namespace std;
vector<int> ind[1010101];
int d[1010101];
int go(int s, int pos) {
	if (ind[s].empty()) return 0;
	auto it = upper_bound(ind[s].begin(), ind[s].end(), pos);
	if (it == ind[s].end()) return 0;
	int & res = d[s];
	if (res != -1) return res;
	res = 0;
	return go(s + 1, *it) + 1;
}
int main() {
	memset(d, -1, sizeof(d));
	int n, num; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		ind[num].push_back(i);
	}
	int ans = 0;
	for (int i = 1; i <= 1000000; ++i)
		ans = max(ans, go(i, -1));
	printf("%d", n - ans);
}