#include<cstdio>
#include<cmath>
int gcd(int a, int b) {
	if (b) return gcd(b, a % b);
	return a;
}

int dist(int x1, int y1, int x2, int y2) {
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
	int x, y, curx, cury, dx, dy;
	scanf("%d %d %d %d %d %d", &x, &y, &curx, &cury, &dx, &dy);
	int g = gcd(abs(dx), abs(dy));
	dx /= g;
	dy /= g;
	int ansDist = 1e9;
	int ansx = 0, ansy = 0;
	for (int i = 0; i < 1000; ++i) {
		if (ansDist > dist(x, y, curx + dx * i, cury + dy * i)) {
			ansDist = dist(x, y, curx + dx * i, cury + dy * i);
			ansx = curx + dx * i;
			ansy = cury + dy * i;
		}
	}
	printf("%d %d", ansx, ansy);
}