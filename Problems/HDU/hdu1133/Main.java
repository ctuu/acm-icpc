import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    BigInteger com[][] = new BigInteger[203][203];
    for(int i = 0; i < 203; ++i)
      for(int j = 0; j < 203; ++j)
          com[i][j] = BigInteger.ZERO;
    com[1][0] = BigInteger.ONE;
    for(int i = 1; i < 203; ++i)
      for(int j = 1; j < 203; ++j)
          com[j][i] = com[j-1][i-1].add(com[j][i-1]);
    BigInteger fact[] = new BigInteger[103];
    fact[0] = BigInteger.ONE;
    fact[1] = BigInteger.ONE;
    for(int i = 2; i < 103; ++i)
      fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));

    BigInteger catn[] = new BigInteger [103];
    for(int i = 0; i < 103; ++i)
      catn[i] = BigInteger.ZERO;
    catn[0] = BigInteger.ONE;
    catn[1] = BigInteger.ONE;
    catn[2] = BigInteger.valueOf(2);
    for(int i = 3; i < 103; ++i)
      for(int j = 0; j < i; ++j)
        catn[i] = catn[i].add(catn[j].multiply(catn[i-j-1]));
    Scanner cin = new Scanner(System.in);
    int t = 1;
    while(true)
    {
      int m = cin.nextInt();
      int n = cin.nextInt();
      if(n == 0 && m == 0)
        break;
      System.out.println("Test #" + t + ":");
      if(m < n)
      {
        System.out.println("!0");
        continue;
      }
      BigInteger p1 = catn[n];
      BigInteger p2 = com[n+1][m];
      BigInteger p3 = n == 0 ? BigInteger.ONE: com[m-n+1][2 * n + 1];
      BigInteger p4 = fact[m-n];      
      BigInteger p6 = fact[n].pow(2);
      BigInteger res = p1.multiply(p2).multiply(p3).multiply(p4).multiply(p6);
      System.out.println(res);
    }
  }
}