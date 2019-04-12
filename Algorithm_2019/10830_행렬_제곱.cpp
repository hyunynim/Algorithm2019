#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e3;
class MAT {
public:
	ll dat[10][10] = { 0 };
	int sz;
	MAT(int n) {
		sz = n;
	}
	MAT(int n, int f) {
		sz = n;
		for (int i = 0; i < sz; ++i)
			dat[i][i] = 1;
	}
	MAT operator *= (MAT m2) {
		MAT res(sz);
		for (int i = 0; i < sz; ++i)
			for (int j = 0; j < sz; ++j)
				for (int k = 0; k < sz; ++k)
					res.dat[i][j] += this->dat[i][k] * m2.dat[k][j];
		for (int i = 0; i < sz; ++i)
			for (int j = 0; j < sz; ++j)
				this->dat[i][j] = res.dat[i][j];
		return res;
	}
	MAT operator %= (int n) {
		for (int i = 0; i < sz; ++i)
			for (int j = 0; j < sz; ++j)
				dat[i][j] %= n;
		return *this;
	}
};

MAT pow(MAT m, ll k, ll n) {
	MAT res(n, 1);
	while (k) {
		if (k % 2) {
			res *= m;
			res %= mod;
		}
		m *= m;
		m %= mod;
		k >>= 1;
	}
	return res;
}
int main() {
	ll n, b;
	scanf("%lld %lld", &n, &b);
	MAT mat(n), res(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &mat.dat[i][j]);
	res = pow(mat, b, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%d ", res.dat[i][j]);
		puts("");
	}
}