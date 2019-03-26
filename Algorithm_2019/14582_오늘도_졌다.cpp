#include<cstdio>

int score[2][9];

int main() {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 9; ++j)
			scanf("%d", &score[i][j]);
	}
	int a = 0, b = 0;
	bool ans = 0;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (j)
				b += score[j][i];
			else
				a += score[j][i];
			if (a > b)
				ans = 1;
		}
	}
	if (ans)
		printf("Yes");
	else
		printf("No");
}