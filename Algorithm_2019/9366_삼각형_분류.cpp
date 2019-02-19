#include<cstdio>
#include<queue>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	priority_queue<int> q;
	int tc = 1;
	while (t--) {
		int num;
		for (int i = 0; i < 3; ++i) {
			scanf("%d", &num);
			q.push(-num);
		}
		printf("Case #%d: ", tc++);
		int a = -q.top(), b, c; q.pop();
		b = -q.top(); q.pop();
		c = -q.top(); q.pop();
		if (a + b > c) {
			if (a == b) {
				if (b == c)
					puts("equilateral");
				else
					puts("isosceles");
			}
			else if (b == c)
				puts("isosceles");
			else
				puts("scalene");
		}
		else
			puts("invalid!");
	}
}