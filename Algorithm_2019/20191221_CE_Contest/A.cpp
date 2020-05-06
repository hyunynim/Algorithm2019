#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
string chk = "aeiou";
void go(string& s, int toPick) {
	if (toPick == 0) {
		bool c = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (binary_search(chk.begin(), chk.end(), s[i])) {
				c = 1; break;
			}
		}
		if(c)
			cout << s << '\n';
		return;
	}
	for (int i = 0; i < str.size(); ++i) {
		if (s.size() > 1) {
			if (*(s.end() - 1) == *(s.end() - 2) && s.back() == str[i])
				continue;
		}
		s.push_back(str[i]);
		go(s, toPick - 1);
		s.pop_back();
	}
}
int main() {
	char s1[10], s2[10];
	int n; scanf("%s %s %d", s1, s2, &n);
	for (int i = 0; i <= s2[0] - s1[0]; ++i)
		str.push_back(s1[0] + i);
	string tmp = "";
	go(tmp, n);
}