#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int chk(vector<int> seq, int k, int mid) {
	int res = 2e9;
	for (int i = 0; i < seq.size(); ++i) {
		if (seq[i] < mid) {
			int tmp = mid - seq[i];
			seq[i] += tmp;
			k -= tmp;
		}
		if (k < 0) return -1;
		res = min(res, seq[i]);
	}
	if (k < 0) return -1;
	return res;
}

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	int l = 1, r = 1e9;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int tmp = chk(seq, k, mid);
		if (tmp == -1)
			r = mid - 1;
		else {
			l = mid + 1;
			ans = max(tmp, ans);
		}
	}
	printf("%d", ans);
}