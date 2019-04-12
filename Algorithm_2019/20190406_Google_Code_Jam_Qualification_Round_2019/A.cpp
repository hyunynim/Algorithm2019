#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int TC = 0; TC < t; ++TC) {
		string num;
		cin >> num;
		string ans1 = "", ans2 = "";
		for (int i = 0; i < num.size(); ++i) {
			if (num[i] != '4') {
				ans1.push_back(num[i]);
				ans2.push_back('0');
			}
			else {
				ans1.push_back('3');
				ans2.push_back('1');
			}
		}
		reverse(ans2.begin(), ans2.end());
		while (ans2.size() && ans2.back() == '0')
			ans2.pop_back();
		reverse(ans2.begin(), ans2.end());
		cout << "Case #" << TC + 1 << ": ";
		cout << ans1 << " " << ans2 << '\n';
		
	}
}