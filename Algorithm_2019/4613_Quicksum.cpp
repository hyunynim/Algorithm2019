#include<cstdio>

int main() {
	while (1) {
		int ans = 0;
		char msg[1234];
		fgets(msg, 1233, stdin);
		if (msg[0] == '#') return 0;
		for (int i = 0; msg[i] != '\0' && msg[i] != '\n'; ++i) {
			if (msg[i] == ' ') continue;
			ans += (i + 1) * (msg[i] - 'A' + 1);
		}
		printf("%d\n", ans);
	}
}