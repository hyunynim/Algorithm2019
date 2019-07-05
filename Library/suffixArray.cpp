#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> suf(string s) {
	int len;
	len = s.size();
	vector<int> sufarr(len);
	vector<int> g(len+1);
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