#include<bits/stdc++.h>
using namespace std;
bool sieve[30303] = { 1, 1 };
int d[30303];
void pre() {
	memset(d, -1, sizeof(d));
	for (int i = 2; i * i <= 30303; ++i) {
		if (sieve[i]) continue;
		for (int j = i * i; j <= 30303; j += i)
			sieve[j] = 1;
	}
}
int del(int num, int pos) {
	int del = 1;
	for (int i = 0; i < pos; ++i)
		del *= 10;
	int tmp = num % del;
	num /= del;
	num /= 10;
	num *= del;
	num += tmp;
	return num;
}
int go(int num) {
	if (num <= 1) return 0;
	if (num < 10) return (sieve[num] == 0);
	int& res = d[num];
	if (res != -1)
		return res;
	res = (sieve[num] == 0);
	int end = (int)log10(num);
	for (int i = 0; i <= end; ++i) {
		int next = del(num, i);
		if (sieve[next]) continue;
		res = max(res, go(next) + (sieve[num] == 0));
	}
	return res;
}
int main() {
	int t; scanf("%d", &t);
	pre();
	for (int TC = 1; TC <= t; ++TC) {
		int a, b; scanf("%d %d", &a, &b);
		int ans1 = go(a), ans2 = go(b);
		printf("Case #%d\n", TC);
		if (ans1 > ans2)
			puts("1");
		else if (ans1 < ans2)
			puts("2");
		else
			puts("3");
	}
}