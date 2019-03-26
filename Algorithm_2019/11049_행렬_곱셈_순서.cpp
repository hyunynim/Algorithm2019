#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll d[505][505];
struct MAT {
	ll r, c;
};
vector<MAT> mat;
ll go(int l, int r, int curR, int curC) {
	if (r <= l) return 0;
	if (r - l == 1) {
		return mat[l].r * mat[r].c * mat[l].c;
	}
	ll & res = d[l][r];
	if (res != -1) return res;
	res = 1e10;
	for (int i = l + 1; i < r; ++i) 
		res = min(res, go(l, i, mat[l].r, mat[i].c) + go(i + 1, r, mat[i + 1].r, mat[r].c) + mat[l].r * mat[i + 1].r * mat[r].c);
	return res;
}
int main() {
	memset(d, -1, sizeof(d));
	int n; scanf("%d", &n);
	mat.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%lld %lld", &mat[i].r, &mat[i].c);
	printf("%lld", go(0, n - 1, 1, 1));
}