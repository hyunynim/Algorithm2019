#include<cstdio>
#include<vector>

using namespace std;
bool chk(int n) {
	int cnt = 0;
	while (n) {
		if (n % 10 == 6)
			++cnt;
		if (cnt == 3) return 1;
		if (cnt && n % 10 != 6)
			cnt = 0;
		n /= 10;
	}
	return cnt >= 3;
}
int main() {
	vector<int> ans;
	ans.push_back(666);
	for (int i = 1666; i <= 10000000; ++i) {
		if (chk(i)) {
			ans.push_back(i);
			if (ans.size() == 10000)
				break;
		}
	}
	int n;
	scanf("%d", &n);
	printf("%d", ans[n - 1]);
}