import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        BigInteger[] dp = new BigInteger[1003];
        BigInteger bs = BigInteger.ONE;
        BigInteger ex = new BigInteger("2");
        dp[0] = BigInteger.ZERO;
        dp[1] = BigInteger.ZERO;
        dp[2] = BigInteger.ONE;
        for(int i  = 3; i < 1003; ++i)
        {
            dp[i] = bs.add(dp[i-2]);
            bs = bs.multiply(ex);
        }
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            int n = cin.nextInt();
            System.out.println(dp[n]);
        }
    }
}