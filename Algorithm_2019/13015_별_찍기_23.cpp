#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j)
			putchar(' ');
		for (int j = 0; j < n; ++j) {
			if (i == 0)
				putchar('*');
			else {
				if (j == 0 || j == n - 1)
					putchar('*');
				else
					putchar(' ');
			}
		}
		for (int j = 0; j < (n - 1) * 2 - 1 - 2 * i; ++j)
			putchar(' ');
			for (int j = 0; j < n; ++j) {
			if (i == 0)
				putchar('*');
			else {
				if (j == 0 && i == n - 1) continue;
				if (j == 0 || j == n - 1)
					putchar('*');
				else
					putchar(' ');
			}
		}
		puts("");
	}
	for (int i = n - 2; i >= 0; --i) {
		for (int j = 0; j < i; ++j)
			putchar(' '); 
		for (int j = 0; j < n; ++j) {
			if (i == 0)
				putchar('*');
			else {
				if (j == 0 || j == n - 1)
					putchar('*');
				else
					putchar(' ');
			}
		}
		for (int j = 0; j < (n - 1) * 2 - 1 - 2 * i; ++j)
			putchar(' ');
		for (int j = 0; j < n; ++j) {
			if (i == 0)
				putchar('*');
			else {
				if (j == 0 || j == n - 1)
					putchar('*');
				else
					putchar(' ');
			}
		}
		puts("");
	}
}