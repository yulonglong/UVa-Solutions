// Steven Kester Yuwono - UVa 10334

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	static BigInteger fib[] = new BigInteger[1001];
	public static void init() {
		fib[0] = BigInteger.ONE;
		fib[1] = BigInteger.valueOf(2);
		for(int i=2;i<=1000;i++){
			fib[i] = fib[i-2].add(fib[i-1]);
		}
	}

	public static void main (String[] args) {
		init();
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()) {
			int n = cin.nextInt();
			System.out.println(fib[n]);
		}
	}
}
