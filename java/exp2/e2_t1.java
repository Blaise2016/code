import java.util.*;

public class e2_t1 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int[][]	a = new int[n+1][n+1];
		for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++) 
			a[i][j] = input.nextInt();
		int[] ans = findLargestBlock(a);
		System.out.println(ans[0]+" "+ans[1]+" "+ans[2]);
	}

	public static int[] findLargestBlock(int[][] m) {
		int n = m.length - 1;
		int i, j, k;
		int maxk=1, maxi=1, maxj=1;
		int ok;
		for (i=1; i<=n; i++) 
		for (j=1; j<=n; j++) {
			k = 0;
			ok = 1;
			while (k+i<=n && k+j<=n) {
				for (int u=0; u<=k; u++) {
					if (m[i+k][j+u]!=1) {ok = 0; break;}
					if (m[i+u][j+k]!=1) {ok = 0; break;}
				}
				if (ok == 0) break;
				k++;
			}
			if (k>maxk) {
				maxi = i;
				maxj = j;
				maxk = k;
			}
		}
		int ans[] = {maxi-1, maxj-1, maxk};
		return ans;
	}
}