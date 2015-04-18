import java.util.*;

public class e2_t2 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double a, b, c;
		a = input.nextDouble();
		b = input.nextDouble();
		c = input.nextDouble();
		QuadraticEquation QE = new QuadraticEquation(a, b, c);
		System.out.println("二次方程的a系数是: " + QE.getA());
		System.out.println("二次方程的b系数是: " + QE.getB());
		System.out.println("二次方程的c系数是: " + QE.getC());
		System.out.println("二次方程的delta是: " + QE.getDiscriminant());
		System.out.println("二次方程的第一个根是: " + QE.getRoot1());
		System.out.println("二次方程的第二个根是: " + QE.getRoot2());
	}
}

class QuadraticEquation {
	private double a=0, b=0, c=0;
	private double delta=0;
	private static final double eps = 1e-8;
	private boolean havaRoots;
	private String r1, r2;


	public QuadraticEquation(double a, double b, double c){
		this.a = a;
		this.b = b;
		this.c = c;
		delta = b*b-4*a*c;
		if (delta<this.eps) 
			havaRoots = false;
		else {
			havaRoots = true;
			this.r1 = Double.toString((-this.b+Math.sqrt(this.delta))/(2*this.a));
			this.r2 = Double.toString((-this.b-Math.sqrt(this.delta))/(2*this.a));
		}
	}	

	public double getA() {
		return this.a;
	}
	public double getB() {
		return this.b;
	}
	public double getC() {
		return this.c;
	}
	public double getDiscriminant() {
		return delta;
	}
	public String getRoot1() {
		if (this.delta<0) return "没有实根";
		return r1;
	}
	public String getRoot2() {
		if (this.delta<0) return "没有实根";
		return r2;
	}

}