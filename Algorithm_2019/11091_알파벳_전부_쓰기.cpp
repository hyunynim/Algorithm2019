#include<cstdio>

int main() {
	int t; scanf("%d", &t);
	getchar();
	while (t--) {
		char msg[1234];
		int cnt[26] = { 0 };
		fgets(msg, 1010, stdin);
		for (int i = 0; msg[i] != '\0'; ++i) {
			if ('a' <= msg[i] && msg[i] <= 'z')
				cnt[msg[i] - 'a']++;
			else if ('A' <= msg[i] && msg[i] <= 'Z')
				cnt[msg[i] - 'A']++;
		}
		bool ok = 1;
		for (int i = 0; i < 26; ++i)
			if (cnt[i] == 0) ok = 0;

		if (ok)
			puts("pangram");
		else {
			printf("missing ");
			for (int i = 0; i < 26; ++i)
				if (cnt[i] == 0) putchar(i + 'a');
			puts("");
		}
	}
}