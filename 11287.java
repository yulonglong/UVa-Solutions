//uva 11287

import java.util.*;
import java.io.*;
import java.math.*;

class Main{
    public static void main(String[] args){
        long a,p;
        Scanner cin = new Scanner(System.in);
        p=cin.nextLong();
        a=cin.nextLong();
        while(!((a==0)&&(p==0))){
            BigInteger A = BigInteger.valueOf(a);
            BigInteger P = BigInteger.valueOf(p);
            BigInteger ans2 = A.modPow(P,P);
            if((A.equals(ans2))&&!(P.isProbablePrime(10))){
                System.out.println("yes");
            }
            else{
                System.out.println("no");
            }
            
            p=cin.nextLong();
            a=cin.nextLong();
        }
    }
}