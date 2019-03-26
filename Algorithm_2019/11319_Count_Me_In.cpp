#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	char msg[1010];
	char vowels[] = "AEIOUaeiou";
	getchar();
	for (int i = 0; i < n; ++i) {
	int ans1 = 0, ans2 = 0;
		fgets(msg, 1009, stdin);
		for (int j = 0; msg[j] != '\0' && msg[j] != '\n'; ++j) {
			if (binary_search(vowels, vowels + 10, msg[j]))
				++ans1;
			else if(('a' <= msg[j] && msg[j] <= 'z')
				|| ('A' <= msg[j] && msg[j] <= 'Z'))
				++ans2;
		}
		printf("%d %d\n", ans2, ans1);
	}
}