#include<bits/stdc++.h>
using namespace std;
int d[366];
vector<int> seq;
bool go(int cur) {
	if (cur < 0) cur *= -1;
	cur %= 360;
	int& res = d[cur];
	if (res != -1) return res;
	res = 0;
	for (int i = 0; i < seq.size(); ++i) {
		if (go(cur - seq[i])) return res = 1;
		if (go(cur + seq[i])) return res = 1;
	}
	return 0;
}
int main() {
	memset(d, -1, sizeof(d));
	int n, k; scanf("%d %d", &n, &k);
	seq.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		d[seq[i]] = 1;
	}
	for (int i = 0; i < k; ++i) {
		int deg; scanf("%d", &deg);
		if (go(deg))
			puts("YES");
		else
			puts("NO");
	}
}