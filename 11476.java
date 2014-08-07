//Steven Kester Yuwono - UVa 11476

import java.util.*;
import java.math.*;
import java.io.*;
import java.util.Map.Entry;

class Main {
	public static long abs_val(long a) {
		return (a > 0) ? a : -a;
	}

	public static long mulmod(long a, long b, long c) {
		long x = 0;
		long y = a % c;
		while(b > 0) {
			if(b % 2 == 1) x = (x + y) % c;
			y=(y*2)%c;
			b/=2;
		}
		return x % c;
	}

	public static long gcd(long a, long b) {
		return (b == 0) ? a : gcd(b, a % b);
	}

	public static long pollard_rho(long n) {
		if(n == 6 || n == 4) return 2;
		int i = 0;
		int k = 2;
		long x = 3;
		long y = 3;
		while(true) {
			i++;
			x = (mulmod(x, x, n) + n - 1) % n;
			long d = gcd(abs_val(y - x), n);
			if(d != 1 && d != n) return d;
			if(i==k) {
				y = x;
				k *= 2;
			}
		}
	}
	
	public static void getPrimeFactor(long num, Queue<Long> q ){
		//System.out.println("num " + num);
		for(long i=3;i<num;i+=2){
			if(num%i==0){
				long ans = i;
				q.offer(ans);
				q.offer(num/ans);
				//System.out.println(ans);
				//System.out.println(num/ans);
				return;
			}
		}
	
	}

	public static void solvePollardRho(long num){
		PrintWriter pw = new PrintWriter(System.out);
		long oriNum = num;
		// System.out.printf("%d = \n", oriNum);
		TreeMap<Long,Long> m = new TreeMap<Long,Long>();
		m.clear();
		BigInteger BI;

		BI = BigInteger.valueOf(num);
		if(BI.isProbablePrime(10)){
			pw.print(oriNum);
			pw.print(" = ");
			pw.print(oriNum);
			pw.println();
			pw.flush();
			return;
		}
		
		Queue<Long> q = new LinkedList<Long>();
		
		long ans;
		while(num%2==0){
			ans=2;
			
			Long temp = m.get(ans);
			if (temp==null){
				m.put(ans,(long)1);
			}
			else{
				m.put(ans,(long)temp+1);
			}
			
			num=num/2;
		}
		
		
		q.offer(num);
		while(!q.isEmpty()){
			long ans1;
			long ans2;
			num = q.poll();
		
			
			BI = BigInteger.valueOf(num);
			if(BI.isProbablePrime(10)){
				Long temp = m.get(num);
			
				if (temp==null){
					m.put(num,(long)1);
					
				}
				else{
					m.put(num,(long)temp+1);
				}
			}
			else{
				if(num<1000000){
					getPrimeFactor(num,q);
				}
				else{
					ans1 = pollard_rho(num);
					ans2 = num/ans1;
					q.offer(ans1);
					q.offer(ans2);
				}
			}
			
		}
		int first=1;
		
		pw.print(oriNum);
		pw.print(" = ");
		
		for(Entry<Long, Long> it : m.entrySet()) {
			if(first==0){
				pw.print(" * ");
			}
			else{
				first = 0;
			}
			long key = it.getKey();
			long value = it.getValue();
			pw.print(key);
			if(value!= 1) {
				pw.print("^");
				pw.print(value);
			}
		}
        pw.println();
        pw.flush();
		return;

	}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		
		while(tc-- > 0) {
			long num = Long.parseLong(sc.next());
			solvePollardRho(num);
		}
	}
}
