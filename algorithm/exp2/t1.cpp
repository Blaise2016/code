#include <stdio.h>

int a[1047][1047];
int n, dx, dy;
int ind = 0;

void divide(int x, int y, int len, int dx, int dy) {
	if (len==2) {
		++ind;
		if (x!=dx || y!=dy) a[x][y] = ind;
		if ((x+1)!=dx || y!=dy) a[x+1][y] = ind;
		if (x!=dx || (y+1)!=dy) a[x][y+1] = ind;
		if ((x+1)!=dx || (y+1)!=dy) a[x+1][y+1] = ind;
	} else {
		int tx = x + (len>>1) - 1,
		    ty = y + (len>>1) - 1;
		int x1 = x, y1 = y,
			x2 = x, y2 = y + (len>>1),
			x3 = x + (len>>1), y3 = y,
			x4 = x + (len>>1), y4 = y + (len>>1);
		
		++ind;
		if (dx<=tx && dy<=ty) {
			a[tx+1][ty] = a[tx][ty+1] = a[tx+1][ty+1] = ind;
			divide(x1, y1, len>>1, dx, dy);
			divide(x2, y2, len>>1, tx, ty+1);
			divide(x3, y3, len>>1, tx+1, ty);
			divide(x4, y4, len>>1, tx+1, ty+1);
		} else 
		if (dx<=tx && dy>ty) {
			a[tx][ty] = a[tx+1][ty] = a[tx+1][ty+1] = ind;
			divide(x1, y1, len>>1, tx, ty);
			divide(x2, y2, len>>1, dx, dy);
			divide(x3, y3, len>>1, tx+1, ty);
			divide(x4, y4, len>>1, tx+1, ty+1);
		} else 
		if (dx>tx && dy<=ty) {
			a[tx][ty] = a[tx][ty+1] = a[tx+1][ty+1] = ind;
			divide(x1, y1, len>>1, tx, ty);
			divide(x2, y2, len>>1, tx, ty+1);
			divide(x3, y3, len>>1, dx, dy);
			divide(x4, y4, len>>1, tx+1, ty+1);
		} else 
		if (dx>tx && dy>ty) {
			a[tx][ty] = a[tx][ty+1] = a[tx+1][ty] = ind;
			divide(x1, y1, len>>1, tx, ty);
			divide(x2, y2, len>>1, tx, ty+1);
			divide(x3, y3, len>>1, tx+1, ty);
			divide(x4, y4, len>>1, dx, dy);
		}
	}
	
}

int main() {
	scanf("%d", &n);
	n = 1<<n;
	scanf("%d %d", &dx, &dy);
	
	divide(1, 1, n, dx, dy);
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<n; j++) printf("%d ", a[i][j]);
		printf("%d\n", a[i][n]);
	}
	
	return 0;
}
