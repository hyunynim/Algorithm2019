#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, s;
	while (~scanf("%d", &n)) {
		int cnt = 0;
		vector<int> seq(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &seq[i]);
		scanf("%d", &s);
		bool stop = 0;
		bool isSort = 1;
		while (1) {
			for (int i = 0; i < n - 1; ++i) {
				if (seq[i] < seq[i + 1]) {
					isSort = 0;
					swap(seq[i], seq[i + 1]);
					++cnt;
					if (cnt == s) {
						stop = 1; break;
					}
				}
			}
			if (stop || isSort) break;
		}
		for (auto i : seq)
			printf("%d ", i);
		puts("");
		seq.clear();
	}
}