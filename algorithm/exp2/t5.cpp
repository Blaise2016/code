#include <stdio.h>

int a[1003][1003], f[1003][1003];
int ans = 0, n;

int max(int a, int b) {
	return a>b?a:b;
}

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	for (int j=1; j<=i; j++) scanf("%d", &a[i][j]);
	
	f[1][1] = a[1][1];
	
	for (int i=2; i<=n; i++) {
		ans = max(ans, f[i][1] = f[i-1][1] + a[i][1]);	
		ans = max(ans, f[i][i] = f[i-1][i-1] + a[i][i]);
		for (int j=2; j<i; j++)
			ans = max(ans, f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j]);
	}
	
	printf("%d", ans);
	return 0;
}
