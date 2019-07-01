#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> s1(n);
		vector<int> s2(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &s1[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &s2[i]);

		vector<int> lis[2];
		for (int j = 0; j < 2; ++j) {
			lis[j].push_back(j ? s2[0] : s1[0]);
			for (int i = 1; i < n; ++i) {
				auto it = lower_bound(lis[j].begin(), lis[j].end(), j ? s2[i] : s1[i]);
				if (it == lis[j].end())
					lis[j].push_back(j ? s2[i] : s1[i]);
				else
					*it = j ? s2[i] : s1[i];
			}
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if (s1 != s2 || lis[0].size() > lis[1].size()) 
			puts("NO");
		else
			puts("YES");
	}
}