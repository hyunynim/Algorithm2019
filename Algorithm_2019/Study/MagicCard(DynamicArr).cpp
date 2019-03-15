#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> card(n);
	for (int i = 1; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j))
				card[j].push_back(i);
		}
	}
	for (int i = 0; i < card.size(); ++i) {
		printf("%d : ", i);
		for (int j = 0; j < card[i].size(); ++j)
			printf("%d ", card[i][j]);
		puts("");
	}
	int has;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &has);
		ans |= (has << i);
	}
	printf("니가 고른 수는 %d 이겁니다", ans);
}