#include<bits/stdc++.h>
using namespace std;
int x[1010101];
int main() {
	string s[2];
	cin >> s[0] >> s[1];
	int pre = 0, ans = 0, len = s[1].size();
	for (int i = 0; i < s[0].size(); ++i) {
		if (i < s[1].size())
			pre ^= (s[1][i] - '0');
		x[i + 1] = x[i] ^ (s[0][i] - '0');
	}
	for (int i = 0; i <= s[0].size() - len; ++i) 
		if ((pre ^ (x[i + len] ^ x[i])) == 0)
			++ans;
	printf("%d", ans);
}