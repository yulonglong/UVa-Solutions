// Steven Kester Yuwono - UVa 1647

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	static BigInteger TWO = BigInteger.valueOf(2);
	static BigInteger[] memo = new BigInteger[1001];

	public static void initialize() {
		memo[1] = BigInteger.ZERO;
		boolean plus = true;
		for(int i=2;i<=1000;i++){
			memo[i] = memo[i-1].multiply(TWO);
			if(plus){
				memo[i] = memo[i].add(BigInteger.ONE);
				plus = false;
			}
			else {
				memo[i] = memo[i].subtract(BigInteger.ONE);
				plus = true;
			}
		}
	}

	public static void main(String[] args) {
		initialize();
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			int n = cin.nextInt();
			System.out.println(memo[n].toString());
		}
	}
}