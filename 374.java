// Steven Kester Yuwono - UVa 374

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		int b,p,m;
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			b = cin.nextInt();
			p = cin.nextInt();
			m = cin.nextInt();	
			BigInteger bi = BigInteger.valueOf(b);
			bi = bi.modPow(BigInteger.valueOf(p),BigInteger.valueOf(m));
			System.out.println(bi);
		}
	}
}
