#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<utility>
#include<map>
using namespace std;
int p10[] = { 1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6 };
int swap(int a, int b, int num) {
	int c = (num / p10[a]) % 10;
	int d = (num / p10[b]) % 10;
	num = num - (c * p10[a]) + (d * p10[a]) - (d * p10[b]) + (c * p10[b]);
	return num;
}
map<pair<int, int>, int> chk;
int main() {
	int t; scanf("%d", &t);
	for (int TC = 1; TC <= t; ++TC) {
		int num, k;
		scanf("%d %d", &num, &k);
		int cnt = 0, tmp = num;
		while (tmp) {
			++cnt;
			tmp /= 10;
		}
		queue<pair<int, int>> q;
		q.push({ num, 0});
		vector<int> ans;
		while (q.size()) {
			int cur = q.front().first;
			int curCnt = q.front().second;
			q.pop();
			if (curCnt == k) {
				ans.push_back(cur);
				continue;
			}
			for (int i = 0; i < cnt; ++i) {
				for (int j = i + 1; j < cnt; ++j) {
					int next = swap(i, j, cur);
					if (chk[{next, curCnt + 1}] != 1) {
						q.push({ next, curCnt + 1 });
						chk[{next, curCnt + 1}] = 1;
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		printf("#%d %d", TC, ans.back());
		puts("");
		ans.clear();
		chk.clear();
	}
}