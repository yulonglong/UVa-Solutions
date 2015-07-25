// Steven Kester Yuwono - UVa 11029

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main (String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		while (n-- > 0) {
			int a = cin.nextInt();
			int p = cin.nextInt();
			BigInteger bi = BigInteger.valueOf(a);
			String trailingAns = bi.modPow(BigInteger.valueOf(p),BigInteger.valueOf(1000)).toString();
			if (trailingAns.length() == 1) trailingAns = "0" + trailingAns;
			if (trailingAns.length() == 2) trailingAns = "0" + trailingAns;

			double logA = p * Math.log10(a);
			double leadingDouble = Math.pow(10,(logA - Math.floor(logA)))*100.00;
			String leadingAns = Integer.toString((int)leadingDouble);
			System.out.println(leadingAns+"..."+trailingAns);
		}
	}
}
