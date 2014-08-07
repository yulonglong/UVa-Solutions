//uva 325
import java.util.Scanner;
import java.util.regex.*;

class Main{
	public static void main(String[] args){
		String word;
		Scanner cin = new Scanner(System.in);
		word = cin.nextLine();
		word=word.replaceAll("\\s+","");
		while(!word.equals("*")){
			if (word.matches("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)")){
				System.out.println(word+" is legal.");
			}
			else{
				System.out.println(word+" is illegal.");
			}
			word = cin.nextLine();
			word=word.replaceAll("\\s+","");
		}
	}
}
