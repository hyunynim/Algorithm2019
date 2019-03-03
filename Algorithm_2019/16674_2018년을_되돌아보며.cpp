#include<cstdio>
#include<algorithm>
using namespace std;
int cnt[10];

int main() {
	int n, len = 0, sum = 0;;
	while (~scanf("%1d", &n)) {
		++len;
		++cnt[n];
		if (n == 0 || n == 1 || n == 2 || n == 8) 
			++sum;
	}
	if (sum != len)
		printf("0");
	else {
		if (cnt[0] && cnt[1] && cnt[2] && cnt[8]) {
			if (cnt[0] == cnt[1] && cnt[2] == cnt[8]
				&& cnt[0] == cnt[8])
				printf("8");
			else
				printf("2");
		}
		else
			printf("1");
	}
}