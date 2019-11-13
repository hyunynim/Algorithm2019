#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d(2, 50000);
uniform_int_distribution<int> d2(1, 1000000000);
struct P {
	int s, e;
};
bool cmp1(P p1, P p2) {
	return p1.e == p2.e ? p1.s < p2.s : p1.e < p2.e;
}
bool cmp2(P p1, P p2) {
	return p1.s == p2.s ? p1.e < p2.e : p1.s < p2.s;
}
bool cmp3(P p1, P p2) {
	return p1.e == p2.e ? p1.s > p2.s : p1.e > p2.e;
}
bool cmp4(P p1, P p2) {
	return p1.s == p2.s ? p1.e > p2.e : p1.s > p2.s;
}
bool cmp5(P p1, P p2) {
	return p1.e - p1.s == p2.e - p2.s ? cmp2(p1, p2) : p1.e - p1.s < p2.e - p2.s;
}
void solve() {
	int n; scanf("%d", &n);
	vector<P> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &seq[i].s, &seq[i].e);
	sort(seq.begin(), seq.end(), cmp1);
	int ans = 0, e = 0, ans2 = 0;
	for (int i = 0; i < n; ++i) {
		if (seq[i].s >= e) {
			e = seq[i].e;
			++ans;
		}
	}
	sort(seq.begin(), seq.end(), cmp2);
	e = 0;
	for (int i = 0; i < n; ++i) {
		if (seq[i].s >= e) {
			e = seq[i].e;
			++ans2;
		}
	}
	printf("%d %d", ans, ans2);
}
int main() {
//	solve();
//	return 0;
	srand(time(0));
	char msg[1010];
	int cnt = 3, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);
		int n = d(gen);
		if (cnt < 7) n = 1000000;
		else
			n = d(gen);
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) {
			//			printf("%d ", cnt == 2 ? 1000 : rand() % 1000 + 1);
			int a1 = d2(gen);
			int a2 = d2(gen);
			if (a1 > a2) swap(a1, a2);
			printf("%d %d\n", a1, a2);
		}

		fclose(fp);
		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 10) break;
	}
}