#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n, l; scanf("%d %d", &n, &l);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i) scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());

	for (int i = 0; i < n; ++i) {
		if (seq[i] <= l) ++l;
		else {
			printf("%d", l); return 0;
		}
	}
	printf("%d", l);
}