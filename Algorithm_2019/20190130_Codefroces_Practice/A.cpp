#include<cstdio>
#include<algorithm>
#include<tuple>
#include<utility>
#include<functional>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<string.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int l1, l2, r1, r2;
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		printf("%d ", l1);
		for (int j = l2; j <= r2; ++j) {
			if (j == l1) continue;
			printf("%d\n", j);
			break;
		}
	}
}