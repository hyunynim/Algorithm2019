#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 1000000);
uniform_int_distribution<int> d2(1, 1e9);
ll chk(vector<int>& seq, int mid) {
	ll sum = 0;
	for (int i = 0; i < seq.size(); ++i)
		sum += min(mid, seq[i]);
	return sum;
}
int solve() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	int l = 0, r = 0, s, sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		r = max(r, seq[i]);
		sum += seq[i];
	}
	scanf("%d", &s);
	if (s >= sum) {
		printf("%d", r); return 0;
	}
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (chk(seq, mid) > s)
			r = mid - 1;
		else {
			l = mid + 1;
			ans = mid;
		}
	}
	printf("%d", ans);
	return ans;
}
int binary_search(vector<int>& seq, int data) {
	int l = 0, r = seq.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (seq[mid] == data)
			return mid;
		else if (seq[mid] < data)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 1, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);
		int n = d1(gen);
		if (cnt <= 3)
			n = rand() % 5 + 5;
		else if (cnt <= 6)
			n = 1000000;
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) {
			if (cnt <= 3)
				printf("%d ", rand() % 10 + 1);
			else
				printf("%d ", d1(gen));
		}
		int k = d2(gen);
		if (cnt <= 3)
			k = rand() % 50 + 5;
		printf("\n%d", k);
		fclose(fp);
		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 10) break;
	}
}