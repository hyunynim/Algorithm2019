#include<bits/stdc++.h>
using namespace std;
map<string, int> cnt;
struct COW {
	int num;
	vector<string> seq;
	bool operator < (COW c2) {
		return num < c2.num;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<COW> seq(n);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i].num;
		seq[i].seq.resize(seq[i].num);
		for (int j = 0; j < seq[i].num; ++j) {
			cin >> seq[i].seq[j];
			++cnt[seq[i].seq[j]];
		}
	}
	sort(seq.begin(), seq.end());
	bool zero = 0;
	for (int i = 0; i < n; ++i) {
		if (seq[i].num == 0) zero = 1;
		else {
			bool ans = 1;
			for (int j = 0; j < seq[i].seq.size(); ++j) {
				if (cnt[seq[i].seq[j]] > 1) {
					ans = 0;
					break;
				}
				if (ans) {
					puts("yes");
					return 0;
				}
			}
		}
	}
	puts("no");
}