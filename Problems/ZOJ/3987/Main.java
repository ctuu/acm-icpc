import java.util.*;
import java.math.*;

public class Main {
  public static BigInteger TWO = BigInteger.valueOf(2);
  public static BigInteger bas[] = new BigInteger[4005];

  public static void init() {
    bas[0] = BigInteger.ONE;
    for (int i = 1; i <= 4000; ++i)
      bas[i] = bas[i - 1].multiply(TWO);
  }

  public static void main(String[] args) {
    init();
    Scanner cin = new Scanner(System.in);
    try {
      int t = cin.nextInt();
      while (t-- > 0) {
        BigInteger n = cin.nextBigInteger();
        BigInteger m = cin.nextBigInteger();
        int up = 0;
        BigInteger sum = BigInteger.ZERO, tmp = n, ans = BigInteger.ZERO;
        while (sum.compareTo(n) < 0) {
          sum = sum.add(m.multiply(bas[up]));
          ++up;
        }
        for (int i = up; i >= 0; --i) {
          BigInteger tm = bas[i].subtract(BigInteger.ONE);
          if (tm.multiply(m).compareTo(tmp) >= 0)
            continue;
          BigInteger k = tmp.divide(bas[i]);
          k = k.min(m);
          tmp = tmp.subtract(bas[i].multiply(k));
          ans = ans.add(bas[i]);
        }
        System.out.println(ans);
      }
    } finally {
      cin.close();
    }
  }
}