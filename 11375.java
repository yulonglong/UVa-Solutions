// Steven Kester Yuwono - UVa 11375

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static int MAX = 2000;
	static BigInteger ONE = BigInteger.valueOf(1);
	static BigInteger[] combination = new BigInteger[2001];
	static int[] matches = {6,2,5,5,4,5,6,3,7,6};

	public static void initBasicTable() {
		for(int i = 1; i <= MAX; i++) {
			combination[i] = BigInteger.valueOf(0);
		}
		for(int i = 1; i < 10; i++) {
			combination[matches[i]] = combination[matches[i]].add(ONE);
		}
	}

	public static void fillTable() {
		for(int i = 1; i <= MAX; i++) {
			for(int j = 0; j < 10; j++) {
				if(i-matches[j] > 0)
					combination[i] = combination[i].add(combination[i-matches[j]]);
			}
		}
		combination[6] = combination[6].add(ONE);
		for(int i = 1; i < MAX; i++) {
			combination[i+1] = combination[i+1].add(combination[i]);
		}
	}

	public static void main(String args[]) {
		initBasicTable();
		fillTable();
		
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()){
			int N = sc.nextInt();
			System.out.println(combination[N].toString());
		}
		sc.close();
	}
}