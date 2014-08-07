//uva 10235
import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String[] args){
    Scanner cin = new Scanner(System.in);
    while(cin.hasNext()){
      int a = cin.nextInt();
      BigInteger first = BigInteger.valueOf(a);
      String temp = first.toString();
      StringBuffer tempBuffer = new StringBuffer(temp);
      tempBuffer = tempBuffer.reverse();
      temp = tempBuffer.toString();
      int b = Integer.parseInt(temp);
      BigInteger second = new BigInteger(temp);
      System.out.printf("%d is ",a);
      if(!first.isProbablePrime(10)){
        System.out.println("not prime.");
      }
      else if((a!=b)&&(second.isProbablePrime(10))){
        System.out.println("emirp.");
      }
      else{
        System.out.println("prime.");
      }
    }
  }
}
  