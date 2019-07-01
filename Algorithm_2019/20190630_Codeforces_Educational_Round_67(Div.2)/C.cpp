#include<bits/stdc++.h>
using namespace std;
struct SEQ {
	int t, l, r;
	SEQ() {
		t = l = r = 0;
	}
	SEQ(int a, int b, int c) {
		t = a; l = b; r = c;
	}
};
bool operator != (SEQ s1, SEQ s2) {
	return s1.t != s2.t || s1.l != s2.l || s1.r != s2.r;
}
int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector <SEQ> seq(m);
	for (int i = 0; i < m; ++i) 
		scanf("%d %d %d", &seq[i].t, &seq[i].l, &seq[i].r);
	sort(seq.begin(), seq.end(), [](SEQ s1, SEQ s2) {
		return s1.t == s2.t ? s1.l < s2.l : s1.t > s2.t;
		}
	);
	vector<SEQ> ans;
	SEQ cur = { seq[0].t, seq[0].l, seq[0].r };
	int i = 1;
	for (; i < m && seq[i].t; ++i) {
		cur.t = 1;
		if (seq[i].l <= cur.r)
			cur = { 1, cur.l, max(cur.r, seq[i].r) };
		else {
			ans.push_back(cur);
			cur = { 1, seq[i].l, seq[i].r };
		}
	}
	if (ans.empty() || ans.back() != cur) ans.push_back(cur);
	if (i < m)
		cur = { seq[i].t, seq[i].l, seq[i].r };
	for (; i < m; ++i) {
		cur.t = 0;
		if (seq[i].l <= cur.r)
			cur = { 0, cur.l, max(cur.r, seq[i].r) };
		else {
			ans.push_back(cur);
			cur = { 0, seq[i].l, seq[i].r };
		}

	}
	if (ans.empty() || ans.back() != cur) ans.push_back(cur);
	sort(ans.begin(), ans.end(), [](SEQ s1, SEQ s2) {
		return s1.t == s2.t ? (s1.l == s2.l ? s1.r < s2.r : s1.l < s2.l) : s1.t > s2.t;
		}
	);
	int num = 1e6, c = 1;
	int lim = 1e9;
	vector<int> res(n + 1);
	for (int i = 0; i < ans.size(); ++i) {
		for (; c < ans[i].l; ++c)
			res[c] = 1e8;

		if (ans[i].t) {
			for (; c <= ans[i].r; ++c)
				res[c] = num;
			++num;
		}
		else {
			if (res[ans[i].l] == 0)
				res[ans[i].l] = lim--;
			bool ok= 1;
			for (int j = ans[i].l + 1; j <= ans[i].r; ++j) {
				if (res[j - 1] && res[j] && res[j - 1] < res[j]) {
					swap(res[j - 1], res[j]);
					ok = 0;
				}
				else if (res[j] == 0)
					res[j] = lim--;
			}
			if (ok) {
				printf("NO");
				return 0;
			}
		}
	}
	for (int i = 0; i < ans.size(); ++i) {
		bool chk = 0;
		for (int j = ans[i].l + 1; j <= ans[i].r; ++j) {
			if (ans[i].t) {
				if (res[j - 1] > res[j]) {
					printf("NO");
					return 0;
				}
			}
			else {
				if (res[j - 1] > res[j]) {
					chk = 1; break;
				}
			}
		}
		if (ans[i].t == 0 && chk == 0) {
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 1; i < res.size(); ++i)
		printf("%d ", res[i]);
}