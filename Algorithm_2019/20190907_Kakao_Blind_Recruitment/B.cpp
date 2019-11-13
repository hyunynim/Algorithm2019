#include<bits/stdc++.h>
using namespace std;
bool chk(string& s) {
	int c = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			++c;
		else {
			if (c) --c;
			else return 0;
		}
	}
	return c == 0;
}
string go(string s) {
	if (s == "") return s;
	int o = 0, c = 0;
	string ans = "";
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			++o;
		else
			++c;
		if (o == c) {
			string a1 = s.substr(0, i + 1);
			string a2 = s.substr(i + 1);
			if (!chk(a1)) {
				ans.push_back('(');
				ans += go(a2);
				ans.push_back(')');
				a1.erase(0, 1);
				a1.pop_back();
				for (int j = 0; j < a1.size(); ++j) {
					if (a1[j] == '(')
						a1[j] = ')';
					else
						a1[j] = '(';
				}
				ans += a1;
			}
			else {
				ans = a1;
				ans += go(a2);
			}
			return ans;
		}
	}
	return "";
}
string solution(string p) {
	string answer = go(p);
	return answer;
}
int main() {
	cout << solution("()))((()");
}