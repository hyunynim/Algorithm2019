#include<cstdio>

int main() {
	char msg[1234];
	while (1) {
		fgets(msg, 1233, stdin);
		if (msg[0] == '#' && (msg[1] == '\0' || msg[1] == '\n'))
			return 0;
		int cnt[26] = { 0 };
		for (int i = 0; msg[i] != '\0'; ++i) {
			if ('a' <= msg[i] && msg[i] <= 'z')
				++cnt[msg[i] - 'a'];
			else if ('A' <= msg[i] && msg[i] <= 'Z')
				++cnt[msg[i] - 'A'];
		}
		int ans = 0;
		for (int i = 0; i < 26; ++i)
			if (cnt[i]) ++ans;
		printf("%d\n", ans);
	}
}