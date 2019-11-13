#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int x, y; scanf("%d %d", &x, &y);
		if (x >= y) {
			puts("YES");
			continue;
		}
		unordered_map<ll, int> chk;
		ll cur = x;
		bool ans = 0;
		do {
			chk[cur] = 1;
			if (cur >= y) {
				ans = 1;
				break;
			}
			if (cur % 2)
				--cur;
			cur >>= 1;
			cur *= 3;
		} while (chk.count(cur) == 0 && cur != 1);
		if (ans)
			puts("YES");
		else
			puts("NO");
	}
}