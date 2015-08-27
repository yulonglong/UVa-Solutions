// Steven Kester Yuwono - UVa 10579
import java.util.*;
import java.math.BigInteger;

class Main {
	static int MAX = 5000;
	static BigInteger[] fib = new BigInteger[MAX];
	public static void init() {
		fib[1] = BigInteger.ONE;
		fib[2] = BigInteger.ONE;
		for(int i=3;i<MAX;i++){
			fib[i] = fib[i-1].add(fib[i-2]);
		}
	}

	public static void main(String[] args) {
		init();
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			System.out.println(fib[n]);
		}
	}
}
