#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	if (n <= 5)
		printf("%d", n);
	else {
		int a[] = { 4, 3, 2, 1, 2, 3, 4, 5 };
		n -= 6;
		n %= 8;
		printf("%d", a[n]);
	}
}
