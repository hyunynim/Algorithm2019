#include<bits/stdc++.h>

using namespace std;
int d[1010][1010];
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int ans = 0;
	if (s1.size() == s2.size()) {
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] != s2[i]) ++ans;
		}
		printf("%d", ans); return 0;
	}
	if (s1.size() < s2.size()) swap(s1, s2);
	int cnt = 0;
	for (int i = 0; i < s1.size(); ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			if (s1[i] == s2[j])
				d[i + 1][j + 1] = d[i][j] + 1;
			else
				d[i + 1][j + 1] = d[i][j + 1];
			cnt = max(d[i + 1][j + 1], cnt);
		}
	}
	printf("%d", s1.size() - cnt);
}