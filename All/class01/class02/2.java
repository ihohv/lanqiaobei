// https://www.lanqiao.cn/problems/3382/learning/?page=1&first_category_id=1&problem_id=3382

import java.util.*;
import java.io.*;


public class Main {

    public static final int N = 100009;
    public static long a[][] = new long [6][N];
    public static long prefix[][] = new long [6][N];
    public static final long p = 1000000007;
    public static int m,n,l,r,k;

    static StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static void nextToken() {try {st.nextToken();} catch(Exception e){e.printStackTrace();}}
    static int nextInt() {nextToken(); return (int)st.nval;}
    static String next() {nextToken(); return st.sval;}
  
    public static void main(String[] args) throws IOException{
      n = nextInt();
      m = nextInt();
      for(int i=1;i<=n;i++)
        a[1][i] = nextInt();
      compute1();
      for(int i=1;i<=m;i++){
        l = nextInt();
        r = nextInt();
        k = nextInt();
        System.out.println(compute2());
      }
    }

    public static void compute1(){
      for(int i=2;i<=5;i++)
        for(int j=1;j<=n;j++)
          a[i][j] = a[i-1][j]*a[1][j]%p;

      for(int i=1;i<=5;i++)
        for(int j=1;j<=n;j++)
          prefix[i][j] = (prefix[i][j-1]+a[i][j])%p;
    }

    public static long compute2(){
      return (prefix[k][r] - prefix[k][l-1]+p)%p;
    }
}