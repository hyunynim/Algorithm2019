#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> s1(n), s2(n);
	for (int i = 0; i < n; ++i) {
		cin >> s1[i];
		s2[i] = s1[i];
	}
	sort(s2.begin(), s2.end());
	if (s1 == s2)
		cout << "INCREASING";
	else {
		reverse(s2.begin(), s2.end());
		if (s1 == s2)
			cout << "DECREASING";
		else
			cout << "NEITHER";
	}
}