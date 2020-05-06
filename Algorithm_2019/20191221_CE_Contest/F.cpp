#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> seq;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b; char msg[10];
		scanf("%d %d %s", &a, &b, msg);
		if (b == 0) {
			seq.push_back({ a, a * 0.9 });
		}
		else{
			seq.push_back({ ((100 - b) * 0.01) * a, a * 0.9 });
			a *= ((100 - b) * 0.01);
		}

		if (msg[0] == 'Y') 
			seq.push_back({ 2 * a, seq.back().second * 3 });	
	}
	sort(seq.begin(), seq.end());
	seq.erase(unique(seq.begin(), seq.end()), seq.end());
	reverse(seq.begin(), seq.end());
	int ans = 0;
	for (int i = 0; i < seq.size(); ++i) {
		ans += seq[i].second * (n / seq[i].first);
		n %= seq[i].first;
	}
	printf("%d", ans);
}