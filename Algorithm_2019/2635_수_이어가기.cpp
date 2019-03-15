#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> ans;
	ans.push_back(n);
	for (int i = n; i >= n / 2; --i) {
		int cur = i;
		vector<int> tmp;
		tmp.push_back(n);
		tmp.push_back(i);
		while (tmp[tmp.size() - 2] - tmp.back() >= 0) 
			tmp.push_back(tmp[tmp.size() - 2] - tmp.back());
		if (ans.size() < tmp.size())
			ans = tmp;
	}
	printf("%d\n", ans.size());
	for (auto i : ans)
		printf("%d ", i);
}