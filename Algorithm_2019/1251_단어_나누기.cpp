#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;
	char msg[1234];
	vector<string> ans;
	scanf("%s", msg);
	str = msg;
	for (int i = 1; i < str.length() - 1; ++i) {
		for (int j = i + 1; j < str.length(); ++j) {
			string s1, s2, s3;
			s1 = str.substr(0, i);
			s2 = str.substr(i, j - i);
			s3 = str.substr(j);
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());
			ans.push_back(s1 + s2 + s3);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%s", ans[0].c_str());
}