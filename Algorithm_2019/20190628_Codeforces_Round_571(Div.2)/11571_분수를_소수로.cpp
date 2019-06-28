#include<bits/stdc++.h>
using namespace std;
vector<int> pre(string p) {
	int m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = j + 1;
			j += 1;
		}
		else {
			pi[i] = 0;
		}
	}
	return pi;
}
int main() {
	int t; scanf("%d", &t);
	string str;
	vector<int> pi;
	while (t--) {
		str.clear();
		pi.clear();
		int a, b; scanf("%d %d", &a, &b);
		bool zero = 0;
		printf("%d.", a / b);
		while (str.size() < 1024) {
			a %= b;
			if (a % b == 0) {
				zero = 1;
				for (int i = 0; i < str.size(); ++i)
					printf("%d", str[i]);
				printf("(0)\n");
				break;
			}
			a *= 10;
			str.push_back(a / b);
		}
		if (zero) continue;
		reverse(str.begin(), str.end());
		pi = pre(str);
		int len = 0;
		for (int i = 2; i < pi.size(); i += 2) {
			if (i / 2 == pi[i]) {
				len = i / 2;
				break;
			}
		}
		reverse(str.begin(), str.end());
		for (int i = 0; i < str.size() - len; ++i) {
			if (str[i] == str[i + len + 1]) {
				putchar('(');
				for (int j = i; j <= i + len; ++j)
					printf("%d", str[j]);
				putchar(')');
				break;
			}
			else
				printf("%d", str[i]);
		}
		puts("");
	}
}