#include<bits/stdc++.h>
using namespace std;
struct EXP {
	unsigned int a, b, c, d, e, f, g, h, i;
};
double ratio = 1.02;
int print(int n, int &prev) {
	prev = prev + prev / 100;
	printf("%d ", n);
	for (int i = 0; i < 7; ++i) {
		printf("%d ", prev);
	}
	printf("%d\n", 1);
	return prev * ratio;
}
int main() {
	freopen("exp.txt", "r", stdin);
	freopen("result.txt", "w", stdout);
	unsigned int a, b, c, d, e, f, g, h, i;
	vector<EXP> seq;
	while (~scanf("%d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i)) {
		seq.push_back({ a,b,c,d,e,f,g,h,i });
	}
	vector<EXP> res;
	for (int i = 0; i < seq.size() - 1; ++i) {
		/*
		EXP tmp = { (seq[i].a + seq[i + 1].a) / 2,
		(seq[i].b + seq[i + 1].b) / 2,
		(seq[i].c + seq[i + 1].c) / 2,
		(seq[i].d + seq[i + 1].d) / 2,
		(seq[i].e + seq[i + 1].e) / 2,
		(seq[i].f + seq[i + 1].f) / 2,
		(seq[i].g + seq[i + 1].g) / 2,
		(seq[i].h + seq[i + 1].h) / 2,
		(seq[i].i + seq[i + 1].i) / 2 };
		*/
		if (seq[i].a <= 10)
			res.push_back(seq[i]);
		else {
			int r = seq[i].i;
			unsigned int val = res.back().b + (seq[i].b - res.back().b) / r;
			res.push_back({ seq[i].a, val, val, val, val, val, val, val, 1 });
		}
	}
	for (int i = 0; i < res.size(); ++i) {
		printf("%d\t", i + 1);
		for (int j = 0; j < 7; ++j)
			printf("%u\t", res[i].b);
		printf("%d\n", res[i].i);
	}
	int r = 199;
	for (int i = 100; i <= 400; ++i) {
		if (i % 10 == 0) ++r;
		printf("%d\t", i);
		unsigned int val = res.back().b + res.back().b / r;
		for (int j = 0; j < 7; ++j)
			printf("%u\t", val);
		puts("1");
		res.push_back({ (unsigned int)i, val, val, val, val, val, val, val, 1 });
	}
}