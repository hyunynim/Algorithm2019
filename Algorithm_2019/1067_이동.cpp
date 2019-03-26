#include <cstdio>
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
int main() {
	int n; scanf("%d", &n);
	vector<int> s1(n), s2(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &s1[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &s2[i]);
	reverse(s1.begin(), s1.end());
	vector<int> ans;
	FFT::multiply(s1, s2, ans);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		ans[i] += ans[i + n];
		res = max(res, ans[i]);
	}
	printf("%d", res);
}
