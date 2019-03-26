#include<cstdio>
#include<queue>
#include<algorithm>
#include<set>
#include<utility>
#include<tuple>
using namespace std;
set<int> f;
typedef pair<int, int> P;

int chk[505050];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	priority_queue<P> q;
	chk[n] = 1;
	q.push({ 0, n });
	int off = 1, d = 0;
	while (q.size()) {
		while (q.size() && q.top().first == d) {
			int x = q.top().second; q.pop();
			if (x == k) {
				printf("%d", -d); return 0;
			}
			int next[] = { x - 1, x + 1, x * 2 };
			for (int i = 0; i < 3; ++i) {
				if (0 <= next[i] && next[i] <= 500000 && chk[next[i]] == 0) {
					chk[next[i]] = -(d - 1);
					q.push({ d - 1, next[i] });
				}
			}
		}
		k += (off++);
		if (k > 500000) break;
		if (chk[k]) {

		}
		--d;
	}
	printf("-1");
}