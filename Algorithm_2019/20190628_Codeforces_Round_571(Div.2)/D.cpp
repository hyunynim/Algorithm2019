#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct NUM {
	ll num;
	int no;
};
int c2l(char* num, ll& ans) {
	bool dot = 0;
	int flag = 1;
	ans = 0;
	for (int i = 0; num[i] != '\0'; ++i) {
		if (num[i] == '-') {
			flag = -1;
			continue;
		}
		if (num[i] == '.') {
			dot = 1;
			continue;
		}
		if (!dot)
			ans = ans * 10 + (num[i] - '0') * flag;
		if (dot && num[i] != '0')
			return 1 * flag;
	}
	return 0;
}
int main() {
	int n; scanf("%d", &n);
	vector<NUM> seq;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		char num[10]; scanf("%s", num);
		ll ans = 0;
		int chk = c2l(num, ans);
		seq.push_back({ ans, chk });
		sum += seq.back().num;
	}
	if (sum) {
		for (int i = 0; i < n; ++i) {
			if (sum == 0 || seq[i].no == 0) printf("%lld\n", seq[i].num);
			else {
				if (sum < 0 && seq[i].no > 0) {
					printf("%lld\n", seq[i].num + 1);
					++sum;
				}
				else if (sum > 0 && seq[i].no < 0) {
					printf("%lld\n", seq[i].num - 1);
					--sum;
				}
				else
					printf("%lld\n", seq[i].num);
			}
		}
	}
	else {
		for (auto i : seq)
			printf("%lld\n", i);
	}
}