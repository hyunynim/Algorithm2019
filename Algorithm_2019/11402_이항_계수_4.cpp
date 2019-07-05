#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll comb[2020][2020];
void pre(int m) {
	for (int i = 1; i < 2020; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i)
				comb[i][j] = 1;
			else if (j == 1 || i - j == 1)
				comb[i][j] = i;
			else
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			comb[i][j] %= m;
		}
	}
}
ll solve(vector<int>& s1, vector<int>& s2, int m) {
	int len = max(s1.size(), s2.size());
	ll res = 1;
	for (int i = 0; i < len; ++i) {
		int cur1 = i < s1.size() ? s1[i] : 0;
		int cur2 = i < s2.size() ? s2[i] : 0;
		if (cur1 < cur2) return 0;
		else
			res *= comb[cur1][cur2];
		res %= m;
	}
	return res;
}
int main() {
	ll n, k, m;
	cin >> n >> k >> m;
	pre(m);
	vector<int> seqN;
	vector<int> seqK;
	while (n) {
		seqN.push_back(n % m);
		n /= m;
	}
	while (k) {
		seqK.push_back(k % m);
		k /= m;
	}
	cout << solve(seqN, seqK, m);
}