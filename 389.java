//uva 389
import java.io.*;
import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args){
		PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		Scanner cin = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	
		while(cin.hasNext()){
			String a = cin.next();
			int b = cin.nextInt();
			int c = cin.nextInt();
			BigInteger BI = new BigInteger(a,b);
			String word = BI.toString(c).toUpperCase();
			
			if(word.length()>7){
				word = "ERROR";
			}
			pr.printf("%7s\n", word);
			
		}
		pr.close();
		
	}
}
