#include<bits/stdc++.h>
using namespace std;
vector<int> suf(string s) {
	int len;
	len = s.size();
	vector<int> sufarr(len);
	vector<int> g(len + 1);
	for (int i = 0; i < len; ++i) {
		g[i] = s[i];
		sufarr[i] = i;
	}
	g[len] = -1;

	for (int i = 1; i / 2 < len; i *= 2) {
		auto cmp = [&](int u, int v) {
			if (g[u] == g[v])
				return g[u + i] < g[v + i];
			else
				return g[u] < g[v];
		};
		sort(sufarr.begin(), sufarr.end(), cmp);
		vector<int> g2(len + 1);
		g2[sufarr[0]] = 0;
		g2[len] = -1;
		for (int j = 1; j < len; ++j) {
			if (cmp(sufarr[j - 1], sufarr[j]))
				g2[sufarr[j]] = g2[sufarr[j - 1]] + 1;
			else
				g2[sufarr[j]] = g2[sufarr[j - 1]];
		}
		g = g2;
	}
	return sufarr;
}
int main() {
	int t; scanf("%d", &t);
	string str;
	vector<int> pi;
	while (t--) {
		str.clear();
		pi.clear();
		int a, b; scanf("%d %d", &a, &b);
		bool zero = 0;
		printf("%d.", a / b);
		while (str.size() < 1024) {
			a %= b;
			if (a % b == 0) {
				zero = 1;
				for (int i = 0; i < str.size(); ++i)
					printf("%d", str[i]);
				printf("(0)\n");
				break;
			}
			a *= 10;
			str.push_back(a / b);
		}
		if (zero) continue;
		reverse(str.begin(), str.end());
		pi = suf(str);
		int len = 0;
		for (int i = 1; i < pi.size() - 1; ++i) {
			if (abs(pi[i] - pi[i - 1]) == abs(pi[i + 1] - pi[i])) {
				len = abs(pi[i] - pi[i - 1]);
				break;
			}
		}
		reverse(str.begin(), str.end());
		for (int i = 0; i < str.size() - len; ++i) {
			if (str[i] == str[i + len]) {
				putchar('(');
				int k = i + len;
				while (i < k)
					printf("%d", str[i++]);
				printf(")\n");
				break;
			}
			else
				printf("%d", str[i]);
		}
		pi.clear();
	}
}