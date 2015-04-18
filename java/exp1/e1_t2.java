import java.util.*;
import javax.swing.*;
public class e1_t2 {
	public static void main(String[] args) {
		int n = Integer.parseInt(JOptionPane.showInputDialog(null, "please input i"));
		double p = 0;
		for (int i=1; i<=n; i++) {
			p += Math.pow(-1, i+1) / (2*i-1);
		}
		p *= 4;
		JOptionPane.showMessageDialog(null, p);
	}
}