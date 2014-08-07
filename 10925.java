//uva 10925
import java.util.Scanner;
import java.math.BigInteger;

class Main{
 public static void main(String[] args){
  Scanner cin = new Scanner (System.in);
  int counter=1;
  int n=cin.nextInt();
  int f=cin.nextInt();
  while(!((n==0)&&(f==0))){
   BigInteger sum = BigInteger.ZERO;
   for(int i=0;i<n;i++){
    BigInteger tempBI = cin.nextBigInteger();
    sum = sum.add(tempBI);
   }
   System.out.println("Bill #" + (counter++) + " costs " + sum +
    ": each friend should pay " + sum.divide(BigInteger.valueOf(f)) + "\n");
   n=cin.nextInt();
   f=cin.nextInt();
  }
 }
}