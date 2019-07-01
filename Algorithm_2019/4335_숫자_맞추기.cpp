#include<bits/stdc++.h>
using namespace std;
int main() {
	int num;
	bool ans = 1;
	int l = 1, r = 10;
	do {
		scanf("%d", &num);
		if (num == 0) return 0;
		char msg[2][11];
		scanf("%s %s", msg[0], msg[1]);
		
		if (msg[1][0] == 'h')
			r = min(r, num - 1);
		else if (msg[1][0] == 'l')
			l = max(l, num + 1);
		else {
			if (l > num || num > r) ans = 0;
			puts(ans ? "Stan may be honest" : "Stan is dishonest");
			ans = 1;
			l = 1, r = 10;
		}
	} while (1);
}