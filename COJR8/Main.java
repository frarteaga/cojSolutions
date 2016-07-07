//package com.frankr.sol;

//import com.frankr.sol.*;
import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Iterator<Long>{

	final static long MAXN = 1000000;
	long N;

	public Main(){
		N = 0;
	}

	public long[] solve(long N, long k){
		long[] res = new long[(int)N];
		for (long i = N ; i > 0 ; i--){
			res[(int)i - 1] = i;
			if (k >= (i - 2) * (i - 1) / 2){
				int p = 0;
				for (int j = (int)i - 1 ; j > 0 ; j--){
					res[p] = j;
					p++;
				}
				long d = k - (i - 2) * (i - 1) / 2;
				while (d > 0){
					long tmp = res[(int)i - 1];
					res[(int)i - 1] = res[(int)i - 2];
					res[(int)i - 2] = tmp;
					i--;
					d--;
				}
				break;
			}
		}
		return res;
	}

	public boolean check(long N, long k, long[] p){
		if (p.length != N)
			return false;
		long ci = 0;
		for (int i = 0 ; i < N ; i++){
			if (p[i] < 1 || p[i] > N)
				return false;
			for (int j = i + 1 ; j < N ; j++){
				if (p[i] > p[j])
					ci++;
				if (p[i] == p[j])
					return false;
			}
		}
		return ci == k;
	}

	public static void main(String [] args){
		Main sol = new Main();
		Scanner in = new Scanner(System.in);
		while (in.hasNext()){
			//long N = sol.next();
			//long k = sol.next();
			long N = in.nextLong();
			long k = in.nextLong();
			//System.out.println(N + " " + k);

			//long ini = System.currentTimeMillis();
			long[] p = sol.solve(N, k);
			//System.out.println(System.currentTimeMillis() - ini);
			System.out.print(p[0]);
			for (int i = 1; i < N; i++) {
				System.out.print(" " + p[i]);
			}
			//System.out.println(sol.check(N, k, p));
		}
	}

	@Override
	public boolean hasNext() {
		return true;
	}

	@Override
	public Long next() {
		if (N != 0){
			long k = 0;
			while (k > (N - 1) * N / 2 || k <= 0)
				k = Math.round(Math.random() * N * (N - 1) / 2) + 1;
			N = 0;
			return k;
		}
		else
		if (N == 0){
			N = Math.round(Math.random() * MAXN) + 1;
		}
		return N;
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub

	}
}
