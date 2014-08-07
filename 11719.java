//uva 11719

import java.io.*;
import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args){
		BigInteger MOD_CONST = new BigInteger("10000000000000007");
		Scanner cin = new Scanner(System.in);
		int tc = cin.nextInt();
		while(tc-- >0){
			long r = cin.nextLong();
			long c = cin.nextLong();
			long m = r*c/2;
			long n = r*c-m;
			BigInteger M = BigInteger.valueOf(m);
			BigInteger N = BigInteger.valueOf(n);
			BigInteger M1 = BigInteger.valueOf(m-1);
			BigInteger N1 = BigInteger.valueOf(n-1);
			BigInteger M2 = M.modPow(N1,MOD_CONST);
			BigInteger N2 = N.modPow(M1,MOD_CONST);
			BigInteger ans = M2.multiply(N2).mod(MOD_CONST);
			System.out.println(ans.toString());
		}
	}
}
