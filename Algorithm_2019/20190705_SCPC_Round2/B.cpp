#include<bits/stdc++.h>
using namespace std;
int d[5050][5050];
int n;
int count(vector<int>& s1, vector<int>& s2) {
	int res = 0;
	for (int i = 0; i < s1.size(); ++i)
		res += (s1[i] == s2[i]);
	return res;
}
int naive(vector<int>& s1, vector<int>& s2) {
	int res = 0;
	for (int i = 0; i < s1.size(); ++i) {
		for (int j = i + 1; j < s1.size(); ++j) {
			reverse(s2.begin() + i, s2.begin() + j + 1);
			res = max(res, count(s1, s2));
			reverse(s2.begin() + i, s2.begin() + j + 1);
		}
	}
	return res;
}
int main() {
	//score: 60
	int t; cin >> t;
	for (int TC = 1; TC <= t; ++TC) {
		memset(d, 0, sizeof(d));
		int ans = 0;
		cin >> n;
		vector<int> s1(n), s2(n);
		int init = 0;
		for (int i = 0; i < n; ++i)
			cin >> s1[i];
		for (int i = 0; i < n; ++i) {
			cin >> s2[i];
			init += s1[i] == s2[i];
		}
		for (int i = 0; i < n; ++i)
			ans = max(ans, d[i][i] = init);
		for (int i = 0; i < n; ++i) {
			for (int j = 1; i - j >= 0 && i + j < n; ++j) {
				d[i - j][i + j] = d[i - j + 1][i + j - 1] + (s1[i - j] == s2[i + j]) + (s1[i + j] == s2[i - j])
					- (s1[i - j] == s2[i - j]) - (s1[i + j] == s2[i + j]);
			}
		}
		cout << "Case #" << TC << '\n';
		cout << max(init, naive(s1, s2)) << '\n';
	}
}