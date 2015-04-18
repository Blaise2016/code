#include <stdio.h>

int a[107][107], b[107][107], c[107][107], n1, m1, n2, m2;

int main() {
	scanf("%d %d", &n1, &m1);
	for (int i=1; i<=n1; i++) 
	for (int j=1; j<=m1; j++) scanf("%d", &a[i][j]);
	
	scanf("%d %d", &n2, &m2);
	for (int i=1; i<=n2; i++) 
	for (int j=1; j<=m2; j++) scanf("%d", &b[i][j]);
	
	for (int i=1; i<=n1; i++) {

		for (int j=1; j<=m2; j++) {
			int sum = 0;
			for (int k=1; k<=m1; k++) sum += a[i][k]*b[k][j];
			c[i][j] = sum;
			
		}
		
	}
	for (int i=1; i<=n1; i++) {
		for (int j=1; j<m2; j++) printf("%d ", c[i][j]);
		printf("%d\n", c[i][m2]);
	}
	return 0;
}
