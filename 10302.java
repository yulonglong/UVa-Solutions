// Steven Kester Yuwono - UVa 10302
import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main (String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			BigInteger bi = BigInteger.valueOf(n);
			bi = bi.multiply(BigInteger.valueOf(n+1));
			bi = bi.divide(BigInteger.valueOf(2));
			bi = bi.multiply(bi);
			System.out.println(bi);
		}
	}
}
