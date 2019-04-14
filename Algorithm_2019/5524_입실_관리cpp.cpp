#include<bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		char msg[1234];
		scanf("%s", msg);
		for (int i = 0; msg[i] != '\0'; ++i)
			if ('A' <= msg[i] && msg[i] <= 'Z')
				msg[i] = msg[i] - 'A' + 'a';
		printf("%s\n", msg);
	}
}