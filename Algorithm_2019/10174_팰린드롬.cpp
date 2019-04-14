#include<bits/stdc++.h>
using namespace std;

int main() {
	char msg[12345];
	int n; scanf("%d", &n);
	getchar();
	while (n--) {
		fgets(msg, 12344, stdin);
		string str = msg;
		if (str.back() == '\n' || str.back() == '\0')
			str.pop_back();
		bool ans = 1;
		for (int i = 0; i < str.size(); ++i) {
			char b = str[str.size() - i - 1];
			if ('A' <= str[i] && str[i] <= 'Z')
				str[i] = str[i] - 'A' + 'a';
			if ('A' <= b && b <= 'Z')
				b = b - 'A' + 'a';
			if (str[i] != b) {
				ans = 0;
				break;
			}
		}
		if (ans)
			puts("Yes");
		else
			puts("No");
	}
}