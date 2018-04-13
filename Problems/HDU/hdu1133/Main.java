import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {

    BigInteger fact[] = new BigInteger[203];
    fact[0] = BigInteger.ONE;
    fact[1] = BigInteger.ONE;
    for (int i = 2; i < 203; ++i)
      fact[i] = fact[i - 1].multiply(BigInteger.valueOf(i));

    Scanner cin = new Scanner(System.in);
    int t = 0;
    while (cin.hasNext()) {
      ++t;
      int m = cin.nextInt();
      int n = cin.nextInt();
      if (n == 0 && m == 0)
        break;
      BigInteger res = BigInteger.ZERO;
      BigInteger p4 = BigInteger.valueOf(m - n + 1);
      BigInteger p6 = BigInteger.valueOf(m + 1);
      if (m >= n)
        res = fact[m + n].multiply(p4).divide(p6);
      System.out.println("Test #" + t + ":");
      System.out.println(res);
    }
  }
}