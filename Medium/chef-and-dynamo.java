// https://www.codechef.com/JAN20B/problems/DYNAMO
// Maths

import java.util.*;

class Solution
{
	public static long computerPower(int N)
	{
		long result = 1;
		for(int i = 0; i < N; i++) {
			result *= 10;
		}
		return result;
	}
    
	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		long TOTAL, A, B, D, S;

		int t = scan.nextInt();
		while(t-- > 0)
		{
			int N = scan.nextInt();            // get N-digits

			TOTAL = computerPower(N);

			A = scan.nextLong();               // get A

			S = A + 2 * TOTAL;                 // computer S
			System.out.println(S);             // S = A + (B+C) + (D+E) where
			                                   // sum of each pair is TOTAL

			B = scan.nextLong();               // get B
			System.out.println(TOTAL - B);     // computer C

			D = scan.nextLong();               // get D
			System.out.println(TOTAL-D);       // computer E

			int result = scan.nextInt();       // get the result

			if(result == -1) break;
		}
	}
}