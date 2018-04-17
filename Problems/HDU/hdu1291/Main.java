import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String [] args) {
        BigInteger dp[] = new BigInteger[23];
        BigInteger rs[] = new BigInteger[23];
        BigInteger ft[] = new BigInteger[533];
        ft[0] = BigInteger.ONE;
        ft[1] = BigInteger.ONE;
        for(int i = 2; i < 533; ++i)
            ft[i] = ft[i-1].multiply(BigInteger.valueOf(i));
        for(int i = 0; i < 23; ++i)
            rs[i] = ft[i * i];
        for(int i = 1; i < 23; ++i)
        {
            dp[i] = rs[i];
            BigInteger tmp = BigInteger.ONE;
            for (int k = 1; k < 2 * i; ++k)
            {
                BigInteger t2 = BigInteger.valueOf(k);
                tmp = tmp.multiply(t2.pow(i - Math.abs(i - k)));
            }
            dp[i] = dp[i].divide(tmp);
        }
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            int n = cin.nextInt();
            System.out.println(dp[n]);
        }
    }
}