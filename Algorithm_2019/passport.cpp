#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	reverse(seq.begin(), seq.end());
	vector<int> lis;
	lis.push_back(seq[0]);
	for (int i = 1; i < n; ++i) {
		auto it = lower_bound(lis.begin(), lis.end(), seq[i]);
		if (it == lis.end())
			lis.push_back(seq[i]);
		else
			*it = seq[i];
	}
	if (lis.size() <= k)
		cout << "YES";
	else
		cout << "NO";
}