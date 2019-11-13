#include<bits/stdc++.h>
#include<unordered_map>
#include<random>
using namespace std;
typedef pair<int, int> P;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 1000000);
uniform_int_distribution<int> d2(1, 1000000000);
vector<int> ans;
void merge(vector<P>& seq, int l, int r) {
	vector<P> tmp;
	int mid = (l + r) / 2;
	int f = l, s = mid + 1;
	while (f <= mid && s <= r) {
		if (seq[f].first <= seq[s].first)
			tmp.push_back(seq[f++]);
		else {
			tmp.push_back(seq[s]);
			ans[seq[s++].second] += mid - f + 1;
		}
	}
	for (; f <= mid; ++f)
		tmp.push_back(seq[f]);
	for (; s <= r; ++s)
		tmp.push_back(seq[s]);
	for (int i = l; i <= r; ++i)
		seq[i] = tmp[i - l];
}

void merge_sort(vector<P>& seq, int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		merge_sort(seq, l, mid);
		merge_sort(seq, mid + 1, r);
		merge(seq, l, r);
	}
}
void solve() {
	ans.clear();
	int n; scanf("%d", &n);
	vector<P> seq(n);
	ans.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i].first);
		seq[i].second = i;
	}
	merge_sort(seq, 0, n - 1);
	for (auto i : ans)
		printf("%d\n", i);
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 2, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen);
		if (cnt <= 3)
			n = rand() % 10 + 5;
		else if (cnt <= 6)
			n = 1000000;
		printf("%d\n", n);
		unordered_map<int, int> chk;
		for (int i = 0; i < n; ++i) {
			int num = d2(gen);
			if (cnt <= 3)
				num = rand() % 20 + 1;
			while (chk[num]) {
				num = d2(gen);
				if (cnt <= 3)
					num = rand() % 20 + 1;
			}
			printf("%d ", num);
		}
		fclose(fp);


		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 10) break;
	}
}