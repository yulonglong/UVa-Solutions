//uva 11879
import java.io.*;
import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args){
		BigInteger MOD_CONST = new BigInteger("17");
		Scanner cin = new Scanner(System.in);
		String word = cin.next();
		while(!word.equals("0")){
			BigInteger BI = new BigInteger(word);
			
			if((BI.mod(MOD_CONST)).equals(BigInteger.ZERO)){
				System.out.println("1");
			}
			else{
				System.out.println("0");
			}
			
			word = cin.next();
		}
	}
}
