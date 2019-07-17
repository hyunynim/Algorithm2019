#include<bits/stdc++.h>
using namespace std;
bool chk(int n, int k, int flag) {
	if (n < 3) 
		return n == 0 && flag == 0;
	else {
		if (k > n)
			return n % 3 == 2 && flag == 0;
		else
			return (chk(n - 1, k, n ^ 1) | chk(n - 2, k, n  ^ 1) | chk(n - k, k, n ^ 1)) && flag == 0;
	}
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d %d", &n, &k);
		if (chk(n, k, 0))
			puts("Bob");
		else
			puts("Alice");
	}
}