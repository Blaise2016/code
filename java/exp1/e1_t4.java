import java.util.*;

public class e1_t4 {

	private static int n1 = 0, n2 = 0;

	public static int[] merge(int[] list1, int[] list2) {
		int[] ans = new int[200];
		int i = 1, j = 1, k = 0;
		while (i<=n1 && j <=n2) {
			if (list1[i] < list2[j]) {
				ans[++k] = list1[i];
				i++;
			} else {
				ans[++k] = list2[j];
				j++;
			}
		}
		while (i<=n1) ans[++k] = list1[i++];
		while (j<=n2) ans[++k] = list2[j++];
		return ans;
	} 
	public static void main(String[] args) {
		int[] a = new int[100];
		int[] b = new int[100];
		Scanner input = new Scanner(System.in);

		n1 = input.nextInt();
		for (int i=1; i<=n1; i++) a[i] = input.nextInt();
		n2 = input.nextInt();
		for (int i=1; i<=n2; i++) b[i] = input.nextInt();

		int[] ans = merge(a, b);
		for (int i=1; i<=n1+n2; i++) System.out.print(ans[i] + " ");

		System.out.println();
	}
}