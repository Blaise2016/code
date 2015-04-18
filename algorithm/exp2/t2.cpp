#include <stdio.h>

int n, E1, E2, X1, X2, ans;
int a1[1003], a2[1003], t1[1003], t2[1003];
int f1[1003], f2[1003];

int min(int a, int b) {
	return a>b?b:a;
}

int main() {
	scanf("%d", &n);
	scanf("%d %d %d %d", &E1, &E2, &X1, &X2);
	for (int i=1; i<=n; i++) scanf("%d", &a1[i]);
	for (int i=1; i<=n; i++) scanf("%d", &a2[i]);
	for (int i=1; i<n; i++)  scanf("%d", &t1[i]);
	for (int i=1; i<n; i++)  scanf("%d", &t2[i]);
	
	f1[1] = E1 + a1[1]; f2[1] = E2 + a2[1];
	
	for (int i=2; i<=n; i++) {
		f1[i] = min(f1[i-1], f2[i-1]+t2[i-1]) + a1[i];
		f2[i] = min(f2[i-1], f1[i-1]+t1[i-1]) + a2[i];
	}
	
	ans = min(f1[n]+X1, f2[n]+X2);
	
	printf("%d", ans);
} 
