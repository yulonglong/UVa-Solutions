//Steven Kester Yuwono - UVa 10551

import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner(System.in);
    int b;
    b=cin.nextInt();
    while(b!=0){
      String word;
      word=cin.next();
      BigInteger p = new BigInteger(word,b);
      word=cin.next();
      BigInteger m = new BigInteger(word,b);
      word = p.mod(m).toString(b);
      System.out.println(word);
      b=cin.nextInt();
    }
  }
}
  