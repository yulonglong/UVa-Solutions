// Steven Kester Yuwono - UVa 10198

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);

		BigInteger memo[] = new BigInteger[1001];

		memo[0] = BigInteger.ONE;
		memo[1] = BigInteger.valueOf(2);
		memo[2] = BigInteger.valueOf(5);
		memo[3] = BigInteger.valueOf(13);

		for(int i=4; i<1001; i++)
		{
			memo[i] = (BigInteger.valueOf(2).multiply(memo[i-1])).add(memo[i-2]).add(memo[i-3]);
		}

		int query;
		while(cin.hasNext())
		{
			query = cin.nextInt();
			System.out.println(memo[query]);
		}
	}
}