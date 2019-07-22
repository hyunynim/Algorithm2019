#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	int seat = 0, sum = 0, chk = 0;
	vector<int> ans;
	ans.push_back(1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		sum += seq[i];
		if (i == 0)
			seat = chk = seq[i];
		else {
			if (seq[i] * 2 <= seat) {
				ans.push_back(i + 1);
				chk += seq[i];
			}
		}
	}
	chk = 0;
	int i = 0;
	for (; i < ans.size(); ++i) {
		chk += seq[ans[i] - 1];
		if (chk > sum / 2)
			break;
	}
	if (chk <= sum / 2) {
		printf("0");
	}
	else {
		printf("%d\n", i + 1);
		for (int j = 0; j <= i; ++j)
			printf("%d ", ans[j]);
	}
}