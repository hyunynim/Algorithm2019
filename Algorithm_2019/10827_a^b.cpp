#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <complex>
using namespace std;
namespace FFT {
	using base = complex<double>;
	const double PI = acos(-1);
	void fft(vector<base> &a, bool invert) {
		int n = a.size();
		for (int i = 1, j = 0; i < n; i++) {
			int bit = n >> 1;
			for (; j >= bit; bit >>= 1) {
				j -= bit;
			}
			j += bit;
			if (i < j) {
				swap(a[i], a[j]);
			}
		}
		for (int len = 2; len <= n; len <<= 1) {
			double ang = 2 * PI / len * (invert ? -1 : 1);
			base wlen(cos(ang), sin(ang));
			for (int i = 0; i < n; i += len) {
				base w(1);
				for (int j = 0; j < len / 2; j++) {
					base u = a[i + j], v = a[i + j + len / 2] * w;
					a[i + j] = u + v;
					a[i + j + len / 2] = u - v;
					w *= wlen;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < n; i++) {
				a[i] /= n;
			}
		}
	}
	void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res) {
		vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
		int n = 1;
		while (n < max(a.size(), b.size())) n <<= 1;
		n <<= 1;
		fa.resize(n); fb.resize(n);
		fft(fa, false); fft(fb, false);
		for (int i = 0; i < n; i++) {
			fa[i] *= fb[i];
		}
		fft(fa, true);
		res.resize(n);
		for (int i = 0; i < n; i++) {
			res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
		}
	}
}
string getMul(string n1, string n2) {
	vector<int> s1, s2;
	reverse(n1.begin(), n1.end());
	for (auto i : n1)
		s1.push_back(i - '0');
	reverse(n2.begin(), n2.end());
	for (auto i : n2)
		s2.push_back(i - '0');
	vector<int> ans;
	FFT::multiply(s1, s2, ans);
	int carry = 0;
	for (int i = 0; i < ans.size(); i++) {
		ans[i] += carry;
		carry = ans[i] / 10;
		ans[i] %= 10;
	}
	while (ans.size() > 1 && ans.back() == 0)
		ans.pop_back();
	reverse(ans.begin(), ans.end());

	string res = "";
	for (auto i : ans)
		res += i + '0';
	return res;
}

string pow(string num, int a) {
	string res = "";
	while (a) {
		if (a % 2) {
			if (res == "")
				res = num;
			else
				res = getMul(res, num);
		}
		num = getMul(num, num);
		a >>= 1;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a; int b;

	cin >> a >> b;
	bool firstZero = a[0] == '0';
	int point;
	string numOnly = "";
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == '.') {
			point = a.size() - i - 1;
			continue;
		}
		numOnly.push_back(a[i]);
	}
	point *= b;
	string ans = pow(numOnly, b);
	if (firstZero) {
		string tmp = "0.";
		for (int i = 0; i < point - ans.size(); ++i)
			tmp += '0';
		ans = tmp + ans;
	}
	else {
		for (auto it = ans.end(); it != ans.begin(); --it) {
			if (ans.end() - it == point) {
				ans.insert(it, '.');
				break;
			}
		}
	}
	cout << ans;
}
