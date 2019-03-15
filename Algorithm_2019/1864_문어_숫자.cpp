#include<cstdio>
#include<map>

using namespace std;

int main() {
	map<char, int> c2i;
	c2i['-'] = 0;
	c2i['\\'] = 1;
	c2i['('] = 2;
	c2i['@'] = 3;
	c2i['?'] = 4;
	c2i['>'] = 5;
	c2i['&'] = 6;
	c2i['%'] = 7;
	c2i['/'] = -1;
	char msg[1234];
	while (~scanf("%s", msg)) {
		if (msg[0] == '#' && msg[1] == '\0')
			return 0;
		int res = 0;
		for (int i = 0; msg[i] != '\0'; ++i) {
			res *= 8;
			res += c2i[msg[i]];
		}
		printf("%d\n", res);
	}
}