#include<bits/stdc++.h>

using namespace std;
vector<int> seq;
int n;
int ans = 0;
void go(int toPick, int prev, int s, vector<vector<int>> & picked) {
	if (toPick == 0) {
		int res = 0;
		for (int i = 0; i < 4; ++i) {
			int mul = 1;
			if (picked[i].empty()) {
				res = 0;
				break;
			}
			for (int j = 0; j < picked[i].size(); ++j)
				mul *= picked[i][j];
			res += mul;
		}
		ans = max(ans, res);
	}
	for (int i = prev + 1; i < n; ++i) {
		picked[s].push_back(seq[i]);
		go(toPick - 1, i, s, picked);
		if(s < 3)
			go(toPick - 1, i, s + 1, picked);
		picked[s].pop_back();
	}
}
int main() {scanf("%d", &n);
	seq.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	vector<vector<int>> tmp(4);
	go(n, -1, 0, tmp);
	printf("%d", ans);
}