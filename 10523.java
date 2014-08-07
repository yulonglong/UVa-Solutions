//uva 10523

import java.io.*;
import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		
		while(cin.hasNext()){
			long n = cin.nextLong();
			long a = cin.nextLong();
			
			BigInteger A = BigInteger.valueOf(a);
			BigInteger ans = BigInteger.ZERO;
			for(int i=1;i<=n;i++){
				BigInteger I = BigInteger.valueOf(i);
				ans = ans.add(I.multiply(A.pow(i)));
			}
			System.out.println(ans.toString());
		}
	}
}
