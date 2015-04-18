#include <stdio.h>
#include <memory.h>
int n, v[11], a[11];

void dfs(int d) {
	if (d>n) {
		for (int i=1; i<n; i++) printf("%d ", a[i]);
		printf("%d\n", a[n]);
	} else {
		for (int i=1; i<=n; i++)
		if (!v[i]) {
			v[i] = 1;
			a[d] = i;
			dfs(d+1);
			v[i] = 0;
 		}
	}
}

int main() {
	memset(v, 0, sizeof(v));
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	dfs(1);
	return 0;
}
