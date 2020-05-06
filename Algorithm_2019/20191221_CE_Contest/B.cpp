#include<bits/stdc++.h>
using namespace std;
bool sieve[2020202] = { 1, 1 };
vector<int> p;
void pre() {
	for (int i = 2; i * i <= 2000000; ++i) {
		if (sieve[i]) continue;
		for (int j = i * i; j <= 2000000; j += i)
			sieve[j] = 1;
	}
	for (int i = 2; i <= 2000000; ++i)
		if (!sieve[i]) p.push_back(i);
}
vector<int> pf(int num) {
	vector<int> res;
	for (int i = 0; i < p.size() && num > 1; ++i) {
		while (num % p[i] == 0) {
			res.push_back(p[i]);
			num /= p[i];
		}
	}
	return res;
}
int bSearch(int num) {
	int l = 0, r = p.size() - 1;
	while (l <= r) {
		int mid = ((l + r) >> 1);
		if (p[mid] == num)
			return mid;
		else if (p[mid] > num)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}
int main() {
	pre();
	int k; scanf("%d", &k);
	vector<vector<int>> seq;
	for (int i = 0; i < 5; ++i) {
		int num; scanf("%d", &num);
		seq.push_back(pf(num));
	}
	auto st = bSearch(k);
	string ans = "";
	for (int i = 0; i < seq.size(); ++i) {
		int res = 0;
		seq[i].erase(unique(seq[i].begin(), seq[i].end()), seq[i].end());
		for (int j = 0; j < seq[i].size(); ++j) {
			auto ed = bSearch(seq[i][j]);
			if (ed - st > 4) continue;
			res |= (1 << (ed - st));
		}
		ans.push_back('A' + res - 1);
	}
	printf("%s", ans.c_str());
}