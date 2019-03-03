#include<cstdio>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	int cnt = 11;
	for (int i = 1; i < 9; ++i) {
		if (n < cnt) {
			printf("%d", i);
			return 0;
		}
		cnt = cnt * 10 + 1;
	}
	printf("9");
}