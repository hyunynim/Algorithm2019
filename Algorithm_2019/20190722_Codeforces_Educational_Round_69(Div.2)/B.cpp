#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
int main() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	int m = 0, mi;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		if (m < seq[i]) {
			m = seq[i]; mi = i;
		}
	}
	int l = mi - 1, r = mi + 1, next = m - 1;
	while (0 <= l || r < n) {
		if (0 <= l && seq[l] == next) {
				--next; --l; continue;
		}
		if (r < n && seq[r] == next) {
			--next; ++r; continue;
		}
		else {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}