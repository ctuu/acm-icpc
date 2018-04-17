import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    BigInteger[] dp = new BigInteger[103];
    BigInteger[] ft = new BigInteger[103];
    ft[0] = BigInteger.ONE;
    ft[1] = BigInteger.ONE;
    for(int i = 1; i < 103; ++i)
    {
      ft[i] = ft[i-1].multiply(BigInteger.valueOf(i));
      dp[i] = BigInteger.ZERO;
    }
    dp[0] = BigInteger.ONE;
    dp[1] = BigInteger.ONE;
    for(int i = 2; i < 103; ++i)
      for(int j = 0; j < i; ++j)
        dp[i] = dp[i].add(dp[j].multiply(dp[i-j-1]));
    Scanner cin = new Scanner(System.in);
    while(cin.hasNext())
    {
      int n = cin.nextInt();
      if(n == 0)
        break;
      System.out.println(dp[n].multiply(ft[n]));
    }
  }
}
