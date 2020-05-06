#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s2l(string str) {
	ll res = 0;
	for (int i = 0; i < str.size(); ++i) {
		res *= 10;
		res += str[i] - '0';
	}
	return res;
}
double s2d(string str) {
	double res = 0;
	double t = 0.1;
	bool c = 1;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '.') {
			c = 0; continue;
		}
		if (c) {
			res *= 10;
			res += str[i] - '0';
		}
		else {
			res += (str[i] - '0') * t;
			t /= 10;
		}
	}
	return res;
}
ll calc(ll n1, ll n2, string & str) {
	switch (str[0]) {
	case '+':
		return n1 + n2;
		break;
	case '-':
		return n1 - n2;
		break;
	case '*':
		if (str[1] == '*') {
			ll res = 1;
			while (n2) {
				if (n2 % 2) 
					res *= n1;
				n2 /= 2;
				n1 *= n1;
			}
			return res;
		}
		else
			return n1 * n2;
		break;
	case '/':
		return n1 / n2;
		break;
	case '%':
		return n1 % n2;
		break;
	}
}
double calc(double n1, double n2, string str) {
	switch (str[0]) {
	case '+':
		return n1 + n2;
		break;
	case '-':
		return n1 - n2;
		break;
	case '*':
		if (str[1] == '*') {
			ll res = 1;
			while (n2) {
				if ((ll)n2 % 2)
					res *= n1;
				n2 /= 2;
				n1 *= n1;
			}
			return res;
		}
		else
			return n1 * n2;
		break;
	case '/':
		return n1 / n2;
		break;
	case '%':
		return (ll)n1 % (ll)n2;
		break;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	cout.precision(9);
	while (n--) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		bool c = 0;
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] == '.')
				c = 1;
		}
		for (int i = 0; i < s3.size(); ++i)
			if (s3[i] == '.')
				c = 1;
		double d1, d2;
		ll l1, l2;
		if (c) {
			d1 = s2d(s1);
			d2 = s2d(s3);
			double res = calc(d1, d2, s2);
			if (res == (ll)res)
				cout << (ll)res << '\n';
			else
				cout << res << '\n';
		}
		else {
			l1 = s2l(s1);
			l2 = s2l(s3);
			cout << calc(l1, l2, s2) << '\n';
		}
	}
}