//Steven Kester Yuwono - UVa 10814
import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner(System.in);
    int tc = cin.nextInt();
    while(tc>0){
      String temp;
      BigInteger first = cin.nextBigInteger();
      temp=cin.next();
      BigInteger second = cin.nextBigInteger();
      BigInteger cd = first.gcd(second);
      
      System.out.println(first.divide(cd).toString() + " / " +
                         second.divide(cd).toString());
      tc--;
    }
  }
}
  