#include<bits/stdc++.h>
using namespace std;
int chk[10231];
string d[1025][1025];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		int a, b; cin >> a >> b;
		cout << a / b << '.';
		a %= b;
		int sa = a, sb = b;
		string ans = "";
		ans.reserve(2020);
		while (1) {
			a *= 10;
			if (!d[sa][sb].empty()) {
				ans = d[sa][sb];
				break;
			}
			if (a % b == 0) {
				if (a / b)
					ans.push_back(a / b + '0');
				ans += "(0)";
				d[sa][sb] = ans;
				break;
			}
			else {
				int idx = chk[a];
				if (idx) {
					ans.insert(ans.begin() + idx - 1, '(');
					ans.push_back(')');
					d[sa][sb] = ans;
					break;
				}
				else {
					chk[a] = ans.size() + 1;
					ans.push_back(a / b + '0');
					a %= b;
				}
			}
		}
		cout << ans << '\n';
	}
}