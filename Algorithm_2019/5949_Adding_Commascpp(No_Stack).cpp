#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	string ans = "";
	for (int i = 0; i < str.size(); ++i) {
		ans += str[i];
		if (i == str.size() - 1) break;
		if (i % 3 == 2)
			ans.push_back(',');
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}