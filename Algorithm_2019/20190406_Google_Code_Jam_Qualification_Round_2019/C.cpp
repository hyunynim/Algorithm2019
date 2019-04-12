#include<bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	bool p[10101] = { 1, 1, 0 };
	vector<int> prime;
	for (int i = 2; i <= 10000; ++i) {
		if (p[i]) continue;
		prime.push_back(i);
		for (int j = i * i; j <= 10000; j += i)
			p[j] = 1;
	}
	for (int TC = 1; TC <= t; ++TC) {
		int n, l;
		scanf("%d %d", &n, &l);
		vector<int> seq(l);
		vector<int> tmp, pfact;
		for (int i = 0; i < l; ++i) {
			scanf("%d", &seq[i]);
			int num = seq[i];
			for (int j = 0; num > 1; ++j) {
				while (num % prime[j] == 0) {
					num /= prime[j];
					tmp.push_back(prime[j]);
					pfact.push_back(prime[j]);
				}
			}
		}
			sort(tmp.begin(), tmp.end());
			tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
			if (tmp.size() < 26) {
				int start = lower_bound(prime.begin(), prime.end(), tmp[0]) - prime.begin();
			}
			string ans = "";
			for (int i = 0; i < pfact.size() - 1; ++i) {
				int idx = lower_bound(tmp.begin(), tmp.end(), pfact[i]) - tmp.begin();
				ans.push_back(idx + 'A');
				if(i){
					if (pfact[i] == pfact[i + 1])
						++i;
					
					else {
						idx = lower_bound(tmp.begin(), tmp.end(), pfact[i + 1]) - tmp.begin();
						ans.push_back(idx + 'A');
						i += 3;
					}
				}
			}
			printf("Case #%d: %s\n", TC, ans.c_str());
			seq.clear(); tmp.clear(); pfact.clear();
	}
}