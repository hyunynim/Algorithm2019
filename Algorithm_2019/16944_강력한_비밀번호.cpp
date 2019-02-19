#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n; string str;
	cin >> n >> str;
	vector<char> seq[4];
	for (char c = 'a'; c <= 'z'; ++c) {
		seq[0].push_back(c);
		seq[1].push_back(c - 'a' + 'A');
	}
	for (int i = 0; i < 10; ++i)
		seq[2].push_back(i + '0');
	seq[3].push_back('!');
	seq[3].push_back('@');
	seq[3].push_back('#');
	seq[3].push_back('$');
	seq[3].push_back('%');
	seq[3].push_back('^');
	seq[3].push_back('&');
	seq[3].push_back('*');
	seq[3].push_back('(');
	seq[3].push_back(')');
	seq[3].push_back('-');
	seq[3].push_back('+');
	sort(seq[3].begin(), seq[3].end());
	int cnt[4] = { 0 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j)
			if (binary_search(seq[j].begin(), seq[j].end(), str[i]))
				++cnt[j];
	}
	int ans = 4;
	for (int i = 0; i < 4; ++i)
		if (cnt[i]) --ans;
	printf("%d", n + ans < 6 ? 6 - n : ans);
}