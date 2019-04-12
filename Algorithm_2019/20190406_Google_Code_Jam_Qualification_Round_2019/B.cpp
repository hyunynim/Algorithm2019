#include<bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	for (int TC = 1; TC <= t; ++TC) {
		int n; string str;
		cin >> n >> str;
		string ans = "";
		for (int i = 0; i < str.size(); ++i) 
				ans.push_back(str[i] == 'E' ? 'S' : 'E');
		cout << "Case #" << TC << ": " << ans << '\n';
	}

}