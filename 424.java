//Steven Kester Yuwono - UVa 424

import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        String temp;
        BigInteger sum;
        sum=BigInteger.ZERO;
        Scanner cin = new Scanner(System.in);
        temp=cin.next();
        while(!temp.equals("0")){
            BigInteger addNum = new BigInteger(temp);
            sum = sum.add(addNum);
            temp=cin.next();
        }
        System.out.println(sum);
    }
}
