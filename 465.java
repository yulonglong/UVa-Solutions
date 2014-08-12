//Steven Kester Yuwono - UVa 465

import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()){
            String v1 = cin.next();
            String op = cin.next();
            String v2 = cin.next();
            String max = "2147483647";
            BigInteger b1 = new BigInteger(v1);
            BigInteger b2 = new BigInteger(v2);
            BigInteger maxB = new BigInteger(max);
            System.out.println(v1 + " " + op + " " + v2);
            if(b1.compareTo(maxB)>0){
                System.out.println("first number too big");
            }
            if(b2.compareTo(maxB)>0){
                System.out.println("second number too big");
            }
            BigInteger result =BigInteger.ZERO;
            if(op.equals("+")){
                result = b1.add(b2);
            }
            else{
                result = b1.multiply(b2);
            }
            if(result.compareTo(maxB)>0){
                System.out.println("result too big");
            }
        }
    }
}