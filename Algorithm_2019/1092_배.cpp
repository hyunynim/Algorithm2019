#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	int m; scanf("%d", &m);
	priority_queue<int> q;
	for (int i = 0; i < m; ++i) {
		int num; scanf("%d", &num);
		q.push(num);
	}
	sort(seq.begin(), seq.end(), greater<int>());
}