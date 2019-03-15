#include<cstdio>
#include<algorithm>

using namespace std;
bool ca[101][101];

int main() {
	int n, r, c; scanf("%d %d %d", &n, &r, &c);

	bool dig;
	--r; --c;
	if (r % 2 == 0 && c % 2 == 0
		|| r % 2 && c % 2)
		dig = 1;
	else 
		dig = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i % 2 == 0 && j % 2 == 0
				|| i % 2 && j % 2)
				ca[i][j] = dig;
			else
				ca[i][j] = !dig;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (ca[i][j]) putchar('v');
			else putchar('.');
		}
		puts("");
	}
}