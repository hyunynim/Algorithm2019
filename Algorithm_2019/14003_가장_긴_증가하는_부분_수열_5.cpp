#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	vector<int> seq(n), lis;
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	stack<pair<int, int>> s;
	lis.push_back(seq[0]);
	s.push({ 0, seq[0] });
	for (int i = 1; i < n; ++i) {
		auto it = lower_bound(lis.begin(), lis.end(), seq[i]);
		if (it == lis.end()) {
			lis.push_back(seq[i]);
			s.push({ lis.size() - 1, seq[i] });
		}
		else {
			*it = seq[i];
			s.push({ it - lis.begin(), seq[i] });
		}
	}
	printf("%d\n", lis.size());
	vector<int> ans;

	int cur = lis.size() - 1;
	while (s.size()) {
		if (s.top().first == cur) {
			--cur;
			ans.push_back(s.top().second);
		}
		s.pop();
	}
	for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
		printf("%d ", *it);
	}
}