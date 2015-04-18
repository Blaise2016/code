import java.util.*;

public class e2_t3 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double a, b, c, d, e, f;
		a = input.nextDouble();
		b = input.nextDouble();
		c = input.nextDouble();
		d = input.nextDouble();
		e = input.nextDouble();
		f = input.nextDouble();
		LinearEquation LE = new LinearEquation(a, b, c, d, e, f);
		System.out.println("方程组的a系数是: " + LE.getA());
		System.out.println("方程组的b系数是: " + LE.getB());
		System.out.println("方程组的c系数是: " + LE.getC());
		System.out.println("方程组的d系数是: " + LE.getD());
		System.out.println("方程组的e系数是: " + LE.getE());
		System.out.println("方程组的f系数是: " + LE.getF());
		boolean solvable = LE.isSolvable();
		if (solvable) {
			System.out.println("方程有解, 解为: " + LE.getX() + "   " + LE.getY());
		} else {
			System.out.println("方程无解");
		}
	}
}


class LinearEquation {
	private double a, b, c, d, e, f;
	private boolean solvable = false;
	private double r1 = 0, r2 = 0;
	private static final double eps = 1e-8;

	public LinearEquation(double a, double b, double c, double d, double e, double f) {
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;
		this.e = e;
		this.f = f;
		if (Math.abs(a*d-b*c)<this.eps) 
			if (Math.abs(b*f-e*d)<this.eps) {
				solvable = true;
				r1 = 0; r2 = e/b;
			} else 
				solvable = false;
		else {
			solvable = true;
			this.r1 = (e*d-b*f)/(a*d-b*c);
			this.r2 = (a*f-e*c)/(a*d-b*c);
		}
	}

	public double getA() { return this.a; }
	public double getB() { return this.b; }
	public double getC() { return this.c; }
	public double getD() { return this.d; }
	public double getE() { return this.e; }
	public double getF() { return this.f; }

	public boolean isSolvable() {
		return this.solvable;
	}

	public String getX() {
		if (!solvable) 
			return "方程无解";
		else 
			return Double.toString(this.r1);
	}
	public String getY() {
		if (!solvable) 
			return "方程无解";
		else 
			return Double.toString(this.r2);
	}
}