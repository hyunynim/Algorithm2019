#include<deque>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());
	deque<int> q;
	for (auto i : seq)
		q.push_back(i);
	int ans = 0;
	int cur = 1;
	while (q.size()) {
		if (q.size() + cur <= q.back()) 
			q.pop_back();
		else {
			while (q.size() && q.front() <= cur)
				q.pop_front();
			++cur;
		}
		++ans;
	}
	printf("%d", ans);
}