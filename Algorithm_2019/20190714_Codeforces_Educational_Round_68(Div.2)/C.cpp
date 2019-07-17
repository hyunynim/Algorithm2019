#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		vector<int> cnt[3][26];
		char msg[1010];
		for (int i = 0; i < 3; ++i) {
			scanf("%s", msg);
			for (int j = 0; msg[j] != '\0'; ++j) 
				cnt[i][msg[j] - 'a'].push_back(j);
		}
		bool ans = 0;
		for (int i = 0; i < 26; ++i) {
			int chk[101] = { 0 };
			int count = 0;
			ans = 0;
			for (int j = 0; j < cnt[0][i].size(); ++j) {
				for (int k = 0; k < cnt[1][i].size(); ++k) {
					if (chk[k] == 0 && cnt[0][i][j] > cnt[1][i][k]) {
						chk[k] = 1;
						++count;
					}
				}
				if ((count && cnt[2][i].size() < count)) {
					puts("NO");
					ans = 1;
					break;
				}
			}
			if (ans) {
				break;
			}
		}
		if (!ans) {
				bool chk = 1;
			for (int i = 0; i < 26; ++i) {
				if (cnt[0][i].size() + cnt[2][i].size() < cnt[1][i].size()) {
					puts("NO");
					chk = 0;
					break;
				}
			}
				if (chk)
					puts("YES");
		}
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 26; ++j)
				cnt[i][j].clear();
	}
}