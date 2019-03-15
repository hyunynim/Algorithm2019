#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

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
vector<int> kmp(string s, string p) {
	auto pi = pre(p);
	vector<int> ans;
	int n = s.size();
	int m = p.size();
	int i = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j += 1;
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s1, s2, str = "";
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); ++i)
		if ('a' <= s1[i] && s1[i] <= 'z'
			|| 'A' <= s1[i] && s1[i] <= 'Z')
			str.push_back(s1[i]);
	vector<int> ans = kmp(str, s2);
	if (ans.empty()) printf("0");
	else
		printf("1");
}