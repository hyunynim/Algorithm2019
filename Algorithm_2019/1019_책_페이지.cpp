#include<bits/stdc++.h>
using namespace std;

int cnt[11];
int n;
void go(int toPick, vector<int>& picked) {
	if (toPick == 0) {
		int num = 0;
		for (auto i : picked)
			num = num * 10 + i;
		if (num > n) return;
		for (auto i : picked)
			++cnt[i];
	}
	else {
		int next = picked.empty() ? 1 : 0;
		for (int i = next; i < 10; ++i) {
			picked.push_back(i);
			go(toPick - 1, picked);
			picked.pop_back();
		}
	}
}
int main() {

	scanf("%d", &n);
	int tmpNum = n;
	int lim = 0;
	while (tmpNum) {
		tmpNum /= 10;
		++lim;
	}
	if (n == (int)1e9) {
		--lim;
		++cnt[1];
		cnt[0] += 9;
	}
	vector<int> tmp;
	for (int i = 1; i <= lim; ++i)
		go(i, tmp);
	for (int i = 0; i < 10; ++i)
		printf("%d ", cnt[i]);
}