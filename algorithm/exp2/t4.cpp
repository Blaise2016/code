#include <stdio.h>

char a[1003], b[1003];
int n, m, f[1003][1003];

int max(int a, int b) {
	return a>b?a:b;
}

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i=1; i<=n; i++) scanf("%c", &a[i]);
	scanf("\n");
	for (int i=1; i<=m; i++) scanf("%c", &b[i]);
	for (int i=1; i<=n; i++)
	for (int j=1; j<=m; j++) {
		if (a[i]==b[j]) {
			f[i][j] = f[i-1][j-1] + 1;
		} else {
			f[i][j] = max(f[i-1][j], f[i][j-1]);
		}
	}
	printf("%d", f[n][m]);
	return 0;
}
