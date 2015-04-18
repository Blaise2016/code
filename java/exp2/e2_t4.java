import java.util.*;

public class e2_t4 {
	public static void main(String[] args) {
		double a[][] = {{1,2,3},{8,9,9,5},{4,3,5,7,8}};
		Location l = Location.locateLargest(a);
		System.out.println("Location类row变量的值为: " + l.row);
		System.out.println("Location类col变量的值为: " + l.col);
		System.out.println("Location类maxValue变量的值为: " + l.maxValue);
	}
}

class Location {
	public int row=0, col=0;
	public double maxValue = 0;

	public Location(int r, int c, double m) {
		this.row = r;
		this.col = c;
		this.maxValue = m;
	}

	public static Location locateLargest(double[][] a) {
		double max = a[1][1];
		int maxi=1, maxj=1;
		for (int i=0; i<a.length; i++)
		for (int j=0; j<a[i].length; j++)
		if (a[i][j]>max) {
			max = a[i][j];
			maxi = i;
			maxj = j;
		}
		return new Location(maxi, maxj, max);
	}

}