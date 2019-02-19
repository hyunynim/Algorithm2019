#include<cstdio>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
unordered_map<ll, int> chk;
int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	queue<pair<ll, int>> q;
	q.push({ a, 1 });
	chk[a] = 1;
	while (q.size()) {
		ll cur = q.front().first;
		ll dist = q.front().second;
		q.pop();
		if (cur > b) continue;
		if (cur == b) {
			printf("%d", dist); return 0;
		}
		if (chk[cur * 10 + 1] == 0) {
			chk[cur * 10 + 1] = 1;
			q.push({ cur * 10 + 1, dist + 1 });
		}
		if (chk[cur * 2] == 0) {
			chk[cur * 2] = 1;
			q.push({ cur * 2, dist + 1 });
		}
	}
	printf("-1");
}