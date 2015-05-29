// Steven Kester Yuwono - UVa 787

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main (String[] args) {
		Scanner cin = new Scanner(System.in);
		int[] store; store = new int[101];
		int size = 0;
		while(cin.hasNext()){
			int temp = cin.nextInt();
			if(temp != -999999) {
				store[size++] = temp;
			}
			else {
				BigInteger max = BigInteger.valueOf(-2000000000);
				BigInteger curr = BigInteger.valueOf(1);

				for(int i=0;i<size;i++){
					curr = BigInteger.valueOf(1);
					for(int j=i;j<size;j++) {
						curr = curr.multiply(BigInteger.valueOf(store[j]));
						if (max.compareTo(curr) < 0) {
							max = curr;
						}
					}
				}
				System.out.println(max.toString());
				size = 0;
			}
		}
	}
}