#include<bits/stdc++.h>
using namespace std;
bool change[55];
int main() {
	int n, k; scanf("%d", &n);
	char msg[101];
	vector<vector<int>> seq(n);
	vector<int> cnt[36];
	for (int i = 0; i < 36; ++i) cnt[i].resize(100);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		for (int j = 0; msg[j] != '\0'; ++j) {
			int num = msg[j];
			if ('A' <= msg[j] && msg[j] <= 'Z')
				num = msg[j] - 'A' + 10;
			else
				num -= '0';
			seq[i].push_back(num);
		}
		reverse(seq[i].begin(), seq[i].end());
		for (int j = 0; j < seq[i].size(); ++j)
			cnt[seq[i][j]][j] += (35 - seq[i][j]);
	}
	scanf("%d", &k);

	for (int i = 0; i < 36; ++i) {
		int carry = 0;
		for (int j = 0; j < cnt[i].size(); ++j) {
			cnt[i][j] += carry;
			carry = cnt[i][j] / 36;
			cnt[i][j] %= 36;
		}
		reverse(cnt[i].begin(), cnt[i].end());
		cnt[i].push_back(i);
	}

	sort(cnt, cnt + 36, [](vector<int>& s1, vector<int>& s2) {
		for (int i = 0; i < 100; ++i) {
			if (s1[i] == s2[i]) continue;
			return s1[i] > s2[i];
		}
		return s1.back() < s2.back();
		});
	for (int i = 0; i < 36 && k; ++i) {
		change[cnt[i].back()] = 1;
		--k;
	}
	vector<int> ans;
	int carry = 0;
	for (int j = 0; j < 100; ++j) {
		int sum = carry;
		for (int i = 0; i < n; ++i) {
			if (j < seq[i].size())
				sum += change[seq[i][j]] ? 35 : seq[i][j];
		}
		ans.push_back(sum % 36);
		carry = sum / 36;
	}
	while (ans.size() > 1 && ans.back() == 0)
		ans.pop_back();
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		if (ans[i] > 9)
			putchar('A' + ans[i] - 10);
		else
			printf("%d", ans[i]);
	}
}