#include<bits/stdc++.h>
#include<map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	string str; cin >> str;
	int cnt[26] = { 0 };
	map<pair<int, int>, int> chk;
	for (int i = 0; i < str.size(); ++i) {
		++cnt[str[i] - 'a'];
		chk[{str[i], cnt[str[i] - 'a']}] = i + 1;
	}
	int k; cin >> k;
	for (int i = 0; i < k; ++i) {
		string msg; cin >> msg;
		int ccnt[26] = { 0 };
		int ans = 0;
		for (int i = 0; i < msg.size(); ++i) {
			++ccnt[msg[i] - 'a'];
			ans = max(ans, chk[{msg[i], ccnt[msg[i] - 'a']}]);
		}
		cout << ans << '\n';
	}
}