#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		m = min(m, n - m);
		printf("%d\n", m *(n - m) + 1);
	}
}