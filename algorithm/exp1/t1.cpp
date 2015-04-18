#include <stdio.h>

long a[1000007], n;

void sort(long l, long r) {
	long i=l, j=r, x=a[(l+r)>>1];
	do {
		while (a[i]<x) i++;
		while (a[j]>x) j--;
		if (i<=j) {
			long t=a[i]; a[i]=a[j];a[j]=t;
			i++; j--;
		}
	} while (i<=j);
	if (i<r) sort(i, r);
	if (l<j) sort(l, j);
}

int main() {
	scanf("%ld", &n);
	for (long i=1; i<=n; i++) scanf("%ld", &a[i]);
	sort(1, n);
	for (long i=1; i<n; i++) printf("%ld ", a[i]);
	printf("%ld", a[n]);
	return 0; 
} 
