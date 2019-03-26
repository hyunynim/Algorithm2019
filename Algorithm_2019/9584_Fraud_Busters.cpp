#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string str, tmp; cin >> str;
	int n; cin >> n;
	vector<string> ans;
	for (int i = 0; i < n; ++i) {
		bool ok = 1;
		cin >> tmp;
		for (int j = 0; j < str.size(); ++j) {
			if (str[j] == '*') continue;
			if (str[j] != tmp[j]) {
				ok = 0;
				break;
			}
		}
		if (ok)
			ans.push_back(tmp);
	}
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << '\n';
}