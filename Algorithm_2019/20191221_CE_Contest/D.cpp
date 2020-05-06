#include<bits/stdc++.h>
using namespace std;
string str;
vector<int> seq;
int all, cnt;
int co[] = { 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5 };
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
void go(int num) {
	if (num == seq.size()) {
		int res = 0;
		for (int i = 0; i < 12; ++i) {
			res += (co[i] * (str[i] - '0'));
			res %= 11;
		}
		res = (11 - res) % 10;
		if (res == str.back() - '0') {
			++all;
			if (str[0] == '1' && str[6] == '1')
				++cnt;
			else if (str[0] == '0' && str[6] == '3')
				++cnt;
		}
		return;
	}
	for (int i = 0; i < 10; ++i) {
		str[seq[num]] = '0' + i;
		if (str[0] == '1' && str[1] == '9' && (str[6] != '1' && str[6] != '2' && str[6] != 'X')) continue;
		if (str[0] == '0' && (str[6] != '3' && str[6] != '4' && str[6] != 'X')) continue;
		go(num + 1);
	}
}
int main() {
	cin >> str;
	str.erase(str.begin() + 6);
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'X')
			seq.push_back(i);
	}
	go(0);
	if (cnt == 0 || all == 0)
		printf("%d %d", cnt, all);
	else {
		int g = gcd(cnt, all);
		printf("%d %d", cnt / g, all / g);
	}

}