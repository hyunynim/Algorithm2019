#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
void change(vector<string> & seq, char c) {
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, string>> seq;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		seq.push_back({ str.size(), str });
	}
	sort(seq.begin(), seq.end(), greater<pair<int, string>>());
	cout << '\n';
	vector<string> ans;
	int maxLen = seq[0].first;
	for (auto i : seq) {
		string tmp = "";
		for (int j = 0; j < maxLen - i.first; ++j)
			tmp += '#';
		tmp += i.second;
		ans.push_back(tmp);
	}
	int k; cin >> k;
	for (int i = 0; i < k; ++i) {
		int cnt[36] = { 0 };
		for (int j = 0; j < n; ++j) {
			for (auto c : ans[j]) {

			}
		}
	}
}