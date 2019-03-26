#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct SCORE {
	int con, stu, score;
};
int cnt[1010];
int main() {
	int n;
	scanf("%d", &n);
	vector<SCORE> seq(n);
	for (int i = 0; i < n; ++i) 
		scanf("%d %d %d", &seq[i].con, &seq[i].stu, &seq[i].score);
	sort(seq.begin(), seq.end(), [](SCORE a, SCORE b) {
		return a.score > b.score;
	});
	int ans = 0;
	for (auto i : seq) {
		if (cnt[i.con] < 2) {
			++cnt[i.con];
			printf("%d %d\n", i.con, i.stu);
			++ans;
		}
		if (ans == 3) return 0;
	}
}