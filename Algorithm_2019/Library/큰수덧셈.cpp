#include<cstdio>
#include<algorithm>
#include<deque>
#include<stack>
#include<string.h>
#define MAX_STRING_LENGTH 1000

using namespace std;
int k = 0;

void sum(char * a, char * b, char * res) {
	stack <char> num1, num2, num3;
	int i, j, tmp;
	int chkNextDegree = 0;

	for (i = 0, j = 0; a[i] != '\0'; i++, j++) {
		num1.push(a[i] - '0');
		num2.push(b[j] - '0');
	}

	while (i && j) {
		tmp = 0;
		if (i != 0)
			tmp += num1.top();
		if (j != 0)
			tmp += num2.top();
		if (chkNextDegree == 1)
			tmp += 1;

		if (num1.top() + num2.top() + chkNextDegree >= 10)
			chkNextDegree = 1;
		else
			chkNextDegree = 0;

		tmp %= 10;
		num3.push(tmp);

		if (i != 0)
			num1.pop();
		if (j != 0)
			num2.pop();
		i--;
		j--;
	}
	while (num1.size()) {
		num3.push((num1.top() + chkNextDegree) % 10);
		chkNextDegree = num1.top() = (num1.top() + chkNextDegree) / 10;
		num1.pop();
	}
	while (num2.size()) {
		num3.push((num2.top() + chkNextDegree) % 10);
		chkNextDegree = num2.top() = (num2.top() + chkNextDegree) / 10;
		num2.pop();
	}
	if (chkNextDegree == 1)
		num3.push(1);
	int tt = 0;
	while (num3.size()) {
		res[tt] = num3.top() + '0';
		num3.pop();
		++tt;
	}
	res[tt] = '\0';
}