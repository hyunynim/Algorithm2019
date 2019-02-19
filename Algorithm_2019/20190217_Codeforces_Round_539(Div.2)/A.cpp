#include<cstdio>
#include<string.h>
#include<algorithm>
#include<utility>
#include<functional>
#include<map>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int main() {
	int n, v;
	scanf("%d %d", &n, &v);
	if (n <= v + 1) {
		printf("%d", n - 1);
		return 0;
	}
	int cur = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (n - i >= v) {
			ans += i * (v - cur);
			cur = v;
		}
		--cur;
	}
	printf("%d", ans);
}