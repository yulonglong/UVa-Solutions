//Steven Kester Yuwono - UVa 1230

import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner(System.in);
    int tc = cin.nextInt();
    while(tc>0){
      BigInteger x = cin.nextBigInteger();
      BigInteger y = cin.nextBigInteger();
      BigInteger n = cin.nextBigInteger();
      System.out.println(x.modPow(y,n));
      tc--;
    }
  }
}
  