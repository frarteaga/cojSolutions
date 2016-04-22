//Prob: Contando Cadenas (3264)
//Matrix exponentiation

import java.util.Scanner;

public class Main {
	static int M[][];
	static int MOD = 1000000007;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		
		M = new int[11][11];
		for(int i = 1; i <= 10; i++)
			M[i][i] = i;
		
		for(int i = 0; i <= 9; i++)
			M[i][i + 1] = 10 - i;
		
		int[][] res = exp(M, n);
		
		int sol = 0;
		for(int i = a; i <= b; i++)
			sol = (sol + res[0][i]) % MOD;
		
		System.out.println(sol);
	}
	
	public static int[][] mult(int[][] A, int[][] B) {
		int n = A.length, m = A[0].length;
		int p = B[0].length;
		int[][] res = new int[n][p];
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < p; j++) {
				res[i][j] = 0;
				
				for(int k = 0; k < m; k++) {
					long x = (A[i][k] * 1L * B[k][j]) % MOD;
					res[i][j] = (res[i][j] + (int) x) % MOD;
				}
			}
		}
		
		return res;
	}
	
	public static int[][] exp(int[][] A, int e) {
		if(e == 1)
			return A;
		
		if((e & 1) == 1)
			return mult(A, exp(A, e - 1));
		
		int[][] S = exp(A, e / 2);
		return mult(S, S);
	}
}
