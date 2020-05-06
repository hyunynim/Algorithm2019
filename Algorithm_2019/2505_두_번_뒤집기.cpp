#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	vector<int> s[2], idx[2], ans[2];
	for (int i = 0; i < 2; ++i) {
		s[i].resize(n); idx[i].resize(n + 1);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &s[0][i]);
		s[1][i] = s[0][i];
		idx[0][s[0][i]] = idx[1][s[0][i]] = i;
	}
	for (int i = 0; i < 2; ++i) {
		if (i == 0) {
			for (int j = 0; j < n; ++j) {
				if (j + 1 != s[i][j]) {
					ans[i].push_back(j);
					ans[i].push_back(idx[i][j + 1]);
					break;
				}
			}
		}
		else {
			for (int j = n - 1; j >= 0; --j) {
				if (j + 1 != s[i][j]) {
					ans[i].push_back(j);
					ans[i].push_back(idx[i][j + 1]);
					break;
				}
			}
		}
		if (ans[i].empty())
			ans[i].push_back(0), ans[i].push_back(0);
		if (ans[i][0] > ans[i][1]) swap(ans[i][0], ans[i][1]);
		reverse(s[i].begin() + ans[i][0], s[i].begin() + ans[i][1] + 1);
		for (int j = 0; j < n; ++j)
			idx[i][s[i][j]] = j;

		if (i == 0) {
			for (int j = 0; j < n; ++j) {
				if (j + 1 != s[i][j]) {
					ans[i].push_back(j);
					ans[i].push_back(idx[i][j + 1]);
					break;
				}
			}
		}
		else {
			for (int j = n - 1; j >= 0; --j) {
				if (j + 1 != s[i][j]) {
					ans[i].push_back(j);
					ans[i].push_back(idx[i][j + 1]);
					break;
				}
			}
		}
		if (ans[i].size() == 2)
			ans[i].push_back(0), ans[i].push_back(0);
		if (ans[i][2] > ans[i][3]) swap(ans[i][2], ans[i][3]);
		reverse(s[i].begin() + ans[i][2], s[i].begin() + ans[i][3] + 1);
	}
	bool f1, f2;
	f1 = f2 = 1;
	for (int i = 0; i < n; ++i) {
		f1 &= (s[0][i] == (i + 1));
		f2 &= (s[1][i] == (i + 1));
	}
	if (f2)
		ans[0] = ans[1];
	for (int i = 0; i < 4; ++i) {
		printf("%d ", ans[0][i] + 1);
		if (i == 1)  puts("");
	}
}