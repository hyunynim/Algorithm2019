#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 1000000);

int solve() {
	//TODO
	int n, e = 0; scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		e = max(seq[i], e);
	}
	sort(seq.begin(), seq.end());
	reverse(seq.begin(), seq.end());
	int ans = 0, cur = 0;
	while (seq.size()) {
		if (cur <= seq.back()) {
			++cur;
			++ans;
		}
		seq.pop_back();
	}
	printf("%d", ans);
	return ans;
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 1, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen);
		if (cnt <= 3) n = rand() % 5 + 5;
		else if (cnt <= 6) n = 1000000;
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) {
			if (cnt == 6)
				printf("%d ", 1);
			else
				printf("%d ", cnt <= 3 ? rand() % 10 + 1 : d1(gen));
		}
		fclose(fp);


		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		if(n == solve()) --cnt;
		if (cnt > 3) break;
	}
}