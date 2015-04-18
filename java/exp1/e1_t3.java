import java.util.*;

public class e1_t3 {
	private static boolean prime(int n) {
		int ceil = (int)Math.sqrt(n);
		for (int i=2; i<=ceil; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}

	private static boolean cir(int n) {
		int[] a = new int[100];
		int len = 0;
		while (n > 0) {
			a[++len] = n % 10;
			n = n / 10;
		}
		for (int i=1; i<=len/2; i++) 
		if (a[i] != a[len-i+1]) return false;
		return true;
	}

	public static void main(String[] args) {
		int cnt = 0;
		int num = 2;
		int line = 0;
		while (cnt < 100) {
			if (prime(num) && cir(num)) {
				System.out.print(num + " ");
				cnt ++;
				line ++;
			}
			num ++;
			if (line == 10) {
				System.out.println();
				line = 0;
			}
		}
	}
}