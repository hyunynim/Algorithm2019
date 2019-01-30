#include<cstdio>
#include<algorithm>
#include<tuple>
#include<utility>
#include<functional>
#include<map>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
void FindDiv(vector<int> & div, int n) {
	div.push_back(1);
	for (int i = 2; i*i <= n; ++i) {
		if (n % i == 0)
			div.push_back(i);
	}
	for (int i = div.size() - 1; i >= 0; --i) {
		if (i == div.size() - 1 && n / div[i] == div.back())
			continue;
		div.push_back(n / div[i]);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			vector<int> div1, div2;
			FindDiv(div1, seq[i]);
			FindDiv(div2, seq[j]);
			vector<int> ans;
			bool hasAns = 0;
			for (int k = 0; k < div1.size(); ++k)
				ans.push_back(div1[k]);
			for (int k = 0; k < div2.size(); ++k)
				ans.push_back(div2[k]);
			sort(ans.begin(), ans.end());
			if (ans.size() == seq.size()) {
				hasAns = 1;
				for (int k = 0; k < ans.size(); ++k) {
					if (ans[k] != seq[k]) {
						hasAns = 0;
						break;
					}
				}
			}
			if (hasAns) {
				printf("%d %d", seq[i], seq[j]);
				return 0;
			}
		}
	}
}