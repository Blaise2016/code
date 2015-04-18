#include <stdio.h>
#include <memory.h>
#define oo 2147480000

int n;
int a[207], f[207][207];

int min(int a, int b) {
	return a>b?b:a;
}

int mult(int i, int j) {
	if (f[i][j] != -1) return f[i][j];
	if (i+1 == j) {
		f[i][j] = 0;
	} else {
		f[i][j] = oo;
		for (int k=i+1; k<=j-1; k++) {
			f[i][j] = min(f[i][j], mult(i, k) + mult(k, j) + a[i]*a[k]*a[j]);
		}
	}
	return f[i][j];
}

int main() {
	scanf("%d", &n);
	n++;
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	memset(f, -1, sizeof(f));
	printf("%d", mult(1, n));
	return 0;
}
