#include<bits/stdc++.h>
using namespace std;
int main() {
	printf("%d", -7 % 3);
	int n; scanf("%d", &n);
	vector<int> seq(n);
	int m = 1e9 + 1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		if (seq[i] < 0)
			seq[i] *= -1;
			//m = min(seq[i], m);
	}
	sort(seq.begin(), seq.end());
	printf("%d", min(seq.back() - seq[0], seq[0]));
}