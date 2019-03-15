#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
string prep(string s) {
	string ans = "^";
	for (int i = 0; i < s.length(); ++i) 
		ans += "#" + s.substr(i, 1);
	ans += "#$";
	return ans;
}
vector<int> manachers(string s) {
	int c = 0;
	int r = 0;
	vector<int> p(s.length());
	for (int i = 1; i < s.length() - 1; ++i) {
		if (i <= r) 
			p[i] = min(p[2 * c - i], r - i);
		
		else 
			p[i] = 0;
		
		while (s[i - p[i] - 1] == s[i + p[i] + 1]) 
			++p[i];
		
		if (i + p[i] > r) {
			r = i + p[i];
			c = i;
		}
	}
	return p;
}
int main() {
	string str;
	cin >> str;
	string t = prep(str);
	vector<int> ans = manachers(t);
	int res = 0;
	for (auto i : ans)
		res = max(res, i);
	printf("%d", res);
}