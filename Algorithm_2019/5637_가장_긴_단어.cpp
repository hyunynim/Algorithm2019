#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<pair<int, int>> seq;
	vector<string> s;
	string str = "";
	while (1) {
		char c = getchar();
		if ('a' <= c && c <= 'z'
			|| 'A' <= c && c <= 'Z'
			|| c == '-')
			str += c;
		else {
			if (str == "E-N-D") break;
			s.push_back(str);
			seq.push_back({ -str.length(), seq.size() });
			str = "";
		}
	}
	sort(seq.begin(), seq.end());
	string ans = s[seq[0].second];
	for (int i = 0; i < ans.length(); ++i) {
		if ('A' <= ans[i] && ans[i] <= 'Z')
			ans[i] += 'a' - 'A';
	}
	cout << ans;
}